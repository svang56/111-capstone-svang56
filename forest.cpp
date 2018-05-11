//Author: Sunny Vang
#include "fighting.h"
#include "forest.h"
#include "textadventure.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <string>
Forest::Forest()
{

}

void Forest::searchForest()
{
    int randomChance = 0;


    srand( time(NULL));

    randomChance = rand()%10 + 1;

    switch(randomChance)
    {
        case 1: 
            potions++;
            std::cout<<"You found a potion as you were roaming the forest.\n";
            break;

        case 2:
            int moneyFound = 0;
            moneyFound = rand()%2 + 1;
            money += moneyFound;
            cout<<"You find "<<moneyFound<<" gold on the ground.\n";
            break;

        case 3:
            std::string input = " ";

            std::cout<<"You found a strange mushroom.\n";
            std::cout<<"What do you want to do?: (1) Eat it (2) Throw it away\n";
            
            if(input == "1")
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

        case 4:
            std::cout<<"You find some worthless junk and throw ";
            std::cout<<" it back where you found it.\n"

            break;
                
        case 5:
            std::cout<<"As you roam the forest searching for items,\n";
            std::cout<<"you come across a dismembered carcass.\n";
            std::cout<<"Out of fear, you slowly back away from the location ";
            std::cout<<"run away.\n";

            break;
    }
    
}

void Forest::eatMushroom()
{
    srand( time(NULL));
    
    int randomChance = 0;

    randomChance = rand()%100 + 1;

    if(randomChance <= 50)
    {
        
        loseHealth();
        std::cout<<"You decide to eat the strange mushroom...\n";
        std::cout<<"You feel fine at first...and then fall to the ground,";
        std::cout<<" unconscious.\nAfter a while, you wake up with the 
        std::cout<<"feeling as if you lost some life.\n"
    }
    else
    {
        restoreOneHealth();
        std::cout<<"You decide to eat the strange mushroom...\n";
        std::cout<<"As you eat the mushroom, you immediately begin to ";
        std::cout<<"feel revitalized.\n";
        
    }


    
}
