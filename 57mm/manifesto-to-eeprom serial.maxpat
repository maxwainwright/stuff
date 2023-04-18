{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 0,
			"architecture" : "x86",
			"modernui" : 1
		}
,
		"rect" : [ 9.0, 110.0, 1212.0, 683.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-42",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 485.0, 661.0, 150.0, 47.0 ],
					"style" : "",
					"text" : "change this to 223 for full range (but extended ascii is all uncontrollable algos"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-28",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 769.0, 699.0, 190.0, 20.0 ],
					"style" : "",
					"text" : "how many have you put in so far?"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-26",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 275.0, 501.0, 150.0, 33.0 ],
					"style" : "",
					"text" : "if Rx doesn't blink, push close and then COMM"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 50.205975,
					"id" : "obj-24",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 271.25, 435.0, 169.0, 63.0 ],
					"style" : "",
					"text" : "COMM"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-23",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 435.0, 533.0, 50.0, 22.0 ],
					"style" : "",
					"text" : "del 100"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-21",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 485.0, 532.0, 32.5, 22.0 ],
					"style" : "",
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 439.25, 435.0, 63.0, 63.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 21.264521,
					"id" : "obj-22",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 769.0, 600.0, 248.0, 54.0 ],
					"style" : "",
					"text" : "for cheating with random numbers"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-17",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 703.0, 696.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 5,
					"numoutlets" : 4,
					"outlettype" : [ "int", "", "", "int" ],
					"patching_rect" : [ 703.0, 667.0, 73.0, 22.0 ],
					"style" : "",
					"text" : "counter"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 703.0, 604.0, 20.0, 20.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-5",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 703.0, 634.0, 58.0, 22.0 ],
					"style" : "",
					"text" : "metro 10"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 439.25, 687.0, 34.0, 22.0 ],
					"style" : "",
					"text" : "+ 32"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"patching_rect" : [ 439.25, 661.0, 45.0, 22.0 ],
					"style" : "",
					"text" : "urn 95"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-20",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 223.0, 435.0, 39.0, 22.0 ],
					"style" : "",
					"text" : "close"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 15.0, 643.0, 20.0, 20.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-7",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 91.0, 718.0, 34.0, 22.0 ],
					"style" : "",
					"text" : "print"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.714864,
					"id" : "obj-4",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 435.0, 567.0, 42.0, 24.0 ],
					"style" : "",
					"text" : "open"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-148",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 395.0, 242.0, 63.0, 20.0 ],
					"style" : "",
					"text" : "for testing"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-142",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 345.0, 242.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 50.205975,
					"id" : "obj-138",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 374.75, 92.0, 150.0, 63.0 ],
					"style" : "",
					"text" : "SEND"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-139",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 314.75, 92.0, 63.0, 63.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-135",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 314.75, 169.0, 32.5, 22.0 ],
					"style" : "",
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-117",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 15.0, 225.0, 20.0, 20.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-106",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 135.0, 210.0, 77.0, 20.0 ],
					"style" : "",
					"text" : "zero counter"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-102",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 105.5, 210.0, 32.5, 22.0 ],
					"style" : "",
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-97",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 30.0, 112.0, 277.0, 20.0 ],
					"style" : "",
					"text" : "For Noisexistance Festival Hamburg March 2018"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-96",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 30.0, 132.0, 199.0, 20.0 ],
					"style" : "",
					"text" : "Max Wainwright and John RIchards"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-95",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 30.0, 92.0, 247.0, 20.0 ],
					"style" : "",
					"text" : "Dumping a 1024 byte manifesto to EEPROM"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-93",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 92.5, 464.0, 75.0, 20.0 ],
					"style" : "",
					"text" : "current char"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-91",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 92.5, 490.0, 80.0, 20.0 ],
					"style" : "",
					"text" : "current index"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-87",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 195.0, 242.0, 95.0, 20.0 ],
					"style" : "",
					"text" : "done with dump"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-85",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 159.0, 242.0, 36.0, 22.0 ],
					"style" : "",
					"text" : "sel 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-83",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 42.5, 490.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-68",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 44.0, 196.0, 20.0, 20.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-66",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 692.0, 508.0, 94.0, 20.0 ],
					"style" : "",
					"text" : "ascii to integers"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-65",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 692.0, 540.0, 117.0, 20.0 ],
					"style" : "",
					"text" : "turn into indexed list"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-62",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 44.0, 216.0, 58.0, 22.0 ],
					"style" : "",
					"text" : "metro 10"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-56",
					"maxclass" : "newobj",
					"numinlets" : 5,
					"numoutlets" : 4,
					"outlettype" : [ "int", "", "", "int" ],
					"patching_rect" : [ 44.0, 242.0, 101.0, 22.0 ],
					"style" : "",
					"text" : "counter 0 0 1024"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-53",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 42.5, 464.0, 50.0, 22.0 ],
					"style" : "",
					"text" : "."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-49",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 73.5, 435.0, 46.0, 22.0 ],
					"style" : "",
					"text" : "itoa"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-41",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 17.5, 435.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-37",
					"maxclass" : "slider",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 17.5, 299.0, 17.0, 128.0 ],
					"size" : 256.0,
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "slider",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 44.0, 272.0, 512.0, 19.0 ],
					"size" : 1024.0,
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"hint" : "",
					"id" : "obj-33",
					"maxclass" : "itable",
					"name" : "",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 44.0, 299.0, 512.0, 128.0 ],
					"range" : 255,
					"size" : 1024,
					"style" : "",
					"table_data" : [ 0, 83, 116, 111, 112, 32, 116, 101, 108, 108, 105, 110, 103, 32, 115, 111, 109, 101, 116, 104, 105, 110, 103, 32, 116, 111, 32, 115, 111, 109, 101, 111, 110, 101, 32, 115, 111, 109, 101, 32, 111, 110, 101, 46, 32, 111, 110, 101, 32, 112, 101, 114, 115, 111, 110, 32, 32, 111, 110, 101, 32, 105, 100, 101, 97, 32, 32, 116, 111, 32, 116, 119, 111, 32, 112, 101, 111, 112, 108, 101, 32, 119, 104, 101, 110, 32, 116, 104, 101, 114, 101, 32, 105, 115, 32, 110, 111, 98, 111, 98, 121, 32, 97, 116, 32, 104, 111, 109, 101, 32, 42, 32, 120, 32, 48, 32, 120, 32, 48, 32, 120, 32, 48, 32, 42, 32, 110, 111, 98, 111, 100, 121, 32, 99, 97, 110, 226, 128, 153, 116, 32, 116, 101, 108, 108, 32, 121, 111, 117, 32, 115, 111, 109, 101, 114, 104, 105, 110, 103, 32, 105, 102, 32, 110, 111, 98, 111, 100, 121, 32, 100, 111, 101, 115, 110, 116, 32, 107, 110, 111, 119, 32, 97, 98, 111, 117, 116, 32, 119, 104, 97, 116, 32, 121, 111, 117, 32, 97, 114, 101, 32, 116, 97, 108, 107, 105, 110, 103, 32, 97, 98, 111, 117, 116, 32, 32, 110, 111, 116, 104, 105, 110, 103, 32, 111, 114, 32, 115, 111, 109, 101, 116, 104, 105, 110, 103, 32, 116, 101, 108, 108, 101, 105, 110, 103, 32, 110, 111, 116, 104, 105, 110, 103, 32, 98, 117, 116, 32, 110, 111, 116, 104, 105, 110, 103, 32, 101, 108, 115, 101, 32, 121, 111, 117, 32, 111, 114, 32, 105, 32, 115, 104, 111, 117, 108, 100, 32, 107, 110, 111, 119, 32, 97, 98, 111, 117, 116, 32, 115, 111, 109, 101, 98, 111, 100, 121, 32, 105, 110, 115, 116, 101, 97, 100, 32, 115, 111, 109, 101, 111, 110, 101, 32, 116, 101, 108, 108, 32, 121, 111, 117, 32, 97, 98, 111, 117, 116, 32, 110, 111, 98, 111, 100, 121, 32, 116, 101, 108, 108, 105, 110, 103, 32, 101, 118, 101, 114, 121, 98, 111, 100, 121, 32, 97, 98, 111, 117, 116, 32, 101, 118, 101, 114, 121, 116, 104, 105, 110, 103, 46, 32, 82, 101, 119, 105, 110, 100, 32, 105, 102, 32, 121, 111, 117, 32, 108, 105, 107, 101, 32, 116, 111, 32, 115, 97, 121, 32, 103, 111, 111, 100, 98, 121, 101, 32, 97, 110, 100, 32, 110, 111, 98, 111, 100, 121, 32, 119, 105, 108, 108, 32, 114, 101, 112, 108, 121, 46, 32, 69, 120, 101, 108, 101, 110, 116, 33, 32, 69, 120, 101, 108, 101, 110, 116, 33, 32, 89, 111, 117, 32, 97, 114, 101, 32, 110, 111, 119, 32, 114, 101, 97, 100, 121, 32, 116, 111, 32, 114, 101, 97, 99, 104, 32, 116, 104, 101, 32, 116, 111, 112, 32, 111, 102, 32, 116, 104, 101, 32, 109, 111, 117, 110, 116, 97, 105, 110, 32, 111, 114, 32, 116, 104, 101, 32, 109, 111, 112, 32, 111, 102, 32, 116, 104, 101, 32, 116, 111, 117, 110, 116, 97, 105, 110, 32, 32, 105, 32, 102, 111, 114, 103, 111, 116, 46, 32, 77, 121, 32, 109, 105, 115, 116, 97, 107, 101, 32, 111, 114, 32, 109, 105, 108, 107, 115, 104, 97, 107, 101, 46, 32, 105, 32, 102, 111, 114, 103, 111, 116, 46, 83, 116, 111, 112, 32, 116, 101, 108, 108, 105, 110, 103, 32, 115, 111, 109, 101, 116, 104, 105, 110, 103, 32, 116, 111, 32, 115, 111, 109, 101, 111, 110, 101, 32, 115, 111, 109, 101, 32, 111, 110, 101, 46, 32, 111, 110, 101, 32, 112, 101, 114, 115, 111, 110, 32, 32, 111, 110, 101, 32, 105, 100, 101, 97, 32, 32, 116, 111, 32, 116, 119, 111, 32, 112, 101, 111, 112, 108, 101, 32, 119, 104, 101, 110, 32, 116, 104, 101, 114, 101, 32, 105, 115, 32, 110, 111, 98, 111, 98, 121, 32, 97, 116, 32, 104, 111, 109, 101, 32, 42, 32, 120, 32, 48, 32, 120, 32, 48, 32, 120, 32, 48, 32, 42, 32, 110, 111, 98, 111, 100, 121, 32, 99, 97, 110, 226, 128, 153, 116, 32, 116, 101, 108, 108, 32, 121, 111, 117, 32, 115, 111, 109, 101, 114, 104, 105, 110, 103, 32, 105, 102, 32, 110, 111, 98, 111, 100, 121, 32, 100, 111, 101, 115, 110, 116, 32, 107, 110, 111, 119, 32, 97, 98, 111, 117, 116, 32, 119, 104, 97, 116, 32, 121, 111, 117, 32, 97, 114, 101, 32, 116, 97, 108, 107, 105, 110, 103, 32, 97, 98, 111, 117, 116, 32, 32, 110, 111, 116, 104, 105, 110, 103, 32, 111, 114, 32, 115, 111, 109, 101, 116, 104, 105, 110, 103, 32, 116, 101, 108, 108, 101, 105, 110, 103, 32, 110, 111, 116, 104, 105, 110, 103, 32, 98, 117, 116, 32, 110, 111, 116, 104, 105, 110, 103, 32, 101, 108, 115, 101, 32, 121, 111, 117, 32, 111, 114, 32, 105, 32, 115, 104, 111, 117, 108, 100, 32, 107, 110, 111, 119, 32, 97, 98, 111, 117, 116, 32, 115, 111, 109, 101, 98, 111, 100, 121, 32, 105, 110, 115, 116, 101, 97, 100, 32, 115, 111, 109, 101, 111, 110, 101, 32, 116, 101, 108, 108, 32, 121, 111, 117, 32, 97, 98, 111, 117, 116, 32, 110, 111, 98, 111, 100, 121, 32, 116, 101, 108, 108, 105, 110, 103, 32, 101, 118, 101, 114, 121, 98, 111, 100, 121, 32, 97, 98, 111, 117, 116, 32, 101, 118, 101, 114, 121, 116, 104, 105, 110, 103, 46, 32, 82, 101, 119, 105, 110, 100, 32, 105, 102, 32, 121, 111, 117, 32, 108, 105, 107, 101, 32, 116, 111, 32, 115, 97, 121, 32, 103, 111, 111, 100, 98, 121, 101, 32, 97, 110, 100, 32, 110, 111, 98, 111, 100, 121, 32, 119, 105, 108, 108, 32, 114, 101, 112, 108, 121, 46, 32, 69, 120, 101, 108, 101, 110, 116, 33, 46 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "list" ],
					"patching_rect" : [ 615.0, 540.0, 58.0, 22.0 ],
					"style" : "",
					"text" : "listfunnel"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-105",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 615.0, 480.0, 61.0, 22.0 ],
					"style" : "",
					"text" : "route text"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-104",
					"linecount" : 21,
					"maxclass" : "textedit",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "", "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 615.0, 169.0, 629.0, 294.0 ],
					"style" : "",
					"text" : "Stop telling something to someone some one. one person, one idea, to two people when there is noboby at home * x 0 x 0 x 0 * nobody can’t tell you somerhing if nobody doesnt know about what you are talking about, nothing or something telleing nothing but nothing else you or i should know about somebody instead someone tell you about nobody telling everybody about everything. Rewind if you like to say goodbye and nobody will reply. Exelent! Exelent! You are now ready to reach the top of the mountain or the mop of the tountain, i forgot. My mistake or milkshake. i forgot.Stop telling something to someone some one. one person, one idea, to two people when there is noboby at home * x 0 x 0 x 0 * nobody can’t tell you somerhing if nobody doesnt know about what you are talking about, nothing or something telleing nothing but nothing else you or i should know about somebody instead someone tell you about nobody telling everybody about everything. Rewind if you like to say goodbye and nobody will reply. Exelent! Exelent! You are now ready to reach the top of the mountain or the mop of the tountain, i forgot. My mistake or milkshake. i forgot.Stop telling something to someone some one. one person, one idea, to two people when there is noboby at home * x 0 x 0 x 0 * nobody can’t tell you somerhing if nobody doesnt know about what you are talking about, nothing or something telleing nothing but nothing else you or i should know about somebody instead someone tell you about nobody telling everybody about everything. Rewind if you like to say goodbye and nobody will reply. Exelent! Exelent! You are now ready to reach the top of the mountain or the mop of the tountain, i forgot. My mistake or milkshake. i forgot.Stop telling something to someone some one. one person, one idea, to two people when there is noboby at home * x 0 x 0 x 0 * nobody can’t tell you somerhing if nobody doesnt know about what you are talking about, nothing or something telleing nothing but nothing else you or i should know about somebody instead someone tell you about nobody telling everybody about everything. Rewind if you like to say goodbye and nobody will reply. Exelent! Exelent! You are now ready to reach the top of the mountain or the mop of the tountain, i forgot. My mistake or milkshake. i forgot."
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.221544, 0.06158, 0.084652, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-63",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 519.0, 169.0, 96.0, 20.0 ],
					"style" : "",
					"text" : "put text here -->",
					"textcolor" : [ 1.0, 0.999974, 0.999991, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 50.205975,
					"id" : "obj-61",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 675.0, 92.0, 147.0, 63.0 ],
					"style" : "",
					"text" : "LOAD"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-59",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 615.0, 92.0, 63.0, 63.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-57",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 692.0, 480.0, 195.0, 20.0 ],
					"style" : "",
					"text" : "to get rid of prepended \"text\" string"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-35",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "list" ],
					"patching_rect" : [ 615.0, 508.0, 46.0, 22.0 ],
					"style" : "",
					"text" : "atoi"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.419921, 0.168637, 0.202023, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-16",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 236.5, 587.0, 207.0, 20.0 ],
					"style" : "",
					"text" : "serial port check, choose the arduino",
					"textcolor" : [ 0.953838, 0.955756, 0.999849, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-13",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 62.5, 587.0, 116.0, 60.0 ],
					"style" : "",
					"text" : "serial should be on\nbut not if testing\neeprom has limited writes :-)"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.856069, 0.254951, 0.292403, 1.0 ],
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0.79,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.856069, 0.254951, 0.292403, 1.0 ],
					"bgfillcolor_color2" : [ 0.685, 0.685, 0.685, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"gradient" : 0,
					"id" : "obj-11",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 236.5, 608.0, 34.0, 22.0 ],
					"style" : "",
					"text" : "print",
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 42.5, 587.0, 20.0, 20.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "" ],
					"patching_rect" : [ 42.5, 660.0, 79.0, 22.0 ],
					"style" : "",
					"text" : "serial b 9600"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 3 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-102", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 624.5, 465.0, 624.5, 465.0 ],
					"source" : [ "obj-104", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 624.5, 501.0, 624.5, 501.0 ],
					"source" : [ "obj-105", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 246.0, 657.0, 52.0, 657.0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-117", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 624.5, 562.0, 126.0, 562.0, 126.0, 522.0, 3.0, 522.0, 3.0, 294.0, 53.5, 294.0 ],
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-68", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-135", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-135", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-139", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-142", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 52.0, 609.0, 52.0, 609.0 ],
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 232.5, 573.0, 27.0, 573.0, 27.0, 630.0, 48.0, 630.0, 48.0, 657.0, 52.0, 657.0 ],
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 494.5, 564.0, 52.0, 564.0 ],
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 53.5, 429.0, 3.0, 429.0, 3.0, 633.0, 52.0, 633.0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 53.5, 429.0, 3.0, 429.0, 3.0, 294.0, 27.0, 294.0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-49", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 53.5, 429.0, 83.0, 429.0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 53.5, 291.0, 53.5, 291.0 ],
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-83", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 53.5, 291.0, 3.0, 291.0, 3.0, 486.0, 52.0, 486.0 ],
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 27.0, 429.0, 27.0, 429.0 ],
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 444.5, 636.0, 189.0, 636.0, 189.0, 657.0, 52.0, 657.0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 83.0, 456.0, 83.0, 456.0 ],
					"source" : [ "obj-49", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 53.5, 264.0, 53.5, 264.0 ],
					"source" : [ "obj-56", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 108.166664, 264.0, 156.0, 264.0, 156.0, 237.0, 168.5, 237.0 ],
					"source" : [ "obj-56", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-104", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 624.5, 156.0, 624.5, 156.0 ],
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 53.5, 237.0, 53.5, 237.0 ],
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-62", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 53.5, 216.0, 53.5, 216.0 ],
					"source" : [ "obj-68", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-68", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 168.5, 264.0, 147.0, 264.0, 147.0, 231.0, 102.0, 231.0, 102.0, 192.0, 53.5, 192.0 ],
					"source" : [ "obj-85", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"dependency_cache" : [  ],
		"autosave" : 0
	}

}
