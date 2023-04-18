//  DDS sound generater using wavetable with bitcrushing
//  For Atmega368P at 16 MHz (Arduino)
//  Written for Noisexistance Festival 2018
//  John Richards/Max Wainwright
//  Based on script by Gary Hill and Michael Smith
//
//  Output pulse-width modulation (PWM) on pin 6 (Timer 0). A simple RC filter is used.
//  Values: R = 2.2k - 10k; C = 0.1uF. Includes a decoupling cap on output after
//  the filter.
//
//  Uses timers 1 and 0. Timer 1 reads the wavetable, SAMPLE_RATE times a second.
//  The wavetable example (sinewave) has 256 entries. Consequently, the wavetable
//  (sinewave) has a frequency of f = SAMPLE_RATE / 256.
//
//  Each element in the wavetable defines the duty-cycle of Timer 0. Timer 0
//  holds pin 6 high from 0 to 255 ticks out of a 256-tick cycle, depending on
//  the current duty cycle. Timer 0 repeats 62500 times per second (16000000 / 256),
//  much faster than the generated wavetable (sinewave) frequency.
//
//  Bitcrushing
//  An AnalogInput (A0) has been used as a variable for the SAMPLE_RATE.
//  The SAMPLE_RATE can be defined and called in the void startPlayback();
//  or as a variable in void loop() for bitcrushing. For 57mm, the AnalogInput
//  is from a microphone and touch controls.



//see startPlayback();
//#define SAMPLE_RATE 8000 // low freq (8000/256 = 31.25 Hz)
//#define SAMPLE_RATE 280000 // 1.04 kHz approx highest poss freq with length of 256?

//  Hexidecimal values. Sinewave. Centered (starts) at 128.
//  Stored in flash memory PROGMEM.
//  Note: Flash (PROGMEM) memory can only be populated at program burn time. You
//  can’t change the values in the flash after the program has started running.
//  Store wavetable in SRAM to cahnge values?

const int sinewave_length = 256;
const unsigned char sinewave_data [] PROGMEM =
{
  0x80, 0x83, 0x86, 0x89, 0x8c, 0x8f, 0x92, 0x95, 0x98, 0x9c, 0x9f, 0xa2, 0xa5, 0xa8, 0xab, 0xae,
  0xb0, 0xb3, 0xb6, 0xb9, 0xbc, 0xbf, 0xc1, 0xc4, 0xc7, 0xc9, 0xcc, 0xce, 0xd1, 0xd3, 0xd5, 0xd8,
  0xda, 0xdc, 0xde, 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xed, 0xef, 0xf0, 0xf2, 0xf3, 0xf5,
  0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfc, 0xfd, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfd, 0xfc, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8, 0xf7,
  0xf6, 0xf5, 0xf3, 0xf2, 0xf0, 0xef, 0xed, 0xec, 0xea, 0xe8, 0xe6, 0xe4, 0xe2, 0xe0, 0xde, 0xdc,
  0xda, 0xd8, 0xd5, 0xd3, 0xd1, 0xce, 0xcc, 0xc9, 0xc7, 0xc4, 0xc1, 0xbf, 0xbc, 0xb9, 0xb6, 0xb3,
  0xb0, 0xae, 0xab, 0xa8, 0xa5, 0xa2, 0x9f, 0x9c, 0x98, 0x95, 0x92, 0x8f, 0x8c, 0x89, 0x86, 0x83,
  0x80, 0x7c, 0x79, 0x76, 0x73, 0x70, 0x6d, 0x6a, 0x67, 0x63, 0x60, 0x5d, 0x5a, 0x57, 0x54, 0x51,
  0x4f, 0x4c, 0x49, 0x46, 0x43, 0x40, 0x3e, 0x3b, 0x38, 0x36, 0x33, 0x31, 0x2e, 0x2c, 0x2a, 0x27,
  0x25, 0x23, 0x21, 0x1f, 0x1d, 0x1b, 0x19, 0x17, 0x15, 0x13, 0x12, 0x10, 0x0f, 0x0d, 0x0c, 0x0a,
  0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x03, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x03, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
  0x09, 0x0a, 0x0c, 0x0d, 0x0f, 0x10, 0x12, 0x13, 0x15, 0x17, 0x19, 0x1b, 0x1d, 0x1f, 0x21, 0x23,
  0x25, 0x27, 0x2a, 0x2c, 0x2e, 0x31, 0x33, 0x36, 0x38, 0x3b, 0x3e, 0x40, 0x43, 0x46, 0x49, 0x4c,
  0x4f, 0x51, 0x54, 0x57, 0x5a, 0x5d, 0x60, 0x63, 0x67, 0x6a, 0x6d, 0x70, 0x73, 0x76, 0x79, 0x7c
};



int button = 2; //set digital input
int outputPin = 6; // (PCINT22/OC0A/AIN0)PD6, Arduino Digital Pin 6

int mic = A0;   // select the input pin for the mic
int touch = A1; //touch input pin

int addr ; //address for EEPROM reading, set to random so program always starts in different ways

int temp = 0; //used here and there for stuff, don't expect it to be anything in particular (probably is zero)
  
              //scaling variables for map()
int tchlo = 100;
int tchhi = 920;
int miclo = 820;
int michi = 1023;

//eepr values declaration
int eepr1;

#include <EEPROM.h>



//volatile uint16_t sample;
volatile uint8_t sample;
// This is called at SAMPLE_RATE kHz to load the next sample.
ISR(TIMER1_COMPA_vect) {
  if (sample >= sinewave_length) {
    sample = -1;

  }
  else {
    OCR0A = pgm_read_byte(&sinewave_data [sample]);
  }

  
  sample += 8;                                //this, plus the sample reading stuff in the various algos
  

}
void startPlayback()
{
  pinMode(button, INPUT);
 // digitalWrite(button ,HIGH);  // enable pullup resistor

  pinMode(outputPin, OUTPUT);

  // Set Timer 0 Fast PWM Mode (Section 14.7.3)
  // WGM = 0b011 = 3  (Table 14-8)
  // TOP = 0xFF, update OCR0A register at BOTTOM
  TCCR0A |= _BV(WGM01) | _BV(WGM00);
  TCCR0B &= ~_BV(WGM02);

  // Do non-inverting PWM on pin OC0A, arduino digital pin 6
  // COM0A = 0b10, clear OC0A pin on compare match,
  //               set 0C0A pin at BOTTOM (Table 14-3)
  TCCR0A = (TCCR0A | _BV(COM0A1)) & ~_BV(COM0A0);

  // COM0B = 0b00, OC0B disconnected (Table 14-6)
  TCCR0A &= ~(_BV(COM0B1) | _BV(COM0B0));

  // No prescaler, CS = 0b001 (Table 14-9)
  TCCR0B = (TCCR0B & ~(_BV(CS02) | _BV(CS01))) | _BV(CS00);

  // Set initial pulse width to the first sample.
  OCR0A = pgm_read_byte(&sinewave_data[0]);

  // Set up Timer 1 to send a sample every interrupt.
  cli();   // disable interrupts

  // Set CTC mode (Section 15.9.2 Clear Timer on Compare Match)
  // WGM = 0b0100, TOP = OCR1A, Update 0CR1A Immediate (Table 15-4)
  // Have to set OCR1A *after*, otherwise it gets reset to 0!
  TCCR1B = (TCCR1B & ~_BV(WGM13)) | _BV(WGM12);
  TCCR1A = TCCR1A & ~(_BV(WGM11) | _BV(WGM10));

  // No prescaler, CS = 0b001 (Table 15-5)
  TCCR1B = (TCCR1B & ~(_BV(CS12) | _BV(CS11))) | _BV(CS10);

  // Set the compare register (OCR1A).
  // OCR1A is a 16-bit register, so we have to do this with
  // interrupts disabled to be safe.

  //   OCR1A = F_CPU / SAMPLE_RATE;    // 16e6 / 8000 = 2000

  // Enable interrupt when TCNT1 == OCR1A (p.136)
  TIMSK1 |= _BV(OCIE1A);

  sample = 0;
  sei();  // enable interrupts
}



volatile int buttonval =0; //needs to be volatile for some reason

// Interrupt Service Routine (ISR)
void buttonpress ()
{
  buttonval = digitalRead(button); //read it!
}  // end of buttonpress



void setup()
{
  
randomSeed(analogRead(A3));             //random doesn't work in setup oterwise
addr = random(1023);                  //start at a random address
eepr1 = EEPROM.read(addr);

attachInterrupt (0, buttonpress, CHANGE);    // that is, for pin D2 //interrupt group 0 that is 
startPlayback();
}

void loop() {
if (buttonval == 0){
switch (eepr1){

      break;
break;
case 32 : // character:
OCR1A =  F_CPU % map (analogRead(touch), tchlo, tchhi, 2, 8192) - (addr/2)  ;          //noise, babbly variant
sample +=  (32 + map (analogRead(mic), miclo, michi, -60, 20)) ;



      break;
case 33 : // character: !
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 12)  ;           //flangy sweeps slow
sample +=  (1-addr/256)+ map (analogRead(mic), miclo, michi, 1, -10);



      break;
case 34 : // character: "
OCR1A =  (random(map (analogRead(touch), tchlo, tchhi, 0,  45))) +map(analogRead(mic), miclo, michi, 0, 30);    //someone likes an input device



      break;
case 35 : // character: #
OCR1A = F_CPU / 1;                  //very ambienty, sing beatings or run into a pitchshifter
sample = map (analogRead(mic), miclo, michi, 0, 100);



      break;
case 36 : // character: $
OCR1A ^=  F_CPU % (map (analogRead(touch), tchlo, tchhi, 0, 420)) ;         //automatic atomation, touchy
sample =  random((map (analogRead(touch), tchlo, tchhi, 0, 255))) ;



      break;
case 37 : // character: %
temp += 1 ;
OCR1A ^=  F_CPU % temp ;                  // you are not invited
sample =  random (255) ;
temp %= random(16000);



      break;
case 38 : // character: &
OCR1A =  F_CPU & map (analogRead(mic), miclo, michi, 8192, 2);              //upside down deep depths
sample -=  (map (analogRead(touch), tchlo, tchhi, 20, -20)) ;



      break;
case 39 : // character: '
temp += 1;
   OCR1A ^=  F_CPU % temp  % (sample>>7);                  //scraping a barrel
   sample ^=  map (analogRead(touch), tchlo, tchhi, 0, 255) ;            
temp %= (map(analogRead(mic), miclo, michi, 500000, 2555));




      break;
case 40 : // character: (
temp +=map (analogRead(touch), tchlo, tchhi, -5, 5);
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 20, 2)  ;           //speewing wodn
   sample =  temp+ map(analogRead(mic), miclo, michi, -255, 255);  
temp % 255;  



      break;
case 41 : // character: )
temp += 1 ;
OCR1A ^=  F_CPU % temp ;                      //sing version of a randoer
sample =  (map (analogRead(mic), miclo, michi, 0, 255));
temp %= random(16000);



      break;
case 42 : // character: *
temp += 1;
OCR1A ^=  F_CPU % temp  % sample;                      //keeps noise coming
sample *=  7 ;            
temp %= random (5000000);



      break;
case 43 : // character: +
OCR1A =  F_CPU / map (analogRead(mic), miclo, michi, 4, 1)  ;           //someone just texted you
sample -=  map (analogRead(touch), tchlo, tchhi, 12, 1)* map (analogRead(mic), miclo, michi, 4, 1)+ OCR1A%6; 


      break;
case 44 : // character: ,
OCR1A = F_CPU / 120;                // dog fi. this country’s going to the dogs and I for one welcome our new canine overlords
sample = analogRead(mic);


      break;
case 45 : // character: -
temp += map (analogRead(touch), tchlo, tchhi, 0, 5) + map (analogRead(mic), miclo, michi, 0, 5) ;
OCR1A ^=  temp + random(10);                                                  //good indigestion
sample =  map (analogRead(mic), miclo, michi, 0, 225);
temp %= random (3000000);


      break;
case 46 : // character: .
temp +=1;
OCR1A -=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 10)  ;      //up swwpess se sweeps
   sample +=  temp+ map(analogRead(mic), miclo, michi, -25, 25);  
temp % 25; 



      break;
case 47 : // character: /

OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 10)  ;      //kicks! , i think it might be original kicks
sample +=  3; 



      break;
case 48 : // character: 0
OCR1A = F_CPU / (random(2)+2);                  //more uncontrollable noise
sample = OCR1A;



      break;
case 49 : // character: 1
temp += map (analogRead(touch), tchlo, tchhi, 0, 10) ;
OCR1A =  temp ;                                                     // random interruptions
sample =  (map (analogRead(mic), miclo, michi, 0, 255));
temp %= random (9000000);


      break;
case 50 : // character: 2
OCR1A = F_CPU >> (map (analogRead(mic), miclo, (michi*2), 8, 1));           //tone gen with pseudovol
sample += (map (analogRead(touch), tchlo, tchhi, 1,12));



      break;
case 51 : // character: 3
OCR1A = F_CPU / 16;                     //low noise
sample = random(255);



      break;
case 52 : // character: 4
OCR1A =  ~OCR1A ;//F_CPU / 12;                          //pitch and soft noise when breathed into
sample = map (analogRead(mic), miclo, michi, 0, 10);



      break;
case 53 : // character: 5
OCR1A ^= F_CPU >> (map (analogRead(mic), miclo, (michi*2), 16, -16));           //digi skippy, carrot mode
sample += (map (analogRead(touch), tchlo, tchhi, 0, 32));


      break;
case 54 : // character: 6
OCR1A = F_CPU >> (map (analogRead(mic), miclo, (michi*2), 16, 4));          //more digital squiggles
sample += (map (analogRead(touch), tchlo, tchhi, 1, 42));



      break;
case 55 : // character: 7
OCR1A = F_CPU / map (analogRead(mic), miclo, michi, -6, 12);            //disagreeable noise
sample = random(map (analogRead(touch), tchlo, tchhi, 0, 255));




      break;
case 56 : // character: 8
temp ^= random(1) ;
OCR1A ^=  F_CPU % random (255);               //automatic expressions
sample =  random(255) ^ temp;
temp = temp % random(255); 



      break;
case 57 : // character: 9
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 2)  ;            //more computer, more giga
   sample +=  1;  




      break;
case 58 : // character: :
OCR1A ^=  F_CPU % map (analogRead(touch), tchlo, tchhi, 8, 2000) - (addr/2)  ;      //distant squeals
sample ^=  (  map (analogRead(mic), miclo, michi, 0, 12)) ;


      break;
case 59 : // character: ;

      break;
case 60 : // character: <
     OCR1A =  F_CPU / map (analogRead(mic), miclo, michi, 8, 1)  ;            //noo ok its ok digy blups
   sample -=  map (analogRead(touch), tchlo, tchhi, 24, 1)* map (analogRead(mic), miclo, michi, 4, 1)+ OCR1A%32; 



      break;
case 61 : // character: =
temp += 1;
   OCR1A ^=  F_CPU % temp  % (sample>>4);                //carrot stuck in a microwave
   sample ^=  map (analogRead(mic), miclo, michi, 0, 255) ;            
temp %= random (map(analogRead(touch), tchlo, tchhi, 255, 500000));

      break;
case 62 : // character: >
OCR1A = F_CPU / 3;                      // quieter noise
sample = random(128);



      break;
case 63 : // character: ?
OCR1A = F_CPU >> (map (analogRead(mic), miclo, (michi*2), 1, 16));            //digi sounds 
sample += (map (analogRead(touch), tchlo, tchhi, 0, 16));


      break;
case 64 : // character: @
OCR1A = F_CPU % sample;                     //fluctuaty noise
sample = random(map(analogRead(mic), miclo, michi, 150, 5));



      break;
case 65 : // character: A
OCR1A = F_CPU >> (map (analogRead(mic), miclo, (michi*2), 1, 16));          //interruptable w .. variant
sample += (map (analogRead(touch), tchlo, tchhi, 1, 12));



        break;
case 66 : // character: B
temp += map (analogRead(mic), miclo, michi, 0, 5) ;
OCR1A ^=  temp + random(10);                                                 //once more with touch
sample =  (map (analogRead(touch), tchlo, tchhi, 0, 125)) - map (analogRead(mic), miclo, michi, 0, 125);
temp %= random (3000000);



      break;
case 67 : // character: C
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 128)  ;            //kicks! //original kicks, no mic!!
   sample +=  3;  



      break;
case 68 : // character: D
OCR1A ^=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 200) - (addr/2)  ;      //sort of sequences...?
sample =  (  map (analogRead(mic), miclo, michi, 0, 255)) ;



      break;
case 69 : // character: E
temp += 1 ;
OCR1A ^=  F_CPU % (temp +(map (analogRead(touch), tchlo, tchhi, 0, 420)) );        //to think that you could have bought a buchla for all this money
sample +=  (map (analogRead(mic), miclo, michi, 0, 16));
temp %= random(16000);


      break;
case 70 : // character: F
temp += 1;
OCR1A ^=  F_CPU % temp  % (sample>>4);                 //dork carrot
sample ^=  map (analogRead(touch), tchlo, tchhi, 0, 255) ;            
temp %= (map(analogRead(mic), miclo, michi, 500000, 2555));



      break;
case 71 : // character: G
temp +=map (analogRead(mic), miclo, michi, -5, 5);
OCR1A =  F_CPU ^ map (analogRead(touch), tchlo, tchhi, 205, 2)  ;      //songable
sample =  temp ^ map(analogRead(mic), miclo, michi, -255, 255);  
temp % 255; 


      break;
case 72 : // character: H
OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 0, 512)  ;          //more aggro drums with high beeps
sample +=  1+random(OCR1A%90)+ map (analogRead(touch), tchlo, tchhi,  -8, 8);     



      break;
case 73 : // character: I
temp +=map (analogRead(mic), miclo, michi, -5, 5);
OCR1A ^=  F_CPU % map (analogRead(touch), tchlo, tchhi, 20, 2)  ;      //carrot sweep down
   sample =  temp+ map(analogRead(mic), miclo, michi, -255, 255);  
temp % 255;



      break;
case 74 : // character: J
temp +=map (analogRead(mic), miclo, michi, -5, 5);
OCR1A =  F_CPU ^ map (analogRead(touch), tchlo, tchhi, 20, 2)  ;      //ups and downs
sample =  temp+ map(analogRead(mic), miclo, michi, -255, 255);  
temp % 255; 



      break;
case 75 : // character: K
temp +=map (analogRead(mic), miclo, michi, -5, 5);
OCR1A =  F_CPU % sample ^ map (analogRead(touch), tchlo, tchhi, 205, (map (analogRead(mic), miclo, michi, -5, -95)));  //cadge of honour
sample =  temp & map(analogRead(mic), miclo, michi, 0, 255);  
temp % random(255255); 



      break;
case 76 : // character: L
temp += 3;
OCR1A ^=  F_CPU % temp  % (sample>>8);                   //song a sing
sample =  map (analogRead(mic), miclo, michi, 0, 255) ;            
temp %= random (4000000);



      break;
case 77 : // character: M
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 2)  ;            //some kind of weird computer stuff
sample +=  map (analogRead(mic), miclo, michi, -8, 0);  



      break;
case 78 : // character: N
OCR1A = F_CPU >> (map (analogRead(mic), miclo, (michi*2), 16, 1));          //interruptable squiggles 
sample += (map (analogRead(touch), tchlo, tchhi, -8, 12));


      break;
case 79 : // character: O
OCR1A =  F_CPU & map (analogRead(mic), miclo, michi, 2, 8192);              //deep depths
sample -=  (map (analogRead(touch), tchlo, tchhi, 0, 20)) ;



      break;
case 80 : // character: P
OCR1A = F_CPU / 30;                 //micy - iny - sing or feedback to this
sample = analogRead(mic);




      break;
case 81 : // character: Q
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 2)  ;           //more VERY strange computer
   sample +=  3;  




      break;
case 82 : // character: R
     OCR1A = F_CPU / (random(45)+30);         //someone likes clicks



      break;
case 83 : // character: S
    OCR1A = F_CPU & analogRead(mic)*10;                             //sing into this
sample -= map (analogRead(touch), tchlo, tchhi, -8, 0);




      break;
case 84 : // character: T
OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 0, 2)  ;            //some kind of weird computer microphone!!
   sample +=  map (analogRead(touch), tchlo, tchhi, -8, 0);  




      break;
case 85 : // character: U
OCR1A ^=  F_CPU % (map (analogRead(mic), miclo, michi, 0, 200)) ;      //you don’t OWN ME MAN
sample =  random(255) ;



      break;
case 86 : // character: V
temp += 1;
   OCR1A ^=  F_CPU % temp  % (sample>>4);                //stuck in a microwave
   sample +=  map (analogRead(mic), miclo, michi, 0, 255) ;            
temp %= random (map(analogRead(touch), tchlo, tchhi, 255, 500000));


      break;
case 87 : // character: W
OCR1A =  ~OCR1A ;//F_CPU / 12;                         //more ambienty sing n breathe
sample = map (analogRead(mic), miclo, michi, 0, 3);


      break;
case 88 : // character: X
temp += 1;
   OCR1A ^=  F_CPU % temp  % (sample>>4);                  //touch ambient
   sample =  random (map(analogRead(touch), tchlo, tchhi, 255, -90)) ;             
temp %= random (5000000);


      break;
case 89 : // character: Y
     OCR1A ^= F_CPU / map (analogRead(mic), miclo, michi, -8, 8);    //i stepped on your banjo
    sample &= map (analogRead(touch), tchlo, tchhi, 0, 8); 


      break;
case 90 : // character: Z
 OCR1A = F_CPU / map(analogRead(mic), miclo, michi, 0, 100) ;   //secret boops
sample +=   map(analogRead(touch), tchlo, tchhi, 0, 2);


      break;
case 91 : // character: [
  OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 50, 1)  ;           //hi perc
   sample &=  map (analogRead(touch), tchlo, tchhi, 50, 0); 




OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 0, 2)  ;             //Pierre Boole’s’s computer mic
   sample +=   ((OCR1A/1000) % addr);  



      break;
case 92 : // character: \
 OCR1A = F_CPU / map(analogRead(mic), miclo, michi, 0, 100) ;   //sing n touch, digi nois
sample +=   map(analogRead(touch), tchlo, tchhi, 0, 100);


      break;
case 93 : // character: ]
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 2)  ;            //you are the singing troglodyte
   sample ^=  map (analogRead(mic), miclo, michi, 0, 3);  


      break;
case 94 : // character: ^
OCR1A = F_CPU >> (map (analogRead(mic), miclo, (michi*2), 16, 1));          //digi skippy 
sample += (map (analogRead(touch), tchlo, tchhi, 0, 16));



      break;
case 95 : // character: _
     OCR1A ^= (sample*(map (analogRead(mic), miclo, michi, 0, 8)));   // this actually does sound broken    
    sample &= map (analogRead(touch), tchlo, tchhi, 1, 8);    //
   sample +=1;                //this one has three lines


      break;
case 96 : // character: `
temp +=map (analogRead(touch), tchlo, tchhi, -2, 2);
OCR1A -=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 20)  ;      //more sweeps
   sample =  temp+ map(analogRead(mic), miclo, michi, -255, 255);  
temp % 255; 


      break;
case 97 : // character: a
 OCR1A = F_CPU / 60;                //micy - iny - sing or feedback to this lo fi wonder
sample = analogRead(mic);



      break;
case 98 : // character: b
OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 0, 2)  ;                //John Cage’s computer mic
   sample =  random(255);  



      break;
case 99 : // character: c
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 2)  ;            //John Cage’s computer
   sample =  random(255);  




      break;
case 100 : // character: d
OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 0, 12)  ;                 //dynakick2
   sample +=  map (analogRead(touch), tchlo, tchhi, 0, 12)  ;



      break;
case 101 : // character: e
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 2)  ;             //Pierre Boole’s’s computer
   sample +=   ((OCR1A/1000) % addr);  



      break;
case 102 : // character: f
    OCR1A ^= sample; // / map (analogRead(mic), miclo, michi, -8, 8);  // i don’t know, angry ant mob or something. GOOD
    sample &= map (analogRead(touch), tchlo, tchhi, 0, 8);    //
    sample &= map (analogRead(mic), miclo, michi, 0, 8);    //this one has three lines


      break;
case 103 : // character: g
    OCR1A = F_CPU % analogRead(mic);          //mic preamp with snails (sing onto this) (yes onto)



      break;
case 104 : // character: h
temp += 3;
   OCR1A ^=  F_CPU % temp  % (sample>>8);                //do not forget to touch the microphone
   sample =  map (analogRead(mic), miclo, michi, 0, 255) ;            
temp %= random (900000);


      break;
case 105 : // character: i
OCR1A ^=  F_CPU % ((map (analogRead(mic), miclo, michi, 0, 200) - (addr/2) )+ (map (analogRead(touch), tchlo, tchhi, 0, -255)))  ;      //sort of sequy 2
sample +=  2 ;


      break;
case 106 : // character: j
     OCR1A ^= (sample*(map (analogRead(touch), tchlo, tchhi, 0, 8)));   // FUCKING YES
    sample &= map (analogRead(mic), miclo, michi, 1, 8);    //
    sample +=1;               //this one has three lines
    


      break;
case 107 : // character: k
     OCR1A -=  F_CPU % map (analogRead(mic), miclo, michi, 0, 128)  ;         //nega-yep “kix”
   sample +=  1+random(OCR1A%20)+ map (analogRead(touch), tchlo, tchhi,  -8, 8);     



      break;
case 108 : // character: l
OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 0, 22)  ;           //underground boopcomputer
   sample +=  random(3);  



      break;
case 109 : // character: m
     OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 0, 2)  ;            //more computer, bit of rand()m mic
   sample +=  random(3);  




      break;
case 110 : // character: n
     OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 0, 128)  ;         //yep kicks with arps
   sample +=  1+random(OCR1A%20)+ map (analogRead(touch), tchlo, tchhi,  -8, 8);     



      break;
case 111 : // character: o
temp ^= random(1) ;
OCR1A ^=  F_CPU % map (analogRead(mic), miclo, michi, -80, 155);      //influencer noise
sample =  random(255) + map (analogRead(touch), tchlo, tchhi, 8, 239);
temp = temp % random(2555); 



      break;
case 112 : // character: p
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 10)  ;      //kicks! , i think it might be original— but deeper
   sample +=  1; 


      break;
case 113 : // character: q
OCR1A ^= F_CPU >> (map (analogRead(mic), miclo, (michi*2), 16, 1));          //digi babbly trills ^ WITH MAGIC CARROT SIGN ^
sample += (map (analogRead(touch), tchlo, tchhi, 0, 32));


      break;
case 114 : // character: r
OCR1A =  ~OCR1A + sample;//F_CPU / 12;                        //soft, sing into, does its own thing
sample = map (analogRead(mic), miclo, michi, 0, 255);



      break;
case 115 : // character: s
 OCR1A =  F_CPU % map (analogRead(touch), tchlo, tchhi, 8, 2000) - (addr/2)  ;        //noise, babbly /variant 2
sample +=  (64 + map (analogRead(mic), miclo, michi, -63, 120)) ;



      break;
case 116 : // character: t
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 2)  ;            //singing troglodytes
sample ^=  3; 


      break;
case 117 : // character: u
OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 0, 12)  ;         //wonderful boop drums
sample +=  1+random(OCR1A%8)+ map (analogRead(touch), tchlo, tchhi,  -8, 8);     




      break;
case 118 : // character: v
OCR1A = F_CPU / 1;                      //noise
sample = random(255);



      break;
case 119 : // character: w
temp += 1;
   OCR1A ^=  F_CPU % temp  % (sample>>4);                   //dork ambient
   sample =  map (analogRead(mic), miclo, michi, 0, 255) ;            
temp %= random (5000000);




      break;
case 120 : // character: x
temp += 1 ;
OCR1A ^=  F_CPU % (temp +(map (analogRead(touch), tchlo, tchhi, 0, 420)) );        //singable, then it goes and ruins everything
sample =  (map (analogRead(mic), miclo, michi, 0, 127) + random(127)) ;
temp %= random(20000);



      break;
case 121 : // character: y
OCR1A = F_CPU >> (map (analogRead(mic), miclo, (michi*2), 1, 16));          //other digi noise
sample = random(map (analogRead(touch), tchlo, tchhi, 0, 16));



      break;
case 122 : // character: z
    OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 0, 128)  ;          //nousy pauken
   sample +=  1+random(OCR1A%90)+ map (analogRead(touch), tchlo, tchhi,  -18, 28);     


      break;
case 123 : // character: {
OCR1A = F_CPU >> (map (analogRead(mic), miclo, (michi*2), 16, 1));          //digi babbly trills
sample += (map (analogRead(touch), tchlo, tchhi, 0, 32));



      break;
case 124 : // character: |
(temp +=1 )% sample;
OCR1A = F_CPU  / addr * map (analogRead(touch), tchlo, tchhi, 1, 9);         // slow upsweeps
sample =  random(map (analogRead(mic), miclo, michi, 0, 128)) ;


      break;
case 125 : // character: }
temp += 1 ;
OCR1A ^=  F_CPU % (temp +(map (analogRead(touch), tchlo, tchhi, 300, 0)) );         //soft and unpredictable (???)
sample +=  (map (analogRead(mic), miclo, michi, -2, 8));
temp %= random(16000);



      break;
case 126 : // character: ~
OCR1A = F_CPU >> (map (analogRead(mic), miclo, (michi*2), 1, 16));              //digi skippy harsh
sample = (map (analogRead(touch), tchlo, tchhi, 0, 16));


      break;
case 127 : // character: 
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 0, 2)  ;           //more computer, bit of rand()m
   sample +=  random(3);  










//here be extended ASCII
//almost all of these (134 and upwards) are not controllable. They make different sounds depending


      break;
case 128 : // character:
OCR1A ^=  map (analogRead(mic), miclo, michi, -80, 155);              //gnarly there ...
sample ^= map (analogRead(touch), tchlo, tchhi, -80, 239);


      break;
case 129 : // character: 
OCR1A = F_CPU / map (analogRead(mic), miclo, michi, 0, 20);             //digi noise with volume
sample = random(map (analogRead(touch), tchlo, tchhi, 0, 255));





      break;
case 130 : // character: 
OCR1A +=  F_CPU % map (analogRead(mic), miclo, michi, 1, 2048) - random (64)  ;        //synthy sawy
   sample +=  (map (analogRead(touch), tchlo, tchhi, 64, -16)+ random(3))/3;  



      break;
case 131 : // character: 
OCR1A +=  F_CPU % map (analogRead(touch), tchlo, tchhi, 8, 2000) - (addr/2)  ;        //rabid kicks
sample +=  (  map (analogRead(mic), miclo, michi, -63, 120)) ;



      break;
case 132 : // character: 
OCR1A ^=  map (analogRead(touch), tchlo, tchhi, -80, 155);        //kinda harsh
sample ^= map (analogRead(mic), miclo, michi, -80, 239);


      break;
case 133 : // character: 
OCR1A =  F_CPU % map (analogRead(mic), miclo, michi, 2, 8192) - (addr/4)  ;         //noise, babbly
sample +=  (64 + map (analogRead(touch), tchlo, tchhi, -60, 200)) ;




      break;
case 134 : // character: 
   OCR1A =  F_CPU /  1              ;         //low and high oscillations
   sample ^= (addr)            ;

      break;
case 135 : // character: 
   OCR1A =  F_CPU /  1              ;         //low and high oscillations
   sample ^= (addr)            ;

      break;
case 136 : // character: 
   OCR1A =  F_CPU /  1              ;         //low and high oscillations
   sample ^= (addr)            ;

      break;
case 137 : // character:
   OCR1A =  F_CPU /  1              ;         //low and high oscillations
   sample ^= (addr)            ;

      break;
case 138 : // character:
   OCR1A =  F_CPU /  1              ;         //low and high oscillations
   sample ^= (addr)            ;

      break;
case 139 : // character: 
   OCR1A =  F_CPU /  1              ;         //low and high oscillations
   sample ^= (addr)            ;

      break;
case 140 : // character: 
   OCR1A =  F_CPU /  1              ;         //low and high oscillations
   sample ^= (addr)            ;

      break;
case 141 : // character:
   OCR1A =  F_CPU /  1              ;         //low and high oscillations
   sample ^= (addr)            ;

      break;
case 142 : // character: 
   OCR1A =  F_CPU /  1              ;         //low and high oscillations
   sample ^= (addr)            ;

      break;
case 143 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                    //low interruotions
   sample ^= (addr) ;            
temp %= random (1111);
      break;
case 144 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                    //low interruotions
   sample ^= (addr) ;            
temp %= random (1111);
      break;
case 145 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                    //low interruotions
   sample ^= (addr) ;            
temp %= random (1111);
      break;
case 146 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                    //low interruotions
   sample ^= (addr) ;            
temp %= random (1111);
      break;
case 147 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                    //low interruotions
   sample ^= (addr) ;            
temp %= random (1111);
      break;
case 148 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                    //low interruotions
   sample ^= (addr) ;            
temp %= random (1111);
      break;
case 149 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                    //low interruotions
   sample ^= (addr) ;            
temp %= random (1111);
      break;
case 150 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                    //low interruotions
   sample ^= (addr) ;            
temp %= random (1111);
      break;
case 151 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                          //different drones
   sample ^= (addr) ;           
temp %= random (addr);
      break;
case 152 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                          //different drones
   sample ^= (addr) ;           
temp %= random (addr);
      break;
case 153 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                          //different drones
   sample ^= (addr) ;           
temp %= random (addr);
      break;
case 154 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                          //different drones
   sample ^= (addr) ;           
temp %= random (addr);
      break;
case 155 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                          //different drones
   sample ^= (addr) ;           
temp %= random (addr);
      break;
case 156 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                          //different drones
   sample ^= (addr) ;           
temp %= random (addr);
      break;
case 157 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                          //different drones
   sample ^= (addr) ;           
temp %= random (addr);
      break;
case 158 : // character: 
temp += 122;
   OCR1A =  F_CPU /  1+ temp;                          //different drones
   sample ^= (addr) ;           
temp %= random (addr);
      break;
case 159 : // character: 
temp += 12;
   OCR1A =  F_CPU / 3 + temp;                        //more different drones
   sample ^= (addr) ;           
temp %= random (addr/3);
      break;
case 160 : // character:
temp += 12;
   OCR1A =  F_CPU / 3 + temp;                        //more different drones
   sample ^= (addr) ;           
temp %= random (addr/3);
      break;
case 161 : // character: !
temp += 12;
   OCR1A =  F_CPU / 3 + temp;                        //more different drones
   sample ^= (addr) ;           
temp %= random (addr/3);
      break;
case 162 : // character: "
temp += 12;
   OCR1A =  F_CPU / 3 + temp;                        //more different drones
   sample ^= (addr) ;           
temp %= random (addr/3);
      break;
case 163 : // character: #
temp += 12;
   OCR1A =  F_CPU / 3 + temp;                        //more different drones
   sample ^= (addr) ;           
temp %= random (addr/3);
      break;
case 164 : // character: $
temp += 12;
   OCR1A =  F_CPU / 3 + temp;                        //more different drones
   sample ^= (addr) ;           
temp %= random (addr/3);
      break;
case 165 : // character: %
temp += 12;
   OCR1A =  F_CPU / 3 + temp;                        //more different drones
   sample ^= (addr) ;           
temp %= random (addr/3);
      break;
case 166 : // character: &
temp += 12;
   OCR1A =  F_CPU / 3 + temp;                        //more different drones
   sample ^= (addr) ;           
temp %= random (addr/3);
      break;
case 167 : // character: '
temp += 122;
   OCR1A =  F_CPU /  2+ temp;                           //different different drones
   sample ^= (addr) ;           
temp %= random (addr);

      break;
case 168 : // character: (
temp += 122;
   OCR1A =  F_CPU /  2+ temp;                           //different different drones
   sample ^= (addr) ;           
temp %= random (addr);

      break;
case 169 : // character: )
temp += 122;
   OCR1A =  F_CPU /  2+ temp;                           //different different drones
   sample ^= (addr) ;           
temp %= random (addr);

      break;
case 170 : // character: *
temp += 122;
   OCR1A =  F_CPU /  2+ temp;                           //different different drones
   sample ^= (addr) ;           
temp %= random (addr);

      break;
case 171 : // character: +
temp += 122;
   OCR1A =  F_CPU /  2+ temp;                           //different different drones
   sample ^= (addr) ;           
temp %= random (addr);

      break;
case 172 : // character: ,
temp += 122;
   OCR1A =  F_CPU /  2+ temp;                           //different different drones
   sample ^= (addr) ;           
temp %= random (addr);

      break;
case 173 : // character: -
temp += 122;
   OCR1A =  F_CPU /  2+ temp;                           //different different drones
   sample ^= (addr) ;           
temp %= random (addr);

      break;
case 174 : // character: .
temp += 122;
   OCR1A =  F_CPU /  2+ temp;                           //different different drones
   sample ^= (addr) ;           
temp %= random (addr);

      break;
case 175 : // character: /
   OCR1A =  F_CPU /  2 ;                                   //fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 176 : // character: 0
   OCR1A =  F_CPU /  2 ;                                   //fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 177 : // character: 1
   OCR1A =  F_CPU /  2 ;                                   //fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 178 : // character: 2
   OCR1A =  F_CPU /  2 ;                                   //fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 179 : // character: 3
   OCR1A =  F_CPU /  2 ;                                   //fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 180 : // character: 4
   OCR1A =  F_CPU /  2 ;                                   //fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 181 : // character: 5
   OCR1A =  F_CPU /  2 ;                                   //fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 182 : // character: 6
   OCR1A =  F_CPU /  2 ;                                   //fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 183 : // character: 7
 OCR1A =  F_CPU /  3 ;                                   //boiled fish and clicks
   sample ^= (addr|OCR1A) ;
      break;
case 184 : // character: 8
 OCR1A =  F_CPU /  3 ;                                   //boiled fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 185 : // character: 9
 OCR1A =  F_CPU /  3 ;                                   //boiled fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 186 : // character: :
 OCR1A =  F_CPU /  3 ;                                   //boiled fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 187 : // character: ;
 OCR1A =  F_CPU /  3 ;                                   //boiled fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 188 : // character: <
 OCR1A =  F_CPU /  3 ;                                   //boiled fish and clicks
   sample ^= (addr|OCR1A) ;

      break;
case 189 : // character: =
   OCR1A =  F_CPU /  1 ;                                   //deep sea fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 190 : // character: >
   OCR1A =  F_CPU /  1 ;                                   //deep sea fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 191 : // character: ?
   OCR1A =  F_CPU /  1 ;                                   //deep sea fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 192 : // character:
   OCR1A =  F_CPU /  1 ;                                   //deep sea fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 193 : // character: 
   OCR1A =  F_CPU /  1 ;                                   //deep sea fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 194 : // character: 
   OCR1A =  F_CPU /  1 ;                                   //deep sea fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 195 : // character: 
   OCR1A =  F_CPU /  1 ;                                   //deep sea fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 196 : // character: 
   OCR1A =  F_CPU /  sample ;                                   //recursive fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 197 : // character: 
   OCR1A =  F_CPU /  sample ;                                   //recursive fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 198 : // character: 
   OCR1A =  F_CPU /  sample ;                                   //recursive fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 199 : // character: 
   OCR1A =  F_CPU /  sample ;                                   //recursive fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 200 : // character: 
   OCR1A =  F_CPU /  sample ;                                   //recursive fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 201 : // character:
   OCR1A =  F_CPU /  sample ;                                   //recursive fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 202 : // character:
   OCR1A =  F_CPU /  sample ;                                   //recursive fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 203 : // character:    OCR1A =  F_CPU /  sample ;                                   //recursive fish and clicks
   sample ^= (addr|OCR1A) ;


      break;
case 204 : // character: 
temp += 1;
     OCR1A =  F_CPU /  2 ;                                   //tough and hard digital fish
   sample ^= (temp&addr) ;
temp %= random (300000);


      break;
case 205 : // character:
temp += 1;
     OCR1A =  F_CPU /  2 ;                                   //tough and hard digital fish
   sample ^= (temp&addr) ;
temp %= random (300000);


      break;
case 206 : // character: 
temp += 1;
     OCR1A =  F_CPU /  2 ;                                   //tough and hard digital fish
   sample ^= (temp&addr) ;
temp %= random (300000);


      break;
case 207 : // character: 
temp += 1;
     OCR1A =  F_CPU /  2 ;                                   //tough and hard digital fish
   sample ^= (temp&addr) ;
temp %= random (300000);


      break;
case 208 : // character: 
temp += 1;
     OCR1A =  F_CPU /  2 ;                                   //tough and hard digital fish
   sample ^= (temp&addr) ;
temp %= random (300000);


      break;
case 209 : // character: 
temp += 1;
     OCR1A =  F_CPU /  2 ;                                   //tough and hard digital fish
   sample ^= (temp&addr) ;
temp %= random (300000);


      break;
case 210 : // character: 
temp += 1;
     OCR1A =  F_CPU /  2 ;                                   //tough and hard digital fish
   sample ^= (temp&addr) ;
temp %= random (300000);


      break;
case 211 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //very deep fried fish
   sample ^= (temp&(100+addr)) ;
temp %= 100000;


      break;
case 212 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //very deep fried fish
   sample ^= (temp&(100+addr)) ;
temp %= 100000;


      break;
case 213 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //very deep fried fish
   sample ^= (temp&(100+addr)) ;
temp %= 100000;


      break;
case 214 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //very deep fried fish
   sample ^= (temp&(100+addr)) ;
temp %= 100000;


      break;
case 215 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //very deep fried fish
   sample ^= (temp&(100+addr)) ;
temp %= 100000;


      break;
case 216 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //very deep fried fish
   sample ^= (temp&(100+addr)) ;
temp %= 100000;


      break;
case 217 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //very deep fried fish
   sample ^= (temp&(100+addr)) ;
temp %= 100000;


      break;
case 218 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //very deep fried fish
   sample ^= (temp&(100+addr)) ;
temp %= 100000;


      break;
case 219 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //baked
   sample ^= (temp&addr) ;
temp %= 100000;


      break;
case 220 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //baked
   sample ^= (temp&addr) ;
temp %= 100000;


      break;
case 221 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //baked
   sample ^= (temp&addr) ;
temp %= 100000;


      break;
case 222 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //baked
   sample ^= (temp&addr) ;
temp %= 100000;


      break;
case 223 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //baked
   sample ^= (temp&addr) ;
temp %= 100000;


      break;
case 224 : // character:
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //baked
   sample ^= (temp&addr) ;
temp %= 100000;


      break;
case 225 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //baked
   sample ^= (temp&addr) ;
temp %= 100000;


      break;
case 226 : // character: 
temp += 3;
     OCR1A =  F_CPU /  2 ;                                   //baked
   sample ^= (temp&addr) ;
temp %= 100000;


      break;
case 227 : // character: 
temp += 7;
     OCR1A =  F_CPU /  (temp >> 10);                                   //fish and squids
   sample ^= (temp&(addr)) ;
temp %= 110101;


      break;
case 228 : // character: 
temp += 7;
     OCR1A =  F_CPU /  (temp >> 10);                                   //fish and squids
   sample ^= (temp&(addr)) ;
temp %= 110101;


      break;
case 229 : // character: 
temp += 7;
     OCR1A =  F_CPU /  (temp >> 10);                                   //fish and squids
   sample ^= (temp&(addr)) ;
temp %= 110101;


      break;
case 230 : // character: 
temp += 7;
     OCR1A =  F_CPU /  (temp >> 10);                                   //fish and squids
   sample ^= (temp&(addr)) ;
temp %= 110101;


      break;
case 231 : // character: 
temp += 7;
     OCR1A =  F_CPU /  (temp >> 10);                                   //fish and squids
   sample ^= (temp&(addr)) ;
temp %= 110101;


      break;
case 232 : // character: 
temp += 7;
     OCR1A =  F_CPU /  (temp >> 10);                                   //fish and squids
   sample ^= (temp&(addr)) ;
temp %= 110101;


      break;
case 233 : // character:
temp += 7;
     OCR1A =  F_CPU /  (temp >> 10);                                   //fish and squids
   sample ^= (temp&(addr)) ;
temp %= 110101;


      break;
case 234 : // character:
temp += 7;
     OCR1A =  F_CPU /  (temp >> 10);                                   //fish and squids
   sample ^= (temp&(addr)) ;
temp %= 110101;


      break;
case 235 : // character: temp += 7;
     OCR1A =  F_CPU /  (temp >> 10);                                   //fish and squids
   sample ^= (temp&(addr)) ;
temp %= 110101;


      break;
case 236 : // character: 
temp += 1;
     OCR1A =  F_CPU /  (temp >> 7);                                   //super mario fishland
   sample ^= ((addr)) ;
temp %= 110101;


      break;
case 237 : // character:
temp += 1;
     OCR1A =  F_CPU /  (temp >> 7);                                   //super mario fishland
   sample ^= ((addr)) ;
temp %= 110101;


      break;
case 238 : // character: 
temp += 1;
     OCR1A =  F_CPU /  (temp >> 7);                                   //super mario fishland
   sample ^= ((addr)) ;
temp %= 110101;


      break;
case 239 : // character: 
temp += 1;
     OCR1A =  F_CPU /  (temp >> 7);                                   //super mario fishland
   sample ^= ((addr)) ;
temp %= 110101;


      break;
case 240 : // character:
temp += 1;
     OCR1A =  F_CPU /  (temp >> 7);                                   //super mario fishland
   sample ^= ((addr)) ;
temp %= 110101;


      break;
case 241 : // character: 
temp += 1;
     OCR1A =  F_CPU /  (temp >> 7);                                   //super mario fishland
   sample ^= ((addr)) ;
temp %= 110101;


      break;
case 242 : // character: 
temp += 1;
     OCR1A =  F_CPU /  (temp >> 7);                                   //super mario fishland
   sample ^= ((addr)) ;
temp %= 110101;


      break;
case 243 : // character: 
temp += 1;
     OCR1A =  F_CPU /  (temp >> 3);                                   //not fish anymore
   sample ^= ((temp/(1000+addr))) ;
temp %= random(2101010);


      break;
case 244 : // character: 
temp += 1;
     OCR1A =  F_CPU /  (temp >> 3);                                   //not fish anymore
   sample ^= ((temp/(1000+addr))) ;
temp %= random(2101010);


      break;
case 245 : // character: 
temp += 1;
     OCR1A =  F_CPU /  (temp >> 3);                                   //not fish anymore
   sample ^= ((temp/(1000+addr))) ;
temp %= random(2101010);


      break;
case 246 : // character: 
temp += 1;
     OCR1A =  F_CPU /  (temp >> 3);                                   //not fish anymore
   sample ^= ((temp/(1000+addr))) ;
temp %= random(2101010);


      break;
case 247 : // character: 
temp += 1;
     OCR1A =  F_CPU /  (temp >> 3);                                   //not fish anymore
   sample ^= ((temp/(1000+addr))) ;
temp %= random(2101010);


      break;
case 248 : // character:
temp += 1;
     OCR1A =  F_CPU /  (temp >> 3);                                   //not fish anymore
   sample ^= ((temp/(1000+addr))) ;
temp %= random(2101010);


      break;
case 249 : // character: 
(temp ^= 1 ) + 1;
     OCR1A =  F_CPU /  (temp^=addr);                                   //fish in bottle
   sample ^= (temp) ;
temp %= 1010;

      break;
case 250 : // character: 
(temp ^= 1 ) + 1;
     OCR1A =  F_CPU /  (temp^=addr);                                   //fish in bottle
   sample ^= (temp) ;
temp %= 1010;

      break;
case 251 : // character: 
(temp ^= 1 ) + 1;
     OCR1A =  F_CPU /  (temp^=addr);                                   //fish in bottle
   sample ^= (temp) ;
temp %= 1010;

      break;
case 252 : // character:
(temp ^= 1 ) + 1;
     OCR1A =  F_CPU /  (temp^=addr);                                   //fish in bottle
   sample ^= (temp) ;
temp %= 1010;

      break;
case 253 : // character: 
(temp ^= 1 ) + 1;
     OCR1A =  F_CPU /  (temp^=addr);                                   //fish in bottle
   sample ^= (temp) ;
temp %= 1010;

      break;
case 254 : // character:
(temp ^= 1 ) + 1;
     OCR1A =  F_CPU /  (temp^=addr);                                   //fish in bottle
   sample ^= (temp) ;
temp %= 1010;

      break;
case 255 : // character:
(temp ^= 1 ) + 1;
     OCR1A =  F_CPU /  (temp^=addr);                                   //fish in bottle
   sample ^= (temp) ;
temp %= 1010;

}
}

if (buttonval ==1)  {          //this is done when the button is pressed:

eepr1 = EEPROM.read(addr);

addr +=1 ;

                          //only increment address once, not once per loop ... :-
if (addr >= 1023)  {
  addr = 1;
}                                       //constrain the address to 0-1023

buttonval = 0;     // jump straight back to playing sounds
}

}
 
      //  NOTE
      //  Max SAMPLE_RATE (1023 +25) * 10 = 10480
      //  Max freq 16000000 / 10480 = 1526.7 Hz
      //  +25 prevents 0 value error with sensorValue





