
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>


const char* ap = "NT-21";
const char* pass = "siecwsizbb";

ESP8266WebServer serwerWWW(80);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ap, pass);

  if(WiFi.waitForConnectResult() != WL_CONNECTED)
  {
     Serial.print("Nie mamy polaczenia z WIFI ");
     Serial.println(ap); 
  } else
  {
  Serial.print("Nasze IP ");
  Serial.println(WiFi.localIP());
  }

  serwerWWW.on("/", HTTP_GET,[](){
      serwerWWW.sendHeader("Access-Control-Allow-Origin", "*");
      serwerWWW.send(200,"text/html","<h1>Hellow Word</h1>");
    });

  serwerWWW.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  serwerWWW.handleClient();
}
