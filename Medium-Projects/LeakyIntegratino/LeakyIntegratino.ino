// Integer
int t = 0;
double dt = 0.01;

double Vm  = 0.0;
double Vth = 1.0;
double Vr  = 0.0;
double g   = 1.0;
double PulseAmplitude = 5.0;

String content = "", reading = "";
char character;

// Spiked in the last t_rest period flag
double t_rest = 0.5;
double last_spike = -100.;
boolean Not_Resting = true;

int ledPin_spikesign = 5;
int readInterrupt    = 2;  // Probing pin
int ledPin_inputSPK  = 3;  // Output LED pin
int inCurrent        = 0;  // The input state

// Setting up the serial port
void setup() 
{
// Setting up baud rate
  Serial.begin(9600);
  
// Sending a first message
  Serial.println("Powered on.");
  
// Setting up the role of each pin
  pinMode(readInterrupt, INPUT);
  pinMode(ledPin_inputSPK, OUTPUT);
  pinMode(ledPin_spikesign, OUTPUT);
}

void loop() 
{
  // Resetting variables
  digitalWrite(ledPin_spikesign, LOW);
  
  // Reading from the button
  inCurrent = 1 - digitalRead(readInterrupt);
  digitalWrite(ledPin_inputSPK, inCurrent);
  
  // Updating the input current
  double I = .3 + inCurrent*PulseAmplitude;
  
  // Updating the membrane potential
  if ( Not_Resting )
  {
    Vm = Vm + dt*(-g*Vm + I);
  }
  else
  {
    Vm = Vr;
    
    if ( t*dt - last_spike > t_rest )
    {
      Not_Resting = true;
    }
  }
  
  // Threshold condition
  if ( Vm >= Vth )
  {
    Vm = 2.0;
    Not_Resting = false;
    last_spike = t*dt;
    digitalWrite(ledPin_spikesign, HIGH);
  }
  
  t++;
  Serial.print(t*dt, 2);
  Serial.print(" ");
  Serial.print(I, 2);
  Serial.print(" ");
  Serial.println(Vm, 8);
  
  delay(50);
}

