  // MG811 CO2 Sensor Reading
  // Connect sensor's analog output to Arduino A0 pin
  // VCC to 5V, GND to GND

  const int CO2_PIN = A0;    // Analog pin for CO2 sensor
  const int SAMPLING_INTERVAL = 1000;  // 1 seconds interval

  // Calibration values - you may need to adjust these
  const float ZERO_POINT_VOLTAGE = 0.220;  // Voltage at 400ppm CO2 (fresh air)
  const float REACTION_VOLTAGE = 0.020;    // Voltage difference for each 100ppm change

  void setup() {
    Serial.begin(9600);  // Initialize serial communication
    Serial.println("MG811 CO2 Sensor Reading");
    Serial.println("Warming up sensor...");
    
    // Allow sensor to warm up (recommended)
    delay(3000);
  }

  void loop() {
    // Read analog value
    int sensorValue = analogRead(CO2_PIN);
    Serial.println(sensorValue);
    
    // Convert analog reading to voltage (0-5V)
    float voltage = sensorValue * (5.0 / 1023.0);
    
    // Calculate CO2 concentration (approximate)
    float co2ppm = calculatePPM(voltage);
    
    // Print results
    Serial.print("Voltage: ");
    Serial.print(voltage, 3);
    Serial.print("V   ");
    Serial.print("CO2 Concentration: ");
    Serial.print(co2ppm, 1);
    Serial.println(" ppm");
    
    // Wait for next reading
    delay(SAMPLING_INTERVAL);
  }

  float calculatePPM(float voltage) {
    if (voltage >= ZERO_POINT_VOLTAGE) {
      return ((voltage - ZERO_POINT_VOLTAGE) / REACTION_VOLTAGE) * 100.0 + 400.0;
    } else {
      return 400.0;  // Fresh air baseline
    }
  } 