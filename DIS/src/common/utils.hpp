//
// Created by WangQing on 06/05/2018.
//

#ifndef DIS_UTILS_HPP
#define DIS_UTILS_HPP

#include <boost/any.hpp>
#include <string>
#include <fstream>

class utils {
public:
    //any cast
    template <typename T>
    static bool can_cast(boost::any &a) {
        return a.type() == typeid(T);
    }

    template <typename T>
    static T& get(boost::any &a) {
        BOOST_ASSERT(can_cast<T>(a));
        return *boost::any_cast<T>(&a);
    }

    template <typename T>
    static T* get_pointer(boost::any &a) {
        BOOST_ASSERT(can_cast<T>(a));
        return boost::any_cast<T>(&a);
    }

    //write read files
    static std::string readAll(const std::string &path) {
        std::ifstream in(path);

        std::istreambuf_iterator<char> begin(in);
        std::istreambuf_iterator<char> end;
        std::string ret(begin, end);

        return ret;
    }
};

#endif //DIS_UTILS_HPP
