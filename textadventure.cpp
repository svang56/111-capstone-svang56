//Author: Sunny Vang

#include<iostream>
#include<string>
#include"textadventure.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//fighting constants
const int bossMoney = 50;
const int bossExp = 70;
const int regMoney = 10;
const int regExp = 40;
const int baseBossPercent = 40;
const int baseRegPercent = 50;
//adventure constants
const double reset = 0;
const double boostStr = 2;

Adventure::Adventure()//initialize stats when player begins game
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
    potions = 0;
}

void Adventure::restoreHealth(std::vector<std::string> vector)
//replaces health vector with "FILLED"
{
    if( potions > 0)
    {
        playerHealth = 0;

        for(int i = 0; i < vector.size(); i++)
        {
            vector[i] = "FILLED";
            playerHealth++;
        }
    }
    else
    {
        std::cout<<"You do not have any potions.\n";
    }

}

void Adventure::restoreOneHealth()//replaces one "EMPTY" with "FILLED" in health vector
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

void Adventure::loseHealth()//searches for first "FILLED" and replaces with "EMPTY"
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

void Adventure::levelUp()//update stats based on experience amount
{
    if(experience >= 100)
    {
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
 
void Adventure::usePotion()//uses a potion and resets health vector to all "FILLED"
{
    restoreHealth(health);

    potions--;
}


void Adventure::displayTutorial()//prints tutorial
{
    std::cout<<"\nWelcome to Adventure Quest Again!. The objective of this game\n";
    std::cout<<"is to travel through the lands to find and defeat the evil Dragon.\n";
    std::cout<<"However, you must be first defeat monsters in order to become ";
    std::cout<<"stronger before\nyou can battle the Dragon.\n";
    std::cout<<"\nAlso, you have health, so you must drink a potion if your";
    std::cout<<" health runs low.\n Besides that, go and explore the areas!\n";
}

void Adventure::viewStats()//displays the statistics of player
{
    std::cout<<"You are level: "<<levels<<std::endl;

    std::cout<<"Your health is: ("<<playerHealth<<"/"<<health.size()<<").\n";

    std::cout<<"Your strength level is: "<<strength<<std::endl;

    std::cout<<"Your willpower level is: "<<will<<std::endl;

    std::cout<<"Your wisdom level is: "<<wisdom<<std::endl;

    std::cout<<"Your experience amount is: ("<<experience<<"/100)\n";

    std::cout<<"You have "<<money<<" gold.\n";

    std::cout<<"You have "<<potions<<" potions.\n";

}

void Adventure::checkHealth()//looks at health user has
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

bool Adventure::battleChance(std::string monsterName)
//determines if player wins/loses battle
{
    srand(time(NULL));

    int winPercentage = 0;
    winPercentage = rand()%100 + 1;
    
    double bossWinPercent = baseBossPercent;
    double monstWinPercent = baseRegPercent;
    //next two lines increase win percent when battling

    bossWinPercent += ((strength + wisdom + will) * .5);//adjusts win rate against
    monstWinPercent += ((strength + wisdom + will) * .5);//boss and regular monsters
                                                         //based on stats
    
    if((monsterName == "Dragon" || monsterName == "Black_Knight" 
        || monsterName == "Black_Bear"))
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

            return false;
        }


    }
    else
    {
        if( winPercentage <= monstWinPercent)
        {
            money += (rand()%regMoney + 10);

            experience += (rand()%regExp + 15);

            return true;
        }
        else
        {
            return false;
        }
    }

}
bool Adventure::fightOrRun(std::string input)
//determines if user wants to run or stay to fight monster
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

void Adventure::encounterMonster(std::string monsterName)
//goes through options to battle monsters
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
        std::cout<<"You realize you do not have enough health to fight\n";

        std::cout<<"You run away from the "<<monsterName<<" and escape.\n";
    }
    
    levelUp();
}

std::string Adventure::stayOrGo()//asks user if want to stay at area
{
    std::string input = " ";

    std::cout<<"Please enter a number:\n";
    std::cout<<"Would you like to: (1) Stay (2) Leave this loccation?\n";
    std::cin>>input;

    return input;
}

std::string Adventure::randomMonster()//randomly generates monster to encounter
{
    srand(time(NULL));
    
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
    else if(randomNumber > 60)
    {
        return regMonster2;
    }
}

void Adventure::getMonsters(std::string weakMonst1, std::string weakMonst2,
                            std::string bossMonst)
//gets strings from int main() and initializes monsters in specific areas
{
    regMonster1 = weakMonst1;

    regMonster2 = weakMonst2;

    bossMonster = bossMonst;
}

void Adventure::shopping()//goes through shopping options
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
    }while(input != "2");
}

void Adventure::goToInn()//goes through options in Inn
{
    std::string input = " ";

    do
    {
        std::cout<<"Welcome to the Inn! \n";
        std::cout<<"It will cost you 25 gold to sleep and recover all of your health.\n";
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

void Adventure::searchForest()//randomly generates items when searching forest
{
    int randomChance = 0;

    srand(time(NULL));

    randomChance = rand()%5 + 1;

    switch(randomChance)
    {
        case 1:
        {
            potions++;

            std::cout<<"You found a potion as you were roaming the forest.\n";

            break;
        }

        case 2:
        {
            int moneyFound = 0;

            moneyFound = rand()%2 + 1;

            money += moneyFound;

            std::cout<<"You find "<<moneyFound<<" gold on the ground\n";

            break;
        }

        case 3:
        {
            std::string input = " ";
            
            std::cout<<"You found a strange mushroom.\n";
            std::cout<<"What do you want to do? (1) Eat it (2) Throw it away\n";
            std::cin>>input;

            if( input == "1")
            {
                eatMushroom();

                break;
            }
            else
            {
                std::cout<<"You decide to leave the strange mushroom where you ";
                std::cout<<"found it.\n";

                break;
            }
        }
        
        case 4:
        {
            std::cout<<"You find some worthless junk and throw ";
            std::cout<<" it back where you found it. \n";
            break;
        }

        case 5:
        {
            std::cout<<"As you roam the forest search for items,\n";
            std::cout<<"you come across a dismembered carcass.\n";
            std::cout<<"Unsure whether it may be an animal or corpse,\n";
            std::cout<<"you slowly back away from the location and run away.\n";

            break;
        }
        
        default:
        {
            break;
        }
    }
}

void Adventure::eatMushroom()//random chance to lose/gain health when eat mushroom
{
    srand(time(NULL));

    int randomChance = 0;

    randomChance = rand()%100 + 1;

    if(randomChance <= 50)
    {
        loseHealth();
        
        std::cout<<"You decide to eat the strange mushroom...\n";
        std::cout<<"You feel fine at first...and then fall to the ground,";
        std::cout<<" unconscious.\nAfter a while, you wake up with the ";
        std::cout<<"feeling as if you lose some life.\n";
    }
    else
    {
        restoreOneHealth();

        std::cout<<"You decide to eat the strange mushroom...\n";
        std::cout<<"As you eat the mustroom, you immediately begin to ";
        std::cout<<"feel revitalized.\n";
    }

}

void Adventure::searchForTreasure()//randomly determines if find chest with gold
{
    srand(time(NULL));

    int randomChance = rand()%100 + 1;

    if(randomChance <= 40)
    {
        int randomGoldAmt = 0;

        randomGoldAmt = rand()%20 + 10;

        money += randomGoldAmt;

        std::cout<<"You search the castle and was able to find a chest that\n";
        std::cout<<"contained "<<randomGoldAmt<<" gold.\n";
    }
    else
    {
        std::cout<<"You were unable to find anything of value in your search.\n";
    }

}
