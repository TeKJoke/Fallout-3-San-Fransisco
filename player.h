#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

struct Special {
    int strength, perseption, endurance, charisma, \
        intelligence, agility, luck;
};

constexpr Special DEFAULT_SPECIAL = {5, 5, 5, 5, 5, 5, 5};
constexpr int DEFAULT_X = 1;
constexpr int DEFAULT_Y = 1;
constexpr int X_BORDER = 0;
constexpr int Y_BORDER = 0;

class Player {
private:
    int health;
    std::string name;
    int x_pos;
    int y_pos;
    Special special;
public:
    Player();
    Player(int health, std::string name, int x_pos, int y_pos, Special special);
    void PrintStats();
    int GetX();
    int GetY();
    void MoveX(int amount_moved);
    void MoveY(int amount_moved);
    void Move();
    void Damage(int damg);
    int GetHealth();
};

#endif