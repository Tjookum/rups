/*
Attempt #5.1 
Jochem van Grieken copyright 10-2021
*/

#include <Arduino.h>
#include <FlashStorage_STM32F1.h>

const uint16_t sinTable[] = {
    0x7ff,
    0x823,
    0x846,
    0x86a,
    0x88e,
    0x8b1,
    0x8d5,
    0x8f9,
    0x91c,
    0x93f,
    0x963,
    0x986,
    0x9a9,
    0x9cc,
    0x9ee,
    0xa11,
    0xa33,
    0xa56,
    0xa78,
    0xa9a,
    0xabb,
    0xadd,
    0xafe,
    0xb1f,
    0xb40,
    0xb60,
    0xb81,
    0xba1,
    0xbc0,
    0xbe0,
    0xbff,
    0xc1e,
    0xc3c,
    0xc5a,
    0xc78,
    0xc95,
    0xcb2,
    0xccf,
    0xcec,
    0xd08,
    0xd23,
    0xd3e,
    0xd59,
    0xd73,
    0xd8d,
    0xda7,
    0xdc0,
    0xdd8,
    0xdf1,
    0xe08,
    0xe1f,
    0xe36,
    0xe4c,
    0xe62,
    0xe77,
    0xe8c,
    0xea0,
    0xeb4,
    0xec7,
    0xeda,
    0xeec,
    0xefe,
    0xf0f,
    0xf1f,
    0xf2f,
    0xf3f,
    0xf4d,
    0xf5c,
    0xf69,
    0xf77,
    0xf83,
    0xf8f,
    0xf9a,
    0xfa5,
    0xfaf,
    0xfb9,
    0xfc2,
    0xfca,
    0xfd2,
    0xfd9,
    0xfdf,
    0xfe5,
    0xfeb,
    0xfef,
    0xff3,
    0xff7,
    0xffa,
    0xffc,
    0xffd,
    0xffe,
    0xfff,
    0xffe,
    0xffd,
    0xffc,
    0xffa,
    0xff7,
    0xff3,
    0xfef,
    0xfeb,
    0xfe5,
    0xfdf,
    0xfd9,
    0xfd2,
    0xfca,
    0xfc2,
    0xfb9,
    0xfaf,
    0xfa5,
    0xf9a,
    0xf8f,
    0xf83,
    0xf77,
    0xf69,
    0xf5c,
    0xf4d,
    0xf3f,
    0xf2f,
    0xf1f,
    0xf0f,
    0xefe,
    0xeec,
    0xeda,
    0xec7,
    0xeb4,
    0xea0,
    0xe8c,
    0xe77,
    0xe62,
    0xe4c,
    0xe36,
    0xe1f,
    0xe08,
    0xdf1,
    0xdd8,
    0xdc0,
    0xda7,
    0xd8d,
    0xd73,
    0xd59,
    0xd3e,
    0xd23,
    0xd08,
    0xcec,
    0xccf,
    0xcb2,
    0xc95,
    0xc78,
    0xc5a,
    0xc3c,
    0xc1e,
    0xbff,
    0xbe0,
    0xbc0,
    0xba1,
    0xb81,
    0xb60,
    0xb40,
    0xb1f,
    0xafe,
    0xadd,
    0xabb,
    0xa9a,
    0xa78,
    0xa56,
    0xa33,
    0xa11,
    0x9ee,
    0x9cc,
    0x9a9,
    0x986,
    0x963,
    0x93f,
    0x91c,
    0x8f9,
    0x8d5,
    0x8b1,
    0x88e,
    0x86a,
    0x846,
    0x823,
    0x7ff,
    0x7db,
    0x7b8,
    0x794,
    0x770,
    0x74d,
    0x729,
    0x705,
    0x6e2,
    0x6bf,
    0x69b,
    0x678,
    0x655,
    0x632,
    0x610,
    0x5ed,
    0x5cb,
    0x5a8,
    0x586,
    0x564,
    0x543,
    0x521,
    0x500,
    0x4df,
    0x4be,
    0x49e,
    0x47d,
    0x45d,
    0x43e,
    0x41e,
    0x3ff,
    0x3e0,
    0x3c2,
    0x3a4,
    0x386,
    0x369,
    0x34c,
    0x32f,
    0x312,
    0x2f6,
    0x2db,
    0x2c0,
    0x2a5,
    0x28b,
    0x271,
    0x257,
    0x23e,
    0x226,
    0x20d,
    0x1f6,
    0x1df,
    0x1c8,
    0x1b2,
    0x19c,
    0x187,
    0x172,
    0x15e,
    0x14a,
    0x137,
    0x124,
    0x112,
    0x100,
    0xef,
    0xdf,
    0xcf,
    0xbf,
    0xb1,
    0xa2,
    0x95,
    0x87,
    0x7b,
    0x6f,
    0x64,
    0x59,
    0x4f,
    0x45,
    0x3c,
    0x34,
    0x2c,
    0x25,
    0x1f,
    0x19,
    0x13,
    0xf,
    0xb,
    0x7,
    0x4,
    0x2,
    0x1,
    0x0,
    0x0,
    0x0,
    0x1,
    0x2,
    0x4,
    0x7,
    0xb,
    0xf,
    0x13,
    0x19,
    0x1f,
    0x25,
    0x2c,
    0x34,
    0x3c,
    0x45,
    0x4f,
    0x59,
    0x64,
    0x6f,
    0x7b,
    0x87,
    0x95,
    0xa2,
    0xb1,
    0xbf,
    0xcf,
    0xdf,
    0xef,
    0x100,
    0x112,
    0x124,
    0x137,
    0x14a,
    0x15e,
    0x172,
    0x187,
    0x19c,
    0x1b2,
    0x1c8,
    0x1df,
    0x1f6,
    0x20d,
    0x226,
    0x23e,
    0x257,
    0x271,
    0x28b,
    0x2a5,
    0x2c0,
    0x2db,
    0x2f6,
    0x312,
    0x32f,
    0x34c,
    0x369,
    0x386,
    0x3a4,
    0x3c2,
    0x3e0,
    0x3ff,
    0x41e,
    0x43e,
    0x45d,
    0x47d,
    0x49e,
    0x4be,
    0x4df,
    0x500,
    0x521,
    0x543,
    0x564,
    0x586,
    0x5a8,
    0x5cb,
    0x5ed,
    0x610,
    0x632,
    0x655,
    0x678,
    0x69b,
    0x6bf,
    0x6e2,
    0x705,
    0x729,
    0x74d,
    0x770,
    0x794,
    0x7b8,
    0x7db,
};

const uint8_t numberOfSegments = 2;

//Encoder resolution is 4 pulses per milimeter.
const int maxRev = 100; //Maximal amplitude of the motion. 25mm
const int offset = 20;  //use this value to center the motion after callibration is done. 5mm

//startpostions to create the sinusoidal pattern  !!need to implement sinus
//reference to 8 pos sin table
const uint8_t startPosition[] = {};



//define sensor pins
const uint8_t sensorPin[] = {PB2, PB10, PB13, PB12, PB11, PA5, PB14, PB15};

//define motor pins
const uint8_t motorPinA[] = {PA6, PB0, PA8, PA10, PA0, PA2, PA15, PB4};
const uint8_t motorPinB[] = {PA7, PB1, PA9, PA11, PA1, PA3, PB3, PB5};

//calibration variables
bool callibrationDone = false;
const int calSwitch = PA12;

bool powerDownCorrect = false;

//onboard led
const int ledPin = PC13;

//initiate motor class for each motor
struct Motor
{
  int motorA;
  int motorB;
  bool motorDir;
  int sensor;
  bool triggered;
  int revolutions;
  bool isCalibrated;
  int startVoltage;
};
Motor motor[numberOfSegments];

//interrupt routines to check the hall effect sensors and increment the rotation values
void checkSensor0()
{
  motor[0].revolutions += 1;
}
void checkSensor1()
{
  motor[1].revolutions += 1;
}
void checkSensor2()
{
  motor[2].revolutions += 1;
}
void checkSensor3()
{
  motor[3].revolutions += 1;
}
void checkSensor4()
{
  motor[4].revolutions += 1;
}
void checkSensor5()
{
  motor[5].revolutions += 1;
}
void checkSensor6()
{
  motor[6].revolutions += 1;
}
void checkSensor7()
{
  motor[7].revolutions += 1;
}
typedef void (*GeneralFunction)();

GeneralFunction checkSensor[] =
    {
        checkSensor0,
        checkSensor1,
        checkSensor2,
        checkSensor3,
        checkSensor4,
        checkSensor5,
        checkSensor6,
        checkSensor7,
};

void blinkLed(int times)
{
  for (int i = 0; i < times; i++)
  {
    digitalWrite(ledPin, LOW);
    delay(100);
    digitalWrite(ledPin, HIGH);
    delay(100);
  }
}

void powerDown()
{
  for (int i = 0; i < numberOfSegments; i++)
  {
    digitalWrite(motor[i].motorA, motor[i].motorDir); //disable motor
    digitalWrite(motor[i].motorB, motor[i].motorDir);
    EEPROM.write(i, motor[i].revolutions);
    EEPROM.write(i + numberOfSegments, motor[i].motorDir);
  }
  powerDownCorrect = true;
  EEPROM.write((numberOfSegments * 2) + 1, powerDownCorrect); //Write powerdowncorrect status to the last register to check if it needs callibration after powerup.
  EEPROM.commit();
  blinkLed(100); //blink led to give the user time to switch off the power.
}

void callibration()
{
  blinkLed(30); //Blink the led 30 times(3 seconds) to give the user time to release the calSwitch
  for (int i = 1; i < numberOfSegments; i++)
  {
    motor[i].motorDir = HIGH;
    while (digitalRead(calSwitch)) //While the calibration switch is not pressed turn on motor.
    {
      digitalWrite(motor[i].motorA, !motor[i].motorDir);
      digitalWrite(motor[i].motorB, motor[i].motorDir);
    }
    motor[i].motorDir = !motor[i].motorDir; //When the motor has reached the callibration endstop, reverse the motor direction and set the home position.
    motor[i].revolutions = 0;

    while (motor[i].revolutions <= startPosition[i] + offset) // turn the motor till it has reached the startingposition and apply an offset to stay clear from the calSwitch.
    {
      digitalWrite(motor[i].motorA, !motor[i].motorDir);
      digitalWrite(motor[i].motorB, motor[i].motorDir);
    }
    digitalWrite(motor[i].motorA, motor[i].motorDir); //disable motor
    digitalWrite(motor[i].motorB, motor[i].motorDir);
    motor[i].revolutions = motor[i].revolutions - offset; //store current position
    motor[i].isCalibrated = true;
  }

  int count = 0;
  for (int i = 1; i < numberOfSegments; i++) //check if all the callibration is done
  {

    if (motor[i].isCalibrated)
    {
      count++;
    }
    if (count == 8)
    {
      blinkLed(10);
      callibrationDone = true;
    }
  }
}

void setup()
{
  EEPROM.init(); //initialize eeprom emulation

  for (int i = 0; i < numberOfSegments; i++)
  {
    //initialise motors
    motor[i].motorA = motorPinA[i];
    pinMode(motor[i].motorA, OUTPUT);
    digitalWrite(motor[i].motorA, LOW);
    motor[i].motorB = motorPinB[i];
    pinMode(motor[i].motorB, OUTPUT);
    digitalWrite(motor[i].motorB, LOW);
    motor[i].isCalibrated = false;
    //initialise sensors
    motor[i].sensor = sensorPin[i];
    pinMode(motor[i].sensor, INPUT_PULLUP);
    attachInterrupt(motor[i].sensor, checkSensor[i], FALLING);

    //Read the position and direction from EEPROM to continue after powerdown.
    motor[i].revolutions = EEPROM.read(i);
    motor[i].motorDir = EEPROM.read(i + numberOfSegments);
  }
  pinMode(calSwitch, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

 //Read EEPROM to see if it has been powered down correctly last time or if it needs callibration.
 powerDownCorrect = EEPROM.read((numberOfSegments * 2) + 1); 
  if (!powerDownCorrect) 
  {
    callibration(); //Go into callibration mode
  }
  else
  {
    blinkLed(5);
  }
}

void loop()
{
  for (int i = 0; i < numberOfSegments; i++)
  {
    // digitalWrite(motor[i].motorA, !motor[i].motorDir);
    // digitalWrite(motor[i].motorB, motor[i].motorDir);

    motor[i].startVoltage = 100;
    if (motor[i].revolutions > 0 && motor[i].revolutions < (maxRev /2)) {
      analogWrite(motor[i].motorA, motor[i].startVoltage + motor[i].revolutions);
      digitalWrite(motor[i].motorB, motor[i].motorDir);
      //analogWrite(motor[i].motorB, motor[i].startVoltage - motor[i].revolutions);
    } else {
      analogWrite(motor[i].motorA, motor[i].startVoltage - motor[i].revolutions);
      digitalWrite(motor[i].motorB, motor[i].motorDir);
      //analogWrite(motor[i].motorB, motor[i].startVoltage + motor[i].revolutions);
    }

    if (motor[i].revolutions >= maxRev) //if the max amplitude is reached reverse the motor
    {
      motor[i].motorDir = !motor[i].motorDir;
      motor[i].revolutions = 0;
    }
  }
  if (!digitalRead(calSwitch)) //Check if the powerDownSwitch is pressed and start the safe powerDown routine. 
  {
    powerDown();
  }
}