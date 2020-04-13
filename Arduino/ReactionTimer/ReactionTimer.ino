/*
  NinePixel
*/

#define ON true
#define OFF false
#define LED 0
#define BUTTON 1
#define GREEN 2
#define RED 3

int pin_no[] = {13, 3, 12, 11};
int n_led = 4;
unsigned int waitTime, startTime, reactTime;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pin_no[LED], OUTPUT);
  pinMode(pin_no[BUTTON], INPUT);
  pinMode(pin_no[GREEN], OUTPUT);
  pinMode(pin_no[RED], OUTPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void turn_led(int index, bool on)
{
  digitalWrite(pin_no[index], on ? HIGH : LOW);
}

void blink_led(int index, int delayTime)
{
  turn_led(index, true);
  delay(delayTime);
  turn_led(index, false);
  delay(delayTime);
}

// the loop function runs over and over again forever
void loop() {
  randomSeed(analogRead(A5));
  Serial.println("When LED turns on, push the button!");
  
  waitTime = random(2000, 4000);
  delay(waitTime);
  turn_led(LED, ON);

  startTime = millis();
  while (digitalRead(pin_no[1]) == HIGH) { }

  reactTime = millis() - startTime;
  turn_led(LED, OFF);
  if (reactTime <= 300) {
    turn_led(GREEN, ON);
    turn_led(RED, OFF);
  } else {
    turn_led(RED, ON);
    turn_led(GREEN, OFF);
  }
  Serial.print("Nice job! Your reaction time was ");
  Serial.print(reactTime);
  Serial.println(" milliseconds.");
}
