☕ Coffee Fermentation Monitoring System (CFMS)
This project is a prototype for monitoring key variables in the coffee fermentation process using an ESP32 microcontroller. The system measures real temperature and simulates the pH reading to determine the optimal fermentation point and alert the user.

📝 Project Description
The goal is to create a low-cost device to help coffee growers standardize the quality of their product. The code monitors two critical conditions for fermentation:

Temperature: Read through a DHT22 sensor.

pH: Simulated using a potentiometer. This allows for testing the system's logic without needing a real pH sensor, which is more expensive and complex to handle.

When the temperature rises above 18°C and the (simulated) pH drops below 4.5, the system prints an alert, indicating that fermentation has reached its ideal point and it is time to proceed with washing the batch.

⚙️ Required Hardware
Microcontroller (an ESP32 is recommended for its 12-bit ADC).

DHT22 temperature and humidity sensor.

A Potentiometer (any value, like 10KΩ, will work well).

A breadboard and connecting wires (jumpers).

🚀 How It Works
The code is structured for the Arduino environment and performs the following tasks in a continuous loop:

Waits for 2 seconds between each measurement to avoid flooding the system.

Reads the temperature in Celsius from pin 15 using the DHT22 sensor.

Reads the analog value from the potentiometer (connected to pin 34). This value ranges from 0 to 4095.

Maps (converts) the potentiometer's value to a realistic pH range (from 8.0 down to 3.0). Turning the knob simulates the decrease in pH during fermentation.

Prints the temperature and simulated pH values to the Serial Monitor.

Evaluates the alert condition: If temperature > 18.0 AND phSimulado < 4.5, it displays a prominent message indicating that the process is complete.

🛠️ Setup and Usage
Connect the components according to the pins defined in the code:

DHT22 sensor to pin 15.

Potentiometer to pin 34.

Open the .ino file in the Arduino IDE.

Install the DHT library: Go to Tools > Manage Libraries... and search for and install the "DHT sensor library" by Adafruit.

Select the correct board (e.g., "ESP32 Dev Module") and COM port from the Tools menu.

Upload the code to your microcontroller.

Open the Serial Monitor (Tools > Serial Monitor) and set its speed to 115200 baud to see the real-time data.

By turning the potentiometer and slightly warming the sensor, you can simulate the conditions and see the alert being triggered.