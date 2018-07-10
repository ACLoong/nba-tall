//
// Created by WangQing on 30/04/2018.
//

#ifndef DIS_MYSQLCONN_HPP
#define DIS_MYSQLCONN_HPP

#include <mysql/mysql.h>
#include <string>

using namespace std;

class result_type {
public:
    bool is_success() {return is_success_;}

private:
    bool is_success_ = false;
};


class MysqlConn {
public:
    enum state_type {
        Connected,
        Connecting,
        Unconnected,
        Disconnecting,
        Disconnected
    };

    MysqlConn(const string &host,
              unsigned port,
              const string &username,
              const string &password,
              const string &db_name);

    virtual ~MysqlConn();

    bool is_available() {return state_ == Connected;}

    result_type select_field();
    result_type insert();
    result_type remove();

protected:
    void init();

protected:
    MYSQL       *conn_ = nullptr;
    state_type  state_ = Unconnected;

    string      host_;
    unsigned    port_;
    string      username_;
    string      password_;
    string      db_name_;
};

MysqlConn::~MysqlConn() {
    if (nullptr != conn_) {
        state_ = Disconnecting;
        mysql_close(conn_);
        state_ = Disconnected;

        delete conn_;
        conn_ = nullptr;
    }
}

result_type MysqlConn::select_field() {
    return result_type();
}

result_type MysqlConn::insert() {
    return result_type();
}

result_type MysqlConn::remove() {
    return result_type();
}

void MysqlConn::init() {
    conn_ = new MYSQL;
    mysql_init(conn_);
    state_ = Connecting;

    auto ret = mysql_real_connect(conn_,
                                 host_.c_str(),
                                 username_.c_str(),
                                 password_.c_str(),
                                 db_name_.c_str(),
                                 port_,
                                 nullptr,
                                 CLIENT_FOUND_ROWS);

    if (nullptr != ret) {
        state_ = Connected;
    }
}

MysqlConn::MysqlConn(const string &host,
                     unsigned port,
                     const string &username,
                     const string &password,
                     const string &db_name) {
    host_ = host;
    port_ = port;
    username_ = username;
    password_ = password;
    db_name_ = db_name;

    init();
}

#endif //DIS_MYSQLCONN_HPP
