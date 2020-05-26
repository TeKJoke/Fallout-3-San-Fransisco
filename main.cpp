#include <iostream>
#include <string>
#include <stdlib.h>
#include "player.h"
#include "map.h"
#include "boss.h"

void print_player(Player player) {
    std::cout << "Player Stats: " << std::endl;
    player.PrintStats();
}

Special make_special() {
    int s, p, e, c, i, a, l;

    std::cout << "Strenght: ";
    std::cin >> s;
    std::cout << "Perception: ";
    std::cin >> p;
    std::cout << "Endurance: ";
    std::cin >> e;
    std::cout << "Charisma: ";
    std::cin >> c;
    std::cout << "Intelligence: ";
    std::cin >> i;
    std::cout << "Agility: ";
    std::cin >> a;
    std::cout << "Luck: ";
    std::cin >> l;

    Special special = {s, p, e, c, i, a, l};

    return special;
}

Player* ask_player() {
    int health;
    std::string name;
    Special special;

    std::cout << "Health: ";
    std::cin >> health;
    std::cout << "Name: ";
    std::cin >> name;

    special = make_special();

    Player* player = new Player(health, name, DEFAULT_X, DEFAULT_Y, special);

    return player;
}

bool player_in_map(Player p, Map m) {
    int max_x_border = m.x_length + 1;
    int max_y_border = m.y_length + 1;
    if(p.GetX() == max_x_border || p.GetX() == X_BORDER || p.GetY() == max_y_border || p.GetY() == Y_BORDER) {
        return false;
    }

    return true;
}

void move_player(Player* player, bool& loop) {
    int ans0, ans1;

    std::cout << "Do you wish to move your player?" << std::endl;
    std::cout << "1 For YES, 2 For NO (EXIT): ";
    std::cin >> ans0;
    switch(ans0) {
    case 1:
        std::cout << "1 For Right; 2 For Left; 3 For Up; 4 For Down: ";
        std::cin >> ans1;
        switch (ans1) {
        case 1:
            player->MoveX(1);
            break;
        case 2:
            player->MoveX(-1);
            break;
        case 3:
            player->MoveY(1);
            break;
        case 4:
            player->MoveY(-1);
            break;
        default:
            std::cout << "ERROR" << std::endl;
            break;
        }
        break;
    case 2:
        std::cout << "Thank you for playing Fallout 3: San Fransisco" << std::endl;
        loop = false;
        break;
    default:
        std::cout << "ERROR" << std::endl;
        break;
    }
}

void boss_room(Player* player, Boss* boss) {
    std::cout << "You are in the boss room!\nYou cannot leave until one of you have died!" << std::endl;

    bool loop = true;
    while(loop) {
        if(player->GetHealth() <= 0 || boss->GetHealth() <= 0) loop = false;

        int chance = (rand() % 10) + 1;
        if(chance < 6) {
            boss->Damage(player->GetAttackDamage());
        } else if(chance > 7) {
            player->Damage(boss->GetAttackDamage());
        }
    }
    std::cout << "Player health: " << player->GetHealth() << std::endl;
    std::cout << "Boss health: " << boss->GetHealth() << std::endl;

    return;
}

int main() {
    srand(471329874);

    Player* player;
    Boss* boss;
    //player = ask_player();
    player = new Player();
    boss = new Boss();

    Map map = {3, 3};

    bool loop = true;
    while(loop) {
        //move_player(player, loop);

        if(!player_in_map(*player, map)) {
            std::cout << "Player outside map borders! Resetting coordinates and damaging player!" << std::endl;
            player->Damage(10);
            player->Move();
        } else {
            std::cout << "Player still inside borders!" << std::endl;
        }

        int chance = (rand() % 10) + 1;
        if(player->GetX() == 2 && player->GetY() == 2 && chance < 3) {
            std::cout << "You are in the chamber of the ghouls and got unlucky" << std::endl;
            player->Damage(20);
        }

        if(player->GetX() == 3 && player->GetY() == 3) {
            boss_room(player, boss);
        }

        if(player->GetHealth() <= 0) {
            std::cout << "You are dead :(" << std::endl;
            std::cout << "Thank you for playing Fallout 3: San Fransisco" << std::endl;
            loop = false;
        } else if(boss->GetHealth() <= 0) {
            std::cout << "You won the game congratulations! :D" << std::endl;
            std::cout << "Thank you for playing Fallout 3: San Fransisco" << std::endl;
            loop = false;
        }

    }
    print_player(*player);

    delete player;

    return 0;
}