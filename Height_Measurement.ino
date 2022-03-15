#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define echoPin 2
#define trigPin 3
long duration;
int distance;
int d;
float f;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
lcd.begin(16, 2);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
Serial.println(distance);
d=202-distance;
f=(int)d/30.0;
if(d >0 && d<200)
{
Serial.print("Distance: ");
Serial.print(d);
Serial.println(" cm");
lcd.setCursor(0,0);
lcd.print("YourHeight:");
lcd.print(d);
lcd.print("CM");
lcd.setCursor(2,1);
lcd.print("In Feet:");
lcd.print(f);
}
delay(250);
}
