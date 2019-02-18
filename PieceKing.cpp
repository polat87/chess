//------------------------------------------------------------------------------
// PieceKing.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "PieceKing.h"
#include "Field.h"

//------------------------------------------------------------------------------
PieceKing::PieceKing():
Piece(KING)
{
}

//------------------------------------------------------------------------------
PieceKing::~PieceKing()
{
}


//------------------------------------------------------------------------------
int PieceKing::move(Field& target)
{
  int ret_val;
  unsigned x_dis = (unsigned)fabs(current_field_->x() - target.x());
  unsigned y_dis = (unsigned)fabs(current_field_->y() - target.y());
  
  if((x_dis > 1) || (y_dis > 1))
    return TGT_NOT_REACH;
  
  if(x_dis == y_dis)
    ret_val = moveAcross(&target);
  else if(!y_dis)
    ret_val = moveHorizontal(&target);
  else
    ret_val = moveVertical(&target);  
  
  return ret_val;
}

//------------------------------------------------------------------------------
int PieceKing::moveVertical(Field* target)
{
  
  if(current_field_->y() < target->y())
  {
    if(current_field_->up() == target)
      return 0;
  }
  else
  {
    if(current_field_->down() == target)
      return 0;
  }
  
  return TGT_NOT_REACH;
}

//------------------------------------------------------------------------------
int PieceKing::moveHorizontal(Field* target)
{  
  if(current_field_->x() < target->x())
  {
    if(current_field_->right() == target)
      return 0;
  }
  else
  {
    if(current_field_->left() == target)
      return 0;
  }
  
  return TGT_NOT_REACH;
}

//------------------------------------------------------------------------------
int PieceKing::moveAcross(Field* target)
{
  if(current_field_->y() < target->y())
  {
    if(current_field_->x() < target->x())
    {
      if(current_field_->upRight() == target)
        return 0;
    }
    else
    {
      if(current_field_->upLeft() == target)
        return 0;
    }
    
  }
  else
  {
    if(current_field_->x() < target->x())
    {
      if(current_field_->downRight() == target)
        return 0;
    }
    else
    {
      if(current_field_->downLeft() == target)
        return 0;
    }
  }
  
  return TGT_NOT_REACH;
}

