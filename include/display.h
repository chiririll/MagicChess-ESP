#ifndef DISPLAY_H
#define DISPLAY_H

#include <LiquidCrystal_I2C.h>

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
}

#endif
