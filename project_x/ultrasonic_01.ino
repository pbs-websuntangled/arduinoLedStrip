// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

// attach pin D2 Arduino to pin Echo of HC-SR04
//attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPin_1 2 
#define trigPin_1 3 

// attach pin D2 Arduino to pin Echo of HC-SR04
//attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPin_2 4 
#define trigPin_2 5 

// attach pin D2 Arduino to pin Echo of HC-SR04
//attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPin_3 6 
#define trigPin_3 7 

// defines variables
// variable for the duration of sound wave travel
long duration; 
// variable for the distance_sensor_1 measurement
int distance_sensor_1;  
int distance_sensor_2;  
int distance_sensor_3;  
int counter;

void setup()
{

    // set the counter to zero 
    counter = 0;

    // Sets the trigPin_1 as an OUTPUT
    // Sets the echoPin_1 as an INPUT
    pinMode(trigPin_1, OUTPUT);                       
    pinMode(echoPin_1, INPUT);    

    // Sets the trigPin_1 as an OUTPUT
    pinMode(trigPin_2, OUTPUT);                       
    pinMode(echoPin_2, INPUT);   

    // Sets the trigPin_1 as an OUTPUT
    pinMode(trigPin_3, OUTPUT);                       
    pinMode(echoPin_3, INPUT);   

    Serial.begin(115200);                               // // Serial Communication is starting with 9600 of baudrate speed
    Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
    Serial.println("with Arduino Mega 2560");
}
void loop()
{
    // keep a counter so I can see how fast the data is transferr
    Serial.print(" ===============  ");
    Serial.print(counter);
    Serial.println(" ===============  ");

    distance_sensor_1 = get_distance(echoPin_1, trigPin_1);
    distance_sensor_2 = get_distance(echoPin_2, trigPin_2);
    distance_sensor_3 = get_distance(echoPin_3, trigPin_3);

    Serial.print("distances in mm: ");
    Serial.print(distance_sensor_1);
    Serial.print(", ");
    Serial.print(distance_sensor_2);
    Serial.print(", ");
    Serial.print(distance_sensor_3);
    Serial.println("");
    Serial.println("");

    // increment the counter
    counter = counter + 1;

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
    // Calculating the distance_sensor_1
    // Speed of sound wave divided by 2 (go and back)
    int distance_sensor = duration * 0.34 / 2;

    delayMicroseconds(200);
    return distance_sensor;
}