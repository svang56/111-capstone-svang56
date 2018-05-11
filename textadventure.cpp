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
        std::cout<<"Congradulations! You have leveled up!\n";
        std::cout<<"
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





