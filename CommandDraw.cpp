//------------------------------------------------------------------------------
// CommandDraw.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "CommandDraw.h"

//------------------------------------------------------------------------------
CommandDraw::CommandDraw(string name): Command(name)
{
  
}

//------------------------------------------------------------------------------
CommandDraw::~CommandDraw()
{
  
}

//------------------------------------------------------------------------------
int CommandDraw::execute(Game& board,vector<string>& params)
{
  if(!board.isDrawOffered())
  {
    if(!params.empty())
    {
      if(params[0] == "decline")
        std::cout << NO_OFFER;
      else
        std::cout << DRAW_USAGE;
      
      return -4;
        
    }
    else
    {
      std::cout << board.getActivePlayer()->getFullName() << SUGGEST;      
      board.setDrawOffer(true);
    }
    
    return -4;
  }
  else
  {
    if(params.empty())
    {
      std::cout << END_DRAW;
      board.setWinner(2);
      return 1;
    }
    else
    {
      if(params[0] == "decline")
      {
        std::cout << board.getActivePlayer()->getFullName();
        std::cout << DRAW_DECLINE;
        board.setDrawOffer(false);
      }
      else
      {
        std::cout << DRAW_USAGE;
      }
    }
  }

  return 1;
}


//------------------------------------------------------------------------------
bool CommandDraw::getAnswer(vector<string>& param)
{
  bool ret_val = false;

    if(param.empty())
      ret_val = false;
    
    if(param.size() == 1)
    {
      if(param[0] == "decline")
      {
        ret_val = true;
      }
      else
      { 
        ret_val = false;
      }
    }
  
  if(!ret_val)
  std::cout << DRAW_USAGE;

  return ret_val;
}
