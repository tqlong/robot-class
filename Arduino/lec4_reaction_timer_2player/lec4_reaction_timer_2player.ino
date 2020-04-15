#define BLUE 0
#define RED 1
#define GREEN 2
#define ON true
#define OFF false
#define n_output_led 3
#define BUTTON 0
#define BUTTON2 1

int leds[] = { 13, 12, 11 };
int input_leds[] = { 3, 5 };
int waitTime;
int startTime;
int reactTime;
bool player2Win, player1Win;

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
  int config[] = { 1, 0, 0 };
  display_configuration(config, 1); 
  startTime = millis();
  
  while ( is_button_not_pressed(BUTTON) && is_button_not_pressed(BUTTON2) ) {}
  reactTime = millis() - startTime;
  player2Win = is_button_not_pressed(BUTTON);
  player1Win = is_button_not_pressed(BUTTON2);

  if (player2Win && player1Win) {
    int config[] = { 0, 1, 1 };
    display_configuration(config, 100); 
  } else if (player2Win) {
    int config[] = { 0, 1, 0 };
    display_configuration(config, 100); 
  } else {
    int config[] = { 0, 0, 1 };
    display_configuration(config, 100); 
  }
  Serial.print("Your reaction time is ");
  Serial.print(reactTime);
  Serial.println(" milliseconds.");
}
