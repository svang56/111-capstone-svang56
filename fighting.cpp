//Author: Sunny Vang
#include<string>
#include<iostream>
#include"fighting.h"
#include"textadventure.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int bossMoney = 50;
const int bossExp = 20;
const int regMoney = 10;
const int regExp = 10;
const int baseBossPercent = 15;
const int baseRegPercent = 45;

bool fighting::battleChance(std::string monsterName)
{
    double bossWinPercent = baseBossPercent;
    double monstWinPercent = baseRegPercent;
    //next two lines increase win percent when battleing

    bossWinPercent += ((strength + wisdom + will) * .5);
    monstWinPercent += ((strength + wisdom + will) * .5);

    srand (time(NULL));
    
    int winPercentage = 0;

    winPercentage = rand()%100 + 1;

    if((monsterName == "Dragon" || monsterName == "Black Knight" || monsterName == "Black Bear") && levels >= 5)
    {
        if(levels >= 5)
        {
            if( winPercentage <= bossWinPercent)
            {
                money =+ (rand()%bossMoney + 20);
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
            std::cout<<"may not be strong enough to defeat the "<<monsterName<<"\n";
            return false;
        }
    
    }
    else
    {

        if( winPercentage <= monstWinPercent)
        {   
            money += (rand()%regMoney + 10);
            experience += (rand()%regExp+15);
            return true;
        }
        else
        {
            return false;
        }
    }

} 

bool fighting::fightOrRun(std::string input)
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

void fighting::encounterMonster(std::string monsterName)
{   
    std::string input = " ";

    bool result = false;
    std::cout<<"You have encountered a "<<monsterName<<".\n";
    std::cout<<"Would you like to fight the "<<monsterName<<" or run?\n";
    std::cout<<"Type (1) to Fight or (2) to run away. \n";
    std::cin>>input;//if 1 then fight , if 2 then run
    result = fightOrRun(input);
    if(playerHealth > 0)
    {
        if( result == true)
        {
            result = battleChance(monsterName);
        
            if(result == true)
            {
                std::cout<<"You have defeated the "<<monsterName<<std::endl;
            }
            else 
            {
                loseHealth();
                std::cout<<"You lost the battle and lose 1 health\n";

            }
        
        }
        else
        {
            std::cout<<"You ran away from the "<<monsterName<<" and escaped.\n";
        }
    }
    else
    {
        std::cout<<"You do not have enough health to fight and run away.\n";
    }

    levelUp();
}


std::string fighting::stayOrGo()
{
    std::string input = " ";
    std::cout<<"Please enter a number:\n";
    std::cout<<"Would you like to (1) Stay or (2) Leave this location?\n";
    std::cin>>input;
    return input;

}

std::string fighting::randomMonster()
{
    srand (time(NULL));
    int randomNumber = 0;
    randomNumber = rand()%100 + 1;
    
    if(randomNumber <= 30)
    {
       
        return bossMonster;

    }
    else if( randomNumber <= 60 && randomNumber > 30)
    {
        return regMonster1;
    }
    else if( randomNumber > 60 && randomNumber <= 100)
    {
        return regMonster2;
    }
}

void fighting::getMonsters(std::string weakMonst1, std::string weakMonst2,
                           std::string bossMonst)
{
    regMonster1 = weakMonst1;
    regMonster2 = weakMonst2;
    bossMonster = bossMonst;

}




