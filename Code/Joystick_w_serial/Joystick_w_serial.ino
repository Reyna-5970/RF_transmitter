// constants

// vars
int joystickAnalog0 = 0;
int joystickAnalog1 = 1;
int analog0val = 0;
int analog1val = 0;

int treatValue(int data) {
  return (data * 9 / 1024) + 48;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analog0val = analogRead(joystickAnalog0);
  delay(100);
  analog1val = analogRead(joystickAnalog1);

  Serial.print(treatValue(analog0val));
  Serial.println(treatValue(analog1val));
}
