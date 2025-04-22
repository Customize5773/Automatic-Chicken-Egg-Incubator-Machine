---

# Automatic-Chicken-Egg-Incubator-Machine 🐣

## Introduction 📚  
In line with the rapid development of modern times, the demand for animal protein among the population has significantly increased. Population growth and modernization have driven the need for more efficient and innovative production methods. However, conventional methods of hatching chicken eggs are still widely used, despite their relatively low success rate. This condition has sparked the search for alternative solutions to improve overall efficiency in the hatching process.

This is where the application of chicken egg incubators comes into play as an innovative option. These machines are designed to carry out the hatching process without direct involvement from the hen, enabling automated and integrated monitoring and control. Such technological approaches are expected not only to increase the number of successfully hatched eggs but also to extend the harvest period, positively impacting productivity and production efficiency.

Furthermore, the implementation of incubator technology provides an opportunity for critical evaluation of traditional hatching systems. By adopting the latest technologies, various challenges that have hindered the optimization of the hatching process, such as initial investment costs and system maintenance, can be addressed. In-depth academic discourse on this innovation also opens avenues for further research on automation mechanisms in farming, allowing the continuous adaptation of such technologies to meet the needs of the industry and society at large.

## Overview 📈  
This project is designed to assist chicken farm entrepreneurs in optimizing the egg-hatching process. By automating key parameters such as temperature and humidity, the hatching machine aims to boost the number of successfully hatched eggs. In doing so, it offers a pathway to stabilize the egg market prices through enhanced production efficiency.

## Purpose 🎯  
The primary goal of this project is to improve egg hatching production by introducing an intelligent, automated incubation system. Leveraging modern microcontrollers and sensor technology, the device monitors and regulates environmental conditions within the incubator. This refinement not only increases the egg quantity—thereby addressing supply issues—but also contributes to the overall stabilization of market prices for eggs.

## Materials 🛠️  

- **Plywood**    
  - Dimension: 40 cm (Length) x 25 cm (Width) x 30 cm (Height)  
- **Arduino Uno (R3)**  
- **ESP32** (for wireless connectivity and remote monitoring)  
- **Jumper Cables/Other Cables**  
- **LCD Display** (for real-time visualization of system status)  
- **DHT 22 Sensor** (for monitoring temperature and humidity)  
- **Incandescent Light Bulb** (220V AC as the heating element)  
- **2-Channel Relay Module** (for precise switching of the heating element)  
- **Servo Motor** (to control the opening and closing of air vents)  
- **Switch Button**  
- **12V Power Supply**  
- **12V PC Fan** (operated at 5V to ensure gentle and even air circulation)
---
| Component            | GPIO       | Power Source        | Notes                                                    |
|----------------------|------------|---------------------|----------------------------------------------------------|
| ESP32                |            |                     |                                                          |
| DHT22 Sensor         | GPIO 15    | 3.3V                | Add 10kΩ pull-up resistor on data pin                    |
| 2-Channel Relay      | GPIO 18    | 5V                  | IN1: bulb control; GND to ESP GND                       |
| Servo Motor (vents)  | GPIO 19    | 5V (external OK)    | Signal wire from servo to pin 19                          |
| PC Fan               | VIN (or GPIO 23) | 5V                  | Direct 5V from VIN (external 5V OK)                    |
| Egg Turning Servo    | GPIO 22    | 5V                  | Separate servo to rotate eggs                            |
| GND (common ground)  | ——         | ——                  | All grounds must connect together                        |

>*Note:* You may modify or expand this component list based on specific application requirements and available resources.

## How It Works ⚙️  

The hatching machine operates by maintaining a controlled and consistent incubation environment through three primary mechanisms:

1. **Temperature Control 🌡️**  
   - **Mechanism:** The system utilizes a 220V incandescent light bulb as its heating element. This bulb is cyclically turned on for 2 seconds and off for 2 seconds.  
   - **Control System:** A DHT 22 sensor continuously monitors the temperature inside the incubator. The Arduino, interfacing with a 2-channel relay, makes real-time decisions to switch the heating element on or off, ensuring the temperature remains within the desired range.

2. **Humidity Control 💧**  
   - **Mechanism:** Humidity is managed by regulating air vent operations. Inside the incubator, a container of water vaporizes to raise the moisture level.  
   - **Control System:** A servo motor adjusts the vents based on sensor input. When humidity exceeds a set threshold, the vents are opened—allowing excess moist air to escape and dry air to enter—thus maintaining an optimal humidity level.

3. **Fan Monitoring 🌬️**  
   - **Mechanism:** A 12V PC fan, running on a reduced 5V, continuously ensures that heat and humidity are evenly distributed throughout the chamber.  
   - **Impact:** This steady circulation helps eliminate hotspots or moisture pockets, contributing significantly to a uniform incubation environment critical for successful hatching.

## How to Run/Use the Hatching Machine 🏗️  

Follow these steps to assemble, set up, and operate the hatching machine:

1. **Assembly and Wiring 🔧**  
   - **Structure Setup:** Construct the incubator frame using the provided plywood dimensions. Mount the heating element, water container, and air vents securely within the enclosure.  
   - **Electrical Integration:** Wire the Arduino Uno, ESP32, sensors, relays, and servo motor according to your detailed circuit diagram. Ensure that all connections are sound and consistent with the prescribed design.

2. **Software Configuration 💻**  
   - **Installation:**  
     - Install the Arduino Integrated Development Environment (IDE).  
     - Add necessary libraries pertinent to the DHT sensor, LCD, and servo motor.  
   - **Code Deployment:**  
     - Navigate to the `src/codes` directory where the source code is located.  
     - Compile and upload the code to the Arduino Uno using the Arduino IDE.  
     - Integrate and configure the ESP32 for any wireless functionality.  
   - **Calibration:**  
     - Once powered by the 12V supply, the LCD should display real-time temperature and humidity readings.  
     - Perform initial calibration tests and adjust system parameters until optimal environmental conditions are reliably maintained.

3. **Operation 🛠️**  
   - **Monitoring:** The hatching machine operates autonomously. However, regular supervision is advised to ensure all components function correctly.  
   - **Maintenance:** Periodically check sensor calibrations, wiring connections, and the physical integrity of the enclosure.  
   - **Adjustment and Feedback:** Use the switch button (or remotely through ESP32) to make incremental adjustments as needed, adapting to different incubation requirements.

## Conclusion 📖  

This automated hatching machine presents an innovative approach to improving egg hatching production. By harnessing affordable microcontrollers, reliable sensors, and simple mechanical actuators, the system addresses critical challenges inherent in conventional hatching methods. The overall design encourages continuous improvement through iterative calibration and provides a scalable solution that can be adapted to various farm environments.

**Happy Hatching and Innovation! 🥚🐥**

---
