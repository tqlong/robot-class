#include <Servo.h>

#define PHOTORESISTOR 0
#define RED 0
#define BLUE 1
#define GREEN 2
#define ON true
#define OFF false
#define SERVO_PIN 3

int analog_pin[] = {A0};
int digital_pin[] = {9, 11, 10};
Servo servo;

void setup() {
//  pinMode(digital_pin[RED], OUTPUT);
//  pinMode(digital_pin[GREEN], OUTPUT);
//  pinMode(digital_pin[BLUE], OUTPUT);
  servo.attach(SERVO_PIN);
  Serial.begin(9600);
}

int read_photoresistor()
{
  // read photo resistor voltage
  return analogRead(analog_pin[PHOTORESISTOR]);
}

void turn(int pin_index, bool on)
{
  digitalWrite(digital_pin[pin_index], on ? HIGH : LOW);
}

void show_RGB(int r, int g, int b)
{
  // use PWM to write color value to RED, GREEN, BLUE pins
  analogWrite(digital_pin[RED], r);
  analogWrite(digital_pin[GREEN], g);
  analogWrite(digital_pin[BLUE], b);
}

void loop() {
  int voltage = read_photoresistor();
  int color = 1023 - voltage; // more light when dark
  color = map(color, 0, 1023, 0, 255); // map color to [0,255] range
  show_RGB(color, color, color); // show the light using show_RGB() utility function
  Serial.println(voltage);

  int angle = map(voltage, 0, 1023, 20, 160);
  servo.write(angle);
  delay(50);

}
