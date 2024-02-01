#include "Mtmchkin.h"
#include "Players/Player.h"
#include "utilities.h"
#include "Cards/CardFactory.h"
#include "Cards/Card.h"
#include "Cards/Dragon.h"
#include "Players/PlayerFactory.h"
#include <bits/stdc++.h>
#include <queue>
using namespace std;

// forward declarations
shared_ptr<queue<shared_ptr<Card>>> loadCards(const std::string& fileName);
shared_ptr<vector<shared_ptr<Player>>> loadPlayers();
bool isValidPlayerName(string basicString);
shared_ptr<Player> getValidPlayerClass(string playerClass);

Mtmchkin::Mtmchkin(const std::string& fileName) : m_looserPlayers() , m_winnerPlayers() , m_currRound(1) {

    // Load cards
    m_cardsQueue = *(loadCards(fileName));

    // Interactively get the number of players and player types.
    m_players = *(loadPlayers());

    m_activePlayers = m_players;
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

shared_ptr<Player> getValidPlayerClass(string playerClass , string playerName) {
    return PlayerFactory::createPlayer(playerClass, playerName);
}

int getInt() {
    int number;

    // Try to read an integer from the user
    if (std::cin >> number) {
        // Input was successful, use the entered number
        return number;
    } else {
        // Input failed, handle the error
        // Clear the error state
        std::cin.clear();
        // Discard the invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw BadNumberError();
    }
}

shared_ptr<vector<shared_ptr<Player>>> loadPlayers() {
    int numPlayers;
    shared_ptr<vector<shared_ptr<Player>>> playersVec = make_shared<vector<shared_ptr<Player>>>();

    printStartGameMessage();

    // Validate input
    do {
        printEnterTeamSizeMessage();
        // Get the number of players
        // cin >> numPlayers;

        try {
            numPlayers = getInt();
        } catch (BadNumberError ex) {
            //printInvalidTeamSize();
            numPlayers = -1;

        }

        if (!(numPlayers >= 2 && numPlayers <=6) ){
            printInvalidTeamSize();
        }


    } while  (!(numPlayers >= 2 && numPlayers <=6));

    // Loop through each player
    bool invalidInput = false;
    for (int i = 1; i <= numPlayers; ++i) {
        do {
            string playerName, playerJob;
            // Get player's name

            if (!invalidInput) {
                printInsertPlayerMessage();
            }

            getline(cin >> ws, playerName, ' '); // Read the name until space
            playerName.erase(0, playerName.find_first_not_of(" \t\n\r\f\v"));
            getline(cin >> ws, playerJob);
            playerJob.erase(0, playerJob.find_first_not_of(" \t\n\r\f\v"));


            if (!isValidPlayerName(playerName)) {
                printInvalidName();
                invalidInput = true;
            }
            else {
                shared_ptr<Player>  newPlayer = nullptr;
                if (((newPlayer = getValidPlayerClass(playerJob, playerName)) == nullptr)) {
                    printInvalidClass();
                    invalidInput = true;
                } else {
                    playersVec->push_back(newPlayer);
                    invalidInput = false;
                }
            }
        } while (invalidInput);
    }

    return playersVec;
}



shared_ptr<queue<shared_ptr<Card>>> loadCards(const std::string& fileName)
{
    shared_ptr<queue<shared_ptr<Card>>> cardsQueue = make_shared<queue<shared_ptr<Card>>>();

    // Open a file for reading
    std::ifstream inputFile(fileName);

    // Check if the file is open
    if (!inputFile.is_open()) {
        //std::cerr << "Error opening the file!" << std::endl;
        throw DeckFileNotFound();
    }

    // Read lines from the file
    int lineNum = 1;
    std::string line;
    while (std::getline(inputFile, line)) {
        try {
            cardsQueue->push((CardFactory::createCard(line)));
        } catch ( DeckFileFormatError ex) {
            throw DeckFileFormatError(lineNum);
        }
        lineNum++;
    }

    if (lineNum <= 5) {
        throw DeckFileInvalidSize();
    }

    // Close the file
    inputFile.close();

    return cardsQueue;
}

void Mtmchkin::playRound() {


    printRoundStartMessage(m_currRound);


    for (vector<shared_ptr<Player>>::iterator it = m_activePlayers.begin(); it != m_activePlayers.end();) {
        shared_ptr<Player> pl = *it;
        shared_ptr<Card>  currCard = m_cardsQueue.front();
        m_cardsQueue.pop();

        printTurnStartMessage(pl->getMName());
        currCard->applyEncounter(*pl);

        if(pl->hasWon()){
           m_activePlayers.erase(it);
           m_winnerPlayers.push_back(pl);
        } else if(pl->hasLost()){
            m_activePlayers.erase(it);
            m_looserPlayers.push_back(pl);
        } else {
            ++it;
        }
        if(isGameOver()){
            printGameEndMessage();
        }
        m_cardsQueue.push(currCard);
    }

    m_currRound++;
}

static void printPlayersSection(int* rank, vector<shared_ptr<Player>> sectionVector,bool order) {

    if (order) {
        for (std::vector<shared_ptr<Player>>::const_reverse_iterator it = sectionVector.rbegin();
             it != sectionVector.rend(); ++it) {
            printPlayerLeaderBoard((*rank)++, **it);
        }
    } else {
        for (std::vector<shared_ptr<Player>>::const_iterator it = sectionVector.begin(); it != sectionVector.end(); ++it) {
            printPlayerLeaderBoard((*rank)++,**it);
        }
    }
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int rank = 1;
    printPlayersSection(&rank,m_winnerPlayers, false);
    printPlayersSection(&rank,m_activePlayers,false);
    printPlayersSection(&rank,m_looserPlayers,true);
}

bool Mtmchkin::isGameOver() const {
    return (m_activePlayers.size() == 0);
}

int Mtmchkin::getNumberOfRounds() const {
    return m_currRound - 1;
}






