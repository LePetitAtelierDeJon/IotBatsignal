#include <iostream>

#include "BatSignalRestHandler.h"

BatSignalRestHandler::BatSignalRestHandler(std::shared_ptr<AbstractBatSignal> batSignal) : batSignal_(batSignal)
{
}

void BatSignalRestHandler::put(web::http::http_request message)
{
    std::cout << "* put ";

    auto paths = web::uri::split_path(web::uri::decode(message.relative_uri().path()));

    if (U("light") == paths[0])
    {
        std::cout << "light\n";
        auto json = message.extract_json().get();

        State state = State::FromJSON(json.as_object());
        batSignal_->turnTheLight(state.value);
        message.reply(web::http::status_codes::OK);
    }
    else if (U("batSignal") == paths[0])
    {
        std::cout << "batSignal\n";
        batSignal_->triggerSignal();
        message.reply(web::http::status_codes::OK);
    }
    else
    {
        message.reply(web::http::status_codes::BadRequest);
        std::cout << "Bad Request\n";
    }
}

void BatSignalRestHandler::get(web::http::http_request message)
{
    std::cout << "* get " << std::endl;
    std::cout << message.relative_uri().path() << "\n";
    auto paths = web::uri::split_path(web::uri::decode(message.relative_uri().path()));
    if (U("light") == paths[0])
    {
        std::cout << "light\n";
        State state = State();
        state.value = batSignal_->lightStatus();

        auto json = state.AsJSON();

        message.reply(web::http::status_codes::OK, json);
    }
    else
    {
        std::cout << "Bad Request\n";
        message.reply(web::http::status_codes::BadRequest);
    }
}

void BatSignalRestHandler::push(web::http::http_request message)
{
    std::cout << "push : not used for batsignal\n";
}

void BatSignalRestHandler::del(web::http::http_request message)
{
    std::cout << "delete : not used for batsignal\n";
}