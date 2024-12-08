#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int max_x = 20;
const int max_y = 20;
const char empty = ' ';
const char snake = '*';
const char food = '@';

int x, y, dx, dy;
int snake_size;
vector<pair<int, int>> snake_pos;

void setup();
void draw();
void move();

int main() {
    setup();
    while (true) {
        draw();
        move();
        if (x < 0 || x >= max_x || y < 0 || y >= max_y || contains(snake_pos, x, y)) {
            break;
        }
        if (x == dx && y == dy) {
            snake_size++;
            snake_pos.push_back({x, y});
            dx = 0;
            dy = 0;
        }
        sleep(100);
    }
    return 0;
}

void setup() {
    srand(time(0));
    x = rand() % max_x;
    y = rand() % max_y;
    dx = 0;
    dy = 0;
    snake_size = 1;
    snake_pos.push_back({x, y});
}

void draw() {
    system("cls");
    for (int i = 0; i < max_y; i++) {
        for (int j = 0; j < max_x; j++) {
            if (i == y && j == x) {
                cout << snake;
            } else if (contains(snake_pos, j, i)) {
                cout << snake;
            } else if (j == dx && i == dy) {
                cout << food;
            } else {
                cout << empty;
            }
        }
        cout << endl;
    }
}

void move() {
    snake_pos.erase(snake_pos.begin());
    pair<int, int> new_pos = {x + dx, y + dy};
    snake_pos.push_back(new_pos);
    x = new_pos.first;
    y = new_pos.second;
}

bool contains(vector<pair<int, int>>& v, int x, int y) {
    for (const auto& p : v) {
        if (p.first == x && p.second == y) {
            return true;
        }
    }
    return false;
}
