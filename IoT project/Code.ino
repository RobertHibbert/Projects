#include <Wire.h>
#include <SPI.h>
#include <WiFiNINA.h>
#include "rgb_lcd.h"
#include "arduino_secrets.h"
rgb_lcd lcd;

const char ssid[] = SECRET_SSID; // This is my network SSID (name)
const char pass[] = SECRET_PASS; // This is my network password 
const byte keyIndex = 0; // Network key Index number (needed only for WEP)
byte status = WL_IDLE_STATUS;

int moistureSensor = A2; // The moisture sensor will connect to A2
int moistureSensorValue = 1; // this will hold the value from the moisture sensor
float moisture = 0.00; // This float will hold the soil moisture value

// these hold values that make up the colour of the LCD screen
byte colorR = 0;
byte colorG = 255;
byte colorB = 0;

const int pinLed = 2; // This is the pin for the LED
byte speakerPin = 3; // This is the pin for the buzzer it will connect to D3
byte length = 0; // This is the number of notes for the buzzer
char notes[] = "ccggaagffeeddc "; // this is the notes of the buzzer sound
int tempo = 300; // This is the tempo of the buzzer

const byte pinTemp = A0; // The temperature sensor will connect to A0
float temperature; // This foat will hold the value from the temperature sensor 
const int B=3975; // B value of the thermistor
float resistance;

WiFiClient client;
IPAddress server(193, 61, 245, 49);   // ip address of the server i am sending the data to

String postData;   // holds postvariable and the temperature value
String postData2;  // holds postvariable2 and the moisture value
String postData3; // holds postdata3 and water usage value
const String postVariable = "moisture=";  // value the same as php page value
const String postVariable2 = "temp=";   // value the same as php page value
const String postVariable3 = "water="; // value same as php page value

const int relayPin = 7; // this is the pin connection for the relay

String waterOn = "yes";


void setup()
{
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  lcd.begin(16, 2); // sets up the spacing on the LCD board
  lcd.setRGB(colorR, colorG, colorB); // sets the colours for the LCD board background 
  pinMode(pinLed, OUTPUT);     // set led pin to output
  pinMode(speakerPin, OUTPUT); // sets the buzzer pin to output
  pinMode(A0,INPUT); //Setting the A0 pin (temp sensor) as input pin to take data from the temperature sensor
  pinMode(relayPin, OUTPUT); // this sets the relay pin to output
  
  while (!Serial) 
  {
      ; // this waits for the serial monitor to connect  ////////////(may need to take this away for main power suply use)
  }

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) 
  {
    Serial.println(F("Communication with WiFi module failed!"));
    // don't continue
    while (true);
  }
  
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) 
  {
    Serial.println(F("Attempting to connect to SSID: "));
    Serial.println(ssid); // prints my ssid it is trying to connect to
    // Connect to WPA/WPA2 network.
    status = WiFi.begin(ssid, pass); // connects using my internets ssid and password
    // wait 10 seconds for connection:
    delay(10000);
  }
  // now it is connected (setup is done) and it will start the main program loop
}

void loop()
{
  temp(); // gets temp value and then calles another function to put it in fahrenheit
  getMoistureValue(); // gets the moisure value as a percentage 
  lcdscreen();
  pump(); //turns the pump on/off
  
  sendData(); // sends the data of the tempature and moisture sensors to the server
  delay(3000); // delay of 1h with 2000 mill secs taken away for the recive data delay
}

void sendData()
{
  postData = postVariable + moisture; // adds the moisture to the post variable2
  postData2 = "&"+postVariable2 + temperature;  // adds the temperature to the post variable
  String dataSize=postData+postData2; // puts the data together that will be sent to the server (the temp value and moisture value)

  // port 443 https and 80
  if (client.connect(server, 80))
  {
    client.println(F("POST /~rthibbert/project.php HTTP/1.1")); // php page location that will handle the sensor values and store them in the database
    client.println(F("Host: 193.61.245.49")); // vesta server ip
    client.println(F("Content-Type: application/x-www-form-urlencoded"));
    client.print(F("Content-Length: "));
    client.println(dataSize.length());
    client.println();
    client.print(dataSize); // sends the data to the server (the webpage to the server)
    client.println();
    delay(2000); // 2 second delay
  } 
  else 
  {
    // if a connection connection can not be made:
    Serial.println(F("connection failed"));
  }
}

void temp()
{
    int val = analogRead(pinTemp); // get analog temperature value
    resistance=(float)(1023-val)*10000/val; // get resistance
    temperature=1/(log(resistance/10000)/B+1/298.15)-273.15; // This works out what the temperature is 
    temperature=degreeF(temperature); // This calls a function that turns the temperature value into fahrenheit 
    Serial.println(temperature); // returns the temperature value
}

float degreeF(float temp)
{
  float fah=temp*9/5+32; // converts the current temperature value to fahrenheit
  return fah; // retuns the fahrenheit value
}

void getMoistureValue()
{
   moistureSensorValue = analogRead(moistureSensor); // This gets the soil moisture value from the sensor
   moisture = (moistureSensorValue/1023.00)*100; // Gets the percentage of moisture (the reading is out of 1023)
   Serial.println(moisture); // prints the moisture value to the serial monitor
}


void playTone(int tone)
{
  for(byte i = 0; i<200; i++)
  {
        digitalWrite(speakerPin, HIGH); // turns the buzzer on
        delayMicroseconds(tone);
        digitalWrite(speakerPin, LOW);// turns the buzzer off
        delayMicroseconds(tone);
  }
}

void playNote(char note) 
{
    int tones[] = { 1915};
    playTone(tones[note]); // calls playTone to turn the buzzer on
}

void lcdscreen()
{
  lcd.setCursor(0, 0); 
  lcd.print("Moisture=");
  lcd.setCursor(10, 0);
  lcd.print(moisture); // prints the moisture
  lcd.setCursor(15, 0);
  lcd.print("%");  // prints "%"
  lcd.setCursor(0, 1); 
  lcd.print("Temp=");
  lcd.setCursor(6, 1); 
  lcd.print(temperature); // prints the temperature
  if(moisture <= 50)
  {
      analogWrite(pinLed, 255); // turns/keeps on the LED light
      colorR = 255; // sets colour to red
      colorG = 0;
      colorB = 0;
      lcd.setRGB(colorR, colorG, colorB); // makes the screen go red
      playNote(notes[0]); // sets off buzzer
  }
  else
  {
      analogWrite(pinLed, 0); // tunes off/keeps off the LED light off 
      colorR = 0;
      colorG = 255; // sets it to green
      colorB = 0;
      lcd.setRGB(colorR, colorG, colorB); // makes the screen go green
  }
}

void pump()
{
  if(moisture <= 50)
  {
    digitalWrite(relayPin, HIGH);
    updatewaterUse();
  }
  else
  {
    digitalWrite(relayPin, LOW);
  }
}

void updatewaterUse()
{
  postData3 = postVariable3 + waterOn;  // adds the temperature to the post variable
  // port 443 https and 80
  if (client.connect(server, 80))
  {
    client.println(F("POST /~rthibbert/project2.php HTTP/1.1")); // php page location that will handle the sensor values and store them in the database
    client.println(F("Host: 193.61.245.49")); // vesta server ip
    client.println(F("Content-Type: application/x-www-form-urlencoded"));
    client.print(F("Content-Length: "));
    client.println(postData3.length());
    client.println();
    client.print(postData3); // sends the data to the server (the webpage to the server)
    client.println();
    delay(2000); // 2 second delay
  } 
  else 
  {
    // if a connection connection can not be made:
    Serial.println(F("connection failed"));
  }
}
