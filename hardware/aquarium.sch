EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:w_connectors
LIBS:maxim
LIBS:aquarium-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Aquarium"
Date "2016-02-10"
Rev "A"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Arduino_Nano_Header J1
U 1 1 56BB93B7
P 4000 2750
F 0 "J1" H 4000 3550 60  0000 C CNN
F 1 "Arduino Nano" H 4000 1950 60  0000 C CNN
F 2 "w_conn_misc:arduino_nano_header" H 4000 2750 60  0001 C CNN
F 3 "" H 4000 2750 60  0000 C CNN
	1    4000 2750
	1    0    0    -1  
$EndComp
$Comp
L DS18B20 U1
U 1 1 56BB9483
P 1800 2450
F 0 "U1" H 1650 2700 50  0000 C CNN
F 1 "DS18B20" H 1800 2200 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 1650 2700 50  0001 C CNN
F 3 "" H 1650 2700 50  0000 C CNN
	1    1800 2450
	-1   0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 56BB952E
P 3000 2300
F 0 "R1" V 3080 2300 50  0000 C CNN
F 1 "4.7k" V 3000 2300 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 2930 2300 50  0001 C CNN
F 3 "" H 3000 2300 50  0000 C CNN
	1    3000 2300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR5
U 1 1 56BB965D
P 4800 2150
F 0 "#PWR5" H 4800 1900 50  0001 C CNN
F 1 "GND" H 4800 2000 50  0000 C CNN
F 2 "" H 4800 2150 50  0000 C CNN
F 3 "" H 4800 2150 50  0000 C CNN
	1    4800 2150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 56BB9677
P 2500 2700
F 0 "#PWR2" H 2500 2450 50  0001 C CNN
F 1 "GND" H 2500 2550 50  0000 C CNN
F 2 "" H 2500 2700 50  0000 C CNN
F 3 "" H 2500 2700 50  0000 C CNN
	1    2500 2700
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR4
U 1 1 56BB9691
P 4550 2350
F 0 "#PWR4" H 4550 2200 50  0001 C CNN
F 1 "VCC" H 4550 2500 50  0000 C CNN
F 2 "" H 4550 2350 50  0000 C CNN
F 3 "" H 4550 2350 50  0000 C CNN
	1    4550 2350
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR3
U 1 1 56BB96D2
P 3000 2000
F 0 "#PWR3" H 3000 1850 50  0001 C CNN
F 1 "VCC" H 3000 2150 50  0000 C CNN
F 2 "" H 3000 2000 50  0000 C CNN
F 3 "" H 3000 2000 50  0000 C CNN
	1    3000 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 2150 4800 2150
Wire Wire Line
	2100 2550 2500 2550
Wire Wire Line
	2500 2550 2500 2700
Wire Wire Line
	2100 2450 3650 2450
Connection ~ 3000 2450
Wire Wire Line
	3000 2000 3000 2150
NoConn ~ 4350 2050
NoConn ~ 4350 2250
NoConn ~ 4350 2450
NoConn ~ 4350 2550
NoConn ~ 4350 2650
NoConn ~ 4350 2750
NoConn ~ 4350 2850
NoConn ~ 4350 2950
NoConn ~ 4350 3050
NoConn ~ 4350 3150
NoConn ~ 4350 3250
NoConn ~ 4350 3350
NoConn ~ 4350 3450
NoConn ~ 3650 3450
NoConn ~ 3650 3350
NoConn ~ 3650 3250
NoConn ~ 3650 3150
NoConn ~ 3650 3050
NoConn ~ 3650 2950
NoConn ~ 3650 2850
NoConn ~ 3650 2750
NoConn ~ 3650 2650
NoConn ~ 3650 2550
NoConn ~ 3650 2350
NoConn ~ 3650 2250
NoConn ~ 3650 2150
NoConn ~ 3650 2050
$Comp
L PWR_FLAG #FLG1
U 1 1 56BB9BB9
P 4800 3200
F 0 "#FLG1" H 4800 3295 50  0001 C CNN
F 1 "PWR_FLAG" H 4800 3380 50  0000 C CNN
F 2 "" H 4800 3200 50  0000 C CNN
F 3 "" H 4800 3200 50  0000 C CNN
	1    4800 3200
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG2
U 1 1 56BB9BD3
P 5250 3200
F 0 "#FLG2" H 5250 3295 50  0001 C CNN
F 1 "PWR_FLAG" H 5250 3380 50  0000 C CNN
F 2 "" H 5250 3200 50  0000 C CNN
F 3 "" H 5250 3200 50  0000 C CNN
	1    5250 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR7
U 1 1 56BB9BED
P 5250 3350
F 0 "#PWR7" H 5250 3100 50  0001 C CNN
F 1 "GND" H 5250 3200 50  0000 C CNN
F 2 "" H 5250 3350 50  0000 C CNN
F 3 "" H 5250 3350 50  0000 C CNN
	1    5250 3350
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR6
U 1 1 56BB9C0A
P 4800 3350
F 0 "#PWR6" H 4800 3200 50  0001 C CNN
F 1 "VCC" H 4800 3500 50  0000 C CNN
F 2 "" H 4800 3350 50  0000 C CNN
F 3 "" H 4800 3350 50  0000 C CNN
	1    4800 3350
	-1   0    0    1   
$EndComp
Wire Wire Line
	4350 2350 4550 2350
Wire Wire Line
	4800 3200 4800 3350
Wire Wire Line
	5250 3200 5250 3350
Wire Wire Line
	2100 2350 2850 2350
Wire Wire Line
	2850 2350 2850 2100
Wire Wire Line
	2850 2100 3000 2100
Connection ~ 3000 2100
Text Notes 1550 3050 0    60   ~ 0
Arduino Nano with \nDS18B20 Sensor
$Comp
L SW_PUSH SW2
U 1 1 56C9D178
P 2600 4500
F 0 "SW2" H 2750 4610 50  0000 C CNN
F 1 "SW_PUSH" H 2600 4420 50  0000 C CNN
F 2 "" H 2600 4500 50  0000 C CNN
F 3 "" H 2600 4500 50  0000 C CNN
	1    2600 4500
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW3
U 1 1 56C9D223
P 2600 4850
F 0 "SW3" H 2750 4960 50  0000 C CNN
F 1 "SW_PUSH" H 2600 4770 50  0000 C CNN
F 2 "" H 2600 4850 50  0000 C CNN
F 3 "" H 2600 4850 50  0000 C CNN
	1    2600 4850
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 56C9D2EA
P 2600 4150
F 0 "SW1" H 2750 4260 50  0000 C CNN
F 1 "SW_PUSH" H 2600 4070 50  0000 C CNN
F 2 "" H 2600 4150 50  0000 C CNN
F 3 "" H 2600 4150 50  0000 C CNN
	1    2600 4150
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW4
U 1 1 56C9D313
P 2600 5200
F 0 "SW4" H 2750 5310 50  0000 C CNN
F 1 "SW_PUSH" H 2600 5120 50  0000 C CNN
F 2 "" H 2600 5200 50  0000 C CNN
F 3 "" H 2600 5200 50  0000 C CNN
	1    2600 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2550 3050 2550
Wire Wire Line
	3050 2550 3050 4150
Wire Wire Line
	3050 4150 2900 4150
Wire Wire Line
	3650 2650 3150 2650
Wire Wire Line
	3150 2650 3150 4500
Wire Wire Line
	3150 4500 2900 4500
Wire Wire Line
	3650 2750 3250 2750
Wire Wire Line
	3250 2750 3250 4850
Wire Wire Line
	3250 4850 2900 4850
Wire Wire Line
	3650 2850 3350 2850
Wire Wire Line
	3350 2850 3350 5200
Wire Wire Line
	3350 5200 2900 5200
Wire Wire Line
	2300 4150 2300 5450
Connection ~ 2300 4500
Connection ~ 2300 4850
$Comp
L GND #PWR1
U 1 1 56C9D9F6
P 2300 5450
F 0 "#PWR1" H 2300 5200 50  0001 C CNN
F 1 "GND" H 2300 5300 50  0000 C CNN
F 2 "" H 2300 5450 50  0000 C CNN
F 3 "" H 2300 5450 50  0000 C CNN
	1    2300 5450
	1    0    0    -1  
$EndComp
Connection ~ 2300 5200
$EndSCHEMATC
