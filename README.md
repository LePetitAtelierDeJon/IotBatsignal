# IOT Batsignal
This project is the code for an IOT Batsignal powered by a RaspberryPi.
It provides a tiny REST API to control the light of the Batsignal.

The models for 3D print the signal can be found [here](https://cults3d.com/fr/modèle-3d/gadget/raspberry-pi-powered-iot-batsignal).

## Installation
### dependencies to install
* [cpprestsdk](https://github.com/microsoft/cpprestsdk) : ```sudo apt-get install libcpprest-dev```
* [wiringpi](http://wiringpi.com/download-and-install/) : ```sudo apt-get install wiringpi```
* others : ```sudo apt-get install libcurl-openssl-dev```

### Build with Visual Studio
The project provides an sln file to crossbuild and deploy the code directly on a raspberry pi from a windows computer.
more informations : https://docs.microsoft.com/en-us/cpp/linux/?view=vs-2019

### Build on raspbian 
```g++ -std=c++11 RestServer.cpp main.cpp -o main -lwiringPi -lcurl -lboost_system -lcrypto -lssl -lcpprest -lm -lpthread```

### Export the gpio to be used in a user software
```gpio export 17 output```

### Setup the software to be launched at startup
Edit the rc.local file : ```sudo nano /etc/rc.local```
Then add before the line ```exit 0``` the following lines :
```
gpio export 17 output
/home/pi/SmartBatSignal.out
```
### Set static IP address :
Edit dhcpcd.conf file : ```sudo nano /etc/dhcpcd.conf```
under the line ```#interface eth0``` add the line :
```static ip_address=<IP_ADDRESS>/24```

## How to use the API
### Turn on/off the light
* Request Type : **PUT**
* Path : ```http://<RPI_IP>:80/batsignal/light/```
* Body : ```{ "state" : <boolean>}```

The state variable in the body defines if the light is on(true) or off(false).

### Make the signal blink 3 times
* Request Type : **PUT**
* Path :  ```http://<RPI_IP>:80/batsignal/batSignal/```
* Body : none

### Get the light status
* Request Type : **GET**
* Path : ```http://<RPI_IP>:80/batsignal/light/```
* Response : ``` {"state": <Boolean>} ```

The state variable in the response defines if the light is on(true) or off(false).
