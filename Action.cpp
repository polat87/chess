//------------------------------------------------------------------------------
// Action.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "Action.h"
#include "Field.h"
#include "Piece.h"
#include "Board.h"
#include "PiecePawn.h"

using std::vector;

//------------------------------------------------------------------------------
Action::Action(Field& start, Field& target):
start_(start),
target_(target)        
{
}

//------------------------------------------------------------------------------
Action::~Action()
{
}

//------------------------------------------------------------------------------
int Action::execute()
  {
  Piece* piece = start_.getCurrentPiece();
  int ret_val;

  if(!(ret_val = piece->move(target_)))
  {
      if(!isTargetFree())
      {
          if(sameTypes())
          {
              std::cout << "Error: Own piece on target location.\n";
              return -1;
          }
      }
      
    noteMovement();

    if(target_.isTaken())
      destroyPiece();
    
    target_.setCurrentPiece(start_.getCurrentPiece());
    start_.setCurrentPiece(NULL);
    return 0;
  }
  else if(ret_val == TGT_NOT_REACH)
    std::cout << "Error: target location not reachable.\n";
  else
    std::cout << "Error: Piece on the way.\n";

  return -1;
}

//------------------------------------------------------------------------------
bool Action::sameTypes()
{
  Player* p_start = start_.getCurrentPiece()->getPlayer();
  Player* p_target = target_.getCurrentPiece()->getPlayer();
  
  if(p_start == p_target)
    return true;
  
  return false;
}
    
//------------------------------------------------------------------------------
bool Action::isTargetFree()
{
  if(target_.isTaken())
    return false;
  
  return true;
}
    
//------------------------------------------------------------------------------
int Action::destroyPiece()
{
  Player* enemy = target_.getCurrentPiece()->getPlayer();
  Piece* to_be_killed = target_.getCurrentPiece();
  vector<Piece*> pieces = enemy->getPieceSet();
  vector<Piece*>::iterator it;

  for(it = pieces.begin(); (*it) != to_be_killed; it++)
  {
    if((*it) == to_be_killed)
    {
      to_be_killed->~Piece();
      pieces.erase(it);
    }
  }

  return 0;
}
  
//------------------------------------------------------------------------------
void Action::noteMovement()
{
  int id;

  if((id = start_.getCurrentPiece()->getPieceId()) != PAWN)
    movement_.push_back(Piece::p_types_[id]);

  movement_.push_back(start_.x());
  movement_.push_back(start_.y());
  movement_.append((char*)(target_.isTaken() ? "x": "-"));
  movement_.push_back(target_.x());
  movement_.push_back(target_.y());

}

//------------------------------------------------------------------------------
string& Action::getMovement()
{
  return movement_;
}

//------------------------------------------------------------------------------
Field& Action::getStart(){
  return start_;
}
  
//------------------------------------------------------------------------------  
 Field& Action::getTarget(){
  return target_;
 }
 
