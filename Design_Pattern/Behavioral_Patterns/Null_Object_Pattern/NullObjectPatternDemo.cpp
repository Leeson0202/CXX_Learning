//
// Created by ￼ Leeson on 2023/12/17.
//

#include "iostream"
#include "CustomerFactory.h"

using namespace std;


int main() {
    auto ctm1 = CustomerFactory::getCustomer("Leeson");
    auto ctm2 = CustomerFactory::getCustomer("Chen");
    auto ctm3 = CustomerFactory::getCustomer("Mo");
    auto ctm4 = CustomerFactory::getCustomer("YY");
    cout << ctm1->getName() << endl;
    cout << ctm2->getName() << endl;
    cout << ctm3->getName() << endl;
    cout << ctm4->getName() << endl;


    return 0;
}