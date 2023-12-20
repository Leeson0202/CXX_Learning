//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"

using namespace std;

#include "Originator.h"
#include "Memento.h"
#include "CareTaker.h"


int main() {
    auto originator = new Originator();
    auto careTaker = new CareTaker();
    originator->setState("State #1");
    originator->setState("State #2");
    careTaker->add(originator->saveStateToMemento());
    originator->setState("State #3");
    careTaker->add(originator->saveStateToMemento());
    originator->setState("State #4");

    cout << "Cur state:" << originator->getState() << endl;
    originator->getStateFromMemento(careTaker->get(0));
    cout << "first state:" << originator->getState() << endl;
    originator->getStateFromMemento(careTaker->get(1));
    cout << "second state:" << originator->getState() << endl;


    return 0;
}