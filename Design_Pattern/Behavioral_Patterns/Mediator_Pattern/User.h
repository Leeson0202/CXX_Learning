//
// Created by ￼ Leeson on 2023/12/20.
//

#ifndef CXXLEARNING_USER_H
#define CXXLEARNING_USER_H

#include "iostream"
#include "ChatRoom.h"

using namespace std;

class User {
public:
    User() = default;

    explicit User(string name) : m_name(name) {
    }

    void setName(string name) {
        m_name = name;
    }

    string &getName() {
        return m_name;
    }

    void sendMessage(string msg) {
        ChatRoom::showMessage(msg);
    }

private:
    string m_name;
};

#endif //CXXLEARNING_USER_H
