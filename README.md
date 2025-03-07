# MG811 CO2 Sensor Arduino Project

This project uses an MG811 CO2 sensor with Arduino to measure and display CO2 concentration levels. The sensor can detect CO2 concentrations between 400ppm (fresh air) to 10000ppm.

## Hardware Requirements

- Arduino board (Uno, Nano, or similar)
- MG811 CO2 sensor module
- Jumper wires
- Power supply (6V) for the sensor
- Voltage regulator (to provide 6V to sensor)

## Power Supply Requirements

1. **For the Sensor (One of these options):**
   - Option 1: Dedicated 6V DC power adapter
   - Option 2: 9V battery with 6V voltage regulator
   - Option 3: 7-12V power supply with 6V voltage regulator

2. **For the Arduino (Separate from sensor power):**
   - USB connection
   - OR dedicated power supply (7-12V)

**Important**: Do NOT attempt to power the MG811 sensor through Arduino's power pins. The sensor's heater requires its own power source to function properly and avoid overloading the Arduino's voltage regulator.

## Wiring Connection

Connect the MG811 sensor to Arduino as follows:

| MG811 Pin | Connection |
|-----------|------------|
| VCC       | 6V power supply |
| GND       | GND (common ground with Arduino AND 6V power supply) |
| AOUT      | A0 (Arduino) |

**Important**: The MG811 sensor requires 6V for the heater to work properly. Do NOT connect it directly to Arduino's 5V pin. Use a separate 6V power supply or a voltage regulator to power the sensor. Make sure to connect ALL grounds together (Arduino, sensor, and 6V power supply) to establish a common reference point.

## Software Setup

1. Install the [Arduino IDE](https://www.arduino.cc/en/software)
2. Download the project files
3. Open `CO2_Sensor.ino` in Arduino IDE
4. Upload the code to your Arduino board

## Wiring Diagram

Connect the MG811 sensor module as follows:
1. Sensor VCC → 6V power supply positive terminal
2. Sensor GND → Common ground (connect ALL grounds together: Arduino GND, sensor GND, and 6V power supply GND)
3. Sensor AOUT → Arduino A0 pin

**Note**: It is essential that all grounds (Arduino, sensor, and power supply) are connected together. Without a common ground, the analog readings will be incorrect or unstable.

## Calibration

The sensor requires calibration for accurate readings. Current calibration values in the code:
- Zero point voltage: 0.220V (at 400ppm CO2)
- Reaction voltage: 0.020V (per 100ppm change)

You may need to adjust these values based on your specific sensor:

## Usage

1. Power up the Arduino and sensor
2. Wait for the 3-second warm-up period
3. Open Serial Monitor (Tools > Serial Monitor) at 9600 baud
4. Readings will display every 5 seconds showing:
   - Voltage reading
   - CO2 concentration in PPM

## Important Notes

1. The sensor needs about 48 hours for first-time preparation
2. Requires 3-5 minutes warm-up time for each power-up
3. Keep the sensor in stable temperature and humidity conditions
4. Avoid exposing the sensor to high concentrations of:
   - Alcohol
   - Toluene
   - Hydrogen
   - Carbon Monoxide

## Troubleshooting

1. No readings:
   - Check power connections
   - Verify analog pin connection
   - Ensure correct serial monitor baud rate (9600)

2. Inaccurate readings:
   - Allow proper warm-up time
   - Check calibration values
   - Ensure stable power supply
   - Avoid interference from other gases

## License

This project is open-source and available under the MIT License.

## Contributing

Feel free to submit issues and enhancement requests!