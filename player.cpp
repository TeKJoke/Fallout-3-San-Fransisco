#include "player.h"

Player::Player()
    : health(100), name("Unknown"), x_pos(DEFAULT_X), y_pos(DEFAULT_Y), special(DEFAULT_SPECIAL) {}

Player::Player(int health, std::string name, int x_pos, int y_pos, Special special) 
    : health(health), name(name), x_pos(x_pos), y_pos(y_pos), special(special) {}

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

void Player::Move() {
    this->x_pos = DEFAULT_X;
    this->y_pos = DEFAULT_Y;
}

void Player::Damage(int damg) {
    this->health -= damg;
}

int Player::GetHealth() { return health; }