
/*
 * CS = 53
 * SCK = 52
 * MOSI = 51
 * MOSO = 50
 * VCC = 5V
 * GND = GND
 * Moisture Sensor AO = A0
 */

#include <SD.h>

File sdcard_file;

int CS_pin = 53; // Pin 10 on Arduino Uno
const int sensor_pin = A0;
float temp;  
float output;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin,INPUT);
  pinMode(CS_pin, OUTPUT);
  // SD Card Initialization
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }
  
  Serial.print("Moisture Level  ");   
  sdcard_file = SD.open("data.txt", FILE_WRITE);
  if (sdcard_file) { 
    sdcard_file.print("Moisture Level  ");   
    sdcard_file.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }
}

void loop() {
  output = analogRead(sensor_pin);
  temp =(output)/1023;
  Serial.println(temp);
 
  sdcard_file = SD.open("data.txt", FILE_WRITE);
  if (sdcard_file) {
    sdcard_file.println(temp);
    sdcard_file.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }
  delay(30);
}
