// Define pin connections
const int trigPin = 6;  // Trigger Pin
const int echoPin = 7;  // Echo Pin

void setup() {
  // Set up pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start the serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Make sure trigger pin is LOW for a moment
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond HIGH pulse to trigger the measurement
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the length of the pulse on the echo pin
  // pulseIn() returns the duration of the HIGH pulse in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters:
  // Speed of sound in air ~ 340 m/s = 29.412 µs/cm (approx 0.0343 cm/µs)
  // Distance is (time x speed) / 2 because the signal travels out and back
  float distanceCm = (duration * 0.0343) / 2.0;

  // Print the distance over serial
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // A short delay so the output is more readable
  delay(250);
}

//Comment
