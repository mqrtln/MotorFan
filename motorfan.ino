#define COUNTER_CLOCKWISE_MOTOR 2
#define CLOCKWISE_MOTOR 7
#define MOTOR_ENABLED 8

int VRy = A1; 

int yPosition = 0; 

int mapY = 0; 

void setup(){
    Serial.begin(9600); 

    // Pins for the LD motor
    pinMode(COUNTER_CLOCKWISE_MOTOR, OUTPUT);
    pinMode(CLOCKWISE_MOTOR, OUTPUT);
    pinMode(MOTOR_ENABLED, OUTPUT);

    // Pins for the joystick
    pinMode(VRy, INPUT);
}

void loop(){



    yPosition = analogRead(VRy);



    mapY = map(yPosition, 0, 1023, -512, 512); 

    digitalWrite(MOTOR_ENABLED, HIGH); 
    // RIGHT & LEFT
    if(mapY == 510){
        Serial.println("LEFT");
        digitalWrite(COUNTER_CLOCKWISE_MOTOR, HIGH);
        digitalWrite(CLOCKWISE_MOTOR, LOW);
    }
    if(mapY == -510){
        Serial.println("RIGHT");
        digitalWrite(CLOCKWISE_MOTOR, HIGH);
        digitalWrite(COUNTER_CLOCKWISE_MOTOR, LOW);
    } else{
       
       digitalWrite(MOTOR_ENABLED, LOW); 
    }


}


