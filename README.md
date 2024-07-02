# Vehicle Control System

This project implements a vehicle control system that allows the user to interact with various functionalities related to the vehicle's engine, sensors, and state. The system provides a menu-based interface to perform different actions and monitor the vehicle's status.

## Requirements
To run this program, you need to have a compatible Python environment installed. The program utilizes the console input and output for interaction.

## Usage
Run the program by executing the main script, vehicle_control_system.py.
Once the program starts, you will be presented with a menu with the following options:
a. Turn on the vehicle engine
b. Turn off the vehicle engine
c. Quit the system
Enter the corresponding letter (a, b, or c) to select an option.
## Turn on the vehicle engine
If you choose to turn on the vehicle engine, the program will display the "Sensors set menu," which simulates the readings from various vehicle sensors. The menu provides the following options:

a. Turn off the engine
b. Set the traffic light color
c. Set the room temperature (Temperature Sensor)
d. Set the engine temperature (Engine Temperature Sensor)

While the engine is ON, the menu mentioned in requirement 5 will be continuously displayed, waiting for your input.
## Sensor Readings and Actions
Based on your input provided in the sensor readings menu, the program will perform the following actions:

a. Based on traffic light data (input from console):
- If the traffic light is 'G,' set the vehicle speed to 100 km/hr.
- If the traffic light is 'O,' set the vehicle speed to 30 km/hr.
- If the traffic light is 'R,' set the vehicle speed to 0 km/hr.

b. Based on room temperature data (input from console):
- If the temperature is less than 10, turn on the AC and set the temperature to 20.
- If the temperature is greater than 30, turn on the AC and set the temperature to 20.
- If the temperature is otherwise, turn off the AC.

c. Based on engine temperature data (input from console):
- If the temperature is less than 100, turn on the "Engine Temperature Controller" and set the temperature to 125.
- If the temperature is greater than 150, turn on the "Engine Temperature Controller" and set the temperature to 125.
- If the temperature is otherwise, turn off the "Engine Temperature Controller."

d. If the vehicle speed is 30 km/hr:
- Turn on the AC if it was off and set the room temperature to the current temperature * (5/4) + 1.
- Turn on the "Engine Temperature Controller" if it was off and set the engine temperature to the current temperature * (5/4) + 1.

After applying the actions described in 7.a to 7.d, the program will display the current vehicle state, including the following information:
Engine state: ON/OFF
AC: ON/OFF
Vehicle speed
Room temperature
Engine Temperature Controller state
Engine temperature
## Turn off the vehicle engine
If you choose to turn off the vehicle engine in the menu mentioned in requirement 5, the program will display the menu from requirement 1, allowing you to select another option.

#3 Quit the system
If you choose to quit the system in the menu mentioned in requirement 1, the program will terminate.

# Conclusion
The vehicle control system provides an interactive interface to manage the vehicle's engine, sensors, and state. It allows you to turn the engine on/off, set sensor readings, and observe the system's behavior based on the provided inputs. Feel free to explore the different options and observe the changes in the vehicle state.

For any questions or issues, please contact [ahmedfaragahmed106@gmail.com].
