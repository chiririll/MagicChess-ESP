#ifndef DEBUG_H
#define DEBUG_H

namespace debug {
    void log(String message)
    {
        if (!DEBUG_MODE)
            return;
        Serial.println("[INFO]: " + message);
    }

    void log(String message, char status)
    {
        if (!DEBUG_MODE)
            return;

        String s;
        switch (status) {
            case 'w':
                s = "WARN";
                break;
            case 'e':
                s = "ERROR";
                break;
            case 'c':
                s = "CRITICAL ERROR";
                break;
            default:
                s = "INFO";
        }
        Serial.println("[" + s + "]: " + message);
    }
}
#endif
