#include "Config.h"
#include <Arduino.h>
#include "HueClient.h"
#include "HueGroup.h"
#include <WiFi.h>
#include <WiFiMulti.h>
#include <OneButton.h>

#define USE_SERIAL Serial

HueClient conn(HUE_IP, HUE_API_USERNAME);
HueGroup group(conn, HUE_GROUP);
OneButton b = OneButton(PIN_BUTTON, false, false);

static void blink() {
    digitalWrite(PIN_LED, HIGH);
    delay(100);
    digitalWrite(PIN_LED, LOW);
    delay(100);
    digitalWrite(PIN_LED, HIGH);
    delay(100);
    digitalWrite(PIN_LED, LOW);
    delay(100);
    digitalWrite(PIN_LED, HIGH);
    delay(100);
    digitalWrite(PIN_LED, LOW);
}

static void handleSingleClick() {
    group.toggle();
    USE_SERIAL.println("single click");
    blink();
}

static void handleDoubleClick() {
    group.scrollBrightnessTick();
    USE_SERIAL.println("double click");
    blink();
}

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

    pinMode(PIN_LED, OUTPUT);
    b.attachClick(handleSingleClick);
    b.attachDoubleClick(handleDoubleClick);
}

void loop()
{
    b.tick();
    delay(10);
}
