//                     ________      _______      _______      _______      _______                         _______      
//  \              /   |       \        |            |            |         |            |\    |            |      \      \    /
//   \            /    |       |        |            |            |         |            | \   |            |      /       \  /
//    \    /\    /     |______/         |            |            |         -----        |  \  |            |------         \/
//     \  /  \  /      |    \           |            |            |         |            |   \ |            |      \        |
//      \/    \/       |     \          |            |            |         |            |    \|            |      /        |
//                                   -------                                -------                         -------

//   _________                   ________                 _______       ________      _______
//       |          |      |     |       \      |  /      |             |       |        |    
//       |          |      |     |       |      | /       |             |_______|        |
//       |          |      |     |______/       |/        -------|      |       |        |
//       |          |      |     |    \         |\               |      |       |        |
//       |          \______/     |     \        | \       _______|      |       |        |        (KEREM OKUMUS)
//     



//Knopfstatus!
int switchState = 0;

//PINS-ANGABE!
int AR = 2;
int AGe = 3;
int AGr = 4;

int IAR = 5;
int IAGe = 6;
int IAGr = 7;

int FR = 8;
int FG = 9;

int switchPin = 10;

//ENDE PINS-ANGABE!


int timer = 0;
int wurdeGedrueckt = 0;
int timerout = 0;


void setup() {
  // put your setup code here, to run once:
  //FÜR SERIAL MONITOR!
  Serial.begin(9600);
  //ENDE SERIAL MONITOR!

  //PIN-AUFGABEN-VERTEILER!

  pinMode(AR, OUTPUT);
  pinMode(AGe, OUTPUT);
  pinMode(AGr, OUTPUT);
  pinMode(FR, OUTPUT);
  pinMode(FG, OUTPUT);
  pinMode(IAR, OUTPUT);
  pinMode(IAGe, OUTPUT);
  pinMode(IAGr, OUTPUT);
  pinMode(switchPin, INPUT);

  //ENDE PIN-AUFGABEN-VERTEILER!

  //START VON AMPEL!

  //FÜR SERIAL MONITOR!
  Serial.write("Initializierung!");
  //ENDE SERIAL MONITOR!

  //ANFANG AMPEL-WERDEGRUEN
  werdeGruen();
}

void loop() {
  // switchState den echten Wert des Knopfs angeben!
  switchState = digitalRead(switchPin);
  //WECHSLE ZU ERSATZ-SCHLEIFE!
  bleibeGruen();

}



//WERDEGRUEN-SEQUENZ!
void werdeGruen() {
  digitalWrite(AR, HIGH);
  digitalWrite(AGe, LOW);
  digitalWrite(AGr, LOW);
  digitalWrite(IAR, HIGH);
  digitalWrite(IAGe, LOW);
  digitalWrite(IAGr, LOW);
  digitalWrite(FR, HIGH);
  digitalWrite(FG, LOW);

  delay(2000);

  digitalWrite(AR, HIGH);
  digitalWrite(AGe, HIGH);
  digitalWrite(AGr, LOW);
  digitalWrite(IAR, HIGH);
  digitalWrite(IAGe, HIGH);
  digitalWrite(IAGr, LOW);
  digitalWrite(FR, HIGH);
  digitalWrite(FG, LOW);

  delay (random(2000, 4000));

  digitalWrite(AR, LOW);
  digitalWrite(AGe, LOW);
  digitalWrite(AGr, HIGH);
  digitalWrite(IAR, LOW);
  digitalWrite(IAGe, LOW);
  digitalWrite(IAGr, HIGH);
  digitalWrite(FR, HIGH);
  digitalWrite(FG, LOW);
  delay(3000);

  bleibeGruen();
}

void bleibeGruen() {
  for (;;) {
    switchState = digitalRead(switchPin);

    if (switchState ==  HIGH  ||  wurdeGedrueckt > 0) {
      wurdeGedrueckt = 0;
      digitalWrite(AR, LOW);
      digitalWrite(AGe, LOW);
      digitalWrite(AGr, HIGH);
      digitalWrite(FR, HIGH);
      digitalWrite(FG, LOW);
      delay(3000);

      digitalWrite(AR, LOW);
      digitalWrite(AGe, HIGH);
      digitalWrite(AGr, LOW);
      digitalWrite(FR, HIGH);
      digitalWrite(FG, LOW);

      delay(3000);

      digitalWrite(AR, HIGH);
      digitalWrite(AGe, LOW);
      digitalWrite(AGr, LOW);
      digitalWrite(FR, HIGH);
      digitalWrite(FG, LOW);

      delay(2000);

      digitalWrite(AR, HIGH);
      digitalWrite(AGe, LOW);
      digitalWrite(AGr, LOW);
      digitalWrite(FR, LOW);
      digitalWrite(FG, HIGH);

      delay(random(2000, 6000));

      digitalWrite(AR, HIGH);
      digitalWrite(AGe, LOW);
      digitalWrite(AGr, LOW);
      digitalWrite(FR, HIGH);
      digitalWrite(FG, LOW);

      delay(random(1000, 3000));



      digitalWrite(AR, HIGH);
      digitalWrite(AGe, HIGH);
      digitalWrite(AGr, LOW);
      digitalWrite(FR, HIGH);
      digitalWrite(FG, LOW);

      delay(random(1000, 3000));

      digitalWrite(AR, LOW);
      digitalWrite(AGe, LOW);
      digitalWrite(AGr, HIGH);
      digitalWrite(FR, HIGH);
      digitalWrite(FG, LOW);


    } else {
      digitalWrite(AR, LOW);
      digitalWrite(AGe, LOW);
      digitalWrite(AGr, HIGH);
      digitalWrite(FR, HIGH);
      digitalWrite(FG, LOW);
      timer ++;
      
      

      if (timer> 100000) {
          
        standby();
      }
    }

  }
}


void standby() {

  if (switchState ==  HIGH) {
    bleibeGruen();
    wurdeGedrueckt = 1;
  } else {
if (switchState ==  HIGH) {
    bleibeGruen();
    wurdeGedrueckt = 1;
  }
    digitalWrite(AR, LOW);
    digitalWrite(AGe, HIGH);
    digitalWrite(AGr, LOW);
    digitalWrite(FR, LOW);
    digitalWrite(FG, LOW);
if (switchState ==  HIGH) {
    bleibeGruen();
    wurdeGedrueckt = 1;
  }
    delay(500);
if (switchState ==  HIGH) {
    bleibeGruen();
    wurdeGedrueckt = 1;
  }
    digitalWrite(AR, LOW);
    digitalWrite(AGe, LOW);
    digitalWrite(AGr, LOW);
    digitalWrite(FR, LOW);
    digitalWrite(FG, LOW);
    delay(500);
  if (switchState ==  HIGH) {
    bleibeGruen();
    wurdeGedrueckt = 1;
  }  
//    timerout++;
//    pause();
//    if(timerout > 1000){
//      pause();
//    }
  }
}


//void pause(){
//  
//  if(switchState == HIGH){
//    wurdeGedrueckt = 1;
//    bleibeGruen();
//    
//  }else{
//    digitalWrite(AR, LOW);
//    digitalWrite(AGe, LOW);
//    digitalWrite(AGr, LOW);
//    digitalWrite(FR, LOW);
//    digitalWrite(FG, LOW);
//  }
//}
