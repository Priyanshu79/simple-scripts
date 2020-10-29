
int R2=2000;
int R0=34000;
float sensor_volt;
float RS_gas;


void setup ()
{
Serial.begin(9600);
}

void loop ()
{

  float sensorValue = analogRead(1);
  sensor_volt=(float)sensorValue/1024*5.0;
  RS_gas = ((5.0 * R2)/sensor_volt) - R2;
  R0 = RS_gas / 1;
  Serial.print("R0: ");
  Serial.println(R0);
  
//411 ppm is the average co2 ppm in clean air today

delay(1000);
}
