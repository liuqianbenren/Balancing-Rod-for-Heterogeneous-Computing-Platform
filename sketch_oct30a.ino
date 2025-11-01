#include<Wire.h>
void mpu_write_byte(uint8_t reg,uint8_t value)
{
  
  Wire.beginTransmission(0x68);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}

void setup() {

Serial.begin(115200);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
delay(100);  
Wire.begin();
mpu_write_byte(0x6b,0x00);
delay(100);
mpu_write_byte(0x1a,0x03);
mpu_write_byte(0x1b,0x08);
mpu_write_byte(0x1c,0x08);
mpu_write_byte(0x1d,0x03);
}

void loop() {
Wire.beginTransmission(0x68);
Wire.write(0x3b);
Wire.endTransmission();


Wire.requestFrom(0x68,14);
int16_t raw_ax = Wire.read()<<8|Wire.read();
int16_t raw_ay = Wire.read()<<8|Wire.read();
int16_t raw_az = Wire.read()<<8|Wire.read();
int16_t temp = Wire.read()<<8|Wire.read();
int16_t angle_x = Wire.read()<<8|Wire.read();
int16_t angle_y = Wire.read()<<8|Wire.read();
int16_t angle_z = Wire.read()<<8|Wire.read();


float ax = raw_ax/8192.0;
float ay = raw_ay/8192.0;
float az = raw_az/8192.0;
float bx = angle_x/65.5;
float by = angle_y/65.5;
float bz = angle_z/65.5;

  digitalWrite(4,HIGH);
  delay(1000);
  digitalWrite(4,LOW);
  //digitalWrite(5,HIGH);
  //delay(ay*100);
  //digitalWrite(5,LOW);
  //digitalWrite(6,HIGH);
  //delay(az*100);
  //digitalWrite(6,LOW);

Serial.print("x:");
Serial.println(ax);
Serial.print("y:");
Serial.println(ay);
Serial.print("z:");
Serial.println(az);
delay(100);
Serial.print("x_angle:");
Serial.println(bx);
Serial.print("y_angle:");
Serial.println(by);
Serial.print("z_angle:");
Serial.println(bz);
delay(500);

}
