//
// Created by ￼ Leeson on 2023/9/24.
//

#include <iostream>

using namespace std;

template<class T>
void printArr(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
}

template<class T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void selectSort(T arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int max = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] > arr[max]) {
                max = j;
            }

        }
        if (max != i) {
            mySwap(arr[i], arr[max]);
        }
    }

}

void test01() {
    char cs[] = "aibvuae";
    selectSort(cs, sizeof(cs) - 1);
    printArr(cs, sizeof(cs) - 1);

}

void test02() {
    int a[] = {1, 4, 2, 5, 7, 3};
    int num = sizeof(a) / sizeof(int);
    selectSort(a, num);
    printArr(a, num);

}

int main() {
//    test01();
    test02();

}