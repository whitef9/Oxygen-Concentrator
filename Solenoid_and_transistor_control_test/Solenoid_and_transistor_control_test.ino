#define test 1

#define Button 13
#define Solenoid 12

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Button, INPUT);
  pinMode(Solenoid, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(Button))
  {
    if (test)
    {
      Serial.println("Button Pressed"); 
    }
    digitalWrite(Solenoid, HIGH);
  }
  else
  {
    digitalWrite(Solenoid,LOW);
  }
}
