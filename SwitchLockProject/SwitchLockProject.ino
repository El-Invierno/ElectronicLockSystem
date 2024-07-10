#include <Servo.h>
Servo myservo;

void setup()
{
  // Declaration of the reset pin:-
  Serial.begin(9600);
  // Declaration of input pins:-
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  
  // Declaration of output pins:-
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  // Declaration of the Servo pin:-
  myservo.write(0);
  myservo.attach(6);
  
  // Arduino program start sign:-
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  delay(3000);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(3000);
  
  // Time to enter the passcode:-
  digitalWrite(11,HIGH);
  delay(10000); // 10 seconds to display green light!
  digitalWrite(11,LOW);
  
  Serial.print(1);
  // Comparison of the switch states and verify pass:-
  if(digitalRead(2) == HIGH)
  {
    Serial.print(2);
    if(digitalRead(3) == LOW)
    {
      Serial.print(3);
      if(digitalRead(4) == HIGH)
      {
        Serial.print(4);
        if(digitalRead(5) == LOW)
        {
          Serial.print(5);
          Serial.print(6);
          long int num = 2147483647;
          while(num--)
          {
            int val;
            val = analogRead(A1);
            map(val,0,1023,0,90);
            myservo.write(val);
            delay(1000);
            // Manually reset once done!!
          }
        
        }
        else
        {
          digitalWrite(7,HIGH);
          delay(3000);
          digitalWrite(7,LOW);
        }
      }
      else
      {
        digitalWrite(7,HIGH);
        delay(3000);
        digitalWrite(7,LOW);
      }
      
    }
    else
    {
      digitalWrite(7,HIGH);
      delay(3000);
      digitalWrite(7,LOW);
    }
  
}
else
{
  digitalWrite(7,HIGH);
  delay(3000);
  digitalWrite(7,LOW);
}
}

void loop()
{
  
}
