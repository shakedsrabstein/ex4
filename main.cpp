#include "Mtmchkin.h"

int main() {

    try {

        Mtmchkin game("deck.txt");
        while (!game.isGameOver()) {
            game.playRound();
        }
        game.printLeaderBoard();
    } catch (const exception& ex) {
        cout << ex.what() << endl;
    }
}