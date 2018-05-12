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

    cout<<"\nWelcome to Adventure Quest!\n";

    do
    {
        cout<<"\nType a number:\n";
        cout<<"(1) Go through the tutorial (2) Get straight into the game";
        cin>>input;
        if(input == "1")
        {
            game.displayTutorial();
        }
        else if(input != "1" && input != "2")
        {
            cout<<"Please enter valid input.";
        }
    
    }while(input != "2");
    

    do
    {
        cout<<"Where would you like to go?\nType a number:";
        cout<<"(1) Go to Town (2) Go to the Forest (3) Go into the Dungeon\n";
        cout<<"(4) Go into the Castle (5) View your Stats (6) Quit the Game\n";
        cin>>input;

        if(input == "1")//__TOWN AREA__
        {

            do
            {
            
                cout<<"You are in town. What would you like to do?\n";
                cout<<"Type a number: (1) Go to the Shop (2) Sleep at the Inn\n";
                cout<<"(3) View Stats (4) Leave Town .\n";
                cin>>input;

                if(input == "1")//goes to shop
                {
                    game.shopping();
                }
                else if(input == "2")//goes to inn
                {
                    game.goToInn();
                }
                else if (input == "3")//views stats
                {
                    game.viewStats();
                }
                else
                {
                    cout<<"Please enter valid input\n";
                }

            }while(input != "4");

        }
        else if(input == "2")// __FOREST AREA__
        {   

            game.getMonsters("Goblin", "Wolf", "Black_Bear");

            cout<<"You have arrived at the Forest.\n";

            do
            {
                cout<<"Would you like to (1)Search the forest for items (2) Fight ";
                cout<<"monsters (3) Use a potion (4) Leave this area";
                cin>>input;
            
                if(input == "1")//searches forest for items
                {
                    game.searchForest();
                }
                else if(input == "2")//battles forest monsters
                {
                    string enemy = " ";

                    enemy = game.randomMonster();

                    game.encounterMonster(enemy);
              
                    input = game.stayOrGo();

                }
                else if(input == "3")//uses potion
                {
                    game.usePotion();
                }
                else
                {
                    cout<<"Please enter valid input.\n";
                }

            }while(input != "2" && input != "4");


        }
        else if(input == "3")//__DUNGEON AREA__
        {

            game.getMonsters("Zombie", "Slime", "Dragon");
            
            cout<<"You have arrived at the Dungeon.\n";
            do
            {

                cout<<"What would you like to do? (1) Fight Monsters (2) Use potion";
                cout<<"(3) Leave this Area\n";
                cin>>input;
                if(input == "1")//battle monsters in Dungeon
                {
                    do
                    {
                        string enemy = " ";

                        enemy = game.randomMonster();

                        game.encounterMonster(enemy);

                        input = game.stayOrGo();

                    }while(input != "2");
                }
                else if (input == "2")//uses potion
                {
                    game.usePotion();   
                }
                else
                {
                    cout<<"Please enter Valid input\n";
                }

            }while(input != "3");

        }
        else if(input == "4")//castle
        {

            game.getMonsters("Guard", "Magician", "Black_Knight");

            int searchCount = 0;

            cout<<"You have arrived at the Castle\n";

            do
            {
                cout<<"Would you like to: (1) Search the castle for treasure";
                cout<<" (2) Battle the inhabitants of the castle? \n";
                cout<<"(3) Use a potion (4) Leave this Area\n";
                cin>>input;

                if(input == "1" && searchCount < 2)//searches for treasure
                {
                    game.searchForTreasure();
                    searchCount++;
                }
                else if(input == "2" || searchCount >= 2)//battle in castle
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
                else if(input == "3")//use potion
                {
                    game.usePotion();
                }
                else 
                {
                    cout<<"Please enter valid input.";
                }
            
            }while(input != "2" && input != "4");

        }
        else if(input == "5")
        {
           game.viewStats();
        }

    }while(input != "6");//end of game

    return 0;
}


