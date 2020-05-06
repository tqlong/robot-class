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
  const char* dot_dash_pattern[] = {
    "12", // A
    "2111", // B
    "2121", // C
    "211", // D
    "1", // E
    "1121", // F
    "221", // G
    "1111", // H
    "11", // I
    "1222", // J
    "212", // K
    "1211", // L
    "22", // M
    "21", // N
    "222", // O
    "1221", // P
    "2212", // Q
    "121", // R
    "111", // S
    "2", // T
    "112", // U
    "1112", // V
    "122", // W
    "2112", // X
    "2122", // Y
    "2211", // Z    
  };
  int index = c - 'A';
  const char* pattern = dot_dash_pattern[index];
  for (int i = 0; i < strlen(pattern); i++) {
    int led_time = pattern[i] == '1' ? 200 : dash_time;
    Serial.println(pattern[i] == '1' ? "dot" : "dash");
    show_led(led_time);
  }
}

void display_text_in_morse(const char* text)
{
  for (int i = 0; i < strlen(text); i++) {
    display_morse_code(text[i]);
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

  dash_time = map(resistor_value, 20, 1023, 500, 2000);
  Serial.println(dash_time);
  display_text_in_morse(text);
}
