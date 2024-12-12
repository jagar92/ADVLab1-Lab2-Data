const int trigPin = 9;
const int echoPin = 10;

float duration, distance;
unsigned long currentTime = 0;
unsigned long lastTime = 0;
const unsigned long intervalBetweenData = 2000; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(500000); // Faster baud rate for better performance
}

void loop() {
  unsigned long currentTime = micros();

  // Check if it's time to record data
  if (currentTime - lastTime >= intervalBetweenData) {
    lastTime += intervalBetweenData; // Increment by fixed interval

    // Trigger ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure duration of the echo pulse
    duration = pulseIn(echoPin, HIGH);
    if (duration > 0) {
      distance = (duration * 0.0343) / 2; // Convert to distance in cm
    }

    // Send data to the serial monitor
    Serial.print(currentTime / 1000); // Convert to ms with millisecond precision
    Serial.print(",");
    Serial.println(distance); // Print distance
  }
}
