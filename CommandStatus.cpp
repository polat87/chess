//------------------------------------------------------------------------------
// CommandStatus.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "CommandStatus.h"

//------------------------------------------------------------------------------
CommandStatus::CommandStatus(string name):Command(name)
{    
}

//------------------------------------------------------------------------------
CommandStatus::~CommandStatus()
{
}

//------------------------------------------------------------------------------
int CommandStatus::execute(Game& board, vector<string>& params)
{
  board.getStatus();
  
  return 1;
}
