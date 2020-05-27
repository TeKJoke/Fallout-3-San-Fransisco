#include "enemy.h"

Enemy::Enemy()
    : health(40), attack_damage(7), type(WEAK) {}

Enemy::Enemy(int type)
    : health(40), attack_damage(7), type(type) {}

int Enemy::GetHealth() { return this->health; }

void Enemy::Damage(int amount) {
    this->health -= amount;
}
int Enemy::GetAttackDamage() { return this->attack_damage; }