# XIAO RP2040

## RP2040 - RGB LED - WP154A4SEJ3VBDZGW
[WP154A4SEJ3VBDZGW](https://www.digikey.com/en/products/detail/kingbright/WP154A4SEJ3VBDZGW-CA/6569334) is a 
Red, Green, Blue (RGB) 625nm Red, 525nm Green, 470nm Blue LED Indication - Discrete 2.2V Red, 3.3V Green, 3.3V Blue Radial LED diodei9k

## RP2040 - Analog sensor - MCP9701
[MCP9701](https://store.comet.bg/Catalogue/Product/5003942/) family of sensors with Linear Active Thermistor Integrated Circuit
(IC) comprise a family of analog temperature sensors that convert temperature to analog voltage.
The low-cost, low-power sensors feature an accuracy of ±1°C from +20°C to +70°C (MCP9700B), ±2°C from
0°C to +70°C (MCP9700A/9701A) and ±4°C from 0°C to +70°C (MCP9700/9701) while consuming 6 µA (typical) of operating current.

## RP2040 - Digital sensor - DS18B20
[DS18B20](https://store.comet.bg/en/Catalogue/Product/29267/)The DS18B20 Digital Thermometer provides 9 to 12-bit (configurable) temperature readings which
indicate the temperature of the device.
Information is sent to/from the DS18B20 over a 1-Wire interface, so that only one wire (and ground)
needs to be connected from a central microprocessor to a DS18B20. Power for reading, writing, and
performing temperature conversions can be derived from the data line itself with no need for an external
power source.
Because each DS18B20 contains a unique silicon serial number, multiple DS18B20s can exist on the
same 1-Wire bus. This allows for placing temperature sensors in many different places.

## RP2040 - Digital sensor - DHT11
[DHT11](https://store.comet.bg/Catalogue/Product/50012/) is basic, ultra low-cost digital temperature and humidity sensor. 
It uses a capacitive humidity sensor and a thermistor to measure the surrounding air and spits out a digital signal on the data pin 
(no analog input pins needed). It's fairly simple to use but requires careful timing to grab data.

## RP2040 - E-Paper display- GDEW0154Z17
[GDEW0154Z17](https://www.good-display.com/product/1.54-inch-color-e-paper-display-module,-GDEW0154Z17-204.html)
This is an E ink E paper display panel, 1.54 inch, 152x152 resolution, square, 24 pins FPC connection, optional FPC connector, communicating via SPI interface, with embedded controller(COG package) and on-chip stored waveform,supports red, black, and white three-color. It's IC Driver is UC8151C.
In view of so many advantages: ultra low power consumption, near 180 degree view angle, readable under sunlight, GDEW0154Z17 is a very good choice for applications like:
Shelf label
Smart tags
Wearable devices, smart home application, industrial instrument,
Smart cards and other related products.
Note: All of 3-color epaper doesn't support partial refresh.
Key features are:
hree colors, black, white and red
152x152 resolution
Come with helpful development resources and manual
Front light, Touch screen(Optional)
The I2C signal master interface to read built-in temperature sensor.

### LIbraries for GDEW0154Z17
- [GxEPD](https://github.com/ZinggJM/GxEPD)

### Libraries for DHT11
- [DHT lib](https://github.com/adidax/dht11)

### Libraries for DS18B20
- [DallasTemperature](https://github.com/milesburton/Arduino-Temperature-Control-Library)
- [OneWire](https://www.pjrc.com/teensy/td_libs_OneWire.html)
## Used Software
- [Arduino IDE](https://www.arduino.cc/en/software/)  Version 2.3.6