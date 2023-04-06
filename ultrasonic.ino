#include <NewPing.h>

#define TRIGGER_PIN_B  6
#define ECHO_PIN_B    9
#define TRIGGER_PIN_A  11
#define ECHO_PIN_A    10

// NewPing sonar(x, y);
// NewPing sonar2(x, y);

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN_A, OUTPUT);
  pinMode(ECHO_PIN_A, INPUT);
  pinMode(TRIGGER_PIN_B, OUTPUT);
  pinMode(ECHO_PIN_B, INPUT);
  delay(100);
}

void loop() {
  long duration1, distance1;
  long duration2, distance2;
  digitalWrite(TRIGGER_PIN_A, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(TRIGGER_PIN_A, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(TRIGGER_PIN_A, LOW);
  duration1 = pulseIn(ECHO_PIN_A, HIGH);
  distance1 = (duration1/2) / 29.1;

  if (distance1 > 50){
    distance1 = 50;
  }
  

  digitalWrite(TRIGGER_PIN_B, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(TRIGGER_PIN_B, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(TRIGGER_PIN_B, LOW);
  duration2 = pulseIn(ECHO_PIN_B, HIGH);
  distance2= (duration2/2) / 29.1;

  if (distance2 > 50){
    distance2 = 50;
  }

Serial.print("Distance A is:"  );
Serial.print(distance1 );
Serial.println( "cm");
Serial.print("Distance B is:"  );
Serial.print( distance2);
Serial.println( "cm");
 delay(100);
}




