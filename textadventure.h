//Author: Sunny Vang
#ifndef TEXTADVENTURE_H_
#define TEXTADVENTURE_H_

#include<iostream>
#include<vector>
#include<string>

class Adventure
{

    private:
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
       void restoreHealth(std::vector<std::string>);
       void restoreOneHealth();
       void loseHealth();
       void levelUp();
       void usePotion();
       void displayTutorial();
       void viewStats();
       void checkHealth();

       //battle functions
         bool battleChance(std::string);
         bool fightOrRun(std::string);
         void encounterMonster(std::string);
         std::string stayOrGo();
         std::string randomMonster();
         void getMonsters(std::string, std::string, std::string);

       //town functions
         void shopping();
         void goToInn();

       //forest functions
         void searchForest();
         void eatMushroom();

       //no exclusive dungeon functions
      
       //castle function
        void searchForTreasure();



};

#endif

