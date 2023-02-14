#include <AsyncTCP.h>
#include <ESP32Servo.h>
#include <DHT.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

Servo myservo;

const int trigPin1 = 17;
const int echoPin1 = 16;
const int trigPin2 = 5;
const int echoPin2 = 18;
const int led1 = 14;
const int led2 = 27;
const int button1 = 15;
const int button2 = 2;
const int DHT_PIN = 21;
const int DC_Motor = 12;
const int servoPin = 13;
const char* ssid = "Alex";
const char* password = "Robertandrei";
int state = 0;
int servoPos = 0;
AsyncWebServer server(80);

DHT dht(DHT_PIN, DHT11);

void setup() {
  Serial.begin(115200);
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);    
  myservo.attach(servoPin, 500, 2400); 
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(DHT_PIN, INPUT);
  pinMode(DC_Motor, OUTPUT);
  dht.begin();

  // Initialize SPIFFS
  if(!SPIFFS.begin()){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

    // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html");
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(dht.readHumidity()).c_str());
  });
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(dht.readTemperature()).c_str());
  });

  server.on("/turnOn", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(DC_Motor, HIGH);
    state = 1;
    request->send(200, "text/plain", "OK");
  });

  server.on("/turnOff", HTTP_GET, [](AsyncWebServerRequest *request){
    state = 0;
    digitalWrite(DC_Motor, LOW);
    request->send(200, "text/plain", "OK");
  });
 
  // Start server
  server.begin();
  digitalWrite(led2, HIGH);
}

void loop() {
  int duration1, distance1;
  int duration2, distance2;
  int button1State = digitalRead(button1);
  int button2State = digitalRead(button2);
  int state1 = digitalRead(DC_Motor);

    // Ultrasound sensor 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

  // Ultrasound sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;

    // Check if first ultrasound sensor is triggered
  if (distance1 < 5) {
    myservo.write(90);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(5000);
    myservo.write(0);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

  // Check if second ultrasound sensor is triggered
  if (distance2 < 5) {
    myservo.write(90);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(5000);
    myservo.write(0);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

    // Check if button 1 is pressed
  if (button1State == LOW) {
    myservo.write(90);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
     delay(5000);
  }

  // Check if button 2 is pressed
  if (button2State == LOW) {
    myservo.write(0);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
     delay(5000);
  }

    // Read humidity and temperature
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
       Serial.println("Error: Failed to read from DHT sensor!");
    } else {
        //
    }

  // Control DC motor
  if (h > 80 || t > 40 || state == 1) {
    digitalWrite(DC_Motor, HIGH);
  } else {
    digitalWrite(DC_Motor, LOW);
  }
}