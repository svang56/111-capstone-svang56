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
        cout<<"(1) Town (2) Forest (3) Dungeon (4) Castle(5) See more options\n";
        cin>>input;
        if(input == "5")
        {
            cout<<"(6) Save your game (7) Quit the game\n";
        }

        if(input == "1")//town
        {
            cout<<"You have reached town. What would you like to do?\n";
            cout<<"Type a number: (1) Go to the Shop (2) Sleep at the Inn\n";
            cin>>input;//if 1, go to shop, if 2, go to inn
            if(input == "1")
            {
                //shop function
            }
            else
            {
                //sleep at inn function
            }
            
        }
        else if(input == "2")//forest
        {   
            //create object and initialize mosnter names
            cout<<"You have arrived at the Forest.\n";
            do
            {   //randomly choose a monster with rand function
                //encounter monster function
                //fight or run function
                //winorlose function  they will gain money, etx...
                //after win or lose, stay here or go? return string 
            }while(input != "2");

            //if win then gain experience, and money----if lose then lose health
            //then after fight, ask if they would like to stay or leave

        }
        else if(input == "3")//dungeon
        {
            monster1 = "Zombie";
            monster2 = "Dragon";
            monster3 = "Slime";
            cout<<"You have arrived at the Dungeon.\n";
            //same as forest
            //but at dungeon, there is only one dragon and a lot of other monsters
            //unlimited other monsters but they are randomly generated
            //must be level 5 to fight dragon
            //stats dictate win rate for all fights
        }
        else if(input == "4")//castle
        {
            monster1 = "BlackKnight";
            monster2 = "Guard";
            monster3 = "Magician";
            cout<<"You have arrived at the Castle\n";
            //same as forest
            //only one Black knight boss

        }
        else if(input == "6")//saving
        {
            //save stats, level, money, potions, bosses defeated
        }
        

        

//this do while loop will be used to go to places
    }while(input != "7");

    return 0;
}

