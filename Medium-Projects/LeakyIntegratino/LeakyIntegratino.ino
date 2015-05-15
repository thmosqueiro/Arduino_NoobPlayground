// Integer
int t = 0;
double dt = 0.01;

double V0     = 0.0; // resting potential
double Vm     = 0.0; // membrane potential
double Vth    = 1.0; // threshold potential
double Vr     = 0.0; // resetting potential
double g      = 2.0; //
int inCurrent = 0;   // input current

double PulseAmplitude = 5.0; // amplitude of the button pulse
double noiseAmplitude = .8;  // noise amplitude
double R = 0;                // noise variable

// Spiked in the last t_rest period flag
double t_rest = 0.5;          // refractory period
double last_spike = -100.;    // last spike timing
boolean Not_Resting = true;   // refractory period flag


// Digital Pins setup
int ledPin_spikesign = 5;  // LED showing spikes
int readInterrupt    = 2;  // Probing pin
int ledPin_inputSPK  = 3;  // Output LED pin

// Temperature sensor
int tempPin = 1;        // Analog temperature sensor pin
int reading;            // Reading from sensor
float NersntEffectCons = 0.01;


// Analogical output
int outputPin = 6;


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
  pinMode(outputPin, OUTPUT);
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
  V0 = (Temp - 298)*NersntEffectCons;
  
  // Reading from the button
  inCurrent = 1 - digitalRead(readInterrupt);
  digitalWrite(ledPin_inputSPK, inCurrent);
  
  // Updating the input current
  double I = .2 + inCurrent*PulseAmplitude;
  
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
    // Ensuring a refractory period
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
  // Printing result through serial port
  Serial.print(t*dt, 2);
  Serial.print(" ");
  Serial.print(V0, 2);
  Serial.print(" ");
  Serial.println(Vm, 8);
  
  // Updating the analogical output (using PWM)
  analogWrite(outputPin, min(max(20,Vm*250),240) );
  
  delay(30);
}

