# AcuaDom (in procces)

![](https://raw.githubusercontent.com/jero98772/AcuaDom/main/docs/logo.png)

Acuadom is a domotic fishtank system that provides an automated control for various aspects of a fishtank. The system is built using C++ and PlatformIO, and utilizes various sensors and relays to monitor and control the environment of the fishtank. It is developed for ESP32 board with Bluetooth connectivity and is licensed under GPL3.

## Shcema

![]()


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

(we are develoment an wifi conecty)


## Contributing
Contributions are welcome! If you would like to contribute to Acuadom, please fork the repository and submit a pull request with your changes.

## ToDo

- Iot conectivity with ubidots

## Photos



## Credits
Acuadom was developed by jero98772, with the help of Sara Domingez,Camilo and Checho. The code is licensed under the GPL3 License.
