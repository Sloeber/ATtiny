/**
 * HC-SR04 Ping distance sensor for the ATtiny
 *
 * Original code improvements to the Ping sketch sourced from Trollmaker.com
 * Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
 * Some code from https://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
 */

#define trigPin 3
#define echoPin 4
#define RED_LED 1
#define GREEN_LED 0

void setup() {
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	pinMode(RED_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
}

void loop() {
	sendPulse();
	long duration, distance;
	duration = pulseIn(echoPin, HIGH);
	distance = (duration / 2) / 29.1;
	signal(distance);
	delay(500);
}

void signal(int pDistance) {
	if (pDistance < 100) {
		digitalWrite(RED_LED, HIGH);
		digitalWrite(GREEN_LED, LOW);
	} else {
		digitalWrite(RED_LED, LOW);
		digitalWrite(GREEN_LED, HIGH);
	}

}

void sendPulse() {
	digitalWrite(trigPin, LOW);
	delay(2);
	digitalWrite(trigPin, HIGH);
	delay(10);
	digitalWrite(trigPin, LOW);
}
