//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"
#include "MySubject.h"
#include "observer/Observer.h"
#include "observer/BinaryObserver.h"
#include "observer/HexObserver.h"

using namespace std;


int main() {
    auto sub = new MySubject(1);
    BinaryObserver *ob1 = new BinaryObserver(sub);
    Observer *ob2 = new HexObserver(sub);

    sub->attach(ob1);
    sub->attach(ob2);

    sub->setState(1);
    sub->setState(20);
    sub->setState(15);


    return 0;
}