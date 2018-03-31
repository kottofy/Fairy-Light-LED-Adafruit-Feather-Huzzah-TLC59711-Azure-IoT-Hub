uint16_t red = 0;
uint16_t green = 0;
uint16_t blue = 0;
char *method = "";

void displayMethod()
{
    Serial.println("displayMethod");

    char *methodName = getMethod();

    Serial.printf("Displaying: %s. \r\n", methodName);

    if (methodName != "")
    {
        Serial.println("displayMethod() - IF");

        if (methodName == "rgbWipeCycle")
        {
            rgbWipeCycle();
        }
        else if (methodName == "stop")
        {
            stopLEDs();
        }
        else if (methodName == "rainbow")
        {
            rainbow();
        }
        else if (methodName == "rainbowCycle")
        {
            rainbowCycle();
        }
        else if (methodName == "holidayWipe")
        {
            holidayWipe();
        }
        else if (methodName == "RGB")
        {
            colorWipe(red, green, blue, 5);
        }
    }
    else
    {
        Serial.println("displayMethod() - ELSE");

        colorWipe(255*256, 255*256, 255*256, 5);
    }
}

bool setReceivedMethod(String methodName)
{
    Serial.println("setReceivedMethod");

    bool result = true;
    char *tempMethod = "";

    if (methodName != "-1")
    {
        Serial.println("setReceivedMethod - IF");

        if (methodName == "rainbow")
        {
            Serial.println("RAINBOW");
            tempMethod = "rainbow";
        }
        else if (methodName == "rainbowCycle")
        {
            Serial.println("RAINBOW CYCLE");
            tempMethod = "rainbowCycle";
        }
        else if (methodName == "rgbWipeCycle")
        {
            Serial.println("RGB WIPE CYCLE");
            tempMethod = "rgbWipeCycle";
        }
        else if (methodName == "stop")
        {
            Serial.println("STOP");
            tempMethod = "stop";
        }
        else if (methodName == "holidayWipe")
        {
            Serial.println("HOLIDAY");
            tempMethod = "holidayWipe";
        }
        else
        {
            Serial.println("RGB (else)");
            result = false;
            tempMethod = "RGB";
            red = getRed(methodName);
            green = getGreen(methodName);
            blue = getBlue(methodName);

            if (red == -1 || green == -1 || blue == -1)
            {
                Serial.println("Something went wrong with RGB colors. Setting to 0, 0, 0.");
                red = 0;
                green = 0;
                blue = 0;
            }
        }
    }
    else
    {
        Serial.println("setReceivedMethod - ELSE");
    }
    setMethod(tempMethod);
    return result;
}