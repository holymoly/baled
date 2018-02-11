#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ArduinoJson.h>

#include <FS.h>

#define PIN 5       // WS2812b pin?
#define NUMPIXELS 6 // WS2812b amount

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

ESP8266WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(8080);

int delayval = 10; // delay time

int ledState[NUMPIXELS][4];

int fadeStates[7][3] = {  
   {255,   0,   0} ,   /*  initializers for row indexed by 0 */
   {255, 255,   0} ,   /*  initializers for row indexed by 1 */
   {0,   255,   0} ,   /*  initializers for row indexed by 2 */
   {0,   255, 255} ,   /*  initializers for row indexed by 3 */
   {0,     0, 255} ,   /*  initializers for row indexed by 4 */
   {255,   0, 255} ,   /*  initializers for row indexed by 5 */
   {255, 255, 255} ,   /*  initializers for row indexed by 6 */
};

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");

  pinMode(PIN, OUTPUT);
  
  wifiInit();
  otaInit();
  webserverInit();
  websocketInit();
  
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  //initLeds();
  initLedsFloat();
  pixels.begin(); // This initializes the NeoPixel library.

  Dir dir = SPIFFS.openDir("/");
  while (dir.next()) {
      Serial.print(dir.fileName());
      File f = dir.openFile("r");
      Serial.println(f.size());
  }
}

void loop() {
  ArduinoOTA.handle();
  
  //ledFade();
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval);
  server.handleClient();
  webSocket.loop();
}

