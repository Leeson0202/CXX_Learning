//
// Created by ￼ Leeson on 2023/10/6.
//

#include<iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


class Handle {
public:
    Handle() {i = 1;};
    ~Handle() = default;

    int i;
};


// 使用示例
int main() {
    Handle *handle = new Handle();

    cout << "i: " << handle->i<< endl;

    cout << "p: " << handle<< endl;

    delete handle;

    cout << "p: " << handle<< endl;
    cout << "i: " << handle->i<< endl;

    return 0;
}


