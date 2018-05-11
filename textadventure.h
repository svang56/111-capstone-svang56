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
       void loadGame(double, double, double, double,
                     double, double, double);

       void saveGame(double, double, double, double
                     double, double, double);
       void restoreHealth();
       void loseHealth();

       void levelUp();//linear leveling up. everytime reach 100, have function to tell level up. Stats increase with levels -stats will increase by 1. --higher stats mean more chance to win
       void monsterRewards();//gain exp and gold for regular monsters- bosses give more
       void usePotion();
       void showIntroduction();
       void displayTutorial();
       void viewStats();//stats include st

       //forest
       //castle
            //steal stuff in castle
       //dungeon
       //only fight in dungeon/ use vector to randomly generate monster

       //town
//buy stuff like potions 



};

#endif

