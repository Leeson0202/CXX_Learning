//
// Created by ￼ Leeson on 2023/10/6.
//

#include<iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

enum class Type {
    GTPU,
    UDP
};

template<Type T>
class Handle {
public:
    static Handle<T> Inst() {
        cout << "GTPU" << endl;
        Handle<T> handle;
        return handle;
    }
};


// 使用示例
int main() {
    Handle<Type::GTPU> h = Handle<Type::GTPU>::Inst();
    return 0;
}


int main() {

    return 0;
}
