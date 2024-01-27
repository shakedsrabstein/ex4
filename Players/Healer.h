//
// Created by spabl on 1/16/2024.
//
#include <string>
#include "Player.h"

using namespace std;

#ifndef EX4_HEALER_H
#define EX4_HEALER_H


class Healer : public Player{

public:
    Healer(string name , int maxHP = 100 , int force = 5);

    void heal(int addHP);
};


#endif //EX4_HEALER_H
