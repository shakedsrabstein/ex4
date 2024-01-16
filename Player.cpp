//
// Created by spabl on 11/30/2023.
//

#include <iostream>
#include "Player.h"
#include <string>
#include "utilities.h"
using namespace std;

//
//bool Player::hasSpacesOrNonEnglish(const string& input){
//    // Check for spaces
//    if (input.find(' ') != string::npos) {
//        return true;
//    }
//
//    // Check for non-English letters
//    for (char ch : input) {
//        if (!isascii(ch) || !isalpha(ch)) {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//bool Player::isValidName(const string& name){
//    return !this->hasSpacesOrNonEnglish(name);
//}


/**A constructor that creates a player
 *
 * @param name - The name of the player
 * @param maxHp - The amount of HP the player has in full health (default is 100)
 * @param force - The power the player will have (default is 5)
 * */

/*
Player::Player(const string name,int maxHP ,int force) {

    this -> m_level = 1;
    this -> m_coins = 0;
    this -> m_name = name;

    if(force < 0){
        this->m_force = 5;

    } else {
        this->m_force = force;
    }

    if(maxHP < 0){
        this->m_maxHP = 100;
    } else {
        this->m_maxHP = maxHP;
    }

    this->m_HP = this->m_maxHP;
}
*/

Player::Player(const string name,int maxHP ,int force) :
m_name(name),m_maxHP(maxHP >= 0 ? maxHP : DEF_MAX_HP) ,m_HP(maxHP >= 0 ? maxHP : DEF_MAX_HP) , m_force(force > 0 ? force : DEF_FORCE) , m_coins(DEF_COINS),m_level(DEF_LEVEL){}










/**printInfo: prints the stats of the called player
* (The method don`t change the called player)
*/
void Player::printInfo() const {
//    cout << "Player Details:" << endl;
//    cout << "Name: " << this->m_name << endl;
//    cout << "Level: " << this->m_level << endl;
//    cout << "Force: " << this->m_force << endl;
//    cout << "HP: " << this->m_HP << endl;
//    cout << "Coins: " << this->m_coins << endl;


    printPlayerInfo(this->m_name.c_str(), this->m_level, this->m_force , this->m_HP ,this->m_coins);
}

void Player::addCoins(int toAdd) {
    if(toAdd <= 0){
        return;
    }
    this->m_coins += toAdd;

}

bool Player::pay(int toPay) {

    if(toPay < 0){
        return true;
    }

    if(this->m_coins >= toPay){
        this->m_coins -= toPay;
        return true;
    } else {
        return false;
    }

}

void Player::heal(int addHP) {
    if(addHP <= 0){
        return;
    }
    if(this->m_HP + addHP >= this->m_maxHP){
        this->m_HP = this->m_maxHP;


    } else {
        this->m_HP += addHP;
    }



}

void Player::damage(int toReduce){
    if(toReduce < 0){
        return;
    }

    if(this->m_HP - toReduce < 0){
        this->m_HP = 0;
    } else {
        this->m_HP -= toReduce;
    }


}

void Player::levelUp() {

    if(this->m_level < 10){
        this->m_level = this->m_level + 1;
    }

}

void Player::buff(int toAdd) {

    if(toAdd <= 0){
        return;
    }
    this->m_force = this->m_force + toAdd;
}

int Player::getAttackStrength() const {
    return this->m_level + this->m_force;
}

bool Player::isKnockedOut() const {
    if(this->m_HP <= 0){
        return true;
    }

    return false;
}

int Player::getMCoins() const {
    return m_coins;
}

void Player::setMCoins(int mCoins) {
    m_coins = mCoins;
}

const string &Player::getMName() const {
    return m_name;
}

void Player::setMName(const string &mName) {
    m_name = mName;
}

int Player::getLevel() const {
    return m_level;
}

void Player::setLevel(int mLevel) {
    m_level = mLevel;
}

int Player::getForce() const {
    return m_force;
}

void Player::setForce(int mForce) {

    m_force = mForce;
}

int Player::getMaxHp() const {
    return m_maxHP;
}

void Player::setMaxHp(int mMaxHp) {
    m_maxHP = mMaxHp;
}

int Player::getHp() const {
    return m_HP;
}

void Player::setHp(int mHp) {
    m_HP = mHp;
}
