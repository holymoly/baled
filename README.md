# BALED

Started as a project to add LEDs to balloon and control them, but can be used for any setup controlling WS2812b with an ESP8266.

## Arduino Code
The ESP8266 code is written for the Arduino IDE. After the first dowload updates can be downloaded over the air (OTA).

## Angular Webinterface
Contolled are the LEDs using a webinterface provided by the ESP8266. The Interface is written in ANGULAR 6. Its uploaded to the ESP8266 using [arduino-esp8266fs-plugin](https://github.com/esp8266/arduino-esp8266fs-plugin). 
The files can not be downloaded over the air (OTA).