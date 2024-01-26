//
// Created by spabl on 1/16/2024.
//
#include <string>


#ifndef EX4_NINJA_H
#define EX4_NINJA_H


#include "Player.h"

class Ninja : public Player {

public:

    Ninja(std::string name , int maxHP = 100 , int force = 5);

};


#endif //EX4_NINJA_H
