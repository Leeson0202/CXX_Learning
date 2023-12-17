//
// Created by ￼ Leeson on 2023/12/13.
//

#ifndef CXXLEARNING_PROTOTYPECACHE_H
#define CXXLEARNING_PROTOTYPECACHE_H

#include "map"
#include "string"
#include "Shape.h"
#include "./impl/Circle.h"
#include "./impl/Square.h"


class PrototypeCache {
public:
    static void loadCache() {
        Shape *shape = new Circle();
        cache.insert({"1", shape});
        shape = new Square();
        cache.insert({"2", shape});
    }

    static Shape *getById(const std::string& id) {
        auto shape = cache.at(id);
        if (shape != nullptr) return shape->Clone();
        return shape;
    }

private:
    static map<std::string, Shape *> cache;
};


#endif //CXXLEARNING_PROTOTYPECACHE_H
