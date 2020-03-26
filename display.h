#ifndef DISPLAY_H
#define DISPLAY_H

LiquidCrystal_I2C lcd(0x27, 16, 2);

namespace led
{
    void progressBar(String title) {
        lcd.clear();
        int start = (16 - title.length()) / 2;
        lcd.home();
        lcd.print("################");
        lcd.setCursor(start, 0);
        lcd.print(title);
        lcd.setCursor(0, 1);
        lcd.print("----------------");
    }

    void updProgress (int progress) {
        lcd.setCursor(0, 1);
        for (int i = 0; i < progress*16; i++)
            lcd.write('=');

        for (int i = progress*16; i < 16; i++)
            lcd.write('-');
    }

    // TODO: Refactor
    void write () {
        String text;
        for (int i = 0; i < server.args(); i++) {
            if (server.argName(i) == "text")
                text = server.arg(i);
        }

        if (text == "")
            text = "Null";

        lcd.clear();
        lcd.setCursor(0, 0);

        for (int i = 0; i < 16 && i < text.length(); i++)
            lcd.print(text[i]);

        lcd.setCursor(0, 1);

        for (int i = 16; i < text.length(); i++)
            lcd.print(text[i]);
    }

    // TODO: Refactor
    void bl() {
        BackLight = !BackLight; // Global var
        lcd.setBacklight(BackLight);
    }
}

#endif
