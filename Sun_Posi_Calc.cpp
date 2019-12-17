

//////////////////////////////////////////////////  
//PUT YOUR LATITUDE, LONGITUDE, AND TIME ZONE HERE
  float latitude = 35.91;
  float longitude = -79.05;
  float timezone = 4;
//////////////////////////////////////////////////  

//If you live in the southern hemisphere, it would probably be easier
//for you if you make north as the direction where the azimuth equals
//0 degrees. To do so, switch the 0 below with 180.  
  float northOrSouth = 0;

/////////////////////////////////////////////////////////// 
//MISC. VARIABLES
///////////////////////////////////////////////////////////  
  float pi = 3.14159265;
  float delta;
  float h;
/////////////////////////////////////////////////////////// 
//END MISC. VARIABLES
///////////////////////////////////////////////////////////
  
float calculation(float month2, float day, float hour2, float minute2) {
  latitude = latitude * pi/180;
  
  //START OF THE CODE THAT CALCULATES THE POSITION OF THE SUN
  float n = daynum(month2) + day;//NUMBER OF DAYS SINCE THE START OF THE YEAR. 
  delta = .409279 * sin(2 * pi * ((284 + n)/365.25));//SUN'S DECLINATION.
  day = dayToArrayNum(day);//TAKES THE CURRENT DAY OF THE MONTH AND CHANGES IT TO A LOOK UP VALUE ON THE HOUR ANGLE TABLE.
  h = (FindH(day,month2)) + longitude + (timezone * -1 * 15);//FINDS THE NOON HOUR ANGLE ON THE TABLE AND MODIFIES IT FOR THE USER'S OWN LOCATION AND TIME ZONE.
  h = ((((hour2 + minute2/60) - 12) * 15) + h)*pi/180;//FURTHER MODIFIES THE NOON HOUR ANGLE OF THE CURRENT DAY AND TURNS IT INTO THE HOUR ANGLE FOR THE CURRENT HOUR AND MINUTE.
  altitude = (asin(sin(latitude) * sin(delta) + cos(latitude) * cos(delta) * cos(h)))*180/pi;//FINDS THE SUN'S ALTITUDE.
  azimuth = ((atan2((sin(h)),((cos(h) * sin(latitude)) - tan(delta) * cos(latitude)))) + (northOrSouth*pi/180)) *180/pi;//FINDS THE SUN'S AZIMUTH.
  //END OF THE CODE THAT CALCULATES THE POSITION OF THE SUN

  azimuth = 180 - abs(azimuth);
 


 
}