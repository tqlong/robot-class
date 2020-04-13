/*
  Reaction Timer for 2 players
*/

#define ON true
#define OFF false
#define PHOTORESISTOR_PIN A0
#define RED 0
#define BLUE 1
#define GREEN 2

int calibrationValue;
int pinNumber[] = {11, 10, 9};
int nPIN = 3;
int photoresistor_voltage;
int difference;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pinNumber[RED], OUTPUT);
  pinMode(pinNumber[GREEN], OUTPUT);
  pinMode(pinNumber[BLUE], OUTPUT);
  calibrationValue = analogRead(PHOTORESISTOR_PIN);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void set_led(int index, int value) {
  digitalWrite(pinNumber[index], value);
}

void set_rgb(int r, int g, int b) {
  analogWrite(pinNumber[RED], r);
  analogWrite(pinNumber[GREEN], g);
  analogWrite(pinNumber[BLUE], b);
}

// the loop function runs over and over again forever
void loop() {
  photoresistor_voltage = analogRead(PHOTORESISTOR_PIN);
  difference = photoresistor_voltage - calibrationValue;
//  Serial.print(photoresistor_voltage); Serial.print(" ");
//  Serial.print(calibrationValue); Serial.print(" ");
//  Serial.println(difference);

  if (difference < -50) {
    set_rgb(155, 196, 226);
  } else {
    set_rgb(0, 0, 0);
  }
}
