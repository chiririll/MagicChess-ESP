#include "main.h"

bool connect();

void Setup()
{
    Serial.begin(115200);
    debug::log("Starting...");
    led::progressBar("Starting");

    lcd.init();
    lcd.backlight();

    if (!connect()) {
        // TODO: create AP
    }
}

// Read password from memory and connect to wifi hotspot
bool connect() {
    debug::log("Scanning wifi...");
    led::progressBar("Connecting");

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    int n = WiFi.scanNetworks();
    if (n == 0) {
        debug::log("Networks not found!", 'w');
        return false;
    }

    debug::log("Found " + String(n) + " networks");

    debug::log("Reading passwords from memory...")
    File passwords = SPIFFS.open("/passwords.txt", 'r');

    if (!passwords) {
        debug::log("File passwords not found!", 'w');
        return false;
    }

    // TODO: get passwords from memory
    // TODO: connect to wifi

    return false;
}
