//Author: Sunny Vang
#ifndef TEXTADVENTURE_H_
#define TEXTADVENTURE_H_

#include<iostream>
#include<vector>


class Adventure
{

    protected:
        double strength;
        double will;
        double wisdom;
        vector<std::string> health;
        double money;
        double potions;
        double levels;
        double experience;
    
    public:
       Adventure();//initialize stats then use load game to get stats
       void loadGame();
       void saveGame();
       void restoreHealth();
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

