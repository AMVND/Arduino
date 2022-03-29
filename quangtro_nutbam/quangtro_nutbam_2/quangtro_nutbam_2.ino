#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
//Khai báo loại màn LCD
int led = 8;
int button = 13;
int ldr = 9;
int lm35Pin = A1;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(button,INPUT);
pinMode(ldr,INPUT);
Serial.begin(9600);
//Khởi tạo kết nối serial với tốc 9600
lcd.begin(); // khởi tạo màn LCD
lcd.backlight(); //bật sáng màn LCD
}

void loop() {
  // put your main code here, to run repeatedly:
int analogvalue;
float nhietdo;
int valueldr= digitalRead(ldr);
int valuebutton = digitalRead(button);
analogvalue = analogRead(lm35Pin);
nhietdo = float(analogvalue)/1024;
nhietdo = nhietdo * 500;
Serial.print("Nhiet do: ");
Serial.print(nhietdo);
delay(1000);
Serial.print("LDR =");
Serial.println(valueldr);
lcd.setCursor(0,0);   //cột, hàng
lcd.print("LDR = ");
lcd.print(valueldr);
delay(1000);
lcd.setCursor(0,1);   //cột, hàng
lcd.print("NHIET DO = ");
lcd.print(nhietdo);
lcd.print(" C");
delay(1000);
if(valuebutton == 1) {
  digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,valueldr);
    }
}
