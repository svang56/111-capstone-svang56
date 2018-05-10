//Author: Sunny Vang
#ifndef FIGHTING_H_
#define FIGHTING_H_
#include<string>
//this will be the base class for the 3 fighting areas / will make own 
//class for the town itself

class fighting
{
        
    public:
        
        void encounterMonster(std::string);//this will randomly spawn monster for player to fight
        bool fightOrRun(std::string);//if 1 then fight, if 2 then run`
        void generateMonster(std::string, std::string, std::string);
        //this will generate monsters 

        bool randomChance(std::string);//this will determine win chance for monster
        //if monster == this, then that chance to win

        std::string stayOrGo();//asks if want to fight again or leave or use potion
        
        //to get monster names, initialize within the do-while loop 
        //in the int main() into the constructor 

        //Each class inheriting will have their own constructor
        //and will have private variables of each monster

        /* when not high enough level, you walk towards the dragon/knight/hugeblackbea but realize 
        you aren't strong enough to fight run away*/

};

#endif
