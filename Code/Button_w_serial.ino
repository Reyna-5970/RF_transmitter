// constants
const int buttonPin = 2;

// vars
int buttonState = 0;
char Str1[] = "Pressed";
char Str2[] = "Not Pressed";

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Serial.print(Str1);
  } else {
    Serial.print(Str2);
  }
}
