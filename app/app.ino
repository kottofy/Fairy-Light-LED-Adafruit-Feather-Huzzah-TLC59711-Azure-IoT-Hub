#include "config.h"
#include <AzureIoTHub.h>
#include <AzureIoTProtocol_MQTT.h>
#include <AzureIoTUtility.h>

static IOTHUB_CLIENT_LL_HANDLE iotHubClientHandle;

void setup()
{
    Serial.println("Initializing Setup.");

    initSerial();
    initWifi();
    initTime();
    initBuiltInLED();
    initTLC();
    initIoTHub();

    Serial.println("Done initializing setup. Here we go!");
}

void loop()
{
    displayMethod();
    checkNewMessages();
}
