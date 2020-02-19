#include "RestServer.h"

RestServer::RestServer() : RestServer(U("")) {
}

RestServer::RestServer(utility::string_t uri) : listener_(uri) {
    open().wait();
}

RestServer::~RestServer() {
    close();
}

void RestServer::addGetCallCallaback(std::function<void(web::http::http_request)> callback) {
    std::cout << "Add get callback.\n";
    listener_.support(web::http::methods::GET, callback);
}

void RestServer::addPutCallCallaback(std::function<void(web::http::http_request)> callback) {
    std::cout << "Add put callback.\n";
    listener_.support(web::http::methods::PUT, callback);
}

void RestServer::addPushCallCallaback(std::function<void(web::http::http_request)> callback) {
    std::cout << "Add push callback.\n";
    listener_.support(web::http::methods::POST, callback);
}

void RestServer::addDeleteCallCallaback(std::function<void(web::http::http_request)> callback) {
    std::cout << "Add delete callback.\n";
    listener_.support(web::http::methods::DEL, callback);
}