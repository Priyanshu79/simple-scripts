//Arduino code involved in automating PABS(Pollutants Automated Battling System? I do not remember the full form tbh ;-;)
//Made by Purity For Mankind (my team ahaha)

//remark on 29/10/2020:  Nostalgic code, dates back to 30 Nov 2019 XD



int e=7;
int f=600;

int pinmos1=2;
int pinmos2=3;

long unsigned int times;
float RS_gas = 0;
float ratio = 0;
float sensorValue = 0;
float sensor_volt = 0;
float R0 = 14000;

//sensor input PIN
int mqInput = A5;
//pull-down resistor value
int mqR = 3000 ;
//rO sensor value
long rO = 48000;

//sensor a coefficient value
float a = 116.6020682;
//sensor b coefficient value
float b = -2.769034857;


void setup() {
  Serial.begin(9600);
   

  pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
 
  delay(2000);
  Serial.println("Initialising...");
  Serial.println("=================");
}

void loop() {
   
   times=millis();

   //CO
   sensorValue = analogRead(A1);
   sensor_volt = sensorValue/1024*5.0;
   RS_gas = (5.0-sensor_volt)/sensor_volt;
   ratio = RS_gas/R0; 
   float x = 1538.46 * ratio;
   float ppm = pow(x,-1.709);
    Serial.print("  ");
   Serial.print("Carbon monoxide PPM: ");
   Serial.print(ppm);
  

  //CO2
   int adcRaw = analogRead(mqInput);
  long rS = ((1024.0 * mqR) / adcRaw) - mqR;
  float rSrO = (float)rS / (float)rO;
  float ppmc = a * pow((float)rS / (float)rO, b);
 if(ppmc<1000){
 Serial.print(' ');
 Serial.print("    Carbon dioxide PPM: ");
 Serial.println(ppmc);}
 else 
 {Serial.print("   Carbon dioxide PPM: ");
  Serial.println("OVER 1000");}
  delay(1000);

//logic
if (times>20000)
{if (ppm>e or ppmc>f){
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
delay (10000);}}
 
if (ppm<e or ppmc<f){
digitalWrite(2, LOW);
digitalWrite(3, LOW);
}


}
