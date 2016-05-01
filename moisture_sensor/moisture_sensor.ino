/*
 * Moisture Sensor
 * ---------------
 */

#define PIN_LED_DRYNESS 7
#define PIN_MOISTURE_SENSOR 0
#define MIN_VALUE_BEFORE_DRYNESS 350

#define DELAY 1000

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(PIN_LED_DRYNESS, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_LED_DRYNESS, LOW);

  // high value means dryness
  int sensorValue = analogRead(PIN_MOISTURE_SENSOR);

  Serial.println(sensorValue);

  // if the soil is too dry
  if (sensorValue > MIN_VALUE_BEFORE_DRYNESS)
  {
    Serial.println("Need more Water");
    digitalWrite(PIN_LED_DRYNESS, HIGH);
  }

  delay(DELAY);
}
