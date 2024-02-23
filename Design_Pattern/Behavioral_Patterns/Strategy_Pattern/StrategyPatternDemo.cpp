//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"
#include "Context.h"
#include "strategy/SubStrategy.h"
#include "strategy/AddStrategy.h"

using namespace std;


int main() {
    auto add = new AddStrategy();
    auto sub = new SubStrategy();
    auto context = new Context(add);
    cout << context->executeStrategy(1, 2) << endl;

    context = new Context(sub);
    cout << context->executeStrategy(1, 2) << endl;
    return 0;
}