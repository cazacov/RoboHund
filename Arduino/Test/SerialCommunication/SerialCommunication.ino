/*
 Connects Arduino to Raspberry Pi
 Arduino: SoftSerial
 Raspberry Pi: GPIO UART

 This is just a simple passthrough, based on Arduino SoftSerial example
 
 Wiring: http://www.andremiller.net/content/raspberry-pi-and-arduino-via-gpio-uart
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10); // RX, TX

void setup()  
{
 // Open serial communications to PC and wait for port to open:
  Serial.begin(57600);
  Serial.println("Connected to PC");

  // set the data rate for the SoftwareSerial port to Raspberry Pi
  mySerial.begin(9600);
}

void loop() // run over and over
{

  int byteCount;

  // If data is available on Raspberry Pi, print it to PC
  if (byteCount = mySerial.available())
  {
    while (byteCount--)
    {
      Serial.write(mySerial.read());
    }
  }

  // If data is available on PC, print it to Raspberry Pi
  if (byteCount = Serial.available())
  {
    while (byteCount--)
    {
      mySerial.write(Serial.read());
    }
  }
}
