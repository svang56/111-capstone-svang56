//Author: Sunny Vang
#include<string>
#include"fighting.h"

bool randomChance(std::string monsterName)
{
    int winPercentage = 0;

    rand()100 + 1;

    if(monsterName == "Dragon" || monsterName == "BlackKnight")
    {
        if( winPercentage <= 30)
        {
            return true;
        }
        else if( winPercentage > 30 && winPercentage != 77)
        {
            return false;
        }
    }
    else
    {
        if( winPercentage >= 50)
        {   
            return true;
        }
        else
        {
            return false
        }
    }

} 

bool fightOrRun()
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

void encounterMonster(std::string monsterName)
{   
    bool result = false;

    std::cout<<"You have encountered a "<<monsterName<<".\n"
    std::cout<<"Would you like to fight the "<<monsterName<<" or run?\n";
    cin>>input;//if 1 then fight , if 2 then run
    result = fightOrRun(input);
    if( result == true)
    {
        result = randomChance(std::string);
        
        if(result == true)
        {
            std::cout<<"You have defeated the "<<monsterName<<endl;
        }
        else
        {
            std::cout<<"You lost the battle and lose 1 health\n";
        }
        
    }
    else
    {
        std::cout<<"You ran away from the "<<monsterName<<" and escaped.\n";
    }

}

std::string stayOrGo()
{
    std::cout<<"Please enter a number:\n";
    std::cout<<"Would you like to (1) Stay or (2) Leave this location?\n"
    std::cin>>input;
    return input;

}
