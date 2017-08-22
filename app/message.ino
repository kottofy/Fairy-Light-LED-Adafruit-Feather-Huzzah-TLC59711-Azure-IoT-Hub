#include <ArduinoJson.h>

// void createMessage(int messageId, char *payload)
// {
//     StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
//     JsonObject &root = jsonBuffer.createObject();
//     root["deviceId"] = DEVICE_ID;
//     root["messageId"] = messageId;
   
//     root.printTo(payload, MESSAGE_MAX_LEN);
// }

String getColor(char json[])
{
    StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(json);

    // Test if parsing succeeds.
    if (!root.success()) {
        Serial.println("parseObject() failed");
        return "-1";
    }

    String color = root["color"];
    // Serial.println(color);    

   
    return color;
}

uint16_t getRed(String json) {
    uint16_t red = 0;

    StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(json);

    // Test if parsing succeeds.
    if (!root.success()) {
        Serial.println("parseObject() failed");
        return -1;
    }

    red = (uint16_t)root["red"];

    return red*256;
}

uint16_t getGreen(String json) {
    uint16_t green = 0;
    
    StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(json);

    // Test if parsing succeeds.
    if (!root.success()) {
        Serial.println("parseObject() failed");
        return -1;
    }

    green = (uint16_t)root["green"];

    return green*256;
}

uint16_t getBlue(String json) {
    uint16_t blue = 0;

    StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(json);

    // Test if parsing succeeds.
    if (!root.success()) {
        Serial.println("parseObject() failed");
        return -1;
    }

    blue = (uint16_t)root["blue"];

    return blue*256;
}

void parseTwinMessage(char *message)
{
    StaticJsonBuffer<MESSAGE_MAX_LEN> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(message);
    if (!root.success())
    {
        Serial.printf("Parse %s failed.\r\n", message);
        return;
    }
}
