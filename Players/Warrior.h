//
// Created by spabl on 1/16/2024.
//
#include <string>
#include "Player.h"

using namespace std;

#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H


class Warrior : public Player {

public:
    Warrior(string name , int maxHP = 100 , int force = 5);

    int getAttackStrength() const;

    string getJob() const;

};


#endif //EX4_WARRIOR_H
