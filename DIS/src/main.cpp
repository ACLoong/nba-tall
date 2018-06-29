#include "controller/controllerbinder.hpp"

#include <iostream>
#include <handy/handy.h>

using namespace std;
using namespace handy;
int main(int argc, char **argv) {

    int threads = 1;
    if (argc > 1) {
        threads = atoi(argv[1]);
    }
    setloglevel("TRACE");
    MultiBase base(threads);
    HttpServer sample(&base);
    int r = sample.bind("", 8081);
    exitif(r, "bind failed %d %s", errno, strerror(errno));

    ControllerBinder controllerBinder;
    controllerBinder.bindAll(sample);

    Signal::signal(SIGINT, [&]{base.exit();});
    base.loop();

    return 0;
}
