/*
  NinePixel
*/

int pin_no[9] = {13, 12, 11, 10, 9, 8, 7, 6, 5};
int n_led = 9;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for (int i = 0; i < n_led; i++)
    pinMode(pin_no[i], OUTPUT);
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

void display_pattern(int pattern[9])
{
  for (int i = 0; i < n_led; i++)
    turn_led(i, pattern[i] > 0);
}

void wave(int delayTime)
{
  for (int i = 0; i < n_led; i++) turn_led(i, false);
  
  for (int i = 0; i < n_led; i++) {
    int prev = (i+n_led-1) % n_led;
    turn_led(prev, false);
    turn_led(i, true);
    delay(delayTime);
  }
}

void loop_through_pattern(int patterns[][9], int n_pattern, int delayTime)
{
  for (int p = 0; p < n_pattern; p++) {
    display_pattern(patterns[p]);
    delay(delayTime);
  }
}

void side_to_center(int delayTime)
{
  int patterns[][9] = {
    { 1, 0, 0, 0, 0, 0, 0, 0, 1},
    { 0, 1, 0, 0, 0, 0, 0, 1, 0},
    { 0, 0, 1, 0, 0, 0, 1, 0, 0},
    { 0, 0, 0, 1, 0, 1, 0, 0, 0},
    { 0, 0, 0, 0, 1, 0, 0, 0, 0},
    { 0, 0, 0, 1, 0, 1, 0, 0, 0},
    { 0, 0, 1, 0, 0, 0, 1, 0, 0},
    { 0, 1, 0, 0, 0, 0, 0, 1, 0},
  };
  loop_through_pattern(patterns, 8, delayTime);
}

void block3(int delayTime)
{
  int patterns[][9] = {
    { 1, 1, 1, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 1, 1, 1, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 1, 1, 1},
    { 0, 0, 0, 1, 1, 1, 0, 0, 0},
  };
  loop_through_pattern(patterns, 4, delayTime);
}

void blink_all(int delayTime)
{
  int patterns[][9] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0},
  };
  loop_through_pattern(patterns, 2, delayTime);
}

void consecutive(int delayTime)
{
  int patterns[][9] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 1, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 1, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 1, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 1, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 1, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 1, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 1, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 1},
  };
  loop_through_pattern(patterns, 11, delayTime);
}

void consecutive2(int delayTime)
{
  int patterns[][9] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 1, 1, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 1, 1, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 1, 1, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 1, 1, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 1},
    { 0, 0, 0, 0, 0, 0, 0, 1, 1},
    { 0, 0, 0, 0, 0, 1, 1, 0, 0},
    { 0, 0, 0, 1, 1, 0, 0, 0, 0},
    { 0, 1, 1, 0, 0, 0, 0, 0, 0},
    { 1, 0, 0, 0, 0, 0, 0, 0, 0},
  };
  loop_through_pattern(patterns, 12, delayTime);
}

void alternate_side(int delayTime)
{
  int patterns[][9] = {
    { 0, 0, 0, 0, 1, 0, 0, 0, 0},
    { 0, 0, 0, 1, 0, 0, 0, 0, 0},
    { 0, 0, 1, 0, 0, 0, 0, 0, 0},
    { 0, 1, 0, 0, 0, 0, 0, 0, 0},
    { 1, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 1, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 1, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 1, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 1, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 1, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 1, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 1},
    { 0, 0, 0, 0, 0, 0, 0, 1, 0},
    { 0, 0, 0, 0, 0, 0, 1, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 0, 0},
  };
  loop_through_pattern(patterns, 16, delayTime);
}

// the loop function runs over and over again forever
void loop() {
  // wave(50);
  // side_to_center(100);
  // block3(200);
  // blink_all(200);
  // consecutive(200);
  // consecutive2(200);
  alternate_side(100);
}
