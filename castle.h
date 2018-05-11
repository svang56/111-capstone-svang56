//Author: Sunny Vang
#ifndef CASTLE_H_
#define CASTLE_H_

#include "fighting.h"
#include "textadventure.h"

class Castle: public fighting
{
    public:
        Castle();
        void searchForTreasure();
};

#endif
