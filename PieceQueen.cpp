//------------------------------------------------------------------------------
// PieceQueen.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "PieceQueen.h"
#include "Field.h"

//------------------------------------------------------------------------------
PieceQueen::PieceQueen():
Piece(QUEEN)
{
}

//------------------------------------------------------------------------------
PieceQueen::~PieceQueen()
{
}

//------------------------------------------------------------------------------
int PieceQueen::move(Field& target)
{
   int ret_val = TGT_NOT_REACH;
   Field* cur = current_field_;
   unsigned x_dis = (unsigned)fabs(current_field_->x() - target.x());
   unsigned y_dis = (unsigned)fabs(current_field_->y() - target.y());
 
   if((cur->y() == target.y()) || (cur->x() == target.x()))
   {

       if(cur->y() == target.y())
       {
           if(cur->x() > target.x())
               ret_val = moveLeft(&target, x_dis);
           else
               ret_val = moveRight(&target, x_dis);
       }
       else
       {
           if(cur->y() < target.y())
               ret_val = moveUp(&target, y_dis);
           else
               ret_val = moveDown(&target, y_dis);
       }    
   }
   else
   {
       if(x_dis != y_dis)
         return TGT_NOT_REACH;   
     
     if(cur->y() < target.y())
     {
       if(cur->x() < target.x())
         ret_val = moveRightUp(&target, x_dis);
       else
         ret_val = moveLeftUp(&target, x_dis);
     }
     else
     {         
         if(cur->x() < target.x())
         {
           ret_val = moveRightDown(&target, x_dis);
         }
         else
         ret_val = moveLeftDown(&target, x_dis);
     }
   }

  return ret_val;
}



//------------------------------------------------------------------------------
int PieceQueen::moveUp(Field* target, unsigned& steps)
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
int PieceQueen::moveDown(Field* target, unsigned& steps)
{
  Field* cur = current_field_;
  
  for(unsigned i = 0; i < steps - 1; i++)
  {
    cur = cur->down();
    
    if(cur->isTaken())
      return PIECE_ON_WAY;
  }
  
  return 0;
}

//------------------------------------------------------------------------------
int PieceQueen::moveRight(Field* target, unsigned& steps)
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
int PieceQueen::moveLeft(Field* target, unsigned& steps)
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


//------------------------------------------------------------------------------
int PieceQueen::moveRightUp(Field* target, unsigned& steps)
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
int PieceQueen::moveLeftUp(Field* target, unsigned& steps)
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
int PieceQueen::moveRightDown(Field* target, unsigned& steps)
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
int PieceQueen::moveLeftDown(Field* target, unsigned& steps)
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

