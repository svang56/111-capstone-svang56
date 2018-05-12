//Author: Sunny Vang
#include<iostream>
#include <string>
#include "textadventure.h"

const int reset = 0;

using namespace std;

int main()
{
    string input = " ";

    Adventure game;

    do
    {
        cout<<"\nWelcome to Adventure Quest! \n\nType a number:\n";
        cout<<"(1) Go through the tutorial (2) get straight into the game?";
        cin>>input;
        if(input == "1")
        {
            //tutorial
        }
    
    }while(input != "2");
    

    do
    {
        cout<<"Where would you like to go?\nType a number:";
        cout<<"(1) Go to Town (2) Go to the Forest (3) Go into the Dungeon\n";
        cout<<"(4) Go into the Castle (5) View your Stats (6) Save your game ";
        cout<<"(7) Quit the game\n";
        cin>>input;

        if(input == "1")//town
        {

            do
            {
            
                cout<<"You are in town. What would you like to do?\n";
                cout<<"Type a number: (1) Go to the Shop (2) Sleep at the Inn\n";
                cout<<"(3) View Stats (4) Leave Town .\n";
                cin>>input;

                if(input == "1")
                {
                    game.shopping();
                }
                else if(input == "2")
                {
                    game.goToInn();
                }
                else if (input == "3")
                {
                    game.viewStats();
                }
                else
                {
                    cout<<"Please enter valid input\n";
                }

            }while(input != "4");

        }
        else if(input == "2")//-------------forest
        {   

            game.getMonsters("Goblin", "Wolf", "Black Bear");

            cout<<"You have arrived at the Forest.\n";

            do
            {
                cout<<"Would you like to (1)Search the forest for items (2) Fight ";
                cout<<"monsters (3) Use a potion";
                cin>>input;
            
                if(input == "1")
                {
                    game.searchForest();
                }
                else if(input == "2")
                {
                    string enemy = " ";

                    enemy = game.randomMonster();

                    game.encounterMonster(enemy);
              
                    input = game.stayOrGo();

                }
                else if(input == "3")
                {
                    game.usePotion();
                }
                else
                {
                    cout<<"Please enter valid input.\n";
                }

            }while(input != "2");


        }
        else if(input == "3")//dungeon
        {

            game.getMonsters("Zombie", "Slime", "Dragon");
            
            cout<<"You have arrived at the Dungeon.\n";
            cout<<"What would you like to do? (1) Fight Monsters (2) Use potion\n";
            cin>>input;
            if(input == "1")
            {
                do
                {
                    string enemy = " ";

                    enemy = game.randomMonster();

                    game.encounterMonster(enemy);

                    input = game.stayOrGo();

                }while(input != "2");
            }
            else if (input == "2")
            {
                game.usePotion();   
            }
            else
            {
                cout<<"Please enter Valid input\n";
            }

        }
        else if(input == "4")//castle
        {

            game.getMonsters("Guard", "Magician", "Black Knight");

            int searchCount = 0;

            cout<<"You have arrived at the Castle\n";

            do
            {
                cout<<"Would you like to: (1) Search the castle for treasure";
                cout<<" (2) Battle the inhabitants of the castle? \n";
                cout<<"(3) Use a potion\n";
                cin>>input;

                if(input == "1" && searchCount < 2)
                {
                    game.searchForTreasure();
                    searchCount++;
                }
                else if(input == "2" || searchCount >= 2)
                {

                    string enemy = " ";

                    enemy = game.randomMonster();

                    game.encounterMonster(enemy);

                    input = game.stayOrGo();

                    if(searchCount >= 2)
                    {
                        searchCount = reset;
                    }

                }
                else if(input == "3")
                {
                    game.usePotion();
                }
                else 
                {
                    cout<<"Please enter valid input.";
                }
            
            }while(input != "2");

        }
        else if(input == "5")
        {
           game.viewStats();
        }
        else if(input == "6")//saving
        {
            //save stats, level, money, potions, bosses defeated
        }

        

    }while(input != "7");

    return 0;
}


