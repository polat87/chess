//------------------------------------------------------------------------------
// main.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "Player.h"
#include "Game.h"
#include "Piece.h"
#include "GameChess.h"
#include "GameSetup.h"
#include "Game.h"
#include "PiecePawn.h"
#include <iostream>
#include <exception>

#include "Board.h"

#define INV_PARAM_COUNT -1
#define OUT_OF_MEMORY -2

using std::bad_alloc;


//------------------------------------------------------------------------------
int main (int argc, char** argv)
{
    int ret_val = SUCCESS;
    string config_str;
    
    if(argc > 2)
    {
        std::cout << "Error: Invalid parameter count." << "\n";
        return INV_PARAM_COUNT;
    }
    
    if(argc == 2)
    {
        config_str.append(argv[1]);
        ret_val = GameSetup::checkConfigString(config_str);
    }
    
    if(!ret_val)
    {
        GameChess* game = NULL;
    
        try
        {
            if(!(ret_val = GameSetup::buildGameEnvironment(config_str, &game)))
            {
                ret_val = game->run();
            }
        }
        catch(bad_alloc)
        {
            std::cout << "Error: Out of memory.\n";
            ret_val = OUT_OF_MEMORY;
        }
    
        delete game;
    }
    
    return ret_val;
}


