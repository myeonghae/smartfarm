#include <DHT11.h>

// DHT11 센서의 핀번호를 7번으로 설정
DHT11 dht11(7);

// DHT11 센서의 데이터를 저장할 변수
String input = "";
String cmd = "temp";
String response = "";

void setup() {
  // 시리얼 통신을 9600bps로 설정
  Serial.begin(9600);
  Serial.println("DHT11 Test");
}

void loop() {
  float temp, humi
  // 시리얼 통신으로 입력된 데이터가 있으면
  if(Serial.available()) {
    // 시리얼 통신으로 입력된 데이터를 읽어옴
    input = Serial.readStringUntil('\n');
  }
}

if(Serial.available() == 0 && input == cmd) {
  // DHT11 센서로부터 온도와 습도를 읽어옴
  dht11.read(&temp, &humi);
  // 읽어온 온도와 습도를 시리얼 통신으로 전송 
  Serial.print("temp:");
  Serial.print(temp);
  Serial.print(" humi:");
  Serial.println(humi);
  // 입력된 데이터를 초기화
  input = "";
}