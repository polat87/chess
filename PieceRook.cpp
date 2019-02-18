//------------------------------------------------------------------------------
// PieceRook.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "PieceRook.h"
#include "Field.h"

//------------------------------------------------------------------------------
PieceRook::PieceRook():
Piece(ROOK)
{
}

//------------------------------------------------------------------------------
PieceRook::~PieceRook()
{
}

//------------------------------------------------------------------------------
int PieceRook::move(Field& target)
{
  int ret_val = TGT_NOT_REACH;
  
  if(current_field_->x() != target.x() && current_field_->y() != target.y())
    return TGT_NOT_REACH;
  
  unsigned x_dis = (unsigned)fabs(current_field_->x() - target.x());
  unsigned y_dis = (unsigned)fabs(current_field_->y() - target.y());  

  if(current_field_->y() == target.y())
  {
    if(current_field_->x() > target.x())
      ret_val = moveLeft(&target, x_dis);
    else
      ret_val = moveRight(&target, x_dis);
  }
  else
  {
    if(current_field_->y() < target.y())
      ret_val = moveUp(&target, y_dis);
    else
      ret_val = moveDown(&target, y_dis);
  }  
    
  return ret_val;
}



//------------------------------------------------------------------------------
int PieceRook::moveUp(Field* target, unsigned& steps)
{
  Field* cur = current_field_;
  
  for(unsigned i = 0; i < steps - 1; i++)
  {
    cur = cur->up();
    
    if(cur->isTaken())
      return PIECE_ON_WAY;
  }
  
  return 0;
}

//------------------------------------------------------------------------------
int PieceRook::moveDown(Field* target, unsigned& steps)
{
  Field* cur = current_field_;
  
  for(unsigned i = 0; i < steps-1; i++)
  {
    cur = cur->down();
    
    if(cur->isTaken())
      return PIECE_ON_WAY;
  }
  
  return 0;
}

//------------------------------------------------------------------------------
int PieceRook::moveRight(Field* target, unsigned& steps)
{ 
  Field* cur = current_field_;

  for(unsigned i = 0; i < steps - 1; i++)
  {
    cur = cur->right();
    
    if(cur->isTaken())
      return PIECE_ON_WAY;
  }
  
  return 0;
}

//------------------------------------------------------------------------------
int PieceRook::moveLeft(Field* target, unsigned& steps)
{
  Field* cur = current_field_;

  for(unsigned i = 0; i < steps - 1; i++)
  {
    cur = cur->left();
    
    if(cur->isTaken())
      return PIECE_ON_WAY;
  }
  
  return 0;  
}

