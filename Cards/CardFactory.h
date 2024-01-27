#include <map>

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

// Map to associate the strings with the enum values
static std::map<std::string, CardNames> s_mapstr2enumval;

class CardFactory {

public:

    CardFactory();
    ~CardFactory() = default;
    static Card* createCard(string cardStr);

};


