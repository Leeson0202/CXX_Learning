//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_PROXYIMAGE_H
#define CXXLEARNING_PROXYIMAGE_H

#include "Image.h"
#include "RealImage.h"

class ProxyImage : public Image {
public:
    ProxyImage(std::string filename) : fileName(filename) {
        std::cout << "申请系统权限成功!" << std::endl;
    }

    void display() override {
        if (realImage == nullptr) {
            realImage = new RealImage(fileName);
        }
        realImage->display();
    }

private:
    RealImage *realImage;
    std::string fileName;

};

#endif //CXXLEARNING_PROXYIMAGE_H
