//Author: Sunny Vang
#include "castle.h"
#include "fighting.h"
#include "textadventure.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

Castle::Castle()
{

}

void Castle::searchForTreasure()
{
    srand(time(NULL));

    int randomChance = rand()%100 + 1;

    if(randomChance <= 40)
    {
        int randomGoldAmt = 0;
        randomGoldAmt = rand()%20 + 10;
        money += randomGoldAmt;

        std::cout<<"You searched the castle and was able to find a chest that\n";
        std::cout<<"contained "<<randomGoldAmt<<" gold.\n";
     }
     else
     {
        std::cout<<"You were unable to find anything of value in your search.\n";
     }

}
