// Setting up the serial port
void setup() 
{
// Setting up baud rate
  Serial.begin(9600);
  
// Sending a first message
  Serial.println("Powered on.");
}


// Integer
int a = 0;
String content = "", reading = "";
char character;


void loop() 
{
  // Printing a string
  Serial.println("Hello world");
  
  if ( Serial.available() )
  {
    content = "";
  }
  while( Serial.available() )
  {
    character = Serial.read();
    content.concat(character);
  }
  
  // Printing integer + what's been read before
  a++;
  Serial.print(a);
  Serial.print(" - ");
  Serial.println(content);
  
  delay(200);
}
