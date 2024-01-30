
#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Mtmchkin.h"
#include "Cards/Witch.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Exception.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Cards/Witch.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Players/Healer.h"
#include <algorithm>
#include <sstream>
#include <random>
#include <cstdio>
#include <fstream>
#include <cstring>

using std::unique_ptr;
using std::cout;
using std::cerr;
using std::string;
using std::fstream;
using std::istringstream;
using std::vector;


/* ---------------------------------------------------------------------------------------------- */
// --------------------------------       General Helper Functions          ------------------------------

void createTextFile(const string &filename, const string &input)
{
    std::ofstream file(filename);
    if(file){
        file << input;
    }
}

void deleteTextFile(const string &filename)
{
    std::remove(filename.c_str());
}

bool compareFiles(const string &filename1, const string &filename2)
{
    string line1,line2;
    fstream file1(filename1),file2(filename2);
    if( !file2){
         cerr<<"Error opening file 2"<<std::endl;
         return false;
    }
	if(!file1 ){
         cerr<<"Error opening file 1"<<std::endl;
         return false;
    }
    while(!file1.eof()){ //read file until you reach the end
        getline(file1,line1);
        getline(file2,line2);
        if(!(line1==line2))
        {
            return false;
        }
    }
    if(!file2.eof()){
        return false;
    }
    return true;
}

bool GeneralGameSimulationTestFiles(const string &tempDeckFilename, string input, string deck, string expectedOutputFileName)
{
    //   init cin from file
    //createTextFile(tempDeckFilename+".txt",deck);

    istringstream in(input);
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf());

    std::ofstream outfile(tempDeckFilename+"out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(outfile.rdbuf());

    Mtmchkin game(deck);
    while(!game.isGameOver() && game.getNumberOfRounds() < 100){
        game.playRound();
        game.printLeaderBoard();
    }

    bool res = compareFiles(tempDeckFilename+"out.txt", expectedOutputFileName);
    outfile.close();
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    deleteTextFile(tempDeckFilename+".txt");
    return res;
}

bool GeneralGameSimulationTest(const string &tempDeckFilename, string input, string deck, string expectedOutputFileName)
{
    //   init cin from file
    createTextFile(tempDeckFilename+".txt",deck);
    istringstream in(input);
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf());

    std::ofstream outfile(tempDeckFilename+"out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(outfile.rdbuf());
    Mtmchkin game(tempDeckFilename+".txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < 100){
        game.playRound();
        game.printLeaderBoard();
    }

    bool res = compareFiles(tempDeckFilename+"out.txt", expectedOutputFileName);
	outfile.close();
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    deleteTextFile(tempDeckFilename+".txt");
    return res;
}

void run_test(std::function<bool()> test, std::string test_name)
{
    if(!test()){
        std::cout<< test_name <<" FAILED."<<std::endl;
        std::cout << std::endl;
        return;
    }
    std::cout<<test_name<<" SUCCEEDED."<<std::endl;
    std::cout << std::endl;

}


/* ---------------------------------------------------------------------------------------------- */
// --------------------------------       Tests for Card class          ------------------------------

bool cardsPrintsTest()
{
    
    Barfight junta;
    Dragon mushu;
    Mana mana;
    Gremlin gremlin;
    Merchant pizzaHut;
    Well well;
    Treasure factor;
    Witch witch;
    cout << junta << std::endl << mushu << std::endl << mana   
                    << std::endl << gremlin  << std::endl << pizzaHut
                    << std::endl << well  << std::endl << factor
                    << std::endl << witch;
    return true;
}

bool playersPrintsTest()
{
    
    Ninja player1("Itay");
    Warrior player2("Efrat");
    Healer player3("Jimmy");
    cout << player1 << std::endl << player2 << std::endl << player3   
                    << std::endl;
    return true;
}

bool testCard()
{
    vector<unique_ptr<Card>> cards;
    cards.push_back(unique_ptr<Card>(new Gremlin()));
    cards.push_back(unique_ptr<Card>(new Witch()));
    cards.push_back(unique_ptr<Card>(new Dragon()));
    cards.push_back(unique_ptr<Card>(new Treasure()));
    cards.push_back(unique_ptr<Card>(new Merchant()));
    cards.push_back(unique_ptr<Card>(new Mana()));
    cards.push_back(unique_ptr<Card>(new Barfight()));
    cards.push_back(unique_ptr<Card>(new Well()));
    for(unique_ptr<Card>& card : cards){
        cout << *card;
    }
	cards.erase(cards.begin(),cards.end());
    return true;
}

/* ---------------------------------------------------------------------------------------------- */
// --------------------------------       Tests for Mtmchkin class          ------------------------------

bool gameRunTest()
{
    //   init cin from file
    std::ifstream in("in.txt");
    if(!in.is_open()){
        throw std::exception();
    }
    std::cin.rdbuf(in.rdbuf());
    Mtmchkin game("gametest.txt");
    while(!game.isGameOver()){
        game.playRound();
    }

    return true;
}

bool dragonDenTest()
{
    const string tmp_file("dragonDen_test");
    string input("2\nJimmy Healer\nPikachu Warrior");
    string deck("Dragon\nDragon\nDragon\nDragon\nDragon");
    string expectedOutputFilename("tests/dragonDen_test_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

bool witchLairTest()
{
    const string tmp_file("witchLair_test");
    string input("2\nItay Warrior\nPikachu Ninja");
    string deck("Witch\nWitch\nWitch\nWitch\nWitch");
    string expectedOutputFilename("tests/witchLair_test_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

bool gremlinCaveTest()
{
    const string tmp_file("gremlinCave_test");
    string input("2\nItay Healer\nPikachu Ninja");
    string deck("Gremlin\nGremlin\nGremlin\nGremlin\nGremlin");
    string expectedOutputFilename("tests/gremlinCave_test_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

bool nonMostersTest()
{
    const string tmp_file("noMonster_test");
    string input("2\nItay Healer\nPikachu Ninja");
    string deck("Mana\nBarfight\nWell\nTreasure\nMana");
    string expectedOutputFilename("tests/noMonster_test_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

bool roundLimitTest()
{
    const string tmp_file("roundLimit_test");
    string input("2\nmatamDalf Healer\nrocky Warrior");
    string deck("Mana\nMana\nMana\nMana\nMana");
    string expectedOutputFilename("tests/roundLimit_test_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

bool allTenTest()
{
    const string tmp_file("allTen_test");
    string input("2\nmatamDalf Healer\nrocky Warrior");
    string deck("Gremlin\nGremlin\nGremlin\nGremlin\nGremlin");
    string expectedOutputFilename("tests/allTen_test_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

bool badPlayerInputTest()
{
    const string tmp_file("badPlayerInput_test");
    string input("2\nmatamDalf Healerd\nmatamDalf ninha\nmatamDalf Healer\nrocky Warrior");
    string deck("Gremlin\nWitch\nGremlin\nGremlin\nDragon");
    string expectedOutputFilename("tests/badPlayerInput_test_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

bool merchantInputTest()
{
    const string tmp_file("merchantInput_test");
    string input("2\nmatamDalf Healerd\nmatamDalf rogoe\nmatamDalf Healer\nrocky Warrior\n"
                 "1\n"
                 "1\n"
                 "0\n"
                 "2\n"
                 "0\n");
    string deck("Gremlin\nGremlin\nMerchant\nMerchant\nDragon");
    string expectedOutputFilename("tests/merchantInput_test_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

/* ---------------------------------------------------------------------------------------------- */
// --------------------------------       Tests for Exceptions          ------------------------------

bool badSizeTest()
{
    const string tmp_file("badSize_test");
    string input("4\nBarbieGirl Healer\nInABarbieWorld Ninja\nMadeOfPlastic Ninja\nITSFANTASTIC Healer");
    string deck("Mana");
    string expectedOutputFilename("notneeded.txt");
	bool flag= false;
    try{
        Mtmchkin("inputs/empty.txt");
    }
    catch(const DeckFileInvalidSize& e){
        flag = true;
    }
    return flag;
}

bool noFileTest()
{
    const string tmp_file("noFile_test");
    string input("2\nItay Healer\nPikachu Ninja");
    string expectedOutputFilename("notneeded.txt");
    string deck("This_is_not_the_file_your_looking_for");
    bool flag = false;
    try{
        Mtmchkin("inputs/noFile.txt");
    }
    catch(const DeckFileNotFound& e){
        flag=true;
    }
    return flag;
}

bool badFormatTest()
{
    const string tmp_file("badFormat_test");
    string input("2\nItay Healer\nPikachu Ninja");
    string deck("SomeBody Once told me the world is gonna roll me\nWitch\n");
    string expectedOutputFilename("notneeded.txt");
    bool flag = false;
    try {
        Mtmchkin("inputs/badFormat_test.txt");
    }
    catch(const DeckFileFormatError& e){
        if(strcmp(e.what(),"Deck File Error: File format error in line 2")==0) {
            flag=true;
        }
    }
    return flag;
}

bool badFormatStartTest()
{
    const string tmp_file("badFormat_test");
    string input("2\nItay Healer\nPikachu Ninja");
    string deck("I aint the sharpest tool in the shed\nWitch");
    string expectedOutputFilename("notneeded.txt");
    bool flag = false;
    try {
        Mtmchkin("inputs/badFormat_test_start_of_file.txt");
    }
    catch(const DeckFileFormatError& e){
        if(strcmp(e.what(),"Deck File Error: File format error in line 1")==0)
        {
            flag = true;
        }
    }
    return flag;
}


bool test0()
{
    const string tmp_file("test0_test");
    string input("2\n"
                 "Simplton Healer\n"
                 "Trickelton Ninja");
    string deck("Gremlin\n"
                "Mana\n"
                "Witch\n"
                "Well\n"
                "Witch");
    string expectedOutputFilename("tests/test0_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}


bool numOfPlayersAsChar()
{
    const string tmp_file("numOfPlayersAsChar");
    string input("d\n"
                 "2\n"
                 "Simplton Healer\n"
                 "Trickelton Ninja");
    string deck("Gremlin\n"
                "Mana\n"
                "Witch\n"
                "Well\n"
                "Witch");
    string expectedOutputFilename("tests/numOfPlayersAsChar_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

bool test13()
{
    const string tmp_file("test13");
    string input("-93\n"
                 "-47\n"
                 "19\n"
                 "51\n"
                 "29\n"
                 "-18\n"
                 "4\n"
                 "[Annoying MetargelMatam\n"
                 "Anno-ing Warrior\n"
                 "Ann0ying TheDeanOfComputerScience\n"
                 "ThisShouldBePlayerErrorNotClass Healer\n"
                 "\"Annoying\" MetargelMatam\n"
                 "AnnoyingAnnoyingso TheDeanOfComputerScience\n"
                 "Annoying_ TheDeanOfComputerScience\n"
                 "Annoying@you Ninja\n"
                 "AnnoyingAnnoyingson TestsLord\n"
                 "AnnoyingAnnoyings MetargelMatam\n"
                 "Annoyin9 MetargelMatam\n"
                 "Ann0ying TheDeanOfComputerScience\n"
                 "AnnoyingAnnoying TheDeanOfComputerScience\n"
                 "Daniel Ninja\n"
                 "AnnoyingAnnoyingso TestsLord\n"
                 "Annoying0 Warrior\n"
                 "4nnoying Warrior\n"
                 "Annoying@ Healer\n"
                 "Annoying@ MetargelMatam\n"
                 "AnnoyingAnnoyingso TestsLord\n"
                 "EitanYaakombi` TestsLord\n"
                 "AnnoyingAnnoyings TestsLord\n"
                 "@Annoying TestsLord\n"
                 "Ann0ying MetargelMatam\n"
                 "Anno-ing MetargelMatam\n"
                 "Omerz MetargelMatam\n"
                 "Annoying_ TestsLord\n"
                 "Ann0ying TheDeanOfComputerScience\n"
                 "AnnoyingAnnoyingson MetargelMatam\n"
                 "Ann0ying TestsLord\n"
                 "4nnoying TheDeanOfComputerScience\n"
                 "TheOneAndOnlyCPPLanguage TestsLord\n"
                 "ThisIsLike1025CharectersForSomeReason____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ TheDeanOfComputerScience\n"
                 "ThisShouldBePlayerErrorNotClass TheDeanOfComputerScience\n"
                 "AnnoyingAnnoyings TheDeanOfComputerScience\n"
                 "Ann0ying Healer\n"
                 "Annoy1ng TheDeanOfComputerScience\n"
                 "ThisIsLike1025CharectersForSomeReason____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ Healer\n"
                 "4nnoying TestsLord\n"
                 "Annoy1ng Ninja\n"
                 "\"Annoying\" MetargelMatam\n"
                 "0Annoying TestsLord\n"
                 "Annoying_ TestsLord\n"
                 "^ Warrior\n"
                 "AnnoyingAnnoying TheDeanOfComputerScience\n"
                 "Annoyin9 Warrior\n"
                 "Annoying0 TestsLord\n"
                 "ThisIsLike1025CharectersForSomeReason____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ TheDeanOfComputerScience\n"
                 "Annoying? MetargelMatam\n"
                 "Annoying? MetargelMatam\n"
                 "Amirmann TheDeanOfComputerScience\n"
                 "Annoying_ MetargelMatam\n"
                 "AnnoyingAnnoying TestsLord\n"
                 "GalLalush TestsLord\n"
                 "AnnoyingAnnoying TheDeanOfComputerScience\n"
                 "AnnoyingAnnoyings TheDeanOfComputerScience\n"
                 "EitanYaakombi` TheDeanOfComputerScience\n"
                 "Annoying? TestsLord\n"
                 "Annoying'sMom Ninja\n"
                 "Omerz TestsLord\n"
                 "TheOneAndOnlyCPPLanguage MetargelMatam\n"
                 "\"Annoying\" TheDeanOfComputerScience\n"
                 "AnnoyingAnnoying TestsLord\n"
                 "Amirmann Warrior\n"
                 "Anno-ing MetargelMatam\n"
                 "GalLalush TheDeanOfComputerScience\n"
                 "AnnoyingAnnoyingson Ninja\n"
                 "TomerM TestsLord\n"
                 "^ TheDeanOfComputerScience\n"
                 "Daniel TestsLord\n"
                 "0Annoying Ninja\n"
                 "^ TestsLord\n"
                 "AnnoyingAnnoyingson TheDeanOfComputerScience\n"
                 "Annoying_ TestsLord\n"
                 "[Annoying TestsLord\n"
                 "Annoying_ Healer\n"
                 "{Annoying TheDeanOfComputerScience\n"
                 "Annoying! TheDeanOfComputerScience\n"
                 "Annoying[ TheDeanOfComputerScience\n"
                 "Annoyin9 Ninja\n"
                 "0Annoying TestsLord\n"
                 "Annoy1ng TestsLord\n"
                 "TheOneAndOnlyCPPLanguage Healer\n"
                 "AnnoyingAnnoyingson TestsLord\n"
                 "@Annoying Healer\n"
                 "\"Annoying\" Healer\n"
                 "`Annoying MetargelMatam\n"
                 "Annoyin9 Warrior\n"
                 "Annoying{ MetargelMatam\n"
                 "\"Annoying\" Ninja\n"
                 "Efrat TestsLord\n"
                 "Ann0ying TestsLord\n"
                 "0Annoying TestsLord\n"
                 "@Annoying TheDeanOfComputerScience\n"
                 "EitanYaakombi` TestsLord\n"
                 "Annoyin9 TheDeanOfComputerScience\n"
                 "{Annoying TheDeanOfComputerScience\n"
                 "Galush++ TestsLord\n"
                 "ThisIsLike1025CharectersForSomeReason____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ TestsLord\n"
                 "Annoying_ MetargelMatam\n"
                 "Annoying_ Warrior\n"
                 "`Annoying MetargelMatam\n"
                 "0Annoying Ninja\n"
                 "{Annoying Warrior\n"
                 "GalLalush MetargelMatam\n"
                 "AnnoyingAnnoying Healer\n"
                 "Ann0ying MetargelMatam\n"
                 "Anno-ing Ninja\n"
                 "Annoying{ TheDeanOfComputerScience\n"
                 "Daniel TestsLord\n"
                 "AnnoyingAnnoying MetargelMatam\n"
                 "Annoying? TheDeanOfComputerScience\n"
                 "EitanYaakombi` TheDeanOfComputerScience\n"
                 "ThisIsLike1025CharectersForSomeReason____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ TestsLord\n"
                 "0Annoying Warrior\n"
                 "GalLalush MetargelMatam\n"
                 "\"Annoying\" Warrior\n"
                 "0Annoying TheDeanOfComputerScience\n"
                 "@Annoying MetargelMatam\n"
                 "Ann0ying TheDeanOfComputerScience\n"
                 "ThisIsLike1025CharectersForSomeReason____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ Warrior\n"
                 "@Annoying TestsLord\n"
                 "Annoying'sMom TestsLord\n"
                 "Annoying_ TheDeanOfComputerScience\n"
                 "GalLalush MetargelMatam\n"
                 "TheOneAndOnlyCPPLanguage TheDeanOfComputerScience\n"
                 "ThisIsLike1025CharectersForSomeReason____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ TestsLord\n"
                 "Annoying{ MetargelMatam\n"
                 "Anno-ing TestsLord\n"
                 "Annoying? TheDeanOfComputerScience\n"
                 "Amirmann Warrior\n"
                 "Annoying'sMom Ninja\n"
                 "Annoying[ TheDeanOfComputerScience\n"
                 "AnnoyingAnnoying TheDeanOfComputerScience\n"
                 "Annoying? TheDeanOfComputerScience\n"
                 "Annoying_ Ninja\n"
                 "@Annoying Ninja\n"
                 "Annoying! MetargelMatam\n"
                 "ThisIsLike1025CharectersForSomeReason____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ Healer\n"
                 "Annoying[ MetargelMatam\n"
                 "AnnoyingAnnoyingso MetargelMatam\n"
                 "Annoying0 MetargelMatam\n"
                 "Annoying0 TheDeanOfComputerScience\n"
                 "4nnoying Healer\n"
                 "Ann0ying MetargelMatam\n"
                 "AnnoyingAnnoyingson TestsLord\n"
                 "GalLalush TestsLord\n"
                 "Galush++ TheDeanOfComputerScience\n"
                 "Annoy1ng MetargelMatam\n"
                 "@Annoying TheDeanOfComputerScience\n"
                 "{Annoying MetargelMatam\n"
                 "`Annoying TestsLord\n"
                 "\"Annoying\" TestsLord\n"
                 "Annoying@ MetargelMatam\n"
                 "AnnoyingAnnoying Warrior\n"
                 "Annoying_ TestsLord\n"
                 "Annoying0 Warrior\n"
                 "`Annoying MetargelMatam\n"
                 "Anno-ing TestsLord\n"
                 "0Annoying TheDeanOfComputerScience\n"
                 "Annoying` TestsLord\n"
                 "AnnoyingAnnoyingso TestsLord\n"
                 "^ Ninja\n"
                 "Daniel TheDeanOfComputerScience\n"
                 "Amirmann TestsLord\n"
                 "EitanYaakombi` TestsLord\n"
                 "\"Annoying\" TheDeanOfComputerScience\n"
                 "Annoying{ MetargelMatam\n"
                 "\"Annoying\" TheDeanOfComputerScience\n"
                 "Omerz MetargelMatam\n"
                 "AnnoyingAnnoyings Ninja\n"
                 "EitanYaakombi` MetargelMatam\n"
                 "^ TestsLord\n"
                 "4nnoying TestsLord\n"
                 "AnnoyingAnnoyingson TheDeanOfComputerScience\n"
                 "Annoying` Healer\n"
                 "GalLalush MetargelMatam\n"
                 "0Annoying TheDeanOfComputerScience\n"
                 "Annoy1ng Healer\n"
                 "Amirmann TheDeanOfComputerScience\n"
                 "Annoying@you Warrior\n"
                 "ThisIsLike1025CharectersForSomeReason____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ MetargelMatam\n"
                 "Galush++ TheDeanOfComputerScience\n"
                 "GalLalush MetargelMatam\n"
                 "Daniel MetargelMatam\n"
                 "\"Annoying\" MetargelMatam\n"
                 "{Annoying TheDeanOfComputerScience\n"
                 "Anno-ing Warrior\n"
                 "ThisShouldBePlayerErrorNotClass TheDeanOfComputerScience\n"
                 "Annoy1ng TheDeanOfComputerScience\n"
                 "{Annoying MetargelMatam\n"
                 "Amirmann Healer\n"
                 "1\n"
                 "2\n"
                 "1\n"
                 "2\n"
                 "L\n"
                 "4\n"
                 "1\n"
                 "1\n"
                 "T\n"
                 "1\n"
                 "2\n"
                 "(\n"
                 "2\n"
                 "\u000B\n"
                 "1\n"
                 "x\n"
                 "2\n"
                 "c\n"
                 "0\n"
                 "y\n"
                 "0\n"
                 "s\n"
                 "\n"
                 "\n"
                 "2\n"
                 "1\n"
                 "Z\n"
                 "2\n"
                 "1\n"
                 "V\n"
                 "p\n"
                 "0\n"
                 "0\n"
                 "{\n"
                 "0\n"
                 "\n"
                 "0\n"
                 "1\n"
                 "9\n"
                 "0\n"
                 "x\n"
                 ",\n"
                 "1\n"
                 "1\n"
                 "9\n"
                 "D\n"
                 "1\n"
                 "/\n"
                 "1\n"
                 "2\n"
                 "Y\n"
                 "1\n"
                 "0\n"
                 ";\n"
                 "0\n"
                 "[\n"
                 "1\n"
                 "1\n"
                 "1\n"
                 "1\n"
                 "$\n"
                 "2\n"
                 "L\n"
                 "1\n"
                 "`\n"
                 "3\n"
                 "1\n"
                 "7\n"
                 "0\n"
                 "p\n"
                 "1\n"
                 "1\n"
                 "2\n"
                 "1\n"
                 "2\n"
                 "k\n"
                 "s\n"
                 "1\n"
                 "1\n"
                 "[\n"
                 "1\n"
                 " \n"
                 "1\n"
                 "g\n"
                 "/\n"
                 "2\n"
                 "O\n"
                 "0\n"
                 "0\n"
                 ">\n"
                 "3\n"
                 "1\n"
                 "0\n"
                 "d\n"
                 "n\n"
                 "2\n"
                 "1\n"
                 "o\n"
                 "2\n"
                 "q\n"
                 "I\n"
                 "1\n"
                 "F\n"
                 "1\n"
                 "1\n"
                 "/\n"
                 "t\n"
                 "2\n"
                 "1\n"
                 "r\n"
                 "0\n"
                 "U\n"
                 "1\n"
                 "/\n"
                 "1\n"
                 "}\n"
                 "=\n"
                 "0\n"
                 ":\n"
                 "2\n"
                 "5\n"
                 "\u000B\n"
                 "2\n"
                 "h\n"
                 "0\n"
                 "2\n"
                 "1\n"
                 "/\n"
                 "2\n"
                 "2\n"
                 " \n"
                 "1\n"
                 "2\n"
                 "|\n"
                 "1\n"
                 "n\n"
                 "j\n"
                 "1\n"
                 "(\n"
                 "0\n"
                 "J\n"
                 "2\n"
                 "o\n"
                 "-\n"
                 "2\n"
                 "6\n"
                 "^\n"
                 "2\n"
                 "G\n"
                 "1\n"
                 "k\n"
                 "1\n"
                 "2\n"
                 "z\n"
                 "1\n"
                 "V\n"
                 "2\n"
                 "X\n"
                 "0\n"
                 "(\n"
                 "E\n"
                 "0\n"
                 "@\n"
                 "2\n"
                 "o\n"
                 "1\n"
                 "L\n"
                 "1\n"
                 "*\n"
                 "0\n"
                 "B\n"
                 ".\n"
                 "1\n"
                 "{\n"
                 "q\n"
                 "2\n"
                 "^\n"
                 "2\n"
                 "1\n"
                 "+\n"
                 "0\n"
                 "\u000B\n"
                 "0\n"
                 "0\n"
                 "x\n"
                 "e\n"
                 "0\n"
                 "2\n"
                 "1\n"
                 "%\n"
                 "0\n"
                 "X\n"
                 "0\n"
                 "o\n"
                 "0\n"
                 "d\n"
                 "0\n"
                 "u\n"
                 "n\n"
                 "0\n"
                 "0\n"
                 "0\n"
                 "F\n"
                 "1\n"
                 "2\n"
                 "M\n"
                 "1\n"
                 "z\n"
                 "1\n"
                 "3\n"
                 "A\n"
                 "1\n"
                 "7\n"
                 "B\n"
                 "2\n"
                 "x\n"
                 "v\n"
                 "0\n"
                 ",\n"
                 "=\n"
                 "1\n"
                 "k\n"
                 "0\n"
                 "T\n"
                 "D\n"
                 "2\n"
                 "1\n"
                 "4\n"
                 "0\n"
                 "0\n"
                 "*\n"
                 "2\n"
                 "T\n"
                 "0\n"
                 "U\n"
                 "U\n"
                 "2\n"
                 "n\n"
                 "2\n"
                 "0\n"
                 "0\n"
                 "{\n"
                 "2\n"
                 "0\n"
                 "M\n"
                 "1\n"
                 "L\n"
                 "s\n"
                 "1\n"
                 "0\n"
                 "v\n"
                 "1\n"
                 "D\n"
                 "E\n"
                 "0\n"
                 "2\n"
                 "1\n"
                 "n\n"
                 "&\n"
                 "1\n"
                 "*\n"
                 "X\n"
                 "2\n"
                 "0\n"
                 "S\n"
                 "C\n"
                 "1\n"
                 "2\n"
                 "?\n"
                 "0\n"
                 "e\n"
                 "0\n"
                 "n\n"
                 "\f\n"
                 "1\n"
                 "%\n"
                 "Y\n"
                 "1\n"
                 "J\n"
                 "8\n"
                 "1\n"
                 "c\n"
                 "G\n"
                 "1\n"
                 ",\n"
                 "1\n"
                 "3\n"
                 "1\n"
                 "'\n"
                 "M\n"
                 "0\n"
                 "q\n"
                 "e\n"
                 "1\n"
                 "1\n"
                 "q\n"
                 "5\n"
                 "0\n"
                 "1\n"
                 "*\n"
                 "2\n"
                 "\n"
                 "^\n"
                 "1\n"
                 "{\n"
                 "u\n"
                 "1\n"
                 "T\n"
                 "2\n"
                 "2\n"
                 "c\n"
                 "/\n"
                 "1\n"
                 "1\n"
                 ".\n"
                 "~\n"
                 "2\n"
                 "-\n"
                 "Y\n"
                 "2\n"
                 "M\n"
                 "4\n"
                 "1\n"
                 ">\n"
                 "0\n"
                 "0\n"
                 "4\n"
                 "{\n"
                 "2\n"
                 "n\n"
                 "[\n"
                 "2\n"
                 "*\n"
                 "2\n"
                 "E\n"
                 "1\n"
                 "1\n"
                 "<\n"
                 "2\n"
                 "1\n"
                 "N\n"
                 "2\n"
                 "2\n"
                 ";\n"
                 "\"\n"
                 "1\n"
                 "h\n"
                 "U\n"
                 "0\n"
                 "L\n"
                 "0\n"
                 "A\n"
                 "1\n"
                 "2\n"
                 "1\n"
                 "0\n"
                 "<\n"
                 "0\n"
                 "0\n"
                 "\\\n"
                 "2\n"
                 "|\n"
                 "~\n"
                 "0\n"
                 "1\n"
                 "B\n"
                 "[\n"
                 "1\n"
                 "0\n"
                 "0\n"
                 "^\n"
                 "2\n"
                 ".\n"
                 "1\n"
                 "\u000B\n"
                 "1\n"
                 "5\n"
                 "0\n"
                 "u\n"
                 "9\n"
                 "1\n"
                 "a\n"
                 "H\n"
                 "2\n"
                 "Q\n"
                 "1\n"
                 ")\n"
                 "B\n"
                 "2\n"
                 "0\n"
                 "=\n"
                 "1\n"
                 "f\n"
                 "H\n"
                 "0\n"
                 "M\n"
                 "E\n"
                 "1\n"
                 "2\n"
                 "d\n"
                 "0\n"
                 "R\n"
                 "_\n"
                 "0\n"
                 ":\n"
                 "^\n"
                 "0\n"
                 "g\n"
                 "2\n"
                 "2\n"
                 "r\n"
                 "F\n"
                 "0\n"
                 "8\n"
                 "k\n"
                 "2\n"
                 "i\n"
                 " \n"
                 "0\n"
                 "4\n"
                 "\f\n"
                 "0\n"
                 "j\n"
                 "1\n"
                 "c\n"
                 "J\n"
                 "1\n"
                 "l\n"
                 "\f\n"
                 "1\n"
                 "C\n"
                 "a\n"
                 "2\n"
                 "X\n"
                 "1\n"
                 "j\n"
                 "2\n"
                 "V\n"
                 "2\n"
                 "b\n"
                 "0\n"
                 "2\n"
                 "2\n"
                 "~\n"
                 "0\n"
                 "\n"
                 "\n"
                 "2\n"
                 "+\n"
                 "F\n"
                 "1\n"
                 "0\n"
                 "1\n"
                 "4\n"
                 "-\n"
                 "2\n"
                 "{\n"
                 "0\n"
                 "=\n"
                 "E\n"
                 "2\n"
                 "'\n"
                 "h\n"
                 "0\n"
                 ";\n"
                 "1\n"
                 "x\n"
                 "1\n"
                 "#\n"
                 "0\n"
                 "2\n"
                 "b\n"
                 "1\n"
                 "A\n"
                 "=\n"
                 "1\n"
                 "u\n"
                 "6\n"
                 "0\n"
                 "I\n"
                 "0\n"
                 "^\n"
                 "S\n"
                 "2\n"
                 ":\n"
                 "A\n"
                 "2\n"
                 "1\n"
                 "<\n"
                 "2\n"
                 "5\n"
                 "|\n"
                 "0\n"
                 "F\n"
                 "H\n"
                 "1\n"
                 "u\n"
                 "2\n"
                 "~\n"
                 "2\n"
                 "2\n"
                 "9\n"
                 "f\n"
                 "1\n"
                 "1\n"
                 "u\n"
                 "1\n"
                 "2\n"
                 "l\n"
                 "2\n"
                 "0\n"
                 "1\n"
                 "0\n"
                 "y\n"
                 "0\n"
                 "D\n"
                 "v\n"
                 "0\n"
                 "2\n"
                 "R\n"
                 "e\n"
                 "0\n"
                 "s\n"
                 "!\n"
                 "1\n"
                 "2\n"
                 "h\n"
                 "i\n"
                 "2\n"
                 "T\n"
                 "v\n"
                 "0\n"
                 "1\n"
                 "k\n"
                 "1\n"
                 "1\n"
                 "0\n"
                 "N\n"
                 "\n"
                 "1\n"
                 "5\n"
                 "2\n"
                 "v\n"
                 "T\n"
                 "2\n"
                 "=\n"
                 "2\n"
                 "`\n"
                 "0\n"
                 "d\n"
                 "N\n"
                 "1\n"
                 "p\n"
                 "U\n"
                 "2\n"
                 "w\n"
                 "2\n"
                 "d\n"
                 "2\n"
                 "<\n"
                 "\t\n"
                 "0\n"
                 "h\n"
                 "0\n"
                 "_\n"
                 "0\n"
                 "\n"
                 "\n"
                 "0\n"
                 "0\n"
                 "8\n"
                 "1\n"
                 "v\n"
                 "1\n"
                 "-\n"
                 "l\n"
                 "2\n"
                 "M\n"
                 "\\\n"
                 "2\n"
                 "2\n"
                 "0\n"
                 "1\n"
                 "0\n"
                 "1\n"
                 "\n"
                 "K\n"
                 "0\n"
                 "2\n"
                 "0\n"
                 "[\n"
                 "I\n"
                 "1\n"
                 "O\n"
                 "s\n"
                 "0\n"
                 "T\n"
                 "1\n"
                 "_\n"
                 "1\n"
                 "1\n"
                 "G\n"
                 "X\n"
                 "1\n"
                 "~\n"
                 "1\n"
                 "$\n"
                 "S\n"
                 "2\n"
                 "L\n"
                 "0\n"
                 "a\n"
                 "K\n"
                 "1\n"
                 "~\n"
                 "0\n"
                 "~\n"
                 "0\n"
                 "0\n"
                 "0\n"
                 "a\n"
                 "0\n"
                 "R\n"
                 "%\n"
                 "2\n"
                 "g\n"
                 "0\n"
                 "`\n"
                 "1\n"
                 "o\n"
                 "W\n"
                 "0\n"
                 "2\n"
                 "e\n"
                 "o\n"
                 "2\n"
                 "2\n"
                 "8\n"
                 "2\n"
                 "u\n"
                 "]\n"
                 "1\n"
                 "R\n"
                 "b\n"
                 "0\n"
                 "3\n"
                 "1\n"
                 " \n"
                 "u\n"
                 "0\n"
                 "1\n"
                 ":\n"
                 "0\n"
                 "^\n"
                 "2\n"
                 "2\n"
                 "1\n"
                 "#\n"
                 "2\n"
                 "0\n"
                 "1\n"
                 "1\n"
                 "+\n"
                 "0\n"
                 "2\n"
                 ";\n"
                 "2\n"
                 "0\n"
                 "^\n"
                 "1\n"
                 ";\n"
                 "z\n"
                 "1\n"
                 "\u000B\n"
                 " \n"
                 "0\n"
                 "1\n"
                 "2\n"
                 "B\n"
                 "0\n"
                 "1\n"
                 "a\n"
                 "g\n"
                 "2\n"
                 "/\n"
                 "-\n"
                 "0\n"
                 "f\n"
                 "O\n"
                 "1\n"
                 "0\n"
                 "`\n"
                 "0\n"
                 "N\n"
                 "|\n"
                 "2\n"
                 "2\n"
                 "2\n"
                 "j\n"
                 "0\n"
                 "2\n"
                 "1\n"
                 "\t\n"
                 "7\n"
                 "1\n"
                 "2\n"
                 "B\n"
                 "2\n"
                 "^\n"
                 "w\n"
                 "1\n"
                 "\n"
                 "$\n"
                 "2\n"
                 "-\n"
                 "[\n"
                 "0\n"
                 "\n"
                 "l\n"
                 "2\n"
                 "[\n"
                 "2\n"
                 "1\n"
                 "#\n"
                 "e\n"
                 "1\n"
                 "j\n"
                 "G\n"
                 "1\n"
                 "2\n"
                 "\t\n"
                 "1\n"
                 "/\n"
                 "0\n"
                 "E\n"
                 "\\\n"
                 "0\n"
                 "e\n"
                 ":\n"
                 "1\n"
                 "2\n"
                 "m\n"
                 "0\n"
                 "1\n"
                 "1\n"
                 "2\n"
                 "0\n"
                 "g\n"
                 "V\n"
                 "0\n"
                 "+\n"
                 "m\n"
                 "0\n"
                 "0\n"
                 "F\n"
                 "S\n"
                 "0\n"
                 "b\n"
                 "2\n"
                 "1\n"
                 "2\n"
                 "H\n"
                 "2\n"
                 "t\n"
                 "9\n"
                 "0\n"
                 "f\n"
                 "<\n"
                 "1\n"
                 ";\n"
                 "w\n"
                 "0\n"
                 "?\n"
                 "0\n"
                 "2\n"
                 "D\n"
                 "1\n"
                 "!\n"
                 "2\n"
                 "+\n"
                 "\"\n"
                 "1\n"
                 "M\n"
                 "1\n"
                 "s\n"
                 "1\n"
                 "j\n"
                 "1\n"
                 "e\n"
                 "^\n"
                 "0\n"
                 "0\n"
                 "2\n"
                 ",\n"
                 "0\n"
                 "\"\n"
                 "0\n"
                 "q\n"
                 "1\n"
                 "1\n"
                 "G\n"
                 "y\n"
                 "2\n"
                 "I\n"
                 "1\n"
                 "0\n"
                 "M\n"
                 ":\n"
                 "0\n"
                 "@\n"
                 "1\n"
                 "2\n"
                 "2\n"
                 "9\n"
                 "V\n"
                 "2\n"
                 "e\n"
                 "R\n"
                 "1\n"
                 "D\n"
                 "0\n"
                 "C\n"
                 "2\n"
                 "2\n"
                 "[\n"
                 "X\n"
                 "1\n"
                 "%\n"
                 "1\n"
                 "\n"
                 "\n"
                 "*\n"
                 "2\n"
                 "0\n"
                 "q\n"
                 "2\n"
                 "1\n"
                 "o\n"
                 "E\n"
                 "0\n"
                 "1\n"
                 "0\n"
                 "0\n"
                 "2\n"
                 "j\n"
                 "X\n"
                 "2\n"
                 "0\n"
                 "B\n"
                 "1\n"
                 "3\n"
                 "x\n"
                 "0\n"
                 ".\n"
                 "2\n"
                 "'\n"
                 "1\n"
                 "5\n"
                 "0\n"
                 "}\n"
                 "k\n"
                 "1\n"
                 "X\n"
                 "1\n"
                 "+\n"
                 "*\n"
                 "2\n"
                 "0\n"
                 "3\n"
                 "w\n"
                 "2\n"
                 "\n"
                 "\n"
                 "D\n"
                 "2\n"
                 "0\n"
                 "0\n"
                 "!\n"
                 "0\n"
                 "\f\n"
                 "C\n"
                 "2\n"
                 "K\n"
                 "'\n"
                 "1\n"
                 " \n"
                 "V\n"
                 "2\n"
                 "@\n"
                 "1\n"
                 "&\n"
                 "0\n"
                 "U\n"
                 "2\n"
                 "2\n"
                 "2\n"
                 "]\n"
                 "1\n"
                 "y\n"
                 "2\n"
                 "0\n"
                 "!\n"
                 "2\n"
                 "0\n"
                 "1\n"
                 ".\n"
                 "/\n"
                 "1\n"
                 "1\n"
                 "9\n"
                 "2\n"
                 "\n"
                 "\n"
                 "1\n"
                 "1\n"
                 "0\n"
                 "q\n"
                 "K\n"
                 "1\n"
                 "0\n"
                 " \n"
                 "2\n"
                 ",\n"
                 "2\n"
                 "\u000B\n"
                 "2\n"
                 "B\n"
                 "0\n"
                 "]\n"
                 "-\n"
                 "0\n"
                 "-\n"
                 "0\n"
                 "0\n"
                 "3\n"
                 "6\n"
                 "1\n"
                 "x\n"
                 "2\n"
                 "\"\n"
                 "1\n"
                 "P\n"
                 "0\n"
                 "%\n"
                 "0\n"
                 "0\n"
                 "2\n"
                 "2\n"
                 "u\n"
                 "0\n"
                 "L\n"
                 "1\n"
                 "N\n"
                 "0\n"
                 "T\n"
                 "1\n"
                 "$\n"
                 "0\n"
                 "S\n"
                 "+\n"
                 "0\n"
                 "u\n"
                 "1\n"
                 "\\\n"
                 "1\n"
                 "T\n"
                 "L\n"
                 "2\n"
                 "2\n"
                 "|\n"
                 "1\n"
                 "E\n"
                 "1\n"
                 "@\n"
                 "0\n"
                 "1\n"
                 "0\n"
                 "_\n"
                 "*\n"
                 "0\n"
                 "i\n"
                 "D\n"
                 "0\n"
                 "2\n"
                 "0\n"
                 "\u000B\n"
                 "1\n"
                 "\n"
                 "\n"
                 "(\n"
                 "2\n"
                 "J\n"
                 "t\n"
                 "0\n"
                 "0\n"
                 "z\n"
                 "4\n"
                 "2\n"
                 "z\n"
                 "2\n"
                 "0\n"
                 "l\n"
                 "v\n"
                 "2\n"
                 "=\n"
                 "2\n"
                 "]\n"
                 "`\n"
                 "2\n"
                 "\"\n"
                 "O\n"
                 "0\n"
                 "X\n"
                 "1\n"
                 "N\n"
                 "1\n"
                 "+\n"
                 "1\n"
                 "2\n"
                 "1\n"
                 "?\n"
                 "2\n"
                 "{\n"
                 "G\n"
                 "1\n"
                 "0\n"
                 "0\n"
                 "7\n"
                 "1\n"
                 "e\n"
                 "4\n"
                 "2\n"
                 " \n"
                 "0\n"
                 "0\n"
                 "5\n"
                 "2\n"
                 "?\n"
                 "d\n"
                 "1\n"
                 "2\n"
                 "1\n"
                 "C\n"
                 "h\n"
                 "0\n"
                 "1\n"
                 ",\n"
                 "0\n"
                 "[\n"
                 "T\n"
                 "0\n"
                 "1\n"
                 "\\\n"
                 "S\n"
                 "2\n"
                 "2\n"
                 ":\n"
                 "'\n"
                 "1\n"
                 "\\\n"
                 "4\n"
                 "1\n"
                 "r\n"
                 "h\n"
                 "2\n"
                 "T\n"
                 "a\n"
                 "2\n"
                 "x\n"
                 "E\n"
                 "1\n"
                 "*\n"
                 "2\n"
                 "0\n"
                 "g\n"
                 "1\n"
                 "`\n"
                 "1\n"
                 "\n"
                 "\n"
                 "*\n"
                 "1\n"
                 "\t\n"
                 "1\n"
                 "2\n"
                 "Y\n"
                 "1\n"
                 "]\n"
                 "1\n"
                 "w\n"
                 "@\n"
                 "2\n"
                 "1\n"
                 "-\n"
                 "0\n"
                 "}\n"
                 "0\n"
                 "\"\n"
                 "`\n"
                 "0\n"
                 "S\n"
                 "1\n"
                 "3\n"
                 "o\n"
                 "0\n"
                 ",\n"
                 "U\n"
                 "0\n"
                 "W\n"
                 " \n"
                 "0\n"
                 "v\n"
                 "1\n"
                 "1\n"
                 "8\n"
                 "0\n"
                 "3\n"
                 "?\n"
                 "1\n"
                 "p\n"
                 "1\n"
                 "B\n"
                 "2\n"
                 "2\n"
                 "]\n"
                 "0\n"
                 "P\n"
                 "g\n"
                 "0\n"
                 "1\n"
                 "w\n"
                 "F\n"
                 "1\n"
                 "2\n"
                 "1\n"
                 "1\n"
                 "1\n"
                 "1\n"
                 "0\n"
                 "0\n"
                 "K\n"
                 " \n"
                 "1\n"
                 "u\n"
                 "1\n"
                 "0\n"
                 "\f\n"
                 "A\n"
                 "0\n"
                 "*\n"
                 "1\n"
                 "F\n"
                 "2\n"
                 "\n"
                 "H\n"
                 "0\n"
                 "1\n"
                 "D\n"
                 "0\n"
                 "2\n"
                 "0\n"
                 "1\n"
                 "2\n"
                 "2\n"
                 "p\n"
                 " \n"
                 "0\n"
                 "1\n"
                 "2\n"
                 "2\n"
                 "0\n"
                 "X\n"
                 "\"\n"
                 "0\n"
                 "0\n"
                 "1\n"
                 "1\n"
                 "}\n"
                 "E\n"
                 "1\n"
                 "o\n"
                 "\\\n"
                 "1\n"
                 "h\n"
                 "1\n"
                 "0\n"
                 "`\n"
                 "2\n"
                 "{\n"
                 "1");
    string deck("Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure\n"
                "Treasure");
    string expectedOutputFilename("tests/test13_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

bool test1000()
{
    const string tmp_file("test1000_test");
    string input("test1000.in");
    string deck("test1000.deck");
    string expectedOutputFilename("tests/test1000_expected.txt");
    return GeneralGameSimulationTestFiles(tmp_file, input, deck, expectedOutputFilename);
}
bool test1()
{
    const string tmp_file("test0_test");
    string input("6\n"
                 "AnnoyingAnnoyingson Ninja\n"
                 "AnnoyingAnnoyingso Ninja\n"
                 "AnnoyingAnnoyings Ninja\n"
                 "AnnoyingAnnoying Ninja\n"
                 "Annoying'sMom Ninja\n"
                 "Annoying! Ninja\n"
                 "Annoying? Ninja\n"
                 "Annoying_ Ninja\n"
                 "Anno-ing Ninja\n"
                 "Annoying@you Ninja\n"
                 "@Annoying Ninja\n"
                 "Annoying@ Ninja\n"
                 "Annoying[ Ninja\n"
                 "[Annoying Ninja\n"
                 "Annoying` Ninja\n"
                 "`Annoying Ninja\n"
                 "Annoying{ Ninja\n"
                 "{Annoying Ninja\n"
                 "Annoying0 Ninja\n"
                 "0Annoying Ninja\n"
                 "Ann0ying Ninja\n"
                 "Annoy1ng Ninja\n"
                 "Annoyin9 Ninja\n"
                 "4nnoying Ninja\n"
                 "\"Annoying\" Ninja\n"
                 "ThisIsLike1025CharectersForSomeReason____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ Ninja\n"
                 "RougeA Ninja\n"
                 "HealerA Healer\n"
                 "HealerB Healer\n"
                 "FigtherA Warrior\n"
                 "CopyCat Warrior\n"
                 "CopyCat Warrior");
    string deck("Gremlin\n"
                "Mana\n"
                "Witch\n"
                "Gremlin\n"
                "Well\n"
                "Witch");
    string expectedOutputFilename("tests/test1_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}

/* ---------------------------------------------------------------------------------------------- */
// --------------------------------       Main function          ------------------------------

int main(){
    setbuf(stdout,0);
	run_test(cardsPrintsTest,"cardsPrintsTest");
	run_test(playersPrintsTest,"playersPrintsTest");
	run_test(testCard,"Deck creation test");
	run_test(dragonDenTest,"Dragon Den simulation test");
	run_test(gremlinCaveTest,"Gremlin Cave simulation test");
	run_test(witchLairTest,"Witch Lair simulation test");
	run_test(nonMostersTest,"Non monsters cards simulation test");
	run_test(badFormatStartTest,"Bad format at start of file exception test");
	run_test(badFormatTest,"Bad format exception test");
	run_test(noFileTest,"File Doesnt exist exception test");
	run_test(badSizeTest,"Bad size exception test");
    run_test(roundLimitTest,"Round upper limit test");
    run_test(allTenTest,"All reach lvl 10 test");
    run_test(badPlayerInputTest,"Bad player input test");
    run_test(test0,"test0");
    run_test(numOfPlayersAsChar,"Number of players as char");
    run_test(test13,"test13");
    run_test(test1,"test1");
    //run_test(test1000,"test1000");
    return 0;
}


int mymain(){
    const int MAX_NUMBER_OF_ROUNDS = 100;
    Mtmchkin game("deck.txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
        game.playRound();
    }
    game.printLeaderBoard();
    return 0;
}
