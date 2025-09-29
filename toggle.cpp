int xPin = A0;      //Set up pins to recieve input
int yPin = A1;
int buttonPin = 7;

int upLED = 10; //Set up pins that will output for LED
int downLED = 6;
int leftLED = 11;
int rightLED = 5;

void setup() {

  pinMode(upLED, OUTPUT); //I set up Pins as output of electricity
  pinMode(downLED, OUTPUT);
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP); //This is pin which will be 0 or 1
}

void loop() {

  int xVal = analogRead(xPin); //Variables that will recieve input to read
  int yVal = analogRead(yPin);
  boolean button = digitalRead(buttonPin);

  int upPWM = map(yVal, 511, 0, 0, 255); //Translation from toggle stick to LED power
  int downPWM = map(yVal, 511, 1023, 0, 255);
  int leftPWM = map(xVal, 511, 0, 0, 255);
  int rightPWM = map(xVal, 511, 1023, 0, 255);

  if (yVal <= 511) { //if statements to light up the correct position of toggle 
    analogWrite(upLED, upPWM);
  }

  if (yVal >= 511) {
    analogWrite(downLED, downPWM);
  }

  if (xVal <= 511) {
    analogWrite(leftLED, leftPWM);
  }

  if (xVal >= 511) {
    analogWrite(rightLED, rightPWM);
  }

  if (button == LOW) { //If toggle is pressed all light up
    digitalWrite(upLED, HIGH);
    digitalWrite(downLED, HIGH);
    digitalWrite(leftLED, HIGH);
    digitalWrite(rightLED, HIGH);
  }
