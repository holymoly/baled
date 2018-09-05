# BALED

Started as a project to add LEDs to balloon and control them, but can be used for any setup controlling WS2812b with an ESP8266.

## Arduino Code
The ESP8266 code is written for the Arduino IDE. After the first dowload updates can be downloaded over the air (OTA).

## Arduino IDE Settings
Choose your ESP under "Board".
Set Flash Size to "4M (3MSPIFFS)".

## Angular Webinterface
Contolled are the LEDs using a webinterface provided by the ESP8266. The Interface is written in ANGULAR 6. Its uploaded to the ESP8266 using [arduino-esp8266fs-plugin](https://github.com/esp8266/arduino-esp8266fs-plugin). 
The files can not be downloaded over the air (OTA).

### Build webinterface

The files for the webinterface are in the folder data. The arduino-esp8266fs-plugin uploads every file which is in this directory.
If changes were made to the interface the data need to be updated (angular cli required).
Update can be done with the following commands.
```bash
cd ng
ng build --prod --aot --output-hashing=none
cp dist/* data
```
After a succesfull build upload the files using the Arduino IDE and the arduino-esp8266fs-plugin.