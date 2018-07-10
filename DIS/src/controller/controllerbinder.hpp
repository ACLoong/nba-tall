//
// Created by WangQing on 14/04/2018.
//

#ifndef PCOC_VIEWERBINDER_H
#define PCOC_VIEWERBINDER_H

#include "basecontroller.hpp"

#include <iostream>

using namespace std;
using namespace handy;

class ControllerBinder {
public:
    void bindAll(handy::HttpServer& httpServer) {
        //shared_ptr<BaseViewer> viewer = make_shared<VersionViewer>(httpServer);

        //remeber to delete
    }
};

#endif //PCOC_VIEWERBINDER_H
