#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
//Khai báo loại màn LCD
int led = 8;
int lm35Pin = A1;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
Serial.begin(9600);
//Khởi tạo kết nối serial với tốc 9600
lcd.begin(); // khởi tạo màn LCD
lcd.backlight(); //bật sáng màn LCD
}

void loop() {
  // put your main code here, to run repeatedly:
int analogvalue;
float nhietdo;
analogvalue = analogRead(lm35Pin);
nhietdo = float(analogvalue)/1024;
nhietdo = nhietdo * 500;
Serial.print("Nhiet do");
Serial.println(nhietdo);
delay(1000);
lcd.setCursor(0,1);   //cột, hàng
lcd.print("NHIET DO = ");
lcd.print(nhietdo);
lcd.print(" C");
delay(500);
if(nhietdo>40)
{ lcd.setCursor(0,0);   //cột, hàng
  lcd.print("CANH BAO");
  delay(1000);
  digitalWrite(led, HIGH);
  delay(1000);
  }else {
  lcd.setCursor(0,0);   //cột, hàng
  lcd.print("BINH THUONG");
  delay(500);
  digitalWrite(led, LOW);
  delay(1000);}
}
