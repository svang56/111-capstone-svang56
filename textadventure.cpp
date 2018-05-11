//Author: Sunny Vang
#include<iostream>
#include<string>
#include"textadventure.h"
const double reset = 0;
const double boostStr = 2;

Adventure::Adventure()
{
}

void Adveture::loadGame()
{
//pull shit from file
}

void Adventure::saveGame(         )
{
//delete stuff in file and then put numbers in
}

void Adventure::restoreHealth()
{
    for(int i = 0; i < health.size(); i++)
    {
        health[i] = "FILLED";
    }

}

void Adventure::loseHealth()
{
    int i = 0;
    while(health[i] == "EMPTY")
    {
        i++:
    }
    health[i] == "EMPTY";
            
}

void Adventure::levelUp();
{
//after everybattle, include this. 
    if(experience >= 100)
    {//this resets counter to 0. Adds extra experience to next level
        double temp = 0;
        experience = experience - 100;
        experience = temp;
        experience = reset;
        experience = experience + temp;
        levels++;
        strength = strength + 2;
        will = will + 1;
        wisdom = wisdom + 1;
        health.push_back();

        std::cout<<"Congradulations! You have leveled up!\n";
        std::cout<<"Your stats have increased.\n";
        std::cout<<"Level: "<<levels<<std::endl;
        std::cout<<"Health: "<<health.size()<<std::endl;
        std::cout<<"Strength: "<<strengh<<std::endl;
        std::cout<<"Will: "<<will<<std::endl;
        std::cout<<"Wisdom: "<<wisdom<<std::endl;
        std::cout<<"Experience: "<<experience<<"/100\n";

        //finsih this shit
    }

}
 
void Adventure::usePotion();
{
}

void Adventure::showIntroduction();
{
}

void Adventure::displayTutorial();
{
}

void Adventure::viewStats();
{
    
}





