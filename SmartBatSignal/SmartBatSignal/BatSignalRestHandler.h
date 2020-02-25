#ifndef BATSIGNAL_REST_HANDLER_H_
#define BATSIGNAL_REST_HANDLER_H_

#include "AbstractRestHandler.h"
#include "AbstractBatSignal.h"

struct State
{
    bool value;

    static State FromJSON(const web::json::object& object)
    {
        State state;
        state.value = object.at(U("state")).as_bool();

        return state;
    }

    web::json::value AsJSON() const
    {
        web::json::value result = web::json::value::object();
        result[U("state")] = web::json::value::boolean(value);
        return result;
    }
};

class BatSignalRestHandler :
    public AbstractRestHandler
{
public:
    BatSignalRestHandler(std::shared_ptr<AbstractBatSignal> batSignal);

    // Inherited via AbstractRestHandler
    virtual void put(web::http::http_request message) override;
    virtual void get(web::http::http_request message) override;
    virtual void push(web::http::http_request message) override;
    virtual void del(web::http::http_request message) override;
private:
    std::shared_ptr<AbstractBatSignal> batSignal_;
};

#endif // BATSIGNAL_REST_HANDLER_H_