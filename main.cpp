//Author: Sunny Vang
#include<iostream>
#include<vector>
#include <string>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand( (int) time(0) );

    string monster1, monster2, monster3;
   
    //create objects for each class
    string input;

    cout<<"Welcome to Adventure Quest! \n\nType a number:\n";
    cout<<"(1) Go through the tutorial (2) get straight into the game?";
    cin>>input;


    do
    {
        cout<<"Where would you like to do?\n Type a number:";
        cout<<"(1) Town (2) Forest (3) Dungeon (4) Castle(5) Save your game (6) Quit the game";
        cin>>input;
        
        if(input == "1")//town
        {
            cout<<"You have reached town. What would you like to do?\n";
            cout<<"Type a number: (1) Go to the Shop (2) Sleep at the Inn"'
            cin>>input;
            //at shop, buy health potions. They heal all of your health
            
        }

        if(input == "2")//forest
        {
            monster1 = "Dragon";
            monster2 = ";
            monster3 = ;
            cout<<"You have arrived at the Forest.\n";
            //randomly spawn a monster here
            //then give option to fight or run
            //if win then gain experience, and money----if lose then lose health
            //then after fight, ask if they would like to stay or leave

        }

        if(input == "3")//dungeon
        {
            monster1 = ;
            monster2 = ;
            monster3 = ;
            cout<<"You have arrived at the Dungeon.\n";
            //same as forest
            //but at dungeon, there is only one dragon and a lot of other monsters
            //unlimited other monsters but they are randomly generated
            //must be level 5 to fight dragon
            //stats dictate win rate for all fights
        }

        if(input == "4")//castle
        {
            monster1 = ;
            monster2 = ;
            monster3 = ;
            cout<<"You have arrived at the Castle\n";
            //same as forest
            //only one Black knight boss

        }

        if(input == "5")//saving
        {
            //save stats, level, money, potions, bosses defeated
        }

        

//this do while loop will be used to go to places
    }while(input != "6");

    return 0;
}

