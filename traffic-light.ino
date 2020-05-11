#include <string>

int red = A0;
int yellow = A2;
int green = A4;

bool redLight;
bool yellowLight;
bool greenLight;
bool light;

String currentLightColour;

void displayLight(String colour);
int lightOn(String command);

void setup() {
    Serial.begin(9600);
    
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    digitalWrite(red, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, HIGH);
    delay(2000);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    
    currentLightColour = "";
    Particle.variable("currentLight", currentLightColour);
    light = Particle.function("trafficLight", lightOn);
    
}

void loop() {
}

int lightOn(String command) {
    Serial.printlnf("in function");
    
    String colour = "";
    if (command == "red") {
        Serial.printlnf("in red");
        colour = "red";
    }
    else if (command == "yellow") {
        Serial.printlnf("in yellow");
        colour = "yellow";
    }
    else if (command == "green") {
        Serial.printlnf("in green");
        colour = "green";
    }
    
    if (colour != "") {
        displayLight(colour);
        currentLightColour = colour;
        return 1;
    }
    
    return -1;
}

void displayLight(String colour) {
    Serial.printlnf("in displayLight");
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    if (colour == "red") {
        Serial.printlnf("in red lamp on");
        digitalWrite(red, HIGH);
    }
    if (colour == "yellow") {
        Serial.printlnf("in yellow lamp on");
        digitalWrite(yellow, HIGH);
    }
    if (colour == "green") {
        Serial.printlnf("in green lamp on");
        digitalWrite(green, HIGH);
    }
}
