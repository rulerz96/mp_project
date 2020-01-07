const int TRIGPIN = 5;
const int ECHOPIN = 6;

const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

long DURATION;
int DISTANCE;

const int ON = 0;
const int OFF = 1;

void setup() {
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
 
  pinMode(BLUE,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(5);

  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIGPIN, LOW);

  DURATION = pulseIn(ECHOPIN, HIGH);

  DISTANCE = DURATION*0.034/2;

  Serial.println(DISTANCE);
  
  if (DISTANCE <= 10)
  {
    digitalWrite(BLUE, ON);
    digitalWrite(GREEN, OFF);
    digitalWrite(RED, OFF);
    delayMicroseconds(20);
  }
  else if (DISTANCE >= 11 && DISTANCE <= 20)
  {
    digitalWrite(BLUE, OFF);
    digitalWrite(GREEN, ON);
    digitalWrite(RED, OFF);
    delayMicroseconds(20);
  }
  else if (DISTANCE >= 21)
  {
    digitalWrite(BLUE, OFF);
    digitalWrite(GREEN, OFF);
    digitalWrite(RED, ON);
    delayMicroseconds(20);
  }
}
