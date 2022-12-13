/*****************************************************************************
  programme Wifi et Ping
*****************************************************************************/

#include <ESP_Ping.h>

void setup()
{
  Serial.begin(115200);
  delay(100);

  //WiFi.begin("TP-Link_AD3C", "78850569");
  WiFi.begin("Livebox-C806","bienvenuechezbdv");
  
  // attente connexion
  Serial.print("\nConnexion");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nConnexion OK, IP: ");
  Serial.print(WiFi.localIP());
  Serial.print(" Passerelle: ");
  Serial.println(WiFi.gatewayIP());
  Serial.println("You can try to ping me ;-)");

}

void loop()
{
  
  // Ping IP
  const IPAddress remote_ip(192,168,1,1);
  Serial.print(remote_ip);
  if (Ping.ping(remote_ip)){
      Serial.print(" réponse :");
      Serial.print(Ping.averageTime());
      Serial.println("ms");
  } else {
    Serial.println(" Error !");
  }
  delay(5000);

  // Ping Host
  const char* remote_host = "www.varrel.fr";
  Serial.print(remote_host);
  if (Ping.ping(remote_host)){
      Serial.print(" réponse :");
      Serial.print(Ping.averageTime());
      Serial.println("ms");
  } else {
    Serial.println(" Ping Error !");
  }    
  delay(5000);

}
