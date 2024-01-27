//
// Created by spabl on 1/16/2024.
//

#include "Ninja.h"

#include "string"

Ninja::Ninja(std::string name , int maxHP , int force) : Player(name,maxHP,force) {

}


void Ninja::addCoins(int toAdd) {
    if(toAdd <= 0){
        return;
    }
    toAdd = toAdd * 2;
    this->m_coins += toAdd;

}