//
// Created by WangQing on 30/04/2018.
//

#ifndef DIS_CONF_HPP
#define DIS_CONF_HPP

#include <iostream>
#include <unordered_map>
#include <string>
#include <boost/any.hpp>

#include "common/utils.hpp"
#include "json/json11.hpp"

class Conf{
public:
    Conf(const std::string &path);
    ~Conf();

    boost::any getConf(const std::string &key) const;

private:
    void init();

private:
    json11::Json data_;
    std::string path_;
};

boost::any Conf::getConf(const std::string &key) const{
    boost::any val;

    if (data_[key].type() == json11::Json::STRING) {
        val = data_[key].string_value();
    }

    if (data_[key].type() == json11::Json::NUMBER) {
        val = data_[key].int_value();
    }

    return val;
}

Conf::Conf(const std::string &path) :path_(path) {
    init();
}

Conf::~Conf() {

}

void Conf::init() {
    auto content = utils::readAll(path_);

    std::string err_str;
    data_ = json11::Json::parse(content, err_str);
}



#endif //DIS_CONF_HPP
