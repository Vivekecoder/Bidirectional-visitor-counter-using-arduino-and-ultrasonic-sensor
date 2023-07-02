#include<LiquidCrystal.h>
const int trigger = 6;
const int echo = 9;
const int trigger1 = 10;
const int echo1 = 8;
const int buzzer = 7;
int count = 0;
long duration = 0;
int distance = 0;
long duration1 = 0;
int distance1 = 0;
LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(trigger1, OUTPUT);
pinMode(echo1, INPUT);
pinMode(buzzer, OUTPUT);
lcd.begin(16,2);
lcd.clear();
}
void loop()
{
lcd.clear();
digitalWrite(trigger,HIGH);
delayMicroseconds(1000);
digitalWrite(trigger,LOW);
delayMicroseconds(10);
duration = pulseIn(echo,HIGH);
distance = (duration/2)/29.1;
digitalWrite(trigger1,HIGH);
delayMicroseconds(1000);
digitalWrite(trigger1,LOW);
delayMicroseconds(10);
duration1 = pulseIn(echo1,HIGH);
distance1 = (duration1/2)/29.1;
delay(100);
if (distance<520)
 {
tone(buzzer,2000);
count++;
 }
 if (distance1<520)
 {
tone(buzzer,2000);
count--;
 }
else
noTone(buzzer); 
lcd.clear();
lcd.print("DISTANCE:");
lcd.print(distance);
delay(1000);
lcd.clear();
delay(1000);
lcd.print("DISTANCE1:");
lcd.print(distance1);
lcd.print("cm");
lcd.setCursor(0,1);
lcd.print("no. of object:");
lcd.print(count);
delay(1000);
Serial.print("DISTANCE");
Serial.print(distance);
Serial.print("cm");
delay(1000);
 }

