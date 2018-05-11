//Author: Sunny Vang
#include<iostream>
#include<vector>
#include <string>
#include "fighting.h"
#include "forest.h"
#include "town.h"
#include "dungeon.h"
#include "castle.h"

using namespace std;

int main()
{
    string input = " ";
    Adventure game;

    do
    {
    cout<<"Welcome to Adventure Quest! \n\nType a number:\n";
    cout<<"(1) Go through the tutorial (2) get straight into the game?";
    cin>>input;
    if(input == "1")
    {
        //tutorial
    }
    
    }while(input != "2");
    

    do
    {
        cout<<"Where would you like to go?\n Type a number:";
        cout<<"(1) Go to Town (2) Go to the Forest (3) Go into the Dungeon\n";
        cout<<"(4) Go into the Castle (5) View your Stats (6) Save your game\n";
        cout<<"(7) Quit the game\n";
        cin>>input;

        if(input == "1")//town
        {
            Town townArea;

            do
            {
            
                cout<<"You are in town. What would you like to do?\n";
                cout<<"Type a number: (1) Go to the Shop (2) Sleep at the Inn\n";
                cout<<"(3) View Stats (4) Leave Town .\n";
                cin>>input;

                if(input == "1")
                {
                    townArea.shopping();
                }
                else if(input == "2")
                {
                    townArea.goToInn();
                }
                else if (input == "3")
                {
                    townArea.viewStats();
                }
                else
                {
                    cout<<"Please enter valid input\n";
                }

            }while(input != "4");

        }
        else if(input == "2")//-------------forest
        {   
            Forest forestArea;

            forestArea.getMonsters("Goblin", "Wolf", "BlackBear");

            cout<<"You have arrived at the Forest.\n";

            do
            {
                string enemy = " ";

                enemy = forestArea.randomMonster();

                forestArea.encounterMonster(enemy);

                input = forestArea.stayOrGo();

            }while(input != "2");


        }
        else if(input == "3")//dungeon
        {
            Dungeon dungeonArea;

            dungeonArea.getMonsters("Zombie", "Slime", "Dragon");
            
            cout<<"You have arrived at the Dungeon.\n";

            do
            {
                string enemy = " ";

                enemy = dungeonArea.randomMonster();

                dungeonArea.encounterMonster(enemy);

                input = dungeonArea.stayOrGo();

            }while(input != "2");
            //must be level 5 to fight dragon
            //stats dictate win rate for all fights
        }
        else if(input == "4")//castle
        {
            Castle castleArea;

            castleArea.getMonsters("Guard", "Magician", "BlackKnight");

            cout<<"You have arrived at the Castle\n";

            do
            {
                string enemy = " ";

                enemy = castleArea.randomMonster();

                castleArea.encounterMonster(enemy);

                input = castleArea.stayOrGo();

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

