byte led_digit[8][7] = 
{
  { 1,0,0,0,0,0,0 },
  { 0,1,0,1,0,0,0 },
  { 0,0,1,0,1,0.0 },
  { 1,0,0,1,0,1,0 },
  { 0,1,1,0,0,0,1 },
  { 0,1,0,0,0,1,0 },
  { 1,0,0,0,1,0,0 },
  { 0,1,0,1,0,1,0 }
};

const int analogInPin = A0;
const int ledOutPin = 9;

int sensorValue = 0;
int outputValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void Show(int b){
  byte pin = 7;
  for(byte led = 0; led < 7; led++){
    digitalWrite(pin, led_digit[b][led]);
    pin++;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1000, 0, 10);
  
  for(byte b = 0; b < 8; b++){
    Show(b);
    delay(outputValue*20);
  }

  Serial.print("\nsensor = ");
  Serial.print(sensorValue);
  Serial.print(" output = ");
  Serial.print(outputValue);
}
