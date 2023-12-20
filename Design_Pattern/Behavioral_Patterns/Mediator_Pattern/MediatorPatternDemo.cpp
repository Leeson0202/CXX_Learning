//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"
#include "User.h"
#include "ChatRoom.h"

using namespace std;


int main() {
    auto chen = new User("Chen");
    auto leeson = new User("Leeson");

    chen->sendMessage("hello Chen");
    leeson->sendMessage("hello Leeson");
    return 0;
}