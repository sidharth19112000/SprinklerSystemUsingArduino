#include <LiquidCrystal.h>
#include <dht.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int dht_apin = A1; // the output pin of DHT11
int motor = 11; // the pin where relay
int led = 8; // led pin
int temp;
int reftemp = 36; // the temperature to start the motor
int refhumidity=45;
dht DHT;

 
void setup() {
pinMode(motor, OUTPUT);
pinMode(led, OUTPUT);

pinMode(dht_apin, INPUT);
lcd.begin(16,2);
Serial.begin(9600);
}
 
void loop()
{
  DHT.read11(dht_apin);
 Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
  
if(DHT.temperature < reftemp && DHT.humidity > refhumidity) // if temp is lower than reference temp
{

digitalWrite(motor, LOW);
digitalWrite(led, LOW);
}
if(DHT.temperature >= reftemp && DHT.humidity <= refhumidity) // if temperature is higher than reference temp
{

digitalWrite(motor, HIGH); // spin the motor 
digitalWrite(led, HIGH);
delay(10000);

}
 

 
lcd.print("TEMP    : ");
lcd.print(DHT.temperature); // display the temperature
lcd.print("C ");
lcd.setCursor(0,1); // move cursor to next line);
lcd.print("HUMIDITY: ");
lcd.print(DHT.humidity); // display the temperature
lcd.print("% ");
delay(2000);
lcd.clear();
}
 