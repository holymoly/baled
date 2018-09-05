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
       snprintf(message,100,"{\"msgIdent\":100,\"status\":\"connected\",\"red\":%i,\"green\":%i,\"blue\":%i,\"ledProgram\":%i}",red,green,blue,activProgram);
       // send message to client
       webSocket.sendTXT(num, message);
       sendWifiStrength();
      }
    break;
    case WStype_TEXT:
      char message[100];
      Serial.printf("[%u] get Text: %s\n", num, payload);
      jsonParse(payload);
      
      snprintf(message,500,"{\"msgIdent\":101,\"status\":\"updated\",\"red\":%i,\"green\":%i,\"blue\":%i}",red,green,blue);
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
  
  switch (caseSwitch) {
    //color received
    case 1:
        {
          //Values from message
          const char* color = root["color"];
          int value = root["value"];
          
          if(strcmp(color, "red") == 0){
            //Serial.printf("Color: %s Value: %d\n",color, value);
            red = value;
          }
          if(strcmp(color, "green") == 0){
            green = value;
          }
          if(strcmp(color, "blue") == 0){
            blue = value;
          }
        }
      break;
    // wifi config received    
    case 200:
        {
          //Values from message
          const char* ssid = root["ssid"];
          const char* password = root["password"];
          bool ipMan = root["ipMan"];
          int ipAddress1 = root["ipAddress1"];
          int ipAddress2 = root["ipAddress2"];
          int ipAddress3 = root["ipAddress3"];
          int ipAddress4 = root["ipAddress4"];
          
          int ipSubnet1 = root["ipSubnet1"];
          int ipSubnet2 = root["ipSubnet2"];
          int ipSubnet3 = root["ipSubnet3"];
          int ipSubnet4 = root["ipSubnet4"];

          int ipGateway1 = root["ipGateway1"];
          int ipGateway2 = root["ipGateway2"];
          int ipGateway3 = root["ipGateway3"];
          int ipGateway4 = root["ipGateway4"];

          wifiConfig(ssid, password, ipMan, ipAddress1, ipAddress2, ipAddress3, ipAddress4, ipSubnet1, ipSubnet2, ipSubnet3, ipSubnet4, ipGateway1, ipGateway2, ipGateway3, ipGateway4);
        }
      break;
    // Led program received    
    case 201:
        {
          int ledProgram = root["ledProgram"];
          Serial.print("Led Program: ");
          Serial.println(ledProgram);
          activProgram = ledProgram_type(ledProgram);
        }
      break;
    default:
      Serial.println("Error: Received message identifier (msgIdent) unknown");
  }
}

void websocketSendMessageTxt(const char *number, const char *name, const char  *payload){
  char message[100];
  
  snprintf(message,100,"{\"msgIdent\":%s,\"%s\":%s}",number, name, payload);
  //Serial.println(message);
  webSocket.broadcastTXT(message);
}
  
void websocketInit(){
  // start webSocket server
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void websocketSetup(){
  websocketTimer5s.attach(5,sendWifiStrength);
}
