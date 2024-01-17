//
// Created by spabl on 1/16/2024.
//
#include <string>
using namespace std;

#ifndef EX4_NINJA_H
#define EX4_NINJA_H


#include "Player.h"

class Ninja : public Player {

public:
    Ninja(string name , int maxHP = 100 , int force = 5);

};


#endif //EX4_NINJA_H
