#ifndef BOSS_H
#define BOSS_H

constexpr int BOSS_ATTACK_DAMAGE = 14;

class Boss {
private:
    int health;
    int attack_damage;
public:
    Boss();
    int GetHealth();
    void Damage(int amount);
    int GetAttackDamage();
};

#endif