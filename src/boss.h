#ifndef BOSS_H
#define BOSS_H

#include "entity.h"

constexpr int BOSS_ATTACK_DAMAGE = 14;

class Boss : public Entity {
private:
    int health;
    int attack_damage;
public:
    Boss();
    int GetHealth() override;
    void Damage(int amount) override;
    int GetAttackDamage() override;
};

#endif