# Traffic Management System

The Traffic Management System is an Arduino-based project designed to optimize traffic flow at intersections by dynamically adjusting traffic signal timings. It utilizes RFID technology to detect emergency vehicles and prioritize their movement. This code is intended to control the system's operation.

## Components Used

- **Arduino UNO R3**: The central control unit for the traffic management system.
- **MFRC522 RFID Reader**: To read RFID tags on vehicles, including emergency vehicles.
- **IR Sensors**: Used to detect the presence of vehicles at different lanes.
- **LEDs**: Indicators for traffic signals at each lane.
- **SPI Library**: Required for communication with the RFID reader.

## RFID Tag Configuration

Replace the `MasterTag` variable value with the RFID tag ID of authorized emergency vehicles.

## Code Explanation

The code performs the following tasks:

1. Initializes components and sets up pins for IR sensors, LEDs, and the RFID reader.

2. Continuously checks for the presence of authorized emergency vehicles using the RFID reader. When an authorized RFID tag is detected, it sets a flag (`flag_rf1`) to prioritize the emergency vehicle.

3. Monitors the state of IR sensors at each lane and increments the green signal time (`green1`, `green2`, `green3`) when a vehicle is detected. This helps manage traffic flow and prioritize lanes with vehicle presence.

4. Updates traffic signal timings every second and controls the LEDs accordingly. It switches between lanes and adjusts the signal timings based on vehicle presence and prioritization.

5. Provides debug information through the serial interface.

## Usage

To use this Traffic Management System:

1. Set up the hardware components as specified in your code, including the RFID reader, IR sensors, and LEDs.

2. Upload the provided Arduino code to your Arduino board using the Arduino IDE.

3. Ensure that the RFID tags of authorized emergency vehicles are configured in the `MasterTag` variable.

4. The system will continuously monitor traffic conditions, prioritize emergency vehicles, and optimize traffic signal timings.

## License

This project is open-source and available under the [MIT License](LICENSE). You are free to use, modify, and distribute the code as long as you include the appropriate attribution.

## Contributing

Contributions to this project are welcome. If you have ideas for improvements or bug fixes, please feel free to open an issue or submit a pull request.

---

Thank you for considering the Traffic Management System to enhance traffic flow and prioritize emergency vehicles! If you have any questions or need further assistance, please don't hesitate to reach out.
