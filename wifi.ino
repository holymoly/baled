const char *ssid = "baledAP";
const char *password = "baled1234";

#define retryMax 10

void wifiInit(){
  
  WiFi.begin();
  delay(200);
  //WiFi.printDiag(Serial);
  Serial.println("Try to setup Wifi...");
  wifiSta();
}

void wifiConfig(const char* ssid, const char* password, bool ipMan, int ipAddress1, int ipAddress2, int ipAddress3, int ipAddress4, int ipSubnet1, int ipSubnet2, int ipSubnet3, int ipSubnet4, int ipGateway1, int ipGateway2, int ipGateway3, int ipGateway4){
  int timeOut = 0;
  
  Serial.println("Configure wifi for client mode...");
  WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid, password);
  if(ipMan){
    Serial.println("IP Static");
    WiFi.config(IPAddress(ipAddress1,ipAddress2,ipAddress3,ipAddress4), IPAddress(ipSubnet1,ipSubnet2,ipSubnet3,ipSubnet4), IPAddress(ipGateway1,ipGateway2,ipGateway3,ipGateway4));
  }
  wifiSta();
}

void wifiSta(){
  int timeOut = 0;
  while (WiFi.waitForConnectResult() != WL_CONNECTED and timeOut < retryMax) {
    timeOut++;
    Serial.print(".");
    delay(1000);
  }

  //Wifi connection not possible start AP
  if (WiFi.waitForConnectResult() != WL_CONNECTED){
    delay(200);
    wifiAP();
  }
}

void wifiAP(){
  Serial.println("Start wifi in AP mode...");
  Serial.print("Try to setup AP: ");
  Serial.println(WiFi.SSID());

  WiFi.softAPdisconnect();
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  delay(100);
  
  if (WiFi.softAP(ssid, password)){
    Serial.println("SoftAP setup: success");
  }  else  {
    Serial.println("SoftAP setup: failed");
  }

  //WiFi.printDiag(Serial);
}

void sendWifiStrength(){
  char strength[100];

  snprintf(strength,100,"%d",WiFi.RSSI());
  websocketSendMessageTxt("300", "strength", strength);
}
