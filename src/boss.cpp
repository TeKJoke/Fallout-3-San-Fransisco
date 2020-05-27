#include "boss.h"

Boss::Boss() 
    : health(100), attack_damage(BOSS_ATTACK_DAMAGE) {}

int Boss::GetHealth() { return health; }

void Boss::Damage(int amount) {
    this->health -= amount;
}

int Boss::GetAttackDamage() { return attack_damage; }