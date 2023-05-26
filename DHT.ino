#include <DHT.h>

#define outPin 8         // Defines pin number to which the DHT sensor is connected
#define ledPin 13        // Defines pin number to which the LED is connected

DHT DHT_U(8, DHT11);      // Creates a DHT object

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);   // Set the LED pin as an output
}

void loop() {
  delay(2000); // Wait two seconds

  DHT_U.read();

  float t = DHT_U.readTemperature();     // Read temperature
  float h = DHT_U.readHumidity();        // Read humidity

  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print("°C | ");
  Serial.print((t * 9.0) / 5.0 + 32.0);   // Convert Celsius to Fahrenheit
  Serial.println("°F ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("% ");
  Serial.println("");

  // Blink the LED based on temperature value
  if (t > 25.0) {
    digitalWrite(ledPin, HIGH);   // Turn on the LED
    delay(500);                   // LED on time
    digitalWrite(ledPin, LOW);    // Turn off the LED
    delay(500);                   // LED off time
  } else {
    digitalWrite(ledPin, LOW);    // Turn off the LED
    delay(1000);                  // Delay before next reading
  }
}
