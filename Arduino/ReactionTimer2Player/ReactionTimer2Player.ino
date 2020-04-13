/*
  Reaction Timer for 2 players
*/

#define ON true
#define OFF false
#define LED 0
#define BUTTON1 1
#define GREEN 2
#define RED 3
#define BUTTON2 4

int pin_no[] = {13, 3, 12, 11, 2};
int n_led = 5;
unsigned int waitTime, startTime, reactTime, bestReactionTime = 0;
bool isPlayer1Win;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pin_no[LED], OUTPUT);
  pinMode(pin_no[BUTTON1], INPUT);
  pinMode(pin_no[GREEN], OUTPUT);
  pinMode(pin_no[RED], OUTPUT);
  pinMode(pin_no[BUTTON2], INPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void turn_led(int index, bool on)
{
  digitalWrite(pin_no[index], on ? HIGH : LOW);
}

bool is_on(int index)
{
  return digitalRead(pin_no[index]) == HIGH;
}

// the loop function runs over and over again forever
void loop() {
  randomSeed(analogRead(A5));
  Serial.println("When LED turns on, push the button!");
  
  waitTime = random(2000, 4000);
  delay(waitTime);
  turn_led(LED, ON);

  startTime = millis();
  while (is_on(BUTTON1) && is_on(BUTTON2) ) { }
  isPlayer1Win = !is_on(BUTTON1);

  reactTime = millis() - startTime;
  turn_led(LED, OFF);
  if (isPlayer1Win) {
    turn_led(GREEN, ON);
    turn_led(RED, OFF);
  } else {
    turn_led(RED, ON);
    turn_led(GREEN, OFF);
  }
  Serial.print(isPlayer1Win ? "Player 1 won. " : "Player 2 won. ");
  Serial.print("Reaction time was ");
  Serial.print(reactTime);
  Serial.println(" milliseconds.");
}
