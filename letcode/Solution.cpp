//
// Created by ￼ Leeson on 2023/10/6.
//

#include<iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        if (nums.size() == 0) return 0;
        int res = 0;
        int temp = 0;
        int left = 0, right = 1;
        while (right <= nums.size()) {
            temp += nums.at(right - 1);
            while (temp >= k && left < nums.size()) {
                if (temp == k) {
                    res++;
                }
                temp = temp - nums[left];
                left++;
            }
            right++;
        }
        return res;
    }
};

void test() {
    vector<int> vv;
    vv.push_back(1);
    vv.push_back(2);
    vv.push_back(3);
    cout << *(vv.begin() + 1) << endl;
    string s = "hello";

    cout << "index: " << s.find('k', 1) << endl;
}


class MyPrint {
public:
    void operator()(string s) {
        if (s.find("abc") != -1) {
            cout << s << endl;
        }
    }
};

int main() {

    vector<string> vv;
    vv.push_back("bca");
    vv.push_back("cba");
    vv.push_back("abcd");
    vv.push_back("abc");
    sort(vv.begin(), vv.end(), [&](string a, string b) {
        return a <= b;
    });
    for_each(vv.begin(), vv.end(), [](string s) {
        cout << s << endl;
    });
    cout << "  ======= find ====" << endl;
    for_each(vv.begin(), vv.end(), MyPrint());
    return 0;
}
