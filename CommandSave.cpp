//------------------------------------------------------------------------------
// CommandSave.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "CommandSave.h"
#include "FileManager.h"

//------------------------------------------------------------------------------
CommandSave::CommandSave(string name): Command(name)
{
    
}

//------------------------------------------------------------------------------
CommandSave::~CommandSave()
{
  
}

//------------------------------------------------------------------------------
int CommandSave::execute(Game& board, vector<string>& params)
{
  if(params.size() != 1)
  {
    std::cout << "Usage: save filename.\n";    
    return 0;
  }
    
  FileManager::saveDataToFile(board, params[0]);
  
  return 1;
}


