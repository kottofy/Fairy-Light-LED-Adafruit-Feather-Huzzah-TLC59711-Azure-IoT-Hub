// Copy this file and save it as config.h, then fill in the first three missing properties.
// Update any information that may be different for your app.

// IoT Hub Stuff
#define CONNECTION_STRING ""

// Wifi Stuff
#define WIFI_SSID ""
#define WIFI_PASS ""

// Physical device information for board and sensor
#define DEVICE_ID "Feather HUZZAH ESP8266 WiFi"

// EEPROM address configuration
#define EEPROM_SIZE 512

// SSID and SSID password's length should < 32 bytes
// http://serverfault.com/a/45509
#define SSID_LEN 32
#define PASS_LEN 32
#define CONNECTION_STRING_LEN 256
#define MESSAGE_MAX_LEN 256

// TLC59711 Stuff
#define NUM_TLC59711 1
#define DATA_PIN 13
#define CLOCK_PIN 15
