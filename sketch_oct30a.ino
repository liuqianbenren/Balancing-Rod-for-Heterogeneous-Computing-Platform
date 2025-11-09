#include"fuction.h"

int16_t raw_accel_x,raw_accel_y,raw_accel_z;
int8_t acccel_fault_x,acccel_fault_y,acccel_fault_z;
float accel_x,accel_y,accel_z;
//int16_t raw_angle_x,raw_angle_y,raw_angle_z;
//int16_t temp;
//angle_fault_x,angle_fault_y,angle_fault_z;
//float angle_x,angle_y,angle_z;

void setup() {

Serial.begin(115200);
void define_pinmode();
 
all_mpu6500_write_byte();
}

void loop() {

mpu6500_read();

/*angle_x = raw_angle_x/65.5;
angle_x = raw_angle_x/65.5;
angle_x = raw_angle_x/65.5;
Serial.print("accel_x:");
Serial.println(raw_accel_x);
Serial.print("accel_y:");
Serial.println(raw_accel_x);
Serial.print("accel_z:");
Serial.println(raw_accel_x);
delay(100);
Serial.print("x_angle:");
Serial.println(bx);
Serial.print("y_angle:");
Serial.println(by);
Serial.print("z_angle:");
Serial.println(bz);
delay(100);*/

/*digitalWrite(4,HIGH);
  delay(100);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(100);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  delay(100);
  digitalWrite(6,LOW);*/
}
