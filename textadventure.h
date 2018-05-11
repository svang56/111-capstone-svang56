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
    
    public:
       Adventure();//initialize stats then use load game to get stats
       void loadGame();
       void saveGame();
       void restoreHealth(std::vector<std::string>);
       void loseHealth();
       void checkHealth();
       void levelUp();
       void usePotion();
       void showIntroduction();
       void displayTutorial();
       void viewStats();

       //forest
       //castle
            //steal stuff in castle
       //dungeon




};

#endif

