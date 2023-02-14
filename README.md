# Smart Parking System
This research project aims to investigate the potential of utilizing advanced technologies, specifically the ESP32 module, to design and implement an intelligent parking system. The proposed system features a fixed number of parking spaces and utilizes a servomotor to simulate a parking barrier that can operate in two distinct modes, depending on the direction of a vehicle's approach. The manual mode enables an operator to manually raise and lower the barrier via the use of two buttons, while the automatic mode employs proximity sensors to automatically raise the barrier as a vehicle approach.

Furthermore, the proposed parking system features a ventilation subsystem that simulates environmental conditions within the parking lot via the use of temperature and humidity sensors, as well as a motor that controls a fan. The ventilation subsystem is designed to operate in response to temperature and humidity levels that exceed pre-defined thresholds, in order to ensure optimal environmental conditions within the parking lot.

To facilitate monitoring and management of the system, a web-based interface is implemented that allows real-time monitoring of environmental conditions within the parking lot, and the ability to determine the need for ventilation based on sensor data. Through the implementation of this research project, the feasibility of utilizing advanced technologies such as the ESP32 module to create a more efficient and user-friendly parking system was evaluated.

## Project Architecture

  ### Hardware Architecture
  
The proposed system architecture from a hardware perspective includes a selection of electronic components that were chosen based on their functional capabilities and cost-effectiveness.
  - The core component of the system is the ESP32 microcontroller, developed and manufactured by Espressif Systems, a Chinese company based in Shanghai. The ESP32 series is a low-cost, low-power system-on-a-chip that integrates Wi-Fi and dual-mode Bluetooth capabilities, making it an ideal choice for this application;
  
![esp32_microprocessor](https://user-images.githubusercontent.com/48281622/218744936-9d7da33a-69ee-4be2-98e2-09261280ad5b.png)

  - The system includes two breadboards, which are commonly used in the prototyping of electronic circuits. They provide a reusable and non-destructive platform for building and testing circuit designs;

![breadboard](https://user-images.githubusercontent.com/48281622/218745657-82166d27-8183-4dee-a053-27b0109a01b2.png)

  - The system also includes two HC-SR04 ultrasonic sensors, which provide non-contact measurement capabilities in the range of 2cm to 700cm, with a ranging accuracy of 3mm. These sensors are used to detect the presence of vehicles and trigger the movement of the barrier, allowing entry or exit from the parking lot;

![download](https://user-images.githubusercontent.com/48281622/218746023-32c8ef72-87c8-4dcd-8c7e-1fda2eff67da.png)

  - The movement of the barrier is simulated using a MicroServo 9G SG90 servo-motor, which operates based on pulse-width modulation (PWM) control signals. The servo-motor is able to maintain a specific angle based on the width of the PWM signal input, thus providing precise and reliable movement of the barrier;
  
![servomotor](https://user-images.githubusercontent.com/48281622/218746072-7ff54222-bcae-43a6-891a-d3029cbb91f2.png)

  - In order to monitor the environmental conditions inside the parking lot, the system also includes a DHT11 humidity and temperature sensor. This sensor is used to detect the humidity and temperature inside the parking lot, which can be used to control the ventilation system;

![dht11](https://user-images.githubusercontent.com/48281622/218746115-63eae0a8-618e-41e2-bc47-9622df8c0238.png)

  - The system also includes a DC motor with a fan, which simulates the ventilation of the parking lot;

![dcmotor](https://user-images.githubusercontent.com/48281622/218746142-ba7c3f2f-4322-4780-abd4-2a25c4c897b8.png)

  - Furthermore, the system includes two LEDs (green, red) which are used to indicate the status of the barrier, with the red LED indicating that the barrier is down and the green LED indicating that the barrier is up;

![led](https://user-images.githubusercontent.com/48281622/218746159-07b2b9f9-5779-4c2b-ac3b-fbf99318da6f.png)

  - Finally, the system includes two push buttons with which the manual operation of the barrier can be simulated.;

![pushbutton](https://user-images.githubusercontent.com/48281622/218746183-e05e8c5a-4bbd-436b-b69a-a7a393906774.png)

The simulated diagram of the hardware architecture is highlighted in the picture below, where the wiring of the system is detailed and can be optimally analyzed.

![wiring_smart_parking_system2](https://user-images.githubusercontent.com/48281622/218746224-8ac4e8e1-bde3-4c21-b89c-f670a2a59357.png)

From an electrical point of view, the hardware architecture was configured and displayed below for a better understanding of how the system works and how can it be implemented from scratch.
  
![electric_diagram_smart_parking](https://user-images.githubusercontent.com/48281622/218746253-8befa7e5-6339-45f7-a90f-204146dab445.png)

In the end, the physically hardware architecture fully configured on the breadboard can be observed in the picture below where the barrier between the ultrasonic sensors can be also noticed.

![schema_smart_parking_system](https://user-images.githubusercontent.com/48281622/218746319-867d6120-0eff-41a4-9c9d-0a3f1bf39145.png)

A full view of the parking lot is illustrated in the picture below. The difference between these two pictures is that in this case the whole parking lot can be observed and, implicitely, the placement of the system on the table.

![pov_smart_parking2](https://user-images.githubusercontent.com/48281622/218746378-51d0a6bf-ecc0-4f3b-a27c-b14fda57b302.png)

  ### Software Architecture
  









