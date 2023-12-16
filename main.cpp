
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include<numeric>
#include<list>
#include <tuple>
#include <climits>

using namespace std;
// INT_MAX INT_MIN
#define MAX_NUM ((unsigned int)(-1))>>1
#define MIN_NUM MAX_NUM+1


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template<typename T>
void printVectorVector(vector<vector<T>> res) {
    for (auto v: res) {
        for (auto item: v) {
            cout << item << " ";
        }
        cout << endl;
    }
};

template<typename T>
void printVector(vector<T> res) {
    for (auto v: res) {
        cout << v << endl;
    }
};

int GetTupleByN(tuple<string, int, int> &tuple, int n) {
    if (n == 1)
        return std::get<1>(tuple);
    else if (n == 2)
        return std::get<2>(tuple);
}

class Solution {
public:
    vector<tuple<string, int, int>> Step1(vector<tuple<string, string, int, int>> &processes, vector<string> &users) {
        auto *res = new vector<tuple<string, int, int>>();

        for (auto item: processes) {
            string user = std::get<1>(item);
            if (find(users.begin(), users.end(), user) != users.end()) {
                res->push_back({std::get<0>(item), std::get<2>(item), std::get<3>(item)});
            }
        }
        return *res;
    }

    vector<tuple<string, int, int>> Step2(vector<tuple<string, int, int>> &processes) {
        auto *res = new vector<tuple<string, int, int>>();
        for (auto process: processes) {
            string name = std::get<0>(process);
            auto item = find_if(res->begin(), res->end(), [&name](tuple<string, int, int> &i) {
                return std::get<0>(i) == name;
            });
            if (item != res->end()) {
                std::get<1>(*item) = std::get<1>(*item) + std::get<1>(process);
                std::get<2>(*item) = std::get<2>(*item) + std::get<2>(process);
            } else {
                res->emplace_back(std::get<0>(process), std::get<1>(process), std::get<2>(process));
            }
        }
        return *res;
    }

    vector<string> *Step3(vector<tuple<string, int, int>> &processes, vector<string> rule) {
        auto res = new vector<string>();
        map keys{pair<string, int>{"cpu", 1}, {"mem", 2}};
        int size = rule.size();

        sort(processes.begin(), processes.end(),
             [&](tuple<string, int, int> a, tuple<string, int, int> b) {
                 bool f = true;
                 for (int i = 0; i < size; i++) {
                     const int idx = keys.at(rule[i]);
                     int a1 = (int) GetTupleByN(a, idx);
                     int b1 = (int) GetTupleByN(b, idx);
                     if (a1 > b1) {
                         return true;
                     } else if (a1 < b1) {
                         return false;
                     }
                     if (i == size - 1) {
                         // 根据name排序
                         if ((string) std::get<0>(a) <= ((string) std::get<0>(a))) {
                             return true;
                         }
                     }
                 }
                 return f;
             });
        // 返回
        res->push_back((string) std::get<0>(processes[0]));
        res->push_back((string) std::get<0>(processes[1]));
        res->push_back((string) std::get<0>(processes[2]));
        return res;

    }

    vector<string>
    TopProcess(vector<tuple<string, string, int, int>> &processes, vector<string> users, vector<string> rule) {
        // 1. 筛选users
        auto pros = Step1(processes, users);
        for (auto item: pros) {
            cout << std::get<0>(item) << ": " << std::get<1>(item) << ": " << std::get<2>(item) << endl;
        }

        // 2.累加
        auto newPros = Step2(pros);

        // 3. 排序
        auto res = Step3(newPros, rule);

        return *res;
    }

};

int main() {
    vector<int> vs = {1, 2, 3};

    TreeNode head(1);
    ListNode node1(1);
    ListNode node2(2, &node1);
    ListNode node3(3, &node2);
    ListNode node4(2, &node3);
    ListNode node5(1, &node4);


    vector<tuple<string, string, int, int>> processes = {
            {"wx",   "u1", 10, 100},
            {"link", "u1", 5,  90},
            {"wx",   "u2", 10, 200},
            {"edge", "u1", 10, 1000},
            {"chr",  "u1", 10, 200},
            {"chr",  "u2", 10, 400},
            {"chr",  "u3", 10, 300}
    };

    auto res = Solution().TopProcess(
            processes, {"u1", "u2"}, {"cpu", "mem"}
    );
//    cout << res << endl;
    printVector(res);
    // printVectorVector(res);

    // string s = "hello";
    // cout << (s.find_last_of("c") == -1) << endl;
    // cout << (vs.size()) << endl;

    return 0;
};