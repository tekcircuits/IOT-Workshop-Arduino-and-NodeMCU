/*
	Tekcircuits R&D Lab Tutorial 
		
		The circuit:
		* Simple code upload the tempeature and humidity data using thingspeak.com
		* Hardware: NodeMCU with LM35
		
	Copyrighted to Tekcircuits R&D Lab
 */

#include <ESP8266WiFi.h>


const char* ssid     = "wifi name";
const char* password = "wifi password";

const char* streamId   = "....................";
const char* privateKey = "....................";

const char *host = "https://api.thingspeak.com";
unsigned long channelID = 0; //change channel id here
char* readAPIKey = "readapi";
char* writeAPIKey = "writeapi";
unsigned int dataFieldOne = 1; 

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {
  delay(5000);
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 443;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET https://api.thingspeak.com/update?api_key=31RVJ832UANIEYEQ&field1=25\r\n"));
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection"); delay(5000);
}

