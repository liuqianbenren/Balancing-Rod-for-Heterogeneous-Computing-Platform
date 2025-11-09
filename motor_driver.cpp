#include"fuction.h"


void define_pinmode(void)
{

  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT); 
  pinMode(PWMB,OUTPUT);
  delay(10);
}

void A_motor_forward(void)
{
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed);
}

void B_motor_forward(void)
{
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, speed);
}


void A_motor_backward(void)
{
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  analogWrite(PWMA, speed);
}
void B_motor_backward(void)
{
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
  analogWrite(PWMB, speed);
}


void A_motor_break(void)
{
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,HIGH);  
}

void B_motor_break(void)
{
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,HIGH);  
}


void B_motor_stop(void)
{
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,LOW);  
}

void A_motor_stop(void)
{
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,LOW);  
}

void move_straight(void)
{
  A_motor_forward();
  B_motor_forward();
}

void move_right(void)
{
  A_motor_forward();
  B_motor_backward();
}

void move_left(void)
{  
  A_motor_backward();
  B_motor_forward();
}

void Emergency_brake(void)
{
  A_motor_break();
  B_motor_break();
}

void command_stop(void)
{
  A_motor_stop();
  B_motor_stop();
}













