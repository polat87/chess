//------------------------------------------------------------------------------
// PieceBishop.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "PieceBishop.h"
#include "Field.h"

//------------------------------------------------------------------------------
PieceBishop::PieceBishop():
Piece(BISHOP)
{
}

//------------------------------------------------------------------------------
PieceBishop::~PieceBishop()
{
}

//------------------------------------------------------------------------------
int PieceBishop::move(Field& target)
{
  int ret_val;
  
  unsigned x_dis = (unsigned)fabs(current_field_->x() - target.x());
  unsigned y_dis = (unsigned)fabs(current_field_->y() - target.y());
  
  if(x_dis != y_dis)
    return TGT_NOT_REACH;

  if(current_field_->y() < target.y())
  {
    if(current_field_->x() < target.x())
      ret_val = moveRightUp(&target, x_dis);
    else
      ret_val = moveLeftUp(&target, x_dis);
  }
  else
  {
    if(current_field_->x() < target.x())
      ret_val = moveRightDown(&target, x_dis);
    else
      ret_val = moveLeftDown(&target, x_dis);
  }
  
  return ret_val;
}

//------------------------------------------------------------------------------
int PieceBishop::moveRightUp(Field* target, unsigned& steps)
{
  Field* cur = current_field_;
  
  for(unsigned i = 0; i < steps - 1; i++)
  {
    cur = cur->upRight();
    
    if(cur->isTaken())
      return PIECE_ON_WAY;
  }
  
  return 0;
}

//------------------------------------------------------------------------------
int PieceBishop::moveLeftUp(Field* target, unsigned& steps)
{
  Field* cur = current_field_;
  
  for(unsigned i = 0; i < steps - 1; i++)
  {
    cur = cur->upLeft();
    
    if(cur->isTaken())
      return PIECE_ON_WAY;
  }
  
  return 0;  
}

//------------------------------------------------------------------------------
int PieceBishop::moveRightDown(Field* target, unsigned& steps)
{
  Field* cur = current_field_;
  
  for(unsigned i = 0; i < steps - 1; i++)
  {
    cur = cur->downRight();
    
    if(cur->isTaken())
      return PIECE_ON_WAY;
  }

  return 0;
}

//------------------------------------------------------------------------------
int PieceBishop::moveLeftDown(Field* target, unsigned& steps)
{ 
  Field* cur = current_field_;
  
  for(unsigned i = 0; i < steps - 1; i++)
  {
    cur = cur->downLeft();
    
    if(cur->isTaken())
      return PIECE_ON_WAY;
  }
  
  return 0;
}

