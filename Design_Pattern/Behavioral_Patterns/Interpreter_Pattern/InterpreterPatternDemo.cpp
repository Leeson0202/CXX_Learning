//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"
#include "expression/Expression.h"
#include "expression/TerminalExpression.h"
#include "expression/OrExpression.h"
#include "expression/AndExpression.h"

using namespace std;

//规则：Robert 和 John 是男性
Expression *getMaleExpression() {
    Expression *robert = new TerminalExpression("Robert");
    Expression *john = new TerminalExpression("John");
    return new OrExpression(robert, john);
}

//规则：Julie 是一个已婚的女性
Expression *getMarriedWomenExpression() {
    Expression *julie = new TerminalExpression("Julie");
    Expression *married = new TerminalExpression("Married");
    return new AndExpression(julie, married);
}

int main() {
    Expression *isMale = getMaleExpression();
    Expression *isMarriedWoman = getMarriedWomenExpression();
    cout << "John is male? " << isMale->interpret("John") << endl;
    cout << "Julie is a married women? " << isMarriedWoman->interpret("Married Julie") << endl;

    return 0;
}