// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

#define echoPin_1 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin_1 3 //attach pin D3 Arduino to pin Trig of HC-SR04

#define echoPin_2 4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin_2 5 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance;  // variable for the distance measurement

void setup()
{
    // Sets the trigPin_1 as an OUTPUT
    // Sets the echoPin_1 as an INPUT
    pinMode(trigPin_1, OUTPUT);                       
    pinMode(echoPin_1, INPUT);    

    // Sets the trigPin_1 as an OUTPUT
    pinMode(trigPin_2, OUTPUT);                       
    pinMode(echoPin_2, INPUT);   

    Serial.begin(9600);                               // // Serial Communication is starting with 9600 of baudrate speed
    Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
    Serial.println("with Arduino Mega 2560");
}
void loop()
{
    // Clears the trigPin_1 condition
    digitalWrite(trigPin_1, LOW);
    delayMicroseconds(2);
    // Sets the trigPin_1 HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin_1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin_1, LOW);
    // Reads the echoPin_1, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin_1, HIGH);
    // Calculating the distance
    // Speed of sound wave divided by 2 (go and back)
    distance = duration * 0.34 / 2;
    // Displays the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");

    int distance = get_distance(echoPin_2, trigPin_2);
}

int get_distance(int echoPin, int trigPin)
{
    // Clears the trigPin condition
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin_1, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    // Speed of sound wave divided by 2 (go and back)
    distance = duration * 0.34 / 2;
    Serial.print("Trigger pin: ");
    Serial.print(trigPin_1);
    Serial.print("Distance from function: ");
    Serial.print(distance);
    Serial.println(" mm");
    return distance;
}