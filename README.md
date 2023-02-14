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

![download](https://user-images.githubusercontent.com/48281622/218750405-ef4de1a5-7bcd-4389-b23e-46ca9272a9d8.png)

  - The movement of the barrier is simulated using a MicroServo 9G SG90 servo-motor, which operates based on pulse-width modulation (PWM) control signals. The servo-motor is able to maintain a specific angle based on the width of the PWM signal input, thus providing precise and reliable movement of the barrier;
  
![servomotor](https://user-images.githubusercontent.com/48281622/218750446-97730049-36fa-4019-b5ef-a16c10d53599.png)

  - In order to monitor the environmental conditions inside the parking lot, the system also includes a DHT11 humidity and temperature sensor. This sensor is used to detect the humidity and temperature inside the parking lot, which can be used to control the ventilation system;

![dht11](https://user-images.githubusercontent.com/48281622/218750466-672e0988-4f61-424d-96b9-bce551b3c1d6.png)

  - The system also includes a DC motor with a fan, which simulates the ventilation of the parking lot;

![dcmotor](https://user-images.githubusercontent.com/48281622/218750503-f96cac94-4745-4d1c-b6b5-076e7fcb73b0.png)

  - Furthermore, the system includes two LEDs (green, red) which are used to indicate the status of the barrier, with the red LED indicating that the barrier is down and the green LED indicating that the barrier is up;

![led](https://user-images.githubusercontent.com/48281622/218746159-07b2b9f9-5779-4c2b-ac3b-fbf99318da6f.png)

  - Finally, the system includes two push buttons with which the manual operation of the barrier can be simulated.;

![pushbutton](https://user-images.githubusercontent.com/48281622/218746183-e05e8c5a-4bbd-436b-b69a-a7a393906774.png)

The simulated diagram of the hardware architecture is highlighted in the picture below, where the wiring of the system is detailed and can be optimally analyzed.

![wiring_smart_parking_system2](https://user-images.githubusercontent.com/48281622/218746224-8ac4e8e1-bde3-4c21-b89c-f670a2a59357.png)

From an electrical point of view, the hardware architecture was configured and displayed below for a better understanding of how the system works and how can it be implemented from scratch.
  
![electric_diagram_smart_parking](https://user-images.githubusercontent.com/48281622/218746253-8befa7e5-6339-45f7-a90f-204146dab445.png)

In the end, the physically hardware architecture fully configured on the breadboard can be observed in the picture below where the barrier between the ultrasonic sensors can be also noticed.

![schema_smart_parking_system](https://user-images.githubusercontent.com/48281622/218750541-432c9b0a-2808-44af-a5ce-9d3c6b75f805.png)

A full view of the parking lot is illustrated in the picture below. The difference between these two pictures is that in this case the whole parking lot can be observed and, implicitely, the placement of the system on the table.

![pov_smart_parking2](https://user-images.githubusercontent.com/48281622/218746378-51d0a6bf-ecc0-4f3b-a27c-b14fda57b302.png)

  ### Software Architecture
  
In regards to the software architecture implemented for this project, an important aspect to consider is the structure of the file system. As depicted in the diagram below, a comprehensive examination of each file will be conducted in this chapter, in order to thoroughly explain the configuration of each hardware component and its role in the overall system behavior.

![filesystem_smart_parking](https://user-images.githubusercontent.com/48281622/218750564-487d4d3a-7a2a-44f1-9d5c-1e4019a7199a.png)

In this project, the ESP32 microcontroller serves as the central control unit for the operation of all sensors and motors involved. This is demonstrated also in the demo video. Additionally, the file “index.html” was uploaded to the microcontroller's internal memory in order to facilitate the display of a user-friendly web interface, as depicted in the picture below. Through this interface, users can easily monitor the temporal evolution of humidity and temperature and make a decision to activate the ventilation system via the button provided at the top of the page.

![preview_web_server_smart_parking](https://user-images.githubusercontent.com/48281622/218747301-1aadf2c6-bb2a-4cb8-80cb-6278d2fc78ab.png)

The web page is used to display two Highchart graph and a switch button. The switch button is used to turn on and off the ventilation system, when the switch is on the button is green, and when it's off it's red.


  ### Usability. Demo Video
  
The way the proposed solution is working was highlighted in the video attached in the link below. There, the full environment and the hardware implementation's placement in the parking lot can be observed. The example displays how the ultrasonic sensors sense the activity which happens in front of them, how the barrier can be moved manually using the buttons or automatically when the ultrasonic sensors detect some movement, the LEDs which indicate the state of the barrier (open/closed) and the web server interface in which the evolution in time of the humidity and temperature can be seen in the graphs and the trigger button of the DC Motor which should be pressed when temperature/humidity exceed a desired treshold.

Link: https://drive.google.com/file/d/1O56uAq17g-68r0betEHjXbiDiJ5rza-4/view?usp=share_link


  ### Future Work & Improvements
  
This project presents a smart parking system that utilizes an ESP32 microcontroller, two ultrasound sensors, a servomotor, two buttons, a humidity and temperature sensor, two LEDs and a DC motor. The system is capable of detecting the presence of cars at the entrance of the parking lot. However, there is still room for improvement. Future work on this project could include the following:
  - Enhancing the user interface by incorporating a LCD screen to display the temperature, humidity, and the number of cars in the parking lot in real-time. This would provide users with more information about the parking lot conditions and make the system more user-friendly.
  - Integrating a camera and Optical Character Recognition (OCR) algorithm to capture the image of the car's number plate, and using it to keep a record of the cars that entered the parking lot and the time they entered. This would provide more security to the parking lot and make it easier to track cars that have entered the parking lot.
  - Adding a buzzer or LED indicator to alert the user when the parking lot is full. This would help users avoid parking in a lot that is already full.
Overall, the project can be improved by adding more features to make it more user-friendly, efficient and secure.

  ### Conclusions
  
The implementation of the ESP32 module has proven to be highly effective in providing the necessary intelligence and connectivity capabilities to the parking system, allowing for efficient allocation and management of parking spaces.
The use of a servomotor to simulate a parking barrier, along with the implementation of manual and automatic modes of operation, has resulted in a more secure and user-friendly parking experience for users. The integration of temperature and humidity sensors in the ventilation subsystem has not only ensured a comfortable environment for the users but also helped to reduce energy consumption by only activating the ventilation when needed.
The web-based interface has provided an easy way for the administrator to monitor and manage the system, it could also be further developed to allow users to check the parking space availability in advance or reserve parking spots.
The results of this study have shown that it is possible to develop an intelligent parking system that is not only efficient but also cost-effective by using commercially available modules like the ESP32. This research can be expanded to include more sensors and modules to improve the overall performance and user experience, such as license plate recognition to further automate the parking process.

  ### Resources & References
  
  #### Pictures sources
  [1]https://predictabledesigns.com/introduction-to-the-esp32-wifi-bluetooth-wireless-microcontroller/
  [2]https://roboromania.ro/produs/breadboard-420-121-plastic-cu-contacte-nichelate/
  [3]https://www.trionprojects.org/2020/03/ultrasonic-sensor-hc-sr04-with-pic.html
  [4]https://my.cytron.io/p-sg90-micro-servo
  [5]https://www.electrokit.com/en/product/digital-temperature-and-humidity-sensor-dht11/
  [6]https://tehnoelectric.ro/simple/512-04211-motor-cc-15-3v-200ma-38x20x16mm.html
  [7]https://learn.adafruit.com/adafruit-arduino-lesson-2-leds/leds
  [8]https://ardushop.ro/ro/electronica/96-buton-mare-push-button.html?gclid=Cj0KCQiAiJSeBhCCARIsAHnAzT-sl3TxjqzM3SsV762KyG-kay2yzuXtajYANnQOX81WiyXLfUW-HkAaAv_tEALw_wcB
  
  #### Components and their usage
  [9]https://dronebotworkshop.com/esp32-servo/
  [10]https://docs.arduino.cc/built-in-examples/digital/Button
  [12]https://www.tutorialspoint.com/arduino/arduino_blinking_led.htm
  [13]https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
  [14]https://www.tutorialspoint.com/arduino/arduino_dc_motor.htm
  [15]https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
  [16]https://www.instructables.com/Arduino-Servo-Motors/
  [17]https://www.allaboutcircuits.com/projects/servo-motor-control-with-an-arduino/

  #### Software tips
  [18]https://ocw.cs.pub.ro/courses/iothings/laboratoare/2022/lab2
  [19]https://ocw.cs.pub.ro/courses/iothings/laboratoare/2022/lab3
  [20]https://www.youtube.com/watch?v=1y03xt6IM-o
  [21]https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/storage/spiffs.html
  [22]https://randomnerdtutorials.com/esp32-web-server-arduino-ide/
  [23]https://github.com/me-no-dev/arduino-esp32fs-plugin
