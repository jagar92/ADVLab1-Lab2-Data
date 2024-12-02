const int pwmPin = 9;       // Pin to output square wave
const int outputPin = A0;       // Measure output
const int freq = 100;         // Frequency of square wave (Hz)

unsigned long currentTime = 0;
unsigned long lastTIme = 0;
const unsigned long intervalBetweenData = 1000;

void setup() {
  pinMode(pwmPin, OUTPUT);
  Serial.begin(500000);
  tone(pwmPin, freq);       // Generate square wave
}

void loop() {
   currentTime = micros() 
   int outputValue = analogRead(outputPin); // Read filtered voltage


   if (currentTime - lastTime >= intervalBetweenData ) {
            int sensorValue = analogRead(A0);
            lastTime+=intervalBetweenData; 
            
   // Output data to Serial Monitor
   Serial.print(currentTime/1000);
   Serial.print(',');
   Serial.println((outputValue * 5.0) / 1023);

  }

}
