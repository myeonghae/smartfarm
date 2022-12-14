
#include <DHT.h>
#include <Adafruit_NeoPixel.h>
#include <avr/power.h> 

#define PIN 13                   
#define NUMPIXELS 80        
#define BRIGHTNESS 180    
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);  

#define DHTTYPE DHT11
#define DHTPIN 8 
DHT dht(DHTPIN, DHTTYPE);

float h =0;
float t =0;
String string ="";
int colors[4];
String motor = "false";

int ENA=2;
int ENB=5;
int IN1=3;
int IN2=4;
int IN3=6;
int IN4=7;
int index = 0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(60);
  
  dht.begin();
  colors[0] = 255;
  colors[1] = 255; 
  colors[2] = 255;
  strip.setBrightness(BRIGHTNESS);
  strip.begin(); 
  strip.show();

  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
}

void loop() {

  if(motor == "true"){
    stepMotor();
    index = index + 1;
    if(index > 10){
      tempData();
    }
  }
  else{
    tempData();
  }
  
  if(Serial.available()){
    String result = Serial.readStringUntil("\n");

    int nCount = 0;
    int nGetIndex = 0;
    String sTemp = "";
    String sCopy = result;
    while(true){
      nGetIndex = sCopy.indexOf(",");
      if(-1 != nGetIndex){
        sTemp = sCopy.substring(0, nGetIndex);
        colors[nCount] = sTemp.toInt();
        sCopy = sCopy.substring(nGetIndex + 1);
      }
      else{
        motor = sCopy;
        Serial.print(motor);
        break;
      }
      ++nCount;
    }
   delay(200);
   Serial.flush();
  }
  colorWipe(strip.Color(colors[0], colors[1], colors[2]), 50);
}

void tempData(){
  h = dht.readHumidity();
  delay(200);
  t = dht.readTemperature();
  delay(200);
  string = String(h) + "," + String(t);
  delay(200);
  Serial.println(string);
  delay(200);
  index = 0;
}

void colorWipe(uint32_t c, uint8_t wait){    
  for(uint16_t i=0; i<strip.numPixels(); i++)
  {
    strip.setPixelColor(i,c);
    strip.show();
    delay(wait);
  }
}

void stepMotor(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(50);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(50);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(50);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(50);
}
