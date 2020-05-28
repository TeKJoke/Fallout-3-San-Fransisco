#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "entity.h"

struct Special {
    int strength, perseption, endurance, charisma, \
        intelligence, agility, luck;
};

constexpr Special DEFAULT_SPECIAL = {5, 5, 5, 5, 5, 5, 5};
constexpr int DEFAULT_X = 1;
constexpr int DEFAULT_Y = 1;
constexpr int STRENGTH = 0;
constexpr int PERSEPTION = 1;
constexpr int ENDURANCE = 2;
constexpr int CHARISMA = 3;
constexpr int INTELLIGENCE = 4;
constexpr int AGILITY = 5;
constexpr int LUCK = 6;
constexpr int MAX_SPECIAL = 49;

class Player : public Entity {
private:
    std::string name;
    int x_pos = DEFAULT_X;
    int y_pos = DEFAULT_Y;
    Special special;
    int health = this->special.endurance * 11;
    int attack_damage = this->special.strength * 3;
    int speed = this->special.agility;
public:
    Player();
    Player(std::string name, Special special);
    Player(int x_pos, int y_pos, Special special);
    void PrintStats();
    int GetX();
    int GetY();
    void MoveX(int amount_moved);
    void MoveY(int amount_moved);
    void MoveDefault();
    void Damage(int amount) override;
    int GetHealth() override;
    int GetAttackDamage() override;
    void BoostStat(int which_stat);
};

#endif