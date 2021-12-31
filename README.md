# TouhouWatchy

Touhou inspired Watch Face for Watchy hardware.

Touhou images generated from http://javl.github.io/image2cpp/

# Setup
copied from https://github.com/sqfmi/Watchy
1. In the Arduino IDE Boards Manager, install support for the ESP32. You can find instructions here: https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html
    * Arduino > Preferences > Additional Board Manager URL's
    * ```https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json```
2. Compile & Upload with these board settings:
    * Board: "ESP32 Dev Module"
    * Partition Scheme: "Minimal SPIFFS"
    * All Other Settings: leave to default

You may also have to install the [CP2104 USB to Serial drivers](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) if the port is not automatically detected

I had to edit the Watchy source code so I have included it in my repo so you do not have to install the library
in the arduino ide.
