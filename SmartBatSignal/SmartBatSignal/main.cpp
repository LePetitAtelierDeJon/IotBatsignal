#include <wiringPi.h>
#include <iostream>

#include "RestServer.h"
#include "LedBatSignal.h"
#include "BatSignalRestHandler.h"

#define	LED	17

/**
 * Entry point for the Batsignal code.
 */
int main(void)
{
    std::cout << "Starting Batsignal...\n";
    wiringPiSetupSys();

    // Compose url.
    utility::string_t port = U("80");
    utility::string_t address = U("http://0.0.0.0:");
    address.append(port);
    web::uri_builder uri(address);
    uri.append_path(U("batsignal/"));
    auto addr = uri.to_uri().to_string();

    // Create REST Server.
    RestServer server(addr);

    // Create LedBatSignal.
    std::shared_ptr<AbstractBatSignal> batSignal = std::make_shared<LedBatSignal>();

    // Create rest handler.
    BatSignalRestHandler batHandler = BatSignalRestHandler(batSignal);

    // Register methods.
    server.addPutCallCallaback(std::bind(&AbstractRestHandler::put, batHandler, std::placeholders::_1));
    server.addGetCallCallaback(std::bind(&AbstractRestHandler::get, batHandler, std::placeholders::_1));

    // Infinite loop.
    while (true) //get char to quit.
    {
    }

    std::cout << "end\n";

    return 0;
}