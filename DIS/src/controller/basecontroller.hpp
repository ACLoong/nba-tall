//
// Created by WangQing on 14/04/2018.
//

#ifndef PCOC_BASEVIEWER_H
#define PCOC_BASEVIEWER_H

#include "json/json11.hpp"

#include <handy/handy.h>
#include <handy/http.h>
#include <string>

using namespace json11;
using namespace std;
using namespace handy;

#define implements :public

//Viewer Interface
class BaseController {
public:
    BaseController(handy::HttpServer &httpServer)
            : _httpServer(httpServer){}

    virtual ~BaseController() {}

    virtual string handle(const HttpRequest& req) = 0;

    void bindHandle(const std::string& uri) {
        _httpServer.onRequest("POST", uri, [this](const handy::HttpConnPtr& con){
            HttpRequest& req = con.getRequest();
            string v = req.version;
            HttpResponse resp;
            resp.body = Slice(handle(req));
            con.sendResponse(resp);
            if (v == "HTTP/1.0") {
                con->close();
            }
        }) ;
    }

protected:
    handy::HttpServer& _httpServer;
};

#endif //PCOC_BASEVIEWER_H
