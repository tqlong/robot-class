#define LED 13
#define ON true
#define OFF false

void setup() {
  // put your setup code here, to run once:
  // PIN 13 nam canh PIN GND
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void turn(int pin, bool on)
{
  digitalWrite(pin, on ? HIGH : LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  turn(LED, ON);
  delay(500);
  turn(LED, OFF);
  delay(500);
}
