#ifndef REST_SERVER_H_
#define REST_SERVER_H_

#include <cpprest/http_listener.h>

class RestServer
{
public:
    /**
     * Default constructor.
     */
    RestServer();

    /**
     * Constructor with uri.
     * @param uri Uri to use for the REST server.
     */
    RestServer(utility::string_t uri);

    ~RestServer();

    /**
     * Open the listener.
     */
    inline pplx::task<void> open()
    {
        return listener_.open();
    }

    /**
     * Close the listener.
     */
    inline pplx::task<void> close()
    {
        return listener_.close();
    }

    /**
     * Add callback for a get call.
     * @param callback Callback for get call.
     */
    void addGetCallCallaback(std::function<void(web::http::http_request)> callback);

    /**
     * Add callback for a put call.
     * @param callback Callback for put call.
     */
    void addPutCallCallaback(std::function<void(web::http::http_request)> callback);

    /**
     * Add callback for a push call.
     * @param callback Callback for push call.
     */
    void addPushCallCallaback(std::function<void(web::http::http_request)> callback);

    /**
     * Add callback for a delete call.
     * @param callback Callback for delete call.
     */
    void addDeleteCallCallaback(std::function<void(web::http::http_request)> callback);

private:
    web::http::experimental::listener::http_listener listener_;
};

#endif // REST_SERVER_H_