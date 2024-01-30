//
// Created by Alon Goren on 21/01/2024.
//
#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"


/**Card: an abstract class of the cards*/
class Card {
public:
    Card() = default;
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;
    virtual void applyEncounter(Player& player) = 0;
    virtual void printDetails(std::ostream&) const;
    virtual string getName() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Card& card) {
        // Customize the output based on your class members
        card.printDetails(os);
        return os;
    }


    static void CreateCard(string cardStr);
    //Nothing private in the abstract class
};



#endif //EX4_Card_H
