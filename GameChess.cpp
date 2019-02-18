//------------------------------------------------------------------------------
// GameChess.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "GameChess.h"
#include "CommandHandler.h"
#include "Board.h"
#include <stdio.h>

#define QUIT -5



//------------------------------------------------------------------------------
GameChess::GameChess(Point& bounds):
Game(bounds, '8', 'a', false, true)
{
}

//------------------------------------------------------------------------------
GameChess::~GameChess()
{
  
}

//------------------------------------------------------------------------------
int GameChess::run()
{
  bool running = true;
  int ret_val;
  
  while(running)
  {
    std::cout << "sep> ";

    if((ret_val = CommandHandler::handleCommand(*this)) == QUIT)
    {
        ret_val = 0;
      running = false;
    }
    
    
    switch(ret_val)
    {
      case ERR_CMD:
        std::cout << "Error: Unknown command.\n";
        break;
      case ERR_USE:
        std::cout << "Error: Wrong usage of command.\n";
        break;
      case GAME_FINISHED:
        std::cout << "Error: Game finished.\n";
        break;
    }
  }

  return ret_val;
}

