void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

  switch(type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
    break;
    case WStype_CONNECTED: {
      IPAddress ip = webSocket.remoteIP(num);
       char message[100];
       Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
       //prepare actual values for client
       snprintf(message,100,"{\"msgIdent\":100,\"status\":\"connected\",\"red\":%i,\"green\":%i,\"blue\":%i}",red,green,blue);
       // send message to client
       webSocket.sendTXT(num, message);
      }
    break;
    case WStype_TEXT:
      char message[100];
      Serial.printf("[%u] get Text: %s\n", num, payload);
      jsonParse(payload);
      
      snprintf(message,101,"{\"msgIdent\":101,\"status\":\"updated\",\"red\":%i,\"green\":%i,\"blue\":%i}",red,green,blue);
      webSocket.sendTXT(num, message);
    break;
  }
}

void jsonParse(unsigned char *data){
  const size_t bufferSize = JSON_OBJECT_SIZE(5) + 200;
  DynamicJsonBuffer jsonBuffer(bufferSize);

  //const char* json = data;

  JsonObject& root = jsonBuffer.parseObject(data);

  int caseSwitch = root["msgIdent"];
  const char* color = root["color"];
  int value = root["value"];
        
  switch (caseSwitch) {
    //color received
    case 1:
        if(strcmp(color, "red") == 0){
          Serial.printf("Color: %s Value: %d\n",color, value);
          red = value;
        }
        if(strcmp(color, "green") == 0){
          green = value;
        }
        if(strcmp(color, "blue") == 0){
          blue = value;
        }
        
        for (int i=0; i<NUMPIXELS; i++){              //loop throug pixels
          pixels.setPixelColor(i, pixels.Color(red,green,blue));
        }
      break;
    default:
      Serial.println("Error: Received message identifier (msgIdent) unknown");
 }
}
  
void websocketInit(){
  // start webSocket server
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}
