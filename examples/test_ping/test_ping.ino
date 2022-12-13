/******************************************************
  test Ping
******************************************************/

#include <ESP_Ping.h>

void setup()
{
  Serial.begin(115200);
  delay(100);

  WiFi.begin("ssid","password");
  
  // attente connexion
  Serial.print("\nConnection");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nConnection OK, IP: ");
  Serial.print(WiFi.localIP());
  Serial.print(" Gateway: ");
  Serial.println(WiFi.gatewayIP());
  Serial.println("You can try to ping me ;-)");

}

void loop()
{
  
  // Ping IP
  const IPAddress remote_ip(9,9,9,9);
  Serial.print(remote_ip);
  if (Ping.ping(remote_ip)){
      Serial.print(" response time :");
      Serial.print(Ping.averageTime());
      Serial.println("ms");
  } else {
    Serial.println(" Error !");
  }
  delay(5000);

  // Ping Host
  const char* remote_host = "quad9.net";
  Serial.print(remote_host);
  if (Ping.ping(remote_host)){
      Serial.print(" response time :");
      Serial.print(Ping.averageTime());
      Serial.println("ms");
  } else {
    Serial.println(" Ping Error !");
  }    
  delay(5000);

}
