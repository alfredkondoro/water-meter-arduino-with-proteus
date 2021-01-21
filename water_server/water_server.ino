int submitbutton = 3;
int statesubmit = 0;
void setup() {
  pinMode(submitbutton, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  statesubmit= digitalRead(submitbutton);
  if(statesubmit == HIGH){
    Serial.write(2);
  }
}
