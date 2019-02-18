//------------------------------------------------------------------------------
// CommandSetName.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "CommandSetName.h"
#include "Game.h"

//------------------------------------------------------------------------------
CommandSetName::CommandSetName(string name): Command(name)
{
    
}

//------------------------------------------------------------------------------
CommandSetName::~CommandSetName()
{
  
}

//------------------------------------------------------------------------------
int CommandSetName::execute(Game& board,vector<string>& params)
{
  board.getActivePlayer()->setName(params[0]);
  std::cout << "Name set: " << board.getActivePlayer()->getFullName();
  std::cout << "." << "\n";
    
  return 1;
}


