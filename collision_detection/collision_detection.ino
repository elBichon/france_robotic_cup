int Led = 13; // Led intégré connectée à la broche 13. 
int Microrupteur = 5; // Module GT032 à microrupteur connecté à la broche 13. 
int val; // Variable pour la lecture de l'état du microrupteur. 
 
void setup () { 
  pinMode (Led, OUTPUT); // Met la broche "Led" (donc la broche 13) en sortie. 
  pinMode (Microrupteur, INPUT); // Met la broche "Microrupteur" (donc la broche 5) en entrée. 
   
} 

void loop () { 
  bool collision = collision_detection(Microrupteur);
  } 

bool collision_detection(int microrupteur){
  val = digitalRead (Microrupteur);
  if (val == HIGH){ 
    return true;
    } 
  else { 
    return false;
    } 
  }
