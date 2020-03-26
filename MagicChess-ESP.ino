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

void Loop() {}

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

    debug::log("Open file with passwords...");
    File file = SPIFFS.open("/passwords.txt", 'r');

    if (!file) {
        debug::log("File passwords not found!", 'w');
        return false;
    }

    debug::log("Success!");

    std::map <String, String> networks;
    String now_SSID = "";
    String now_passw = "";
    char reading = 's';

    debug::log("Reading networks...");

    for (int i = 0; i < file.size(); i++) {
        char symb = (char) file.read();
        switch (symb) {
            case ',':
                reading = 'p';
                break;
            case ';':
                networks[now_SSID] = now_passw;
                now_SSID = "";
                now_passw = "";
                reading = 's';
                break;
            default:
                if (reading == 's')
                    now_SSID += symb;
                else
                    now_passw += symb;
        }
    }
    file.close();
    debug::log("Done!");

    debug::log("Finding matches...");

    std::map<String, String>::iterator it;

    for (int i = 0; i < n; i++) {
        it = networks.find(WiFi.SSID(i));
        if (it == networks.end())
            continue;
        WiFi.begin(WiFi.SSID(i), it->second);
        debug::log("Connecting to " + String(it->second));

        for (int a = 1; a <= 5 && WiFi.status() != WL_CONNECTED; a++) {
            debug::log("Attempt " + String(a) + "/5");
            led::updProgress(a/5);
            delay(500);
        }

        if (WiFi.status() == WL_CONNECTED) {
            debug::log("Connected!");
            return true;
        } else
            debug::log("Failed!");
    }

    return false;
}
