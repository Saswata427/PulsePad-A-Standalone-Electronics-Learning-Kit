#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h> 
#include <DHT11.h> 
#define RX (3) 
ESP8266WebServer server(80); 
DHT11 dht(D1); 
void handleRoot() { 
server.send(200, "text/html", htmlPage); 
} 
void handleCSS() { 
server.send(200, "text/css", cssPage); 
} 
void handleJS() { 
server.send(200, "text/javascript", jsPage); 
} 
void handleCommand() { 
String cmd = server.arg("cmd"); 
if (cmd == "LED_ON") digitalWrite(LED_BUILTIN, LOW); 
else if (cmd == "LED_OFF") digitalWrite(LED_BUILTIN, HIGH); 
else if (cmd == "TEMP_READ") { 
int temp = dht.readTemperature(); 
if (temp > 100) { 
server.send(200, "text/plain", "Unable to get temperature"); 
      return; 
    } 
    String result = String("Current Temperature is = ") + String(temp) + String(" 
°C\n"); 
    server.send(200, "text/plain", result); 
    return; 
  } 
  else if (cmd == "MOTION_DETECT") { 
    int total = 0; 
    for (int i = 0; i < 10; i++) { 
      if (digitalRead(D3) == HIGH)  
        total++; 
    } 
 
    if (total > 9)  
      server.send(200, "text/plain", "Motion detected near sensor."); 
    else 
      server.send(200, "text/plain", "No motion detected."); 
  } 
  else if (cmd == "LAZER") { 
    server.send(200, "text/plain", "Starting the lazer beam for 10 seconds"); 
    digitalWrite(D5, HIGH); 
    delay(10000); 
    digitalWrite(D5, LOW); 
  } 
  else if (cmd == "PWM") { 
    server.send(200, "text/plain", "Fading out 2 LEDs using PWM"); 
    analogWrite(D7, 1023); 
 
    for (int i = 1022; i >= 0; i--) { 
      analogWrite(D7, i); 
      delay(3); 
    } 
  } 
  else if (cmd == "STATUS") { 
    server.send(200, "text/plain", "All system and sensors are OK."); 
    return; 
  } 
  else { 
    server.send(200, "text/plain", "Playing the piezo crystal for 2 seconds"); 
    digitalWrite(D2, HIGH); 
    delay(2000); 
    digitalWrite(D2, LOW); 
    return; 
  } 
  server.send(200, "text/plain", "OK"); 
} 
 
void setup() { 
pinMode(LED_BUILTIN, OUTPUT); 
pinMode(D2, OUTPUT); 
pinMode(D3, INPUT); 
pinMode(D5, OUTPUT); 
pinMode(D7, OUTPUT); 
analogWrite(D7, 0); 
digitalWrite(D5, LOW); 
digitalWrite(LED_BUILTIN, HIGH); 
Serial.begin(9600); 
WiFi.softAP("PulsePad", "12345678");   // SSID, Password 
Serial.println(WiFi.softAPIP()); 
server.on("/", handleRoot); 
server.on("/command", handleCommand); 
server.on("/style.css", handleCSS); 
server.on("/script.js", handleJS); 
server.begin(); 
} 
void loop() { 
server.handleClient();
}