#ifndef ABSTRACT_REST_HANDLER_H_
#define ABSTRACT_REST_HANDLER_H_

#include <cpprest/http_listener.h>

class AbstractRestHandler
{
public:
    virtual void put(web::http::http_request message) = 0;
    virtual void get(web::http::http_request message) = 0;
    virtual void push(web::http::http_request message) = 0;
    virtual void del(web::http::http_request message) = 0;
};

#endif // !ABSTRACT_REST_HANDLER_H_
