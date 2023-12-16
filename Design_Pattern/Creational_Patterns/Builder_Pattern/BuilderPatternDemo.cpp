//
// Created by ￼ Leeson on 2023/12/12.
//
#include "iostream"
#include "string"
#include "Director.h"
#include "./builder/impl/OfoBuilder.h"
#include "./builder/impl/MobikeBuilder.h"

using namespace std;


int main() {
    Director director(new OfoBuilder());
    Bike ofoBike = director.construct();
    cout << "ofobike: frame: " + ofoBike.getFrame() << endl;
    cout << "ofobike: seat: " + ofoBike.getSeat() << endl;


    Director director1(new MobikeBuilder());
    Bike mobike = director1.construct();
    cout << "mobike: frame: " + mobike.getFrame() << endl;
    cout << "mobike: seat: " + mobike.getSeat() << endl;


    return 0;
}