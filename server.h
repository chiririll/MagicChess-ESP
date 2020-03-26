#ifndef SERVER_H
#define SERVER_H

#include <ESP8266WiFi.h>

WebServer server(80);

namespace api {

    namespace board {
        // Set figures on defined positions
        String setConfig() {}

        // Get positions of figures
        String getConfig() {}

        // Move figure
        String step() {}

        // Set default configuration
        String reset() {}
    }

    namespace wifi {
        // Save WiFi network to memory
        String add() {}

        // Get all WiFi networks
        String get() {}

        // Connect to any wifi network
        String connect() {}

        // Edit saved wifi network
        String edit() {}

        // Delete wifi network from memory
        String del() {}
    }

    namespace display {
        // Write something on display
        String write() {}

        // Clear display
        String clear() {}
    }

    void start() {
        server.begin();

        server.on("/board/set_configuration", [](){
            server.send(200, "text/plain", api::board::setConfig());
        });

        server.on("/board/get_configuration", [](){
            server.send(200, "text/plain", api::board::getConfig());
        });

        server.on("/board/step", [](){
            server.send(200, "text/plain", api::board::step());
        });

        server.on("/board/reset", [](){
            server.send(200, "text/plain", api::board::reset());
        });

        server.on("/wifi/add", [](){
            server.send(200, "text/plain", api::wifi::add());
        });

        server.on("/wifi/get", [](){
            server.send(200, "text/plain", api::wifi::get());
        });

        server.on("/wifi/connect", [](){
            server.send(200, "text/plain", api::wifi::connect());
        });

        server.on("/wifi/edit", [](){
            server.send(200, "text/plain", api::wifi::edit());
        });

        server.on("/wifi/remove", [](){
            server.send(200, "text/plain", api::wifi::remove());
        });

        server.on("/display/write", [](){
            server.send(200, "text/plain", api::display::write());
        });

        server.on("/display/clear", [](){
            server.send(200, "text/plain", api::display::clear());
        });
    }

}
#endif
