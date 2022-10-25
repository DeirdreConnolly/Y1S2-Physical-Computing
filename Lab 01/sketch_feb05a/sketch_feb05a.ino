
// named constant for the pin the sensor is connected to
const int SENSOR_PIN = A0;
int sensorVal;
float voltage, temperature, baselineTemp;
// room temperature in Celsius
const float BASELINE_TEMP = 20.0;
void setup() {
  // open a serial connection to display values
  Serial.begin(9600);
  // set the LED pins as outputs
  // the for() loop saves some extra coding
  for (int pinNumber = 2; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}
void loop() {
  sensorVal = analogRead(SENSOR_PIN);
  // read the value on AnalogIn pin 0 and store it in a variable
  // send the 10-bit sensor value out the serial port
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  // convert the ADC reading to voltage
  float voltage = (sensorVal / 1023.0) * 5.0;
  // Send the voltage level out the Serial port
  Serial.print(", Volts: ");
  Serial.print(voltage);
  // convert the voltage to temperature in degrees C
  // the sensor changes 10 mV per degree
  // the datasheet says there’s a 500 mV offset
  // ((voltage - 500mV) times 100)
  Serial.print(", Degrees C: ");
  float temperature = (voltage - 0.5) * 100;
  Serial.print(temperature);
  // if the current temperature is less than 2 degrees above the baseline
  // turn off all LEDs
  if (temperature < BASELINE_TEMP + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } // if the temperature rises 2-4 degrees, turn an LED on
  else if (temperature < BASELINE_TEMP + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } // if the temperature rises 4-6 degrees, turn a second LED on
  else if (temperature < BASELINE_TEMP + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } // if the temperature rises more than 6 degrees, turn all LEDs on
  else if (temperature < BASELINE_TEMP + 8) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  else {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(500); // wait for a half second
  }
  delay(1);
  if (temperature > BASELINE_TEMP) {
    Serial.print(", ");
    Serial.print(temperature - BASELINE_TEMP);
    Serial.println(" degrees above baseline");
  }
  else if (temperature < BASELINE_TEMP) {
    Serial.print(", ");
    Serial.print(BASELINE_TEMP - temperature);
    Serial.println(" degrees below baseline");
  }
}
