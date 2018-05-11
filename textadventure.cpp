//Author: Sunny Vang
#include<iostream>
#include<string>
#include"textadventure.h"
const double reset = 0;
const double boostStr = 2;

Adventure::Adventure()
{
    
    health.resize(5);
    playerHealth = health.size();
    restoreHealth(health);
    strength = 0;
    will = 0;
    wisdom = 0;
    money = 25;
    levels = 0;
    experience = 0;
}

void Adventure::loadGame()
{
//pull shit from file
}

void Adventure::saveGame()
{
//delete stuff in file and then put numbers in
}

void Adventure::restoreHealth(std::vector<std::string> vector)
{
    for(int i = 0; i < vector.size(); i++)
    {
        vector[i] = "FILLED";
    }

}

void Adventure::restoreOneHealth()
{
    int i = 0;
    while(health[i] == "FILLED" && i< health.size())
    {
        i++;
    }
    
    if( i < health.size())
    {
        health[i] = "FILLED";
        playerHealth++;
    }
    else
    {
        std::cout<<"You have full health and con no longer gain health\n";
    }

}

void Adventure::loseHealth()
{
    int i = 0;

    while(health[i] == "EMPTY" && i < health.size())
    {
        i++;
    }
    if(i < health.size())
    {
        health[i] = "EMPTY";
        playerHealth--;
    }
    else
    {
        std::cout<<"You have no more health and can no longer fight\n";
    }
}

void Adventure::levelUp()
{
//after everybattle, include this. 
    if(experience >= 100)
    {//this resets counter to 0. Adds extra experience to next level
        double temp = 0;
        experience -= 100;
        temp = experience;
        experience = reset;
        experience += temp;
        levels++;
        strength += 2;
        will += 2;
        wisdom += 1;
        health.push_back("EMPTY");

        std::cout<<"Congradulations! You have leveled up!\n";
        std::cout<<"Your stats have increased.\n";
        viewStats();
    }

}
 
void Adventure::usePotion()
{
    restoreHealth(health);
    potions--;
}

void Adventure::showIntroduction()
{
}

void Adventure::displayTutorial()
{
}

void Adventure::viewStats()
{
    std::cout<<"You are level: "<<levels<<std::endl;
    std::cout<<"Your health is: ("<<playerHealth<<"/"<<health.size()<<").\n";
    std::cout<<"Your strength level is: "<<strength<<std::endl;
    std::cout<<"Your willpower level is: "<<will<<std::endl;
    std::cout<<"Your wisdom level is: "<<wisdom<<std::endl;
    std::cout<<"Your experience amount is: ("<<experience<<"/100)\n";
}

void Adventure::checkHealth()
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
    
    playerHealth = healthCount;

    
}





