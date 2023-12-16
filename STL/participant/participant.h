//
// Created by ￼ Leeson on 2023/9/30.
//

#ifndef C__LEARNING_PARTICIPANT_H
#define C__LEARNING_PARTICIPANT_H

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

class Participant {
    friend std::ostream &operator<<(std::ostream &out, const Participant &p);

    friend bool compareParticipant(const Participant &p1, const Participant &p2);

public:

    Participant() {};

    explicit Participant(std::string name);

    void mark(std::deque<int> &scores);

    void setRank(int rank);

    bool operator<(const Participant &p1) const;


private:
    std::string m_name;
    float m_score;
    int m_rank;

};


#endif //C__LEARNING_PARTICIPANT_H
