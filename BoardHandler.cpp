//------------------------------------------------------------------------------
// BoardHandler.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "BoardHandler.h"
#include "Game.h"
#include "GameChess.h"
#include "Action.h"
#include "Board.h"
#include "Field.h"
#include "Piece.h"
#include "CommandMove.h"
#include <stdio.h>

using std::bad_alloc;

//------------------------------------------------------------------------------
int BoardHandler::performAction(Game& board, string& start, string& target)
{   
  int ret_val = -1;
  Field* start_pos = board.getGameBoard()->getField(start[0], start[1]);
  Field* target_pos = board.getGameBoard()->getField(target[0], target[1]);  

  if(!start_pos->isTaken())
  {
    std::cout << "Error: No piece at this location.\n";
    return ret_val;
  }  
  
  if(board.getActivePlayer() != start_pos->getCurrentPiece()->getPlayer())
  {
    std::cout << "Error: No own piece at this location.\n";
    return ret_val;
  }
  
  if(!start_pos->getCurrentPiece()->move(*target_pos))
  {
    if(!isLegalMove(start_pos, target_pos, board.getEnemy()))
    {
      std::cout << SACRIFICE;
      return ret_val;
    }
    else
      board.setGameStatus(RUNNING);
  }

  Action* act;  
  try
  {
    act = new Action(*start_pos, *target_pos);   
  }catch(bad_alloc&)
  {
    throw;
  }

  if(!(ret_val = act->execute()))
  {
    ret_val = 0;
    string histo_add = act->getMovement();    
    Field* king = board.getEnemy()->getKing()->getCurrentField();
    
    if(checkShah(*target_pos, king))
    {
      histo_add.append("+");
      
      if(checkMate(board.getActivePlayer(), king))
      {
        histo_add.append("+");
        board.setGameStatus(WIN);
      }
      else
      {
        board.setGameStatus(SHAH);
      }
    }    
    else if(isStaleMate(board.getActivePlayer(), king))
    {
      if(board.getEnemy()->getPieceSet().size() < 2)
        board.setGameStatus(STALEMATE);
    }
    
    std::cout << histo_add << "\n";   
    board.addToHistory(histo_add);
  }
   
  delete act;
   
  return ret_val;
}
  
//------------------------------------------------------------------------------
bool BoardHandler::checkShah(Field& start, Field* king)
{
  Piece* piece = start.getCurrentPiece();

  if(!piece->move(*king))
    return true;
  
  return false;
}

//------------------------------------------------------------------------------
bool BoardHandler::checkMate(Player* active, Field* king)
{
  vector<Field*> king_temp = calcNeighboursOfKing(king);
  vector<Field*>::iterator f;

  vector<Piece*> pieces = active->getPieceSet();
  vector<Piece*>::iterator p;
  
  vector<Field*> king_next;  
  
  for(f = king_temp.begin(); f != king_temp.end(); f++)
  {   
      if((*f)->isTaken())
      {
          unsigned col1 = (*f)->getCurrentPiece()->getPlayer()->getColor();
          unsigned col2 = king->getCurrentPiece()->getPlayer()->getColor();

          if(col1 != col2)
              king_next.push_back((*f));          
      }
      else
          king_next.push_back((*f));
  }

  for(p = pieces.begin(); p != pieces.end(); p++)
  {
    for(f = king_next.begin(); f != king_next.end(); f++)
    {
      if((*f) != NULL)
      {
        if(!(*p)->move(**f)) 
        {
          (*f) = NULL;
        }
      }     
    }
  }

  for(f = king_next.begin(); f != king_next.end(); f++)
  {
    if((*f) != NULL)
      return false;
  }
  
  return true;
}

//------------------------------------------------------------------------------
vector<Field*> BoardHandler::calcNeighboursOfKing(Field* king)
{
  vector<Field*> neighbours;

  if(king->down())
  neighbours.push_back(king->down());
  
  if(king->up())
  neighbours.push_back(king->up());
  
  if(king->upRight())
  neighbours.push_back(king->upRight());  
  if(king->right())
  neighbours.push_back(king->right());  
  if(king->downRight())
  neighbours.push_back(king->downRight());
  
  if(king->upLeft())
  neighbours.push_back(king->upLeft());  
  if(king->downLeft())
  neighbours.push_back(king->downLeft());
  if(king->left())
  neighbours.push_back(king->left());
 
  return neighbours;
}
  
//------------------------------------------------------------------------------
bool BoardHandler::isStaleMate(Player* active, Field* king)
{

  if(checkMate(active, king))
  {
    return true;
  }
      
  return false;
}

//------------------------------------------------------------------------------
bool BoardHandler::isLegalMove(Field* start, Field* target, Player* enemy)
{
  bool ret_val = true;
  
  if(start->getCurrentPiece()->getPieceId() == KING)
  {
    Piece* helper_king = start->getCurrentPiece();    
    start->setCurrentPiece(NULL);
    
    Piece* helper_target = target->getCurrentPiece();
    if(target->isTaken())
    {
      target->setCurrentPiece(NULL);
    }
    
    vector<Piece*>::iterator p;
    vector<Piece*> pieces = enemy->getPieceSet();
    
        
    for(p = pieces.begin(); p != pieces.end(); p++)
    {
      if(!(*p)->move(*target))
        ret_val = false;
    }    
    
    start->setCurrentPiece(helper_king);
    target->setCurrentPiece(helper_target);
    
  }
  else
  {
      Piece* st_p = start->getCurrentPiece();
      Piece* tar_p = target->getCurrentPiece();
      
      Piece* king = start->getCurrentPiece()->getPlayer()->getKing();      
      start->setCurrentPiece(NULL);
      target->setCurrentPiece(st_p);
  
      vector<Piece*> en_pieces = enemy->getPieceSet();
      vector<Piece*>::iterator p;
      
      Field* king_field = king->getCurrentField();

      for(p= en_pieces.begin(); p!= en_pieces.end(); p++)
      {
          if(!((*p) == tar_p))
          {
              if(!(*p)->move(*king_field))
              {
                  ret_val = true;
              }
          }
        
      }

      start->setCurrentPiece(target->getCurrentPiece());
      target->setCurrentPiece(tar_p);     
    
  }

  
  return ret_val;
}

