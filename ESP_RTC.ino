/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TimeLib.h>
#include <WidgetRTC.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "b7ecd26a4a1040c7b0317e53e92b797a";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SingaporeMilitia";
char pass[] = "123Qweasd";

BlynkTimer timer;
WidgetLED led1(V0);
WidgetRTC rtc;
int ledState = LOW;

// Digital clock display of the time
void clockDisplay()
{
  // You can call hour(), minute(), ... at any time
  // Please see Time library examples for details

  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  String currentDate = String(day()) + " " + month() + " " + year();
  Serial.print("Current time: ");
  Serial.print(currentTime);
  Serial.print(" ");
  Serial.print(currentDate);
  Serial.println();

  // Send time to the App
  Blynk.virtualWrite(V1, currentTime);
  // Send date to the App
  Blynk.virtualWrite(V2, currentDate);

  Serial.print("Hour : ");
  Serial.print(hour());
  Serial.print(" | Minute : ");
  Serial.print(minute());
  Serial.print(" | Second : ");
  Serial.print(second());
  Serial.println();

  Serial.print("Day : ");
  Serial.print(day());
  Serial.print(" | Month : ");
  Serial.print(month());
  Serial.print(" | Year : ");
  Serial.print(year());
  Serial.println();
}

BLYNK_WRITE(V3) {
  
  ledState = param.asInt();
  digitalWrite(LED_BUILTIN, ledState);
  Serial.print("ledState : ");
  Serial.print(ledState);
  Serial.println();

  Serial.print("Hour : ");
  Serial.print(hour());
  Serial.print(" | Minute : ");
  Serial.print(minute());
  Serial.print(" | Second : ");
  Serial.print(second());
  Serial.println();

  Serial.print("Day : ");
  Serial.print(day());
  Serial.print(" | Month : ");
  Serial.print(month());
  Serial.print(" | Year : ");
  Serial.print(year());
  Serial.println();

  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  String currentDate = String(day()) + " " + month() + " " + year();
  Serial.print("Current time: ");
  Serial.print(currentTime);
  Serial.print(" ");
  Serial.print(currentDate);
  Serial.println();

  // Send time to the App
  Blynk.virtualWrite(V1, currentTime);
  // Send date to the App
  Blynk.virtualWrite(V2, currentDate);
  
}

BLYNK_CONNECTED() {
  // Synchronize time on connection

  rtc.begin();

  led1.off();
  delay(1000);
  led1.on();

  Serial.print("Hour : ");
  Serial.print(hour());
  Serial.print(" | Minute : ");
  Serial.print(minute());
  Serial.print(" | Second : ");
  Serial.print(second());
  Serial.println();

  Serial.print("Day : ");
  Serial.print(day());
  Serial.print(" | Month : ");
  Serial.print(month());
  Serial.print(" | Year : ");
  Serial.print(year());
  Serial.println();

  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  String currentDate = String(day()) + " " + month() + " " + year();
  Serial.print("Current time: ");
  Serial.print(currentTime);
  Serial.print(" ");
  Serial.print(currentDate);
  Serial.println();

  // Send time to the App
  Blynk.virtualWrite(V1, currentTime);
  // Send date to the App
  Blynk.virtualWrite(V2, currentDate);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  // Other Time library functions can be used, like:
  //   timeStatus(), setSyncInterval(interval)...
  // Read more: http://www.pjrc.com/teensy/td_libs_Time.html

  setSyncInterval(10 * 60); // Sync interval in seconds (10 minutes)

  // Display digital clock every 10 seconds
  //timer.setInterval(1000L, clockDisplay);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  Blynk.run();
  //timer.run();
}

