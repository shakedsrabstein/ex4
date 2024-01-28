//
// Created by spabl on 11/30/2023.
//
#include <string>
using namespace std;


#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


class Player {


    string m_name;
    string m_job;

protected:
    int m_coins;
    int m_HP;
    int m_maxHP;
    int m_force;
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
    virtual ~Player() = default;
    Player& operator=(const Player& other) = default;

    friend std::ostream& operator<<(std::ostream&, const Player& pl);

    void printInfo() const;

    virtual void addCoins(int toAdd);

    virtual bool pay(int toPay);

    virtual void heal(int addHP);

    virtual void damage(int toReduce);

    virtual void levelUp();

    virtual void buff(int toAdd);

    virtual int getAttackStrength() const;

    virtual bool isKnockedOut() const;

    virtual const string &getMName() const;

    virtual void setMName(const string &mName);

    virtual int getLevel() const;

    virtual void setLevel(int mLevel);

    virtual int getForce() const;

    virtual void setForce(int mForce);

    virtual int getMaxHp() const;

    virtual void setMaxHp(int mMaxHp);

    virtual int getHp() const;

    virtual void setHp(int mHp);

    virtual bool hasWon();

    const int WIN_LEVEL = 10;

    virtual bool hasLost();

    virtual string getJob() const = 0 ;
};

//TODO
//std::ostream& operator<<(std::ostream&, const Player& pl);


#endif //EX2_PLAYER_H
