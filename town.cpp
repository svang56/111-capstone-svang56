//Author: Sunny Vang    
#include "town.h"
#include<string>
#include "textadventure.h"

void Town::shopping()
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
                money == money - 25;
                potions++;
            }
            else
            {
                std::cout<<"You do not have enough money.\n";
            }
        }
        else if (input == "2" )
        {
            std::cout<<"You decide to not buy a potion and leave the shop\n";

        }
        else
        {
            std::cout<<"Please enter valid input.\n";
        }

    }while(input != "2");   
}

void Town::goToInn()
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
                money == money - 25;
                restoreHealth(health);
            }
            else
            {
                std::cout<<"You do not have enough money.\n";
            }
        }

        else if (input == "2" )
        {
            std::cout<<"You decide to not buy a potion and leave the shop\n";

        }
        else
        {
            std::cout<<"Please enter valid input.\n";
        }

    }while(input == "2");
}
