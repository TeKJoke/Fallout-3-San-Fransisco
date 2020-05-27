#include "player.h"

Player::Player()
    : name("Unknown"), special(DEFAULT_SPECIAL) {}

Player::Player(std::string name, Special special)
    : name(name), special(special) {}

Player::Player(int x_pos, int y_pos, Special special) 
    : x_pos(x_pos), y_pos(y_pos), special(special) {}

void Player::PrintStats() {
    std::cout << "Health: " << health << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "(X, Y) Position: " << "(" << x_pos << ", " << y_pos << ")" << std::endl;
    std::cout << "SPECIAL: " << special.strength << ", ";
    std::cout << special.perseption << ", ";
    std::cout << special.endurance << ", ";
    std::cout << special.charisma << ", ";
    std::cout << special.intelligence << ", ";
    std::cout << special.agility << ", ";
    std::cout << special.luck << std::endl;
}

int Player::GetX() { return x_pos; }
int Player::GetY() { return y_pos; }

void Player::MoveX(int amount_moved) {
    this->x_pos += amount_moved;
}

void Player::MoveY(int amount_moved) {
    this->y_pos += amount_moved;
}

void Player::MoveDefault() {
    this->x_pos = DEFAULT_X;
    this->y_pos = DEFAULT_Y;
}

void Player::Damage(int amount) {
    this->health -= amount;
}

int Player::GetHealth() { return health; }

int Player::GetAttackDamage() { return attack_damage; }

void Player::BoostStat(int which_stat) {
    switch(which_stat) {
    case 0:
        this->special.strength++;
        break;
    case 1:
        this->special.perseption++;
        break;
    case 2:
        this->special.endurance++;
        break;
    case 3:
        this->special.charisma++;
        break;
    case 4:
        this->special.intelligence++;
        break;
    case 5:
        this->special.agility++;
        break;
    case 6:
        this->special.luck++;
        break;
    default:
        break;
    }
}