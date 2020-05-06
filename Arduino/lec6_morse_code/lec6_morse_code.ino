#define LED 0
#define RESISTOR 0
#define ON true
#define OFF false

int digital_pin[] = { 11 };
int analog_pin[] = { A0 };
int dash_time = 500;

void setup() {
  pinMode(digital_pin[LED], OUTPUT);
  Serial.begin(9600);
}

void turn(int pin_index, bool on)
{
  digitalWrite(digital_pin[pin_index], on ? HIGH : LOW);
}

int read_resistor()
{
  return analogRead(analog_pin[RESISTOR]);
}

void show_led(int led_time)
{
  turn(LED, OFF);
  delay(50);
  turn(LED, ON);
  delay(led_time);
}

void display_morse_code(char c)
{
  int dot_dash_pattern[] = {
    21, // A
    1112, // B
    1212, // C
    112, // D
    1, // E
    1211, // F
    122, // G
    1111, // H
    11, // I
    2221, // J
    212, // K
    1121, // L
    22, // M
    12, // N
    222, // O
    1221, // P
    2122, // Q
    121, // R
    111, // S
    2, // T
    211, // U
    2111, // V
    221, // W
    2112, // X
    2212, // Y
    1122, // Z    
  };
  int index = c - 'A';
  int pattern = dot_dash_pattern[index];
  while (pattern > 0) {
    int dot_dash = pattern % 10;
    pattern /= 10;
    int led_time = dot_dash == 1 ? 200 : dash_time;
    Serial.println(dot_dash == 1 ? "dot" : "dash");
    show_led(led_time);
  }
}

void loop() {
  const char* text = "SOS";
  // hien thi text in Morse code
  // su dung do dai cua dash tu dien tro
  // da`i nhat = 2s
  // ngan nhat = 0,5s

  //turn(LED, OFF);
  int resistor_value = read_resistor();
//  delay(500);

  dash_time = map(resistor_value, 20, 1023, 500, 2000);
  Serial.println(dash_time);
  for (int i = 0; i < strlen(text); i++) {
    display_morse_code(text[i]);
  }
}
