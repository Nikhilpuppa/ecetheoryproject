#include<Servo.h>
Servo sr;
int servoLimitHigh=180;
int servoLimitLow=10;

const int stepPin = 5;

const int dirPin  = 2;

const int enPin  = 8;

 int photopin1,photopin2,photopin3,photopin4;
 int p = A0;
 int q = A1;
 int r = A2;
 int s = A3;


void setup() {
  Serial.begin(9600);
  
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  // digitalWrite(dirPin,HIGH);

  sr.attach(9);


  pinMode(p,INPUT);
  pinMode(q,INPUT);
  pinMode(r,INPUT);
  pinMode(s,INPUT);

  delay(5000);
}


void loop()
{
  int servo_val=sr.read();

  photopin1=analogRead(p);
  photopin2=analogRead(q);
  photopin3=analogRead(r);
  photopin4=analogRead(s);

  Serial.print(photopin1);
  Serial.print(",");
  Serial.print(photopin2);
  Serial.print(",");
  Serial.print(photopin3);
  Serial.print(",");
  Serial.println(photopin4);

  if(photopin2>photopin4+50)
  {
    sr.write(servo_val+2);
    if(servo_val>servoLimitHigh)
    {
      servo_val=servoLimitHigh;
    }
    delay(8);
  }
  else if(photopin2+50<photopin4)
  {
    sr.write(servo_val-2);
    if(servo_val<servoLimitLow)
    {
      servo_val=servoLimitLow;
    }        
    delay(8);
  }
  else
  {
    sr.write(servo_val);
  }

  if(photopin1>photopin3+50)
  {
    digitalWrite(dirPin,LOW);
    
    for(int i=0;i<9;i++)
    {
      digitalWrite(stepPin,HIGH);

      delayMicroseconds(1000);

      digitalWrite(stepPin,LOW);

      delayMicroseconds(1000);

    }

    delay(8);
  }
  else if(photopin1+50<photopin3)
  {
    digitalWrite(dirPin,HIGH);

    for(int j=0;j<9;j++)
    {
      digitalWrite(stepPin,HIGH);

      delayMicroseconds(1000);

      digitalWrite(stepPin,LOW);

      delayMicroseconds(1000);

    }

    delay(8);
  }
  else
  {
      digitalWrite(enPin,HIGH);
      delay(8);
      digitalWrite(enPin,LOW); 
  }
  delay(50);
}


