//
// Created by ￼ Leeson on 2023/12/17.
//

#ifndef CXXLEARNING_REALIMAGE_H
#define CXXLEARNING_REALIMAGE_H

#include "iostream"
#include "Image.h"

class RealImage : public Image {
public:
    RealImage(std::string filename) : filename(filename) {
        loadImage(filename);
    }

    void display() override {
        std::cout << "realImage display{filename: " << filename << "}" << std::endl;
    }

    void loadImage(std::string file) {
        std::cout << "realImage->loadImage{filename: " << file << "}" << std::endl;
    }

private:
    std::string filename;
};

#endif //CXXLEARNING_REALIMAGE_H
