//
// Created by WangQing on 05/05/2018.
//

#include "minunit/minunit.h"
#include "conf_test.hpp"
#include "utils_test.hpp"

#include <stdio.h>

int main(int argc, char *argv[]) {

    MU_RUN_SUITE(conf);
    MU_RUN_SUITE(utils);
    MU_REPORT();

    return 0;
}