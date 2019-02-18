//------------------------------------------------------------------------------
// PieceKnight.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "PieceKnight.h"
#include "Field.h"

//------------------------------------------------------------------------------
PieceKnight::PieceKnight():
Piece(KNIGHT)
{
}

//------------------------------------------------------------------------------
PieceKnight::~PieceKnight()
{
}

//------------------------------------------------------------------------------
int PieceKnight::move(Field& target)
{
  return calcPossibility(&target);
}

//------------------------------------------------------------------------------
int PieceKnight::calcPossibility(Field* target)
{
  Field* cur = current_field_;
  int ret_val= TGT_NOT_REACH;
  
  unsigned x_dis = (unsigned)fabs(current_field_->x() - target->x());  

  if(x_dis == 2)
  {
    if(current_field_->x() < target->x())
    {
      if(current_field_->y() < target->y())
      {
        if(cur->right()->right()->up() == target)
          ret_val = 0;
      }
      else
      {
        if(cur->right()->right()->down() == target)
          ret_val = 0;
      }
    }
    else
    {
      if(current_field_->y() < target->y())
      {
        if(cur->left()->left()->up() == target)
          ret_val = 0;
      }
      else
      {
        if(cur->left()->left()->down() == target)
          ret_val = 0;
      } 
    }
  }
  else
  {
    if(current_field_->y() < target->y())
    {
      if(current_field_->x() < target->x())
      {
        if(cur->up()->up()->right() == target)
          ret_val = 0;
      }
      else
      {
        if(cur->up()->up()->left() == target)
          ret_val = 0;
      }
    }
    else
    {
      if(current_field_->x() < target->x())
      {
        if(cur->down()->down()->right() == target)
          ret_val = 0;
      }
      else
      {
        if(cur->down()->down()->left() == target)
          ret_val = 0;
      }
    }
  }

  return ret_val;
}

