//------------------------------------------------------------------------------
// PiecePawn.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "PiecePawn.h"
#include "Field.h"

//------------------------------------------------------------------------------
PiecePawn::PiecePawn():
Piece(PAWN),
start_pos_(true)
{
}

//------------------------------------------------------------------------------
PiecePawn::~PiecePawn()
{
}

//------------------------------------------------------------------------------
int PiecePawn::move(Field& target)
{
  int ret_val = 0;

  unsigned x_distance = (unsigned)fabs(current_field_->x() - target.x());
  unsigned y_distance = (unsigned)fabs(current_field_->y() - target.y());

  if(!start_pos_)
  {
      if(y_distance > 1)
          return TGT_NOT_REACH;
  }
  
  if(this->getPlayer()->getColor() == BLACK)
  {
    if(current_field_->y() < target.y())
      return TGT_NOT_REACH;
  }

  if(this->getPlayer()->getColor() == WHITE)
  {
    if(current_field_->y() > target.y())
      return TGT_NOT_REACH;
  }   

  if(current_field_->x() == target.x())
  {
    
    if((y_distance > 2) || (y_distance == 2 && !start_pos_))
      return TGT_NOT_REACH;

    ret_val = moveStraight(&target, y_distance);
  }
  else
  {
    if(x_distance > 1)
      return TGT_NOT_REACH;
    else
     ret_val = moveAcross(&target);
  }

  return ret_val;
}

//------------------------------------------------------------------------------
int PiecePawn::moveStraight(Field* target, unsigned y_distance)
{
  int ret_val = 0;
  Field* current_pos = current_field_;  

  if(current_field_->y() < target->y())
  {
    for(unsigned i = 0; i < y_distance; i++)
    {
      if(current_pos->up()->isTaken())
        ret_val = PIECE_ON_WAY;

      current_pos = current_pos->up();
            
    }
  }
  
  if(current_field_->y() > target->y())
  {
    for(unsigned i = 0; i < y_distance; i++)
    {
      if(current_pos->down()->isTaken())
        ret_val = PIECE_ON_WAY;
      
      current_pos = current_pos->down();
    }
  }

  return ret_val;
}
  
  
//------------------------------------------------------------------------------  
int PiecePawn::moveAcross(Field* target)
{
    
  Field* cur_pos = current_field_;

  if(current_field_->y() > target->y())
  {
    if(current_field_->x() > target->x())
    {
      cur_pos = current_field_->downLeft();
      if(!cur_pos->isTaken())
        return TGT_NOT_REACH;
    }
    else
    {
      cur_pos = current_field_->downRight();
      if(!cur_pos->isTaken())
        return TGT_NOT_REACH;     
    }  
  }
  else
  {
    if(current_field_->x() < target->x())
    {
      cur_pos = current_field_->upRight();
      if(!cur_pos->isTaken())
        return TGT_NOT_REACH;
    }
    else
    {
      cur_pos = current_field_->upLeft();
      if(!cur_pos->isTaken())
        return TGT_NOT_REACH;
    }
    
  }

  return 0;
}


//------------------------------------------------------------------------------
void PiecePawn::setStartPos(bool pos)
{
  start_pos_ = pos;
}

//------------------------------------------------------------------------------
bool PiecePawn::onStartPos()
{
  return start_pos_;
}
