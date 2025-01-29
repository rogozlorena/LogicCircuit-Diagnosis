int timer = 3000;
boolean circuitOK;
int rez;
void setup() {
  pinMode(7, OUTPUT);    // a line
  pinMode(6, OUTPUT);    // b line
  pinMode(5,OUTPUT);    // c line
  pinMode(4,OUTPUT);    // d line 
  pinMode(3,OUTPUT);    // e line
  pinMode(8, INPUT);    // z line
  Serial.begin(9600);    //start serial communication @9600 bps
  }

void loop(){
      /*       
      test the circuit with the following test set
      01000->0,11111->0
      */
      circuitOK = true;
      for (int thisTest = 1; thisTest <3; thisTest++){
          if (thisTest == 1){
            //write values on input lines
            digitalWrite(7, LOW); //a line
            digitalWrite(6, HIGH); //b line
            digitalWrite(5, LOW); //c line
            digitalWrite(4, LOW);   //d line
            digitalWrite(3, LOW);   //e line
            delay(timer);
            //read z line value
            rez = digitalRead(8); 
            if (rez != 0){
              circuitOK = false;
            }
          }
          if (thisTest == 2){
            digitalWrite(7, HIGH); //a line
            digitalWrite(6, HIGH); //b line
            digitalWrite(5, HIGH); //c line
            digitalWrite(4, HIGH); //d line
            digitalWrite(3, HIGH);  // e line
            delay(timer);
            rez = digitalRead(8);
            if (rez != 0){
              circuitOK = false;
            }          
          }
      }
}
