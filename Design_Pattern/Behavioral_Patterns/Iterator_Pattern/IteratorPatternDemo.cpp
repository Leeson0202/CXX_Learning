//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"
#include "./container/NameContainer.h"

using namespace std;


int main() {
    auto repository = new NameContainer();
    auto iterator = repository->getIterator();
    cout << iterator->get() << endl;
    while (iterator->hasNext()) {
        iterator->next();
        cout << iterator->get() << endl;
    }
    return 0;
}