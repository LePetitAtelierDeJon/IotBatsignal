# IOT Batsignal
This project contains code for a IOT batsignal powered by a RaspberryPi.

## Installation
### dependencies to install
* [cpprestsdk](https://github.com/microsoft/cpprestsdk) : ```sudo apt-get install libcpprest-dev```
* [wiringpi](http://wiringpi.com/download-and-install/) : ```sudo apt-get install wiringpi```
* others : ```sudo apt-get install libcurl-openssl-dev```


### Build on raspbian 
```g++ -std=c++11 RestServer.cpp main.cpp -o main -lwiringPi -lcurl -lboost_system -lcrypto -lssl -lcpprest -lm -lpthread```

### Setting up the gpio
```gpio export 17 output```

### Launch the program at launch
```sudo nano /etc/rc.local```

then add before the line ```exit 0```
```
gpio export 17 output
/home/pi/SmartBatSignal.out
```

## How to use the API
### Turn on/off the light
* Request Type : **PUT**
* Path : ```http://<RPI_IP>:80/batsignal/light/```
* Body : ```{ "state" : <boolean>}```

The state variable in the body defines if the light is on(true) or off(false).

### Make the signal blink 3 times
* Request Type : **PUT**
* Path :  ```http://<RPI_IP>:80//batsignal/batSignal/```
* Body : none

### Get the light status
* Request Type : **GET**
* Path : ```http://<RPI_IP>:80//batsignal/batSignal/```
* Response : ``` {"state": <Boolean>} ```

The state variable in the response defines if the light is on(true) or off(false).
