int pbIn = 2;     // Probing pin
int ledOut = 3;   // Output LED pin
int state = 0;    // The input state
 
void setup()
{               
  // Setting up the role of each pin
  pinMode(pbIn, INPUT);
  pinMode(ledOut, OUTPUT);
}

void loop()                    
{
  // Probing the interruptor
  state = digitalRead(pbIn);
  // Sednging the inverse signal
  digitalWrite(ledOut, state);
  
  // Delay
  delay(50);
}
