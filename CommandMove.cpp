// CommandMove.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "CommandMove.h"
#include "Field.h"
#include "Piece.h"
#include "GameSetup.h"
#include "BoardHandler.h"
#include "Action.h"
#include "CommandHandler.h"
#include "CommandDraw.h"
#include "Board.h"

//------------------------------------------------------------------------------
CommandMove::CommandMove(string name): Command(name)
{
  
}

//------------------------------------------------------------------------------
CommandMove::~CommandMove()
{
  
}

//------------------------------------------------------------------------------
int CommandMove::execute(Game& board,vector<string>& params)
{
  int ret_val;

  if(board.isDrawOffered())
  {
    std::cout << UNANS_OFFER;
    return 0;
  }
  
  if(params.size() != 2)
  {
    std::cout << "Usage: move startlocation endlocation.\n";    
    return 0;
  }
  
  if(params[0].size() != 2 || params[1].size() != 2)
  {
    std::cout << "Usage: move startlocation endlocation.\n";    
    return 0;
  }      
  
   
  if(!checkIfCoordsValid(params[0]))
  {
    std::cout << "Error: Incorrect starting location.\n";
    return 0;
  }
    
  if(!checkIfCoordsValid(params[1]))
  {
    std::cout << "Error: Incorrect target location.\n";
    return 0;
  }

  if(!(ret_val = BoardHandler::performAction(board, params[0], params[1])))
  {
    if(board.gameState() == WIN)
    {
      std::cout << board.getActivePlayer()->getFullName() << " wins!" << "\n";
      board.setGameStatus(OVER);
      board.setWinner(board.getActivePlayer()->getColor());
      return ret_val;
    }
    
    if(board.gameState() == STALEMATE)
    {
      std::cout << "Stalemate - the game ends in a draw.\n";
      board.setGameStatus(OVER);
      return ret_val;
    }
    
    board.changeTurn();
    
    return 0;
  }
      
  return 0;
}

//------------------------------------------------------------------------------
bool CommandMove::checkIfCoordsValid(string& param)
{  
    if(!((param[0] >= 'a') && (param[0] <= 'h')))
      return false;

    if(!((param[1] >= '1') && (param[1] <= '8')))
      return false;    
  
  return true;
}

