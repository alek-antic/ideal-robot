/****************************************************************************************
**  This is example LINX firmware for use with the Arduino Uno with the serial
**  interface enabled.
**
**  For more information see:           www.labviewmakerhub.com/linx
**  For support visit the forums at:    www.labviewmakerhub.com/forums/linx
**
**  Written By Sam Kristoff
**  Modified by Aleksandar Antic
**
**  BSD2 License.
****************************************************************************************/

//Include All Peripheral Libraries Used By LINX
#include <SPI.h>
#include <Wire.h>

//Include Device Specific Header From Sketch>>Import Library (In This Case LinxChipkitMax32.h)
//Also Include Desired LINX Listener From Sketch>>Import Library (In This Case LinxSerialListener.h)
#include <LinxArduinoUno.h>
#include <LinxSerialListener.h>

//Create A Pointer To The LINX Device Object We Instantiate In Setup()
LinxArduinoUno* LinxDevice;
int stepMotor();
int resetPos();

//Initialize LINX Device And Listener
void setup()
{
  //It must be these four pins if using the Arduino Motor Shield
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  //Instantiate The LINX Device
  LinxDevice = new LinxArduinoUno();

  //The LINXT Listener Is Pre Instantiated, Call Start And Pass A Pointer To The LINX Device And The UART Channel To Listen On
  LinxSerialConnection.Start(LinxDevice, 0);

  //Allows LabVIEW to call the methods instantiated below
  LinxSerialConnection.AttachCustomCommand(0, resetPos);
  LinxSerialConnection.AttachCustomCommand(1, stepMotor);
}

void loop()
{
  //Listen For New Packets From LabVIEW
  LinxSerialConnection.CheckForCommands();

  //Your Code Here, But It will Slow Down The Connection With LabVIEW
}


/*
  The method that interfaces with LabVIEW in order to get the current and desired position of the knob
*/
int stepMotor(unsigned char numInputBytes, unsigned char* steps, unsigned char* numResponseBytes, unsigned char* response) {

  int delta = steps[1] - steps[0];
  int deg = steps[2];

  if (delta > 0) {
    for (int i = 0; i < delta * deg / 3.6; i++)
      stepClockwise();
  } else if (delta < 0) {
    for (int i = 0; i > delta * deg / 3.6; i--)
      stepCounterClockwise();
  }

  *numResponseBytes = 1;

  response[0] = steps[1];

  //turns off PWM to motor, so that the spring in the knobs with discrete positions can auto-position the motor
  //comment out lines if using a knob that has INDISCRETE values
  analogWrite(3, 0);
  analogWrite(11, 0);

  return 0;
}

/*
   A method to reset the position to the most clockwise position
*/
int resetPos(unsigned char numInputBytes, unsigned char* input, unsigned char* numResponseBytes, unsigned char* response) {
  while (true) {
    stepClockwise();
    if (analogRead(0) + analogRead(1) > 2000)//2000 is arbitrary, needs to be tested
      break;
  }
}

/*
  A method that steps the motor 2 steps (3.6 degrees), clockwise
*/
void stepClockwise() {
  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, HIGH);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A

  delay(2);

  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, LOW);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B

  delay(2);

  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, LOW);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A

  delay(2);

  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, HIGH);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B

  delay(2);
}

/*
   A method that steps the motor 2 steps (3.6 degrees), anti-clockwise
*/
void stepCounterClockwise() {
  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, HIGH);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B

  delay(2);

  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, LOW);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A

  delay(2);

  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, LOW);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B

  delay(2);

  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, HIGH);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A

  delay(2);
}

