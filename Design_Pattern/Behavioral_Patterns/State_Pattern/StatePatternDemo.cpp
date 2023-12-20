//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"
#include "Context.h"
#include "state/StartState.h"
#include "state/EndState.h"

using namespace std;


int main() {
    auto context = new Context();
    State *start = new StartState();
    State *end = new EndState();
    start->doAction(context);
    cout << context->getState()->toString() << endl;
    end->doAction(context);
    cout << context->getState()->toString() << endl;


    return 0;
}