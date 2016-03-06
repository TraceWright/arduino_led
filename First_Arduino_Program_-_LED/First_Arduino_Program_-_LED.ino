/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 The analogWrite() function uses PWM, so if
 you want to change the pin you're using, be
 sure to use another PWM capable pin. On most
 Arduino, the PWM pins are identified with 
 a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

 This example code is in the public domain.
 */

int ledfade = 6;
int ledblink = 8;
int ledfastblink = 10;
int daVariable = 67;
// the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 6 to be an output:
  pinMode(ledfade, OUTPUT);
  pinMode(ledblink, OUTPUT);
  pinMode(ledfastblink, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 6:
  analogWrite(ledfade, brightness);
  if (brightness <= 160){
  digitalWrite(ledblink, true);
  }
  else{
   digitalWrite(ledblink, false);
  }
  // set the orange pin to fastblink
  if (brightness <= 50)
  {
  digitalWrite(ledfastblink, true);
  }
  else if (brightness > 50 && brightness <= 100)
  {
   digitalWrite(ledfastblink, false);
  }
  else if (brightness > 100 && brightness <= 150){
  digitalWrite(ledfastblink, true);
  }
  else if (brightness > 150 && brightness <= 200){
  digitalWrite(ledfastblink, false);
  }
  else {
  digitalWrite(ledfastblink, true);
  }
  
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
