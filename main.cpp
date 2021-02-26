// (c) 2019 Nick Gerakines
// This code is licensed under MIT license

#include <signal.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "cpprest/http_listener.h"

using namespace std;
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;



class Server
{
public:
    Server() : m_listener(U("http://0.0.0.0:8080/"))
    {
        m_listener.support(methods::GET, bind(&Server::handle_get, this, placeholders::_1));
    }

    pplx::task<void> open() { return m_listener.open(); }
    pplx::task<void> close() { return m_listener.close(); }

private:
    void handle_get(http_request message)
    {
        std::string msg = U("Hello world!\n");
        cout << "Mensaje entrante" << endl;      
        message.reply(status_codes::OK, msg);
    }

    http_listener m_listener;
};

unique_ptr<Server> g_httpServer;

void signalHandler(int signum)
{
    g_httpServer->close().wait();
    exit(signum);
}

int main()
{
    g_httpServer = unique_ptr<Server>(new Server());
    g_httpServer->open().wait();

    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);

    while (1)
    {
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}