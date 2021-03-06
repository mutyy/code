#include <SoftwareSerial.h>
#include <Servo.h>   

Servo myservo1, myservo2, myservo3, myservo4; 

int bluetoothTx = 0;
int bluetoothRx = 1;  

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
myservo1.attach(6);
myservo2.attach(7);
myservo3.attach(8);
myservo4.attach(9);
Serial.begin(9600);  
bluetooth.begin(9600);  
}

void loop()
{
if (bluetooth.available() >= 2 ) 
{
unsigned int servopos = bluetooth.read(); 
unsigned int servopos1 = bluetooth.read(); 
unsigned int realservo = (servopos1 * 256) + servopos;  

if (realservo >= 1000 && realservo <= 1135) 
{
int servo1 = realservo;
servo1 = map(servo1, 1000, 1135, 0, 135);
myservo1.write(servo1);
Serial.println("Servo 1 ON");
Serial.println(servo1);
delay(10);
}

if (realservo >= 2000 && realservo <= 2135) { 

int servo2 = realservo;
servo2 = map(servo2, 2000, 2135, 0, 135);
myservo2.write(servo2);
Serial.println("Servo 2 ON");
Serial.println(servo2);
delay(10);
}

if (realservo >= 3000 && realservo <= 3135) { 
int servo3 = realservo;
servo3 = map(servo3, 3000, 3135, 0, 135);
myservo3.write(servo3);
Serial.println("Servo 3 ON");
Serial.println(servo3);
delay(10);

}

if (realservo >= 4000 && realservo <= 4135) {

int servo4 = realservo;
servo4 = map(servo4, 4000, 4135, 0, 135);
myservo4.write(servo4);
Serial.println("Servo 4 ON");
Serial.println(servo4);
delay(10);

}
}
}
