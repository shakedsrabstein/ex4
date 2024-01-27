#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include "Players/Player.h"
#include "Cards//Card.h"
#include <queue>

enum class GameStatus {
    Win, Loss, MidGame
};

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;


protected:

    queue<Card*> m_cardsQueue;

    vector<Player*> m_players;

//    GameStatus m_gameStatus;
//    Player* m_player;
//    int m_numOfCards;
//    Card *m_cardsArray;
//    int m_currCardIndex;
//    const Card *m_currCard;

};



#endif /* MTMCHKIN_H_ */
