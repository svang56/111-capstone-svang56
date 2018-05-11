//Author: Sunny Vang
#include<iostream>
#include<string>
#include"textadventure.h"
const double reset = 0;
const double boostStr = 2;

Adventure::Adventure()
{
    strength = 0;
    will = 0;
    wisdom = 0;
    money = 25;
    levels = 0;
    experience = 0;
}

void Adveture::loadGame()
{
//pull shit from file
}

void Adventure::saveGame()
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
        std::cout<<"You are level: "<<levels<<std::endl;
        checkHealth();
        std::cout<<"Your strength level is: "<<strengh<<std::endl;
        std::cout<<"Your willpower level is: "<<will<<std::endl;
        std::cout<<"Your wisdom level is: "<<wisdom<<std::endl;
        std::cout<<"Your experience amount is: "<<experience<<"/100\n";

        //finsih this shit
    }

}
 
void Adventure::usePotion();
{
    restoreHealth();
    potion--;
}

void Adventure::showIntroduction();
{
}

void Adventure::displayTutorial();
{
}

void Adventure::viewStats();
{
    std::cout<<"You are level: "<<levels<<std::endl;
    checkHealth();
    std::cout<<"Your strength level is: "<<strengh<<std::endl;
    std::cout<<"Your willpower level is: "<<will<<std::endl;
    std::cout<<"Your wisdom level is: "<<wisdom<<std::endl;
    std::cout<<"Your experience amount is: "<<experience<<"/100\n";
}

void Adventure::checkHealth();
{
    std::string healthCheck = " ";

    double healthCount = 0;

    for(int i = 0; i < health.size(); i++)
    {
        healthCheck = health[i];
        
        if(healthCheck == "FILLED")
        {
            healthCount++;
        }
    }

    std::cout<<"Your health is "<<healthCount<<"/"<<health.size()<<".\n";
    
}





