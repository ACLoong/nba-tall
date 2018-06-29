cmake_minimum_required(VERSION 3.8)
project(DIS)
#project(UnitTest)


set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/conn/mysqlconn.hpp src/app/conf.hpp src/common/utils.hpp dep/json/json11.cpp)
set(DIS_SOURCE_FILES ${SOURCE_FILES} src/main.cpp )
set(UNITTEST_SOURCE_FILES  ${SOURCE_FILES} unittest/conf_test.hpp unittest/main.cpp unittest/utils_test.hpp)

include_directories(dep)
include_directories(src)

add_executable(DIS ${DIS_SOURCE_FILES})
add_executable(UnitTest ${UNITTEST_SOURCE_FILES} )

target_link_libraries(DIS -lhandy)
target_link_libraries(DIS -lpthread)