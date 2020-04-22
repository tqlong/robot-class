#define PHOTORESISTOR 0
#define RED 0
#define BLUE 1
#define GREEN 2
#define ON true
#define OFF false

int analog_pin[] = {A0};
int digital_pin[] = {9, 11, 10};

void setup() {
//  pinMode(digital_pin[RED], OUTPUT);
//  pinMode(digital_pin[GREEN], OUTPUT);
//  pinMode(digital_pin[BLUE], OUTPUT);
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
  analogWrite(digital_pin[RED], r);
  analogWrite(digital_pin[GREEN], g);
  analogWrite(digital_pin[BLUE], b);
}

void loop() {
  int voltage = read_photoresistor();
  int color = 1023 - voltage;
  color = map(color, 0, 1023, 0, 255);
  show_RGB(color, color, color);
  Serial.println(voltage);
  delay(1000);

}
