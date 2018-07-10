//
// Created by WangQing on 06/05/2018.
//

#ifndef DIS_UTILS_TEST_HPP
#define DIS_UTILS_TEST_HPP

#include "common/utils.hpp"
#include "minunit/minunit.h"

MU_TEST(utils_case1) {
    boost::any a;
    int d = 5;
    a = d;
    mu_check(utils::can_cast<int>(a));
    if (utils::can_cast<int>(a)) {
        mu_check(5 == utils::get<int>(a));
        utils::get<int>(a) = 10;
        mu_check(10 == utils::get<int> (a));
    }
}

MU_TEST(utils_case2) {
    boost::any a;
    int d = 5;
    a = d;
    mu_check(!utils::can_cast<std::vector<int>>(a));

    if (utils::can_cast<int>(a)) {
        mu_check(0 != utils::get<int>(a));
        auto ptr = utils::get_pointer<int>(a);
        mu_check(5 == *ptr);
    }
}

MU_TEST_SUITE(utils) {
    MU_RUN_TEST(utils_case1);
    MU_RUN_TEST(utils_case2);
}


#endif //DIS_UTILS_TEST_HPP
