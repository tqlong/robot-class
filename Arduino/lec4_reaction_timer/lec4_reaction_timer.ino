#define BLUE 0
#define RED 1
#define GREEN 2
#define ON true
#define OFF false
#define n_output_led 3
#define BUTTON 0

int leds[] = { 13, 12, 11 };
int input_leds[] = { 3 };
int waitTime;
int startTime;
int reactTime;

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

bool is_button_not_pressed(int pin_index) {
  return digitalRead(input_leds[pin_index]) == HIGH;
}

void loop() {
  waitTime = random(1000, 5000);
  delay(waitTime);
  turn(BLUE, ON);
  turn(RED, OFF);
  startTime = millis();
  
  while ( is_button_not_pressed(BUTTON) ) {}
  reactTime = millis() - startTime;

  turn(RED, ON);
  turn(BLUE, OFF);
  Serial.print("Your reaction time is ");
  Serial.print(reactTime);
  Serial.println(" milliseconds.");
}
