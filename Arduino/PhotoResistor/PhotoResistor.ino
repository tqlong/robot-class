#define PHOTORESISTOR 0

int analog_pin[] = {A0};

void setup() {
  // put your setup code here, to run once:
  
}

int read_photoresistor()
{
  return analogRead(analog_pin[PHOTORESISTOR]);
}

void loop() {
  // put your main code here, to run repeatedly:

}
