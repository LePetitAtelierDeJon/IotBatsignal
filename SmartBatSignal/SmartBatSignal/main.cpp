#include <wiringPi.h>
#include <iostream>

#include "RestServer.h"
#include "LedBatSignal.h"

#define	LED	17

/**
 * Entry point for the Batsignal code.
 */
int main(void) {
    std::cout << "Starting Batsignal...\n";
    wiringPiSetupSys();

    std::unique_ptr<RestServer>server;
    utility::string_t port = U("80");
    utility::string_t address = U("http://0.0.0.0:");
    address.append(port);

    web::uri_builder uri(address);
    uri.append_path(U("batsignal/"));

    auto addr = uri.to_uri().to_string();
    server = std::unique_ptr<RestServer>(new RestServer(addr));

    std::shared_ptr<AbstractBatSignal> batSignal = std::make_shared<LedBatSignal>();

    /*server->addPutCallCallaback(std::bind(&BatSignalRestHandler::putBatSignal, batHandler, std::placeholders::_1));
    server->addGetCallCallaback(std::bind(&BatSignalRestHandler::getBatSignal, batHandler, std::placeholders::_1));*/

    pinMode(LED, OUTPUT);

    while (true) {
        digitalWrite(LED, HIGH);  // On
        delay(500); // ms
        digitalWrite(LED, LOW);	  // Off
        delay(500);
    }
    return 0;
}