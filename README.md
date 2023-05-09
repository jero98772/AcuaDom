# AcuaDom (in procces)

![](https://github.com/jero98772/AcuaDom/blob/firstPrototype/docs/images/logo.png?raw=true)

Acuadom is a domotic fishtank system that provides an automated control for various aspects of a fishtank. The system is built using C++ and PlatformIO, and utilizes various sensors and relays to monitor and control the environment of the fishtank. It is developed for ESP32 board with Bluetooth connectivity and is licensed under GPL3.

## Shcema

![Shema](https://raw.githubusercontent.com/jero98772/AcuaDom/main/docs/images/Schema.jpeg)

(neo pixels ring not are working in this version that is the reason becuase they are disconected of data and voltage)

## Features

- Turbidity Sensor: Measures the turbidity of the water in the fishtank.

- Water Temperature Sensor: Measures the temperature of the water in the fishtank.

- DHT Sensor: Measures the humidity and temperature of the air around the fishtank.

- Water Level Sensor: Monitors the level of the water in the fishtank.

- External Light Control Relays: Controls external lights that can be attached to the fishtank.

- Filter Control Relays: Controls filters that are attached to the fishtank.

- Thermostat: Maintains the temperature of the fishtank by turning on/off the heater.

- Neo Pixel LEDs: Provides smart lighting with different modes for morning, noon, afternoon, and night.

## Installation

1. Clone the Acuadom repository to your local machine.

2. Install PlatformIO and its dependencies.

You can install PlatformIO in code oss (visual studio code) or in emacs, or direct use in terminal with Pio command.

PlatformIO automatical install depenencies on PlatformIO.ini file.

3. Connect the sensors and relays to the ESP32 board as per the pinout specified in the code.

4. Upload the code to the ESP32 board.

you can use pio run

## Usage

Once the code has been uploaded to the ESP32 board, the system will start monitoring and controlling the fishtank environment. The system provides various modes for the Neo Pixel LEDs, which can be controlled using a Bluetooth connection and a mobile application.

to conect to network go to wifi you will be see a network name "ACUADOOM" and conect to that network in captive portal 

put your wifi name and password, next you need to search the ip of esp32 in your network and conect to them to see the variables like water temperature, water level, humidity, temperature of room, turbity and you can control relays in that web page.

or you can conect via bluethoot to HC-06 with app Arduino Bluethoot

## Contributing
Contributions are welcome! If you would like to contribute to Acuadom, please fork the repository and submit a pull request with your changes.

## ToDo

- Iot conectivity with ubidots

## Photos

![](https://raw.githubusercontent.com/jero98772/AcuaDom/main/docs/images/acuarium1.jpeg)

![](https://raw.githubusercontent.com/jero98772/AcuaDom/main/docs/images/acuarium2.jpeg)

![](https://github.com/jero98772/AcuaDom/blob/main/docs/images/appbluethoot.jpeg)

![](https://raw.githubusercontent.com/jero98772/AcuaDom/main/docs/images/wifimanager.jpeg)

![](https://github.com/jero98772/AcuaDom/blob/main/docs/images/wifiwebserver.jpeg)

## Credits
Acuadom was developed by jero98772, with the help of Sara Domingez,Camilo and Checho. The code is licensed under the GPL3 License.
