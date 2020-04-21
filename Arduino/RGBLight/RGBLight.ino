#define n_digital_outs 3
#define RED 0
#define BLUE 1
#define GREEN 2
#define ON true
#define OFF false

#define n_analog 1
#define PHOTORESISTOR 0

int digital_out[] = { 11, 10, 9 };
int analog_pin[] = { A0 };
int calibrate_voltage;

void turn(int pin_index, bool on)
{
  digitalWrite(digital_out[pin_index], on ? HIGH : LOW);
}

int read_analog(int pin_index) 
{
  return analogRead(analog_pin[pin_index]);
}

int write_analog(int pin_index, int value)
{
  analogWrite(analog_pin[pin_index], value);
}

void show_configuration(int config[n_digital_outs])
{
  for (int i = 0; i < n_digital_outs; i++)
    turn(i, config[i] > 0 ? ON : OFF);
}

void show_rgb(int r, int g, int b)
{
  analogWrite(digital_out[RED], r);
  analogWrite(digital_out[GREEN], g);
  analogWrite(digital_out[BLUE], b);
}

void setup() {
  for (int i = 0; i < n_digital_outs; i++)
    pinMode(digital_out[i], OUTPUT);
  calibrate_voltage = read_analog(PHOTORESISTOR);
  Serial.begin(9600);
}

void loop() {
//  int config[] = {1, 1, 1};
//  show_configuration(config);
  
  int voltage = read_analog(PHOTORESISTOR);
  int diff = calibrate_voltage-voltage;
  int color = 20 + diff*2;
  color = (color > 255)?255:(color < 0? 0:color);
  show_rgb(color, color, color);
  Serial.println(diff);
  delay(200);
}
