//
// Created by ￼ Leeson on 2024/1/31.
//

#include "templateTest.h"


int main() {

    auto h = TemplateTest<Type::GTPU>::Inst();
    h.Add();

    auto c = TemplateTest<Type::UDP>::Inst();
    c.Add();
    return 0;
}