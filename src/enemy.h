#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

constexpr int WEAK = 0;

class Enemy : public Entity {
private:
    int health;
    int attack_damage;
    int type;
public:
    Enemy();
    Enemy(int type);
    int GetHealth() override;
    void Damage(int amount) override;
    int GetAttackDamage() override;
};

#endif