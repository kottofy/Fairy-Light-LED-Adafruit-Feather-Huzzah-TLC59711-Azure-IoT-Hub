#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <WiFiUdp.h>

void initWifi()
{
    Serial.println("Initializing Wifi.");

    static char *ssid = WIFI_SSID;
    static char *pass = WIFI_PASS;

    // Attempt to connect to Wifi network:
    // Serial.printf("Attempting to connect to SSID: %s.\r\n", ssid);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        // Get Mac Address and show it.
        // WiFi.macAddress(mac) save the mac address into a six length array, but the endian may be different. The huzzah board should
        // start from mac[0] to mac[5], but some other kinds of board run in the oppsite direction.
        uint8_t mac[6];
        WiFi.macAddress(mac);
        Serial.printf("Your device with MAC address %02x:%02x:%02x:%02x:%02x:%02x connection to %s failed! Waiting 10 seconds to retry.\r\n",
                      mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], ssid);
        WiFi.begin(ssid, pass);
        delay(10000);
    }
    // Serial.printf("Wifi successfully initialized. Connected to wifi %s.\r\n", ssid);
}

void initSerial()
{
    int baudrate = 115200;
    
    Serial.printf("Initializing Serial at %i.", baudrate);

    // Start serial and initialize stdout
    Serial.begin(baudrate); 
    Serial.setDebugOutput(true);
    // Serial.println("Serial successfully initialized.");
    delay(3000);
}

void initTime()
{
    Serial.println("Initializing Time.");

    time_t epochTime;
    configTime(0, 0, "pool.ntp.org", "time.nist.gov");

    while (true)
    {
        epochTime = time(NULL);

        if (epochTime == 0)
        {
            Serial.println("Fetching NTP epoch time failed! Waiting 2 seconds to retry.");
            delay(2000);
        }
        else
        {
            // Serial.printf("Time successfully initialized. Fetched NTP epoch time is: %lu.\r\n", epochTime);
            break;
        }
    }
}