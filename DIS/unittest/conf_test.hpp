//
// Created by WangQing on 06/05/2018.
//

#ifndef UNITTEST_CONF_HPP
#define UNITTEST_CONF_HPP

#include "minunit/minunit.h"

#include "common/utils.hpp"
#include "app/conf.hpp"

MU_TEST(conf_case1) {
    Conf conf("../conf/server.conf");

    boost::any a = conf.getConf("port");
    int port = utils::get<int>(a);
    mu_check(8081 == port);
    mu_check(8082 != port);


}

MU_TEST_SUITE(conf) {
    MU_RUN_TEST(conf_case1);
}

#endif //UNITTEST_CONF_HPP
