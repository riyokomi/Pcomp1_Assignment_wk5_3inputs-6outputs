#include <Servo.h>

Servo myservo;
int pos = 0;

const int buttonPin1 = 2;
const int buttonPin2 = 3;

const int redLED = 7;

const int redPin = 13;
const int greenPin = 12;
const int bluePin = 11;

const int buzzer = 6;

int buttonState1 = 0;
int buttonState2 = 0;

void setup()
{
	//serial.begin(9600);
	myservo.attach(9);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 

  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop()
{
	int sensorValue = analogRead(A2);
	//Serial.println(sensorValue);
	pos = map(sensorValue, 0, 1023, 0, 180);
	myservo.write(pos);
 if(pos > 150)
 {
  digitalWrite(redPin, HIGH);
  }
  else
  {
    digitalWrite(redPin, LOW);
  }

 buttonState1 = digitalRead(buttonPin1);
 buttonState2 = digitalRead(buttonPin2);
 if(buttonState1 == HIGH)
 {
  digitalWrite(redLED, HIGH);
  digitalWrite(greenPin, HIGH);
  }
  else
  {
  digitalWrite(redLED, LOW);
  digitalWrite(greenPin, LOW);
  }

  if(buttonState2 == HIGH)
  {
    digitalWrite(bluePin, HIGH);
    analogWrite(buzzer, 128);
    }
   else
   {
    digitalWrite(bluePin, LOW);
    analogWrite(buzzer, 0);
    }
	delay(15);
}
