//Author: Sunny Vang

#include<iostream>
#include<string>
#include"textadventure.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//fighting constants
const int bossMoney = 50;
const int bossExp = 20;
const int regMoney = 10;
const int regExp = 10;
const int baseBossPercent = 15;
const int baseRegPercent = 45;
//adventure constants
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

///////////////////////////////////////////////////////////////////////////////
//begin fighting functions

bool Adventure::battleChance(std::string monsterName)
{
    srand(time(NULL));

    int winPercentage = 0;
    winPercent = rand()%100 + 1;
    
    double bossWinPercent = baseBossPercent;
    double monstWinPercent = baseRegPercent;
    //next two lines increase win percent when battling

    bossWinPercent += ((strength + wisdom + will) * .5);
    monstWinPercent += ((strength + wisdom + will) * .5);
    
    if((monsterName == "Dragon" || monsterName == "Black Knight" 
        || monsterName == "Black Bear") && levels >= 5)
    {
        if(levels >= 5)
        {
            if( winPercentage <= bossWinPercent)
            {
                money += (rand()%bossMoney + 20);
                experience += (rand()%bossExp + 50);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            std::cout<<"As you approach the "<<monsterName<<", you realize you\n";
            std::cout<<"may not be strong enough to defeat the "<<monsterName<<".\n";
            return false:
        }


    }
    else
    {
        if( winPercentage <= monstWinPercent)
        {
            money += (rand()%regMoney + 10);
            experience += (rand()regExp + 15);
            return true
        }
        else
        {
            return false;
        }
    }

}
bool Adventure::fightOrRun(std::string input)
{
    if(input == "1")
    {
        return true;
    }
    else
    {
        return false;
    }

}

void Adventure::encounterMOnster(std::string monsterName)
{
    std::string input = " ";
    bool result = false;

    std::cout<<"You have encountered a "<<monsterName<<".\n";
    std::cout<<"Would you like to fight the "<<monsterName<<" or run?\n";
    std::cout<<"Type (1) to Fight or (2) to run away. \n";
    std::cin>>input;

    result = fightOrRun(input);

    if(playerHealth > 0)
    {
        if(result == true)
        {
            result = battleChance(monsterName);

            if(result == true)
            {
                std::cout<<"You have defeated the "<<monsterName<<std::endl;
            }
            else
            {
                loseHealth();
                std::cout<<"You lose the battle and lose 1 health\n";
            }
        }
    }
    else
    {
        std::cout<<"You ran away from the "<<monsterName<<"and escaped.\n";
    }
    
    levelUp();
}

std::string Adventure::stayOrGo()
{
    std::string input = " ";

    std::cout<<"Please enter a number:\n";
    std::cout>>"Would you like to: (1) Stay (2) Leave this loccation?\n";
    std::cin>>input;

    return input;
}

std::string Adventure randomMonster()
{
    srand(time(NULL));
    
    int randomNumber = 0;
    randomNumber = rand()100 + 1;

    if(randomNumber <= 30)
    {
        return bossMonster;
    }
    else if( randomNumber <= 60 && randomNumber > 30)
    {
        return regMonster1;
    }
    else if(randomNumber > 60)
    {
        return regMonster2;
    }
}

void Adventure::getMonsters(std::string weakMonst1, std::string weakMonst2,
                            std::string bossMonst)
{
    regMonster1 = weakMonst1;
    regMonster2 = weakMonst2;
    bossMonster = bossMonst;
}
///////////////////////////////////////////end of fighting.cpp//////////////////////

//////////////////////begin Town.CPP/////////
void Adventure::shopping()
{
    std::string input = " ";

    do
    {
        std::cout<<"Welcome to the shop! \n";
        std::cout<<"Would you like to buy a potion? It will cost you 25 gold.\n";
        std::cout<<"Enter a number: (1) Yes (2) No\n";
        std::cin>>input;

        if(input == "1")
        {
            if(money >= 25)
            {
                money -= 25;
                potions++;
                std::cout<<"Your current money amount: "<<money<<std::endl;
            }
            else
            {
                std::cout<<"You do not have enough money. \n";
            }
        }
        else if(input == "2")
        {
            std::cout<<"You decide not to buy a potion and leave the shop\n";
        }
        else
        {
            std::cout<<"Please enter valid input.\n";
        }
    }while(input != "2";
}

void Adventure::goToInn()
{
    std::string input = " ";

    do
    {
        std::cout<<"Welcome to the Inn! \n";
        std::cout<<"It will cost you 25 gold to sleep and reconver all of your health.\n";
        std::cout<<"Enter a number: (1) Yes (2) No\n";
        std::cin>>input;

        if(input == "1")
        {
            if(money >= 25)
            {
                money -= 25;
                restoreHealth(health);
            }
            else
            {
                std::cout<<"You do not have enough money.\n";
            }
        }
        else if(input == "2")
        {
            std::cout<<"You decide not to rest at the Inn and leave.\n";
        }
        else
        {
            std::cout<<"Please enter valid input.\n";
        }
    }while(input != "2");
}




