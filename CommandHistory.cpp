//------------------------------------------------------------------------------
// CommandHistory.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "CommandHistory.h"

//------------------------------------------------------------------------------
CommandHistory::CommandHistory(string name): Command(name)
{
  
}

//------------------------------------------------------------------------------
CommandHistory::~CommandHistory()
{
  
}

//------------------------------------------------------------------------------
int CommandHistory::execute(Game& board,vector<string>& params)
{
  board.showHistory();
  
  return 1;
}


