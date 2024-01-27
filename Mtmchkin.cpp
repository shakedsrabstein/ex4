#include "Mtmchkin.h"
#include "Players/Player.h"
#include "Cards/CardFactory.h"
#include "Cards/Card.h"
#include "Cards/Dragon.h"
#include "Players/PlayerFactory.h"
#include <bits/stdc++.h>
#include <queue>
using namespace std;

// forward declarations
queue<Card*>* loadCards(const std::string& fileName);
vector<Player*>* loadPlayers();
bool isValidPlayerName(string basicString);
Player* getValidPlayerClass(string playerClass);

Mtmchkin::Mtmchkin(const std::string& fileName) {

    // Load cards
    m_cardsQueue = *(loadCards(fileName));

    // Interactively get the number of players and player types.
    m_players = *(loadPlayers());
}

bool isValidPlayerName(string playerName) {

    // Check if the length is not longer than 15
    if (playerName.length() > 15) {
        return false;
    }

    // Check if all characters are English alphabet letters (small or capital)
    for (char ch : playerName) {
        if (!isalpha(ch)) {
            return false;
        }
    }

    // If both conditions are met, the player name is valid
    return true;
}

Player* getValidPlayerClass(string playerClass) {
    return PlayerFactory::createPlayer(playerClass);
}

vector<Player*>* loadPlayers() {
    int numPlayers;
    vector<Player*>* playersVec = new vector<Player*>();

    printStartGameMessage();

    // Validate input
    do {
        printEnterTeamSizeMessage();
        // Get the number of players
        cin >> numPlayers;
        if (!(numPlayers >= 2 && numPlayers <=6))
            printInvalidTeamSize();
    } while  (!(numPlayers >= 2 && numPlayers <=6));

    // Loop through each player
    bool invalidInput = false;
    for (int i = 1; i <= numPlayers; ++i) {
        do {
            invalidInput = false;
            string playerName, playerJob;
            // Get player's name
            printInsertPlayerMessage();
            cin.ignore(); // Ignore the newline character left in the buffer
            getline(cin, playerName, ' '); // Read the name until space
            getline(cin >> ws, playerJob);
            if (!isValidPlayerName(playerName)) {
                printInvalidName();
                invalidInput = true;
            }
            Player* newPlayer = nullptr;
            if (((newPlayer = getValidPlayerClass(playerJob)) == nullptr)) {
                printInvalidClass();
                invalidInput = true;
            } else {
                playersVec->push_back(newPlayer);
            }
        } while (!invalidInput);
    }

    return playersVec;
}



queue<Card*>* loadCards(const std::string& fileName)
{
    queue<Card*>* cardsQueue = new queue<Card*>();

    // Open a file for reading
    std::ifstream inputFile(fileName);

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        throw DeckFileNotFound();
    }

    // Read lines from the file
    int lineNum = 0;
    std::string line;
    while (std::getline(inputFile, line)) {
        try {
            cardsQueue->push((CardFactory::createCard(line)));
        } catch ( DeckFileFormatError ex) {
            throw DeckFileFormatError(lineNum);
        }
        lineNum++;
    }

    // Close the file
    inputFile.close();

    return cardsQueue;
}

void Mtmchkin::playRound() {


}

void Mtmchkin::printLeaderBoard() const {

}

bool Mtmchkin::isGameOver() const {
    return false;
}

int Mtmchkin::getNumberOfRounds() const {
    return 0;
}




