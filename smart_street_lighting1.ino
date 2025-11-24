#define LDR A0       
#define PIR 3        
#define LED 12       

int ldrValue;        
int motion;          // variable to store motion sensor reading

void setup() {
  pinMode(LDR, INPUT);    
  pinMode(PIR, INPUT);    
  pinMode(LED, OUTPUT);   
  Serial.begin(9600);     
}

void loop() {
  // read sensors
  ldrValue = analogRead(LDR); 
  motion = digitalRead(PIR);  
  // print sensor readings
  Serial.print("LDR: "); Serial.print(ldrValue);
  Serial.print(" | PIR: "); Serial.println(motion);

  
  if (ldrValue < 700) {        
    if (motion == HIGH) {
      digitalWrite(LED, HIGH);
    } else {
      analogWrite(LED, 100);   
    }
  } else {
    digitalWrite(LED, LOW);   
  }

  delay(500); 
}
