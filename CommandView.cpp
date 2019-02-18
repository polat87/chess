//------------------------------------------------------------------------------
// CommandView.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "CommandView.h"

//------------------------------------------------------------------------------
CommandView::CommandView(string name):Command(name)
{
    
}

//------------------------------------------------------------------------------
CommandView::~CommandView()
{
}

//------------------------------------------------------------------------------        
int CommandView::execute(Game& board, vector<string>& params)
{
  board.showBoard();
  
  return 0;
}


