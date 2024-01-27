//
// Created by spabl on 1/16/2024.
//

#include "Healer.h"


Healer::Healer(std::string name , int maxHP , int force) : Player(name,maxHP,force) {

}

void Healer::heal(int addHP){
    if(addHP <= 0){
        return;
    }
    addHP = addHP * 2;

    if(this->m_HP + addHP >= this->m_maxHP){
        this->m_HP = this->m_maxHP;


    } else {
        this->m_HP += addHP;
    }




}