// our potentiometer will go to Analog Input 1
const int PotInputPin = A1;

// our digital PWM output is set to Digital Out 9
const int outPin = 9;

// we start with an output of 0 and declare this variable as an integer
int outputLevel = 0;

void setup() {
    // Start serial communication for printing values to the serial monitor
    Serial.begin(9600);

    // Define the pin mode for the digital output
    pinMode(outPin, OUTPUT);
}

void loop() {
    // Read the thermistor value from analog input A0
    int thermistorValue = analogRead(A0); 
    // Read the potentiometer value from analog input A1
    int potValue = analogRead(PotInputPin); // Use the defined constant for consistency

    // Use the map() function to scale the potentiometer input from 0-1023 to 0-255
    outputLevel = map(potValue, 0, 1023, 0, 255);

    // Write the outputLevel variable to our digital output pin
    analogWrite(outPin, outputLevel);
    
    // Get the elapsed time since the Arduino started (in milliseconds)
    unsigned long time = millis();
    
    // Print the time, potentiometer, and thermistor values separated by commas
    Serial.print(time);
    Serial.print(","); // Separator
    Serial.print(potValue);
    Serial.print(","); // Separator
    Serial.println(thermistorValue); // Use println for cleaner output

    delay(200);  // Delay before the next reading
}
