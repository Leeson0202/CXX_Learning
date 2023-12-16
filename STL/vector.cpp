//
// Created by ￼ Leeson on 2023/9/27.
//
#include <iostream>

using namespace std;

#include <string>
#include <vector>
#include <algorithm>


void printInt(int v) {
    cout << v << endl;
}

// 打印方法
void print_vector(vector<int> v) {
    cout << "打印方法 1" << endl;
//    vector<int>::iterator begin = v.begin();
    auto begin = v.begin();
    auto end = v.end();
    while (begin != end) {
        cout << *begin << endl;
        begin++;
    }
    cout << "打印方法 2" << endl;
    for (auto t = v.begin(); t != v.end(); t++) {
        cout << *t << endl;
    }
    cout << "打印方法 3" << endl;
    for (auto &t: v) {
        cout << t << endl;
    }
    cout << "打印方法 4" << endl; // algorithm 提供的
    for_each(v.begin(), v.end(), printInt);

}


void test() {
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    print_vector(v);

}

int main() {
    test();
    return 0;
}