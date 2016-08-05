# Robots Turning Dials For Efficiency #
A simpile interface for turning a pre-indexed dial, using an Arudino Uno with a motor shield and a singular stepper motor.

## LabVIEW/Arudino Compatability ##
Using the [Linx Libraries](https://www.labviewmakerhub.com/doku.php?id=libraries:linx:start) for LabVIEW, connecting the Uno to a computer becomes easy. A little bit of custom [firmware](src/Arduino_Uno_Serial.ino) allows  
the addition of custom commands to the Uno, and can be accessed through LabVIEW.

### Planned Updates ###
* Adjustable increments for the knob
* Upgraded UI
* Adjustable angles
* Replace dead-reckoning approach with an encoder/other sensor

## Parts Used ##
* [Arudino Uno] (http://www.robotshop.com/en/arduino-uno-usb-microcontroller-rev-3.html)
* [Arudino Uno Motor Shield] (http://www.robotshop.com/en/arduino-motor-shield-v3.html)
* [3D Printed Frame] (CAD)
* [Module 0.4 42t Teeth 5mm bore gear](http://shop.sdp-si.com/catalog/product/?id=A_1P_2MYD04042C)
* [64 DP, 42 Teeth, 1/8 Inch Bore gear](http://shop.sdp-si.com/catalog/product/?id=A_1P_2-Y64042A)
* [Stepper Motor, 200 steps per revolution, 2.8V, 1.68A, 44 N*cm holding torque](http://www.robotshop.com/en/soyo-reprap-stepper-motor.html)