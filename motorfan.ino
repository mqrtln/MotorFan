#define RIGHT_MOTOR 1
#define LEFT_MOTOR 7
#define MOTOR_ENABLED 8

int VRx = A0; 
int VRy = A1; 

int xPosition = 0; 
int yPosition = 0; 
int mapX = 0; 
int mapY = 0; 

void setup(){
    Serial.begin(9600); 

    // Pins for the LD motor
    pinMode(RIGHT_MOTOR, OUTPUT);
    pinMode(LEFT_MOTOR, OUTPUT);
    pinMode(MOTOR_ENABLED, OUTPUT);

    // Pins for the joystick
    pinMode(VRx, INPUT);
    pinMode(VRy, INPUT);
}

void loop(){



    xPosition = analogRead(VRx); 
    yPosition = analogRead(VRy);



    mapX = map(xPosition, 0, 1023, -512, 512); 
    mapY = map(yPosition, 0, 1023, -512, 512); 




    // RIGHT & LEFT
    if(mapY == 512){
        Serial.println("LEFT");
        rotateMotor("LEFT", HIGH); 
    }
    if(mapY == -512){
        Serial.print("RIGHT");
        rotateMotor("RIGHT", HIGH); 
    } else{
        rotateMotor("RIGHT", LOW); 
        rotateMotor("LEFT", LOW); 
    }


}

void rotateMotor(String motordir, int enabledOrDisabled){
    if(motordir == "RIGHT"){
        Serial.println("Spinning motor to the right"); 
        digitalWrite(MOTOR_ENABLED, enabledOrDisabled); 
        digitalWrite(RIGHT_MOTOR, HIGH); 
        digitalWrite(LEFT_MOTOR, LOW); 
    }else{
        Serial.println("Rotating the motor to the left"); 
        digitalWrite(MOTOR_ENABLED, enabledOrDisabled); 
        digitalWrite(RIGHT_MOTOR, LOW); 
        digitalWrite(LEFT_MOTOR, HIGH); 
    }
}

