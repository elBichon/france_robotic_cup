const int sensorPin = A0;  // Analog input pin that senses Vout
int sensorValue = 0;       // sensorPin default value
float Vin = 5;             // Input voltage
float Vout = 0;            // Vout default value
float Rref = 1000;          // Reference resistor's value in ohms (you can give this value in kiloohms or megaohms - the resistance of the tested resistor will be given in the same units)
float R = 0;               // Tested resistors default value
int pattern = 0;

void setup ()
{
  Serial.begin(9600);      // Initialize serial communications at 9600 bps
}

void loop ()
{
  R = measureResistance(sensorPin,sensorValue,Vin,Vout,Rref,R);
  pattern = findPattern(R);
  Serial.println(pattern);   
}


float measureResistance(int sensorPin, int sensorValue, float Vin, float Vout, float Rref, float R){
  sensorValue = analogRead(sensorPin); // Read Vout on analog input pin A0 (Arduino can sense from 0-1023, 1023 is 5V)
  Vout = (Vin * sensorValue) / 1023;    // Convert Vout to volts
  R = Rref * (1 / ((Vin / Vout) - 1));  // Formula to calculate tested resistor's value                
  Serial.println(R);                    // Give calculated resistance in Serial Monitor for debugging, remove later
  return R;
}

int findPattern(float R){
  if(R > 850 and R < 1050){
    return 2;
  }
  else if(R > 900 and R < 1100){
    return 1;
  }
  else  if(R > 420 and R < 520){
    return 3;
  }
  else  if(R > 1300 and R < 1620){
    return 4;
  }
  else{
      return 0;
  }
}
