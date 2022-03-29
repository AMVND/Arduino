int ldr = 9;
int led = 8;
int value = 0;
int button = 13;
int pothg = 0;
int valuepot = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(button, INPUT_PULLUP);
pinMode(ldr, INPUT_PULLUP);
pinMode(led, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
value = digitalRead(button);
valuepot = analogRead(pothg);
valuepot /=4;
  Serial.println("Button=");
  Serial.println(value);
  delay(1000);
  Serial.print("PotHg =");
  Serial.println(valuepot);
  delay(1000);
  if(value ==0){
    digitalWrite(led,HIGH);
    if(digitalRead(ldr) == HIGH)
  {
    digitalWrite(led, HIGH);
    } else
    {
      digitalWrite(led, LOW);
      }
    }else {
    analogWrite(led,valuepot);
    digitalWrite(led,LOW);
    delay(1000);
    //delay(1) ~1ms
    digitalWrite(led,HIGH);
    delay(1000);
      }
}
