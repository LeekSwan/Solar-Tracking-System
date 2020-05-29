#define IN1a 8
#define IN2a 9
#define IN3a 10
#define IN4a 11

#define IN1b 4
#define IN2b 5
#define IN3b 6
#define IN4b 7


//////////////////////////////////////////////////  
//Global Variables
  float altitude;
  float azimuth;
////////////////////////////////////////////////// 

//////////////////////////////////////////////////  
//User Inputs
//see if we can use a date and time library so we this field doesnt have to be inputed manually.
  int _month = 5;
  int _day = 3;
  int _hour = 17; //24 hour time
  int _minute = 30;
////////////////////////////////////////////////// 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(IN1a, OUTPUT);  
  pinMode(IN2a, OUTPUT);
  pinMode(IN3a, OUTPUT);
  pinMode(IN4a, OUTPUT);

  pinMode(IN1b, OUTPUT);  
  pinMode(IN2b, OUTPUT);
  pinMode(IN3b, OUTPUT);
  pinMode(IN4b, OUTPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  position_test();
  calculation(_month, _day, _hour, _minute);
  float alt_degrees = sun_to_motor(altitude);
  float azi_degrees = sun_to_motor(azimuth);
  
  switch_gears(1);
  delay(250);
  run_motora(64);
  delay(250);
  switch_gears(2);
  delay(250);
  run_motora(64);
  delay(1250);
  switch_gears(0);
  delay(5000);

}


float sun_to_motor(float _degrees) {
  // This method translates the two angles calculated
  // from the sun_Posi_calc and translates it to steps
  // to run the motor
  float steps = _degrees/5.625;
  return steps;
}

void switch_gears(int mode) {
  // This method drives gear b to switch gears
  // Mode 0 to disengage, 1 to engage gear 1 and 2 to engage
  // gear 2.

  int curr_mode;
  float disengage = 64; //set middle position to disengage gears
 
  if (mode = 0) {
    run_motorb(64);
  } else if (mode = 1) {
    run_motorb(32);
  } else if (mode = 2) {
    run_motorb (-96);
  }

}

 void position_test() {
    calculation(_month, _day, _hour, _minute);
    Serial.print("Calculating for: ");
    Serial.print(_month);
    Serial.print("/" );
    Serial.print(_day);
    Serial.print(" " );
    Serial.print(_hour);
    Serial.print(":" );
    Serial.print(_minute);
    Serial.println();
    Serial.print("Altitude: " );
    Serial.print(altitude);
    Serial.println();
    Serial.print("Azimuth: ");
    Serial.print(azimuth);
    Serial.println();
  }
