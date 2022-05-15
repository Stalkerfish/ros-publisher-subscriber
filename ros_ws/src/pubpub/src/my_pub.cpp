// #include <Arduino.h>
#include <ros.h>
#include <std_msgs/Bool.h>

ros::NodeHandle nh;

std_msgs::Bool msg;
ros::Publisher pub("/button", &button_msg);

const int button = 3;
const int led = 13;

bool buttonState;
bool ledState;
bool lastReading = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;

bool published = true;

void setup() {
    nh.initNode();
    nh.advertise(pub);

    pinMode(button, INPUT);
    pinMode(led, OUTPUT);

    digitalWrite(button, HIGH);

    ROS_INFO("Node has been started");
}

void loop() {
    bool reading = digitalRead(button_pin);

    if (lastReading != reading) {
        lastDebounceTime = millis();
        published = false;
    }

    if (!published && (millis() - lastDebounceTime) > debounceDelay) {
        if (reading != buttonState)
            buttonState = reading;
        if (buttonState == HIGH)
            ledState = !ledState;

        button_msg.data = buttonState;
        pub.publish(&button_msg);
        published = true;
    }
	digitalWrite(led, ledState);
	lastReading = reading;

	nh.spinOnce();
}