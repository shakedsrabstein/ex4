//
// Created by spabl on 11/30/2023.
//
#include <string>
using namespace std;


#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


class Player {
    string m_name;
    int m_maxHP;
    int m_HP;
    int m_force;
    int m_coins;
    int m_level;

public:
    int getMCoins() const;

    void setMCoins(int mCoins);

    static const int DEF_MAX_HP = 100;
    static const int DEF_FORCE = 5;
    static const int DEF_LEVEL = 1;
    static const int DEF_COINS = 10;





public:
    Player(string name , int maxHP = 100 , int force = 5);

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;


    void printInfo() const;

    void addCoins(int toAdd);

    bool pay(int toPay);

    void heal(int addHP);

    void damage(int toReduce);

    void levelUp();

    void buff(int toAdd);

    int getAttackStrength() const;

    bool isKnockedOut() const;

    const string &getMName() const;

    void setMName(const string &mName);

    int getLevel() const;

    void setLevel(int mLevel);

    int getForce() const;

    void setForce(int mForce);

    int getMaxHp() const;

    void setMaxHp(int mMaxHp);

    int getHp() const;

    void setHp(int mHp);
};


#endif //EX2_PLAYER_H
