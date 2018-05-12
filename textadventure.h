//Author: Sunny Vang
#ifndef TEXTADVENTURE_H_
#define TEXTADVENTURE_H_

#include<iostream>
#include<vector>
#include<string>

class Adventure
{

    protected:
        double strength;
        double will;
        double wisdom;
        std::vector<std::string> health;
        double money;
        double potions;
        double levels;
        double experience;
        double playerHealth;
        //fighting variables
        std::string regMonster1;
        std::string regMonster2;
        std::string bossMonster;
    public:
       Adventure();//initialize stats then use load game to get stats
       void loadGame();
       void saveGame();
       void restoreHealth(std::vector<std::string>);
       void restoreOneHealth();
       void loseHealth();
       void levelUp();
       void usePotion();
       void showIntroduction();
       void displayTutorial();
       void viewStats();
       void checkHealth();

       //fighting
         bool battleChance(std::string);
         bool fightOrRun(std::string);
         void encounterMonster(std::string);
         std::string stayOrGo();
         std::string randomMonster();
         void getMonsters(std::string, std::string, std::string);

       //town
         void shopping();
         void goToInn();
       //forest
         void searchForest();
         void eatMushroom();

       //dungeon
       //no exclusive functions for dungeon
      
       //castle
        void searchForTreasure();



};

#endif

