#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    virtual int GetHealth() = 0;
    virtual void Damage(int amount) = 0;
    virtual int GetAttackDamage() = 0;
};

#endif