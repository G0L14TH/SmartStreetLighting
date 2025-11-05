#define LDR A0       // LDR sensor connected to analog pin A0
#define PIR 3        // PIR motion sensor connected to digital pin 3
#define LED 12       // LED streetlight connected to digital pin 12

int ldrValue;        // variable to store light sensor reading
int motion;          // variable to store motion sensor reading

void setup() {
  pinMode(LDR, INPUT);    // set LDR pin as input
  pinMode(PIR, INPUT);    // set PIR pin as input
  pinMode(LED, OUTPUT);   // set LED pin as output
  Serial.begin(9600);     // start Serial Monitor for debugging
}

void loop() {
  // read sensors
  ldrValue = analogRead(LDR); // read light level (0–1023)
  motion = digitalRead(PIR);  // read motion state (0 or 1)

  // print sensor readings
  Serial.print("LDR: "); Serial.print(ldrValue);
  Serial.print(" | PIR: "); Serial.println(motion);

  // control LED based on conditions
  if (ldrValue < 700) {        // it's dark
    if (motion == HIGH) {
      digitalWrite(LED, HIGH); // light ON when motion detected
    } else {
      analogWrite(LED, 100);   // dim light when no motion
    }
  } else {
    digitalWrite(LED, LOW);    // turn off light during daytime
  }

  delay(500); // short delay for stability
}
