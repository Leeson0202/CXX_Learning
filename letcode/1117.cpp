
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// INT_MAX INT_MIN
#define MAX_NUM ((unsigned int)(-1))>>1
#define MIN_NUM MAX_NUM+1


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template<typename T>
void printVectorVector(vector<vector<T> > res) {
    for (vector<T> v: res) {
        for (T item: v) {
            cout << item << " ";
        }
        cout << endl;
    }
};

template<typename T>
void printVector(vector<T> res) {
    for (T v: res) {
        cout << v << endl;
    }
};


int main() {
    vector<string> vv{"hello"};

    return 0;
};