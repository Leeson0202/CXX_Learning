//
// Created by ￼ Leeson on 2023/9/30.
//
#include <istream>
#include <string>

using namespace std;

#include <vector>
#include <deque>
#include <algorithm>
#include "participant/participant.h"

#define N 10

void init_participant(vector<Participant> &participants, int n) {
    for (int i = 0; i < n; ++i) {
        Participant p("name_" + std::to_string(i));
        participants.push_back(p);
    }
}

void mark_participant(vector<Participant> &participants) {

    for (int i = 0; i < participants.size(); i++) {
        deque<int> scores;
        for (int i = 0; i < N; i++) {
            scores.push_back(rand() % 41 + 60);
        }
        participants[i].mark(scores);
    }
}

void rank_participant(vector<Participant> &participants) {
    std::sort(participants.begin(), participants.end());
    int idx = 1;
    for (int i = 0; i < participants.size(); i++) {
        participants[i].setRank(idx++);
    }
}

void print_participant(const vector<Participant> &participants) {
    for (auto p: participants) {
        cout << p;
    }
}


int main() {

    vector<Participant> participants;
    // 初始化参与者
    init_participant(participants, 5);
    // 打分
    mark_participant(participants);
    // 计算排名
    rank_participant(participants);
    // 打印结果
    print_participant(participants);

    return 0;
}