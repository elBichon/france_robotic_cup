const int echoPin = 2; // attach pin D2 Arduino to pin Echo of HC-SR04
const int trigPin = 3; //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
float THRESHOLD; //variable for the decision to stop or not
bool decision;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop() {
  distance = measureDistance(echoPin, trigPin);
  decision = dashDecision(distance,THRESHOLD);
}

float measureDistance(int echoPin, int trigPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  return distance;
}

bool dashDecision(float distance, float THRESHOLD){
  if(distance <= THRESHOLD){
    return false;
    }
  else{
    return true;
    }
  }
