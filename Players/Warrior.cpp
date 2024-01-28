#include "Warrior.h"

Warrior::Warrior(std::string name , int maxHP , int force) : Player(name,maxHP,force) {

}

int Warrior::getAttackStrength() const {

    return this->m_level + (this->m_force * 2);
}

string Warrior::getJob() const {
    return "Warrior";
}


