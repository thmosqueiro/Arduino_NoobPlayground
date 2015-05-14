// Integer
int t = 0;
double dt = 0.01;

double V0  = 0.0;
double Vm  = 0.0;
double Vth = 1.0;
double Vr  = 0.0;
double g   = 1.0;
double PulseAmplitude = 5.0;
double noiseAmplitude = .8;
double R = 0;

// Spiked in the last t_rest period flag
double t_rest = 0.5;
double last_spike = -100.;
boolean Not_Resting = true;

int ledPin_spikesign = 5;
int readInterrupt    = 2;  // Probing pin
int ledPin_inputSPK  = 3;  // Output LED pin
int inCurrent = 0;  // The input state

// Temperature sensor
int tempPin = 1;
int reading;
float NersntEffectiveCons = 0.05;

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
  
  
  // Reading the temperature
  reading = analogRead(tempPin);
  // Conversion to Kelvin
  float Temp = ( reading / 1024.0 )*500 + 273;
  // Updating resting potential
  V0 = (Temp - 298)*NersntEffectiveCons;
  
  // Reading from the button
  inCurrent = 1 - digitalRead(readInterrupt);
  digitalWrite(ledPin_inputSPK, inCurrent);
  
  // Updating the input current
  double I = .3 + inCurrent*PulseAmplitude;
  
  // Updating the membrane potential
  if ( Not_Resting )
  {
    R = sqrt(-2*log(random(100)/100.))*cos(2*1.14*random(100)/100.);
    R = min(R,.5);
    R = max(R,-.5);
    Vm = Vm + dt*(V0 - g*Vm + I + noiseAmplitude*R);
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
  Serial.print(V0, 2);
  Serial.print(" ");
  Serial.println(Vm, 8);
  
  delay(50);
}

