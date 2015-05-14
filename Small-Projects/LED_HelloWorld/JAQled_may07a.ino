// Ping of the LED's positive leg
int ledPin=12;

int tempo=500;
int intervalo=250;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // J
  digitalWrite(ledPin, HIGH);
  delay(tempo/2);
  digitalWrite(ledPin, LOW);
  delay(intervalo);
  digitalWrite(ledPin, HIGH);
  delay(tempo);
  digitalWrite(ledPin, LOW);
  delay(intervalo);
  digitalWrite(ledPin, HIGH);
  delay(tempo);
  digitalWrite(ledPin, LOW);
  delay(intervalo);
  digitalWrite(ledPin, HIGH);
  delay(tempo);
  digitalWrite(ledPin, LOW);
  delay(intervalo);

  
  // A
  digitalWrite(ledPin, HIGH);
  delay(tempo/2);
  digitalWrite(ledPin, LOW);
  delay(intervalo);
  digitalWrite(ledPin, HIGH);
  delay(tempo);
  digitalWrite(ledPin, LOW);
  delay(intervalo);
  
  // Q
  digitalWrite(ledPin, HIGH);
  delay(tempo);
  digitalWrite(ledPin, LOW);
  delay(intervalo);
  digitalWrite(ledPin, HIGH);
  delay(tempo);
  digitalWrite(ledPin, LOW);
  delay(intervalo);
  digitalWrite(ledPin, HIGH);
  delay(tempo/2);
  digitalWrite(ledPin, LOW);
  delay(intervalo);
  digitalWrite(ledPin, HIGH);
  delay(tempo);
  digitalWrite(ledPin, LOW);
  delay(intervalo);
}

