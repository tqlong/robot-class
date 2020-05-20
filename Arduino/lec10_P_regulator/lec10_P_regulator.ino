#define LED 11
#define RESISTOR A0

void setLEDLevel(int level) {
  // level: 0 (off) - 255 (brightest)
  analogWrite(LED, level);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  setLEDLevel(255);
  Serial.begin(9600);
}

int getResistor() {
  return analogRead(RESISTOR);
}

float reference_point = 100; // r
float previous_output = 255;
float kp = .1;

float computePID(float y) {
  return kp * (reference_point - y);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int resistor = getResistor(); // y
  int output = previous_output + computePID(resistor); // u
  setLEDLevel(output);
  Serial.print(resistor);  
  Serial.print(" ");  
  Serial.println(output);
  delay(10);
  previous_output = output;
}
