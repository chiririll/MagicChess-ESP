#ifndef SERVER_H
#define SERVER_H

#include <ESP8266WiFi.h>

WebServer server(80);

namespace api {

    namespace board {
        // Set figures on defined positions
        void setConfig() {}

        // Get positions of figures
        void getConfig() {}

        // Move figure
        void step() {}

        // Set default configuration
        void reset() {}
    }

    namespace wifi {
        void add() {}
        void get() {}
        void connect() {}
        void edit() {}
        void delete() {}
    }

    namespace display {
        void write() {}
        void clear() {}
    }

    void start() {
        server.begin();

        server.on("/board/set_configuration", api::board::setConfig);
        server.on("/board/get_configuration", api::board::getConfig)
        server.on("/board/step", api::board::step)
        server.on("/board/reset", api::board::reset)
        server.on("/wifi/add", api::wifi::add)
        server.on("/wifi/get", api::wifi::get)
        server.on("/wifi/connect", api::wifi::connect)
        server.on("/wifi/edit", api::wifi::edit)
        server.on("/wifi/delete", api::wifi::delete)
        server.on("/display/write", api::display::write)
        server.on("/display/clear", api::display::clear)
    }

}
#endif
