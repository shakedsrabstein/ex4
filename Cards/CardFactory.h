#include <map>
#include <memory>
using namespace std;

// Value-Defintions of the different String values

enum CardNames {
    CN_Dragon,
    CN_Barfight,
    CN_Mana,
    CN_Gremlin,
    CN_Merchant,
    CN_Well,
    CN_Treasure,
    CN_Witch

};



class CardFactory {

    static bool initiated;

public:

    static void initiateFactory();
    static std::shared_ptr<Card> createCard(string cardStr);

};


