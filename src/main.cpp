#include "Config.h"
#include <Arduino.h>
#include "HueClient.h"
#include "HueGroup.h"
#include <WiFi.h>
#include <WiFiMulti.h>
#include <Bounce2.h>

#define USE_SERIAL Serial

HueClient conn(HUE_IP, HUE_API_USERNAME);
HueGroup group(conn, HUE_GROUP);
Button b = Button();

void setup()
{
    USE_SERIAL.begin(115200);

    // Connect to wifi
    WiFiMulti wifiMulti;
    for (uint8_t t = 4; t > 0; t--)
    {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
    }
    wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
    if ((wifiMulti.run() != WL_CONNECTED))
    {
        USE_SERIAL.println("Unable to connect");
    }

    b.attach(PIN_BUTTON, INPUT);
    b.interval(100);
    b.setPressedState(HIGH);
    pinMode(PIN_LED, OUTPUT);
}

void loop()
{
    b.update();

    if(b.pressed()) {
        group.toggle();
        USE_SERIAL.println("toggled");
        digitalWrite(PIN_LED, HIGH);
        delay(5000);
        digitalWrite(PIN_LED, LOW);
    }
}
