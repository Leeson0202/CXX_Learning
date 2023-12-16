//
// Created by ￼ Leeson on 2023/9/30.
//

#include "participant.h"
#include <algorithm>
#include <iomanip>

Participant::Participant(std::string name) : m_name(name) {

}

void Participant::mark(std::deque<int> &scores) {
    sort(scores.begin(), scores.end());
    scores.erase(scores.begin());
    scores.erase(scores.end());
    int sum = 0;
    for (int v: scores) {
        sum += v;
    }
    m_score = float(sum) / scores.size();
}

void Participant::setRank(int rank) {
    this->m_rank = rank;
}

std::ostream &operator<<(std::ostream &out, const Participant &p) {
    out << "排名： " << p.m_rank << "， 姓名：" << p.m_name << "   分数： " << p.m_score << std::endl;
    return out;
}

// 比较函数，用于sort算法
bool Participant::operator<(const Participant &p1) const {
    return this->m_score > p1.m_score;
}