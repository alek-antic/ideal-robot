# Robots Turning Dials For Efficiency #
A simpile interface for turning a pre-indexed dial, using an Arudino Uno with a motor shield and a singular stepper motor.

## LabVIEW/Arudino Compatability ##
Using the [Linx Libraries](https://www.labviewmakerhub.com/doku.php?id=libraries:linx:start) for LabVIEW, connecting the Uno to a computer becomes easy. A little bit of custom [firmware](src/Arduino_Uno_Serial.ino) allows  
the addition of custom commands to the Uno, and can be accessed through LabVIEW.

### Planned Updates ###
* Adjustable Increments For the knob
* Upgraded UI
* Adjustable angles
* Replace dead-reckoning approach with an encoder/other sensor

## Parts Used ##
* [Arudino Uno] (https://www.arduino.cc/en/Main/ArduinoBoardUno)
* [Arudino Uno Motor Shield] (https://www.arrow.com/en/products/a000079/arduino-corporation?gclid=CjwKEAjwqpK8BRD7ua-U0orrgkESJADlN3YBQR4bFnq2o7nf6uNxl2OEvTBShy1X3md_8l63oy5e3xoCZYXw_wcB)
* [3D Printed Frame] (CAD)
* [Module 0.4 42t Teeth 5mm bore gear](http://shop.sdp-si.com/catalog/product/?id=A_1P_2MYD04042C)
* [64 DP, 42 Teeth, 1/8 Inch Bore gear](http://shop.sdp-si.com/catalog/product/?id=A_1P_2-Y64042A)
* [Stepper Motor](http://www.zappautomation.co.uk/sy42sth47-1684b-high-torque-hybrid-stepper-motors.html)