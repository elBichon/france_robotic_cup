
const int sensorPin = A0;  // Analog input pin that senses Vout
int sensorValue = 0;       // sensorPin default value
float Vin = 5;             // Input voltage
float Vout = 0;            // Vout default value
float Rref = 1000;          // Reference resistor's value in ohms (you can give this value in kiloohms or megaohms - the resistance of the tested resistor will be given in the same units)
float R = 0;               // Tested resistors default value
int pattern = 0;
int i = 0;

void setup ()
{
  Serial.begin(9600);      // Initialize serial communications at 9600 bps
}

void loop ()
{
  while(i < 100){
    R = measureResistance(sensorPin,sensorValue,Vin,Vout,Rref,R);
    pattern = find_pattern(R);
    Serial.println(pattern);
    i++;
  } 
}


float measureResistance(int sensorPin, int sensorValue, float Vin, float Vout, float Rref, float R){
  sensorValue = analogRead(sensorPin); // Read Vout on analog input pin A0 (Arduino can sense from 0-1023, 1023 is 5V)
  Vout = (Vin * sensorValue) / 1023;    // Convert Vout to volts
  R = ceilf(Rref * (1 / ((Vin / Vout) - 1))); 
  return R;
}


int find_pattern(int R){
  if(R < 1000 and R > 900){//1000
      return 1000;
    }
  else if(R < 490 and R < 500){//2000
      return 2000;
    }
   else if(R < 650 and R < 700){//1470
      return 1470;
    }
    else if(R == 52){//470
      return 470;
    }
  }
