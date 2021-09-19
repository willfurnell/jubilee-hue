// GPIO config
#define PIN_BUTTON 22 // The pin the button is connected to
#define PIN_LED 23 // The pin the LED is connected to

// Wifi Config
#define WIFI_SSID "ssid"
#define WIFI_PASSWORD "pass"

// Hue Config
#define HUE_IP "192.168.0.99" // IP of your hue bridge (you might want to give it a static IP on your router), see https://www.meethue.com/api/nupnp
#define HUE_API_USERNAME "removed" // See https://developers.meethue.com/develop/get-started-2/
#define HUE_GROUP 1 // Numeric id of the group of lights you want to control, call hue api /api/{ username }/groups for this
char scenes[3][16] = { // 15 digit ids of the scenes you want the switch to iterate through. Call hue api /api/{ username }/scenes for these
    "R6zUoRDxO1r7x2R", // Choose only scenes available for your chosen group
    "meAL1gcxZGbxVk-",
    "m8Q-pEzTK39NrAw"
};
