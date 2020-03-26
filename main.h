/* Settings */
#define DEBUG_MODE true
#define DEVICE_ID 1
/* ----- */

/* Libraries */

// System
#include <Arduino.h>

// Interfaces
#include <Wire.h>
#define DS3231_SCL 4
#define DS3231_SDA 2

// Display
#include <LiquidCrystal_I2C.h>

// ESP8266
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>

/* ----- */

/* Functions */

/* ----- */

/* Files */
#include "display.h"
#include "debug.h"
#include "server.h"
/* ----- */
