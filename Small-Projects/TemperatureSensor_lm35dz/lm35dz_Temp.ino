// Global variables
int reading;
int tempPin = 2;
int ledPin_high = 2;
int ledPin_low = 4;


// Setting everything up
void setup()
{
// Baud rate
  Serial.begin(9600);
  Serial.println('Starting...');
  
// Setting digital led ports as outputs
  pinMode(ledPin_high, OUTPUT);
  pinMode(ledPin_low, OUTPUT);
}


void loop()
{
// Reading from the analog pin connected to the lm35dz
  reading = analogRead(tempPin);
  
// Conversion to temperature
  float tCelsius = ( reading / 1024.0 )*500;
  float tFarh = ( tCelsius*9 )/5 + 32;
  
// This will light led red if bigger than 24 degrees
// and green otherwise.
  if ( tCelsius <= 24. )
  {
    digitalWrite(ledPin_low, HIGH);
    digitalWrite(ledPin_high, LOW);
  }
  else
  {
    digitalWrite(ledPin_high, HIGH);
    digitalWrite(ledPin_low, LOW);
  }
  
// Sending the temperature measurement throught serial port
  Serial.print("Temperature = ");
  Serial.print(tCelsius);
  Serial.print(" (oC)");
  Serial.println();
  
  
  delay(500);
}
