#define LED 0
#define LED2 1
#define LED3 2
#define ON true
#define OFF false
#define n_output_led 3

int leds[] = { 13, 12, 11 };

void setup() {
  // put your setup code here, to run once:
  // PIN 13 nam canh PIN GND
  for (int i = 0; i < n_output_led; i++)
    pinMode(leds[i], OUTPUT);
  Serial.begin(9600);
}

void turn(int pin_index, bool on)
{
  digitalWrite(leds[pin_index], on ? HIGH : LOW);
}

void display_configuration(int config[], int delayTime)
{
  for (int i = 0; i < n_output_led; i++) {
    turn(i, config[i] > 0 ? ON : OFF);
  }
  delay(delayTime);
}

void display_chain(int configs[][n_output_led], int delayTimes[], int n_config)
{
  for (int i = 0; i < n_config; i++) {
    display_configuration(configs[i], delayTimes[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int configs[][n_output_led] = {
    { 0, 0, 1 },
    { 0, 1, 0 },
    { 1, 0, 0 },
  };
  int delayTimes[] = {4000, 1000, 2000};
  display_chain(configs, delayTimes, 3);
}
