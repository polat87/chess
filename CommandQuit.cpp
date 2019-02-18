//------------------------------------------------------------------------------
// CommandQuit.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "CommandQuit.h"


//------------------------------------------------------------------------------
CommandQuit::CommandQuit(string name):Command(name)
{
    
}

//------------------------------------------------------------------------------
CommandQuit::~CommandQuit()
{
}

//------------------------------------------------------------------------------
int CommandQuit::execute(Game& board, vector<string>& params)
{
  std::cout << "Bye!" << "\n";
  
  return -5;
}
