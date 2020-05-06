#include <Servo.h>

#define SENSOR_SERVO_PIN (A0+1)
#define SENSOR_ECHO_PIN (12)
#define SENSOR_TRIG_PIN (2)

Servo sensor_servo;

void setup() {
  // put your setup code here, to run once:
  sensor_servo.attach(SENSOR_SERVO_PIN);
  sensor_servo.write(90);
  pinMode(SENSOR_TRIG_PIN, OUTPUT);
  pinMode(SENSOR_ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void rot_servo(int delay_time = 100, int hop = 5, 
               int start_angle = 20, int stop_angle = 160, 
               int start_delay = 200) 
{ 
  sensor_servo.write(start_angle);
  delay(start_delay); 
  for (int angle = start_angle; angle <= stop_angle; angle = angle + hop) { 
    sensor_servo.write(angle);
    delay(delay_time); 
  }
} 

float get_distance()
{
  digitalWrite(SENSOR_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(SENSOR_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SENSOR_TRIG_PIN, LOW);
  
  unsigned long echo_time = pulseIn(SENSOR_ECHO_PIN, HIGH, 5000);
  float distance = (float) echo_time * 0.034 / 2;
  return distance; 
}

void rot_servo_and_map(int delay_time = 100, int hop = 5, 
               int start_angle = 20, int stop_angle = 160, 
               int start_delay = 200) 
{ 
  sensor_servo.write(start_angle);
  delay(start_delay); 
  for (int angle = start_angle; angle <= stop_angle; angle = angle + hop) { 
//    sensor_servo.write(angle);
    delay(delay_time); 
    float distance = get_distance();
    Serial.print(angle);
    Serial.print(" ");
    Serial.println(distance);
  }
} 

void loop() {
  // put your main code here, to run repeatedly:
//  rot_servo(30, 3, 50, 130, 1000);
  rot_servo_and_map(30, 1, 85, 95, 1000);
}
