# TrafficAdvertising
A prototype for traffic advertising build with Arduino - NodeRed - SQL Database
![Project image](/Media/DSC_0218.JPG)


## Project description
This project has the goal of simulating data collection through sensors, persisting the information in a relational database and modeling the information in an accessible form as bar graphs.

## Requirements
### Hardware
    - Arduino Uno with cable
    - HC-SR501 Pir Sensor
    - HC-SR04 Ulrasonic Sensor
    - 74HC595 16 pin 
    - Leds (2-green, 2 yellow, 2 red)
    - 6 Resistors
    - Potentiometer (1)
    - wires (M-M, F-M)
    - Computer
### Software
    - Arduino compiler
    - NodeRed
    - Sql Database server (MSSQL for example)

## Documentation

### Arduino
The following table contains a list of interfaces that goes connected to the Arduino board.

| Sensor/Aktor | Pin | Pin on Arduino|
|--------------|-----|---------------|
| SR04         | TRIG | 12|
| SR04         | ECHO | 11|
| SR501        | PIR | 3|
| LCD          | VSS | Ground|
| LCD          | VDD | 5v|
| LCD          | VO | Potentiometer|
| LCD          | RS | 4|
| LCD          | RW | Ground|
| LCD          | E | 5|
| LCD          | D4 | 6|
| LCD          | D5 | 7|
| LCD          | D6 | 8|
| LCD          | D7 | 9|
| LCD          | A | 5v|
| LCD          | K | Ground|
| 74HC595      | VCC | 5v|
| 74HC595      | QA | -|
| 74HC595      | SER | 2|
| 74HC595      | OE | Ground|
| 74HC595      | RCLK | 13|
| 74HC595      | SRCLK | 10|
| 74HC595      | SRCLR | 5v|
| 74HC595      | QH' | -|
| 74HC595      | QB | To led green|
| 74HC595      | QC | To led yellow|
| 74HC595      | QD | To led red|
| 74HC595      | QE | To led red|
| 74HC595      | QF | To led yellow|
| 74HC595      | QG | To led green|
| 74HC595      | QH | -|
| 74HC595      | Ground | Ground|

### Node-Red
All Node-Red data is inside **"flows node red.json"** you might need to change the user and password for db connection.
<br />
Once Node-Red is installed run the following on the command prompt.
 >node-red 
 
### Sql database
Database related data could be found inside **"TrafficAdvertising.sql"**.
<br />
Please notice you need to create a db user and password or could use the other auth process. 

## Media and related data
Photos related to project could be found inside **"Media"** folder