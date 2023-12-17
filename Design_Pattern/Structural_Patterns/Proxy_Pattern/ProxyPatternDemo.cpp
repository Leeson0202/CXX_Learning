//
// Created by ￼ Leeson on 2023/12/17.
//

#include "image/Image.h"
#include "image/ProxyImage.h"


int main() {
    auto proxy = new ProxyImage("test.jpg");
    proxy->display();
    return 0;
}