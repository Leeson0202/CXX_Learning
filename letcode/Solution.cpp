//
// Created by ￼ Leeson on 2023/10/6.
//

#include<iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <regex>


using namespace std;



class Solution {
public:
    void addTask(int curtime, vector<vector<int>>& CurList, vector<vector<int>>& tasks, int &idx){
        while (idx < tasks.size() && tasks[idx][0] <= curtime) {
            CurList.push_back(tasks[idx++]);
        }
    }

    int procTask(int &curtime, vector<vector<int>>& CurList){
        // 找到处理时间最小的任务
        auto compFunc = [](vector<int> item1, vector<int> item2){
            if (item1[1] == item2[1]) {
                return item1[2] < item2[2];
            }
            return (item1[1] < item2[1]);
        };
        auto minTask = min_element(CurList.begin(), CurList.end(), compFunc);
        int res = (*minTask)[2];
//        cout << "curTime: " << curtime << ", curTask: " << res << ",{"<< (*minTask)[0]<<","<< (*minTask)[1] <<"}"<< endl;
        curtime += (*minTask)[1];
        CurList.erase(minTask);
        return res;
    }

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res = {};
        int i=0;
        for (auto &item: tasks) {
            item.push_back(i);
            i++;
        }
        sort(tasks.begin(), tasks.end(),[](vector<int> item1, vector<int> item2){
            return (item1[0] < item2[0]);
        });
        auto curTime = 0;
        auto idx = 0;
        vector<vector<int>> CurList = {};
        while (idx < tasks.size() || !CurList.empty()) {
            // 1.添加到就绪队列
            addTask(curTime, CurList, tasks, idx);
            if (CurList.empty()) {
                curTime++;
                continue;
            }
            // 2.处理任务
            res.push_back(procTask(curTime,CurList));
        }
        return res;
    }

};
