Programming ATmega328

Upload bootloader if needed
https://www.arduino.cc/en/Tutorial/ArduinoToBreadboard
Requires MaxMSP or MaxMSP Runtime environment to run manifesto-to-eeprom serial.maxpat

In short:
Flash the Atmega 328p with the serial_receive_comm_eeprom_improved_further.ino program
Boot (according to instructions below) and send data to EEPROM using the manifesto-to-eeprom serial.maxpat in MaxMSP.
If you want, flash the Atmega328p with the reading_eeprom_2_check.ino program to check that the EEPROM has indeed been filled (use Serial monitor, I think)
Upload the _57mm_v2.ino code to your Atmega 328p
You now have a working 57mm chip.

//////////////////////////////////////////////////////

Update 13/4/18 
serial_receive_comm_eeprom_improved_further.ino

This one lights the LED (P13) for one second on boot. So now the workflow is like this

(All chips, one at a time)
Bootloader
install Serial-to-eeprom program (led indicates that these two steps worked)

Close arduino
Open MaxMSP, serial-write patch
put chip in breadboard (I used ZIF socket in stripboard)
open communication. When it seems to work, reset uno (= resets address accumulation in 328)

flash into chip, LED light on addr => 1023
take chip out
next chip

After all are done, just put the 57mm program into all of them.

//////////////////////////////////////////////////////

Old

Then it goes like this:
• Load serial_receive_comm_eeprom_improved.ino onto chip(s)
• Open Max patch
• Close Arduino IDE (helps with communication)
• Paste text, push LOAD
• Check which serial port to connect to with print (red)
• Change letter in serial b 9600 if necessary
• Press COMM to turn on serial communication. Watch the Rx LED on the Arduino. Resetting the Arduino might help.
• If it blinks, press SEND to transmit the text. You can also cheat with random numbers. Or draw in the itable, but I don’t recommend it because you get a lot of consecutive characters (103 103 103 103 104 104 105 etc). So button appears to do nothing
• When it is done, load reading_eerprom_2_check.ino and watch the serial monitor. There are two columns. In the second column, a fail is 255 255 255 255 255. Success is whatever you have in your text (variable numbers in second column). 
• If it worked, you can upload the main 57mm synth program. Flash stays regardless what program you have onwards. NOTE! Use Arduino 1.8.1 or later (code big)
