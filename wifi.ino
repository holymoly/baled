
const char* ssid = "your_wifi";
const char* password = "your_pass";

#define retryMax 60

void wifiInit(){

  WiFi.mode(WIFI_STA);  
  WiFi.begin(ssid, password);
  
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    
    ESP.restart();
  }
}

void wifiAP(){
  IPAddress local_IP(10,0,0,1);
  IPAddress gateway(10,0,0,1);
  IPAddress subnet(255,0,0,0);

  Serial.println("Set WiFi to AP!");
  WiFi.mode(WIFI_OFF);
  delay(200);
  
  WiFi.softAPConfig(local_IP,gateway, subnet);
  WiFi.softAP("baledAP", "baled");
}
