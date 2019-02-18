//------------------------------------------------------------------------------
// Field.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "Field.h"
#include "Piece.h"
#include "PiecePawn.h"

//------------------------------------------------------------------------------
Field::Field(char x, char y):
current_piece_(NULL),        
is_taken_(false),
up_(NULL),
down_(NULL),
left_(NULL),
right_(NULL),
up_left_(NULL),
up_right_(NULL),
down_left_(NULL),
down_right_ (NULL),
x_(x),
y_(y)        
{
}

//------------------------------------------------------------------------------
Field::~Field()
{
}

//------------------------------------------------------------------------------
void Field::setCurrentPiece(Piece* piece)
{
  if(piece)
  {
    is_taken_ = true;
    current_piece_ = piece;

    if(piece->getPieceId() == PAWN)
    {
        PiecePawn* pp = dynamic_cast<PiecePawn*>(piece);

            if(pp->getPlayer()->getColor() == BLACK)
            {
                if(this->y() != '7')
                    pp->setStartPos(false);
                else
                    pp->setStartPos(true);
            }
            else
            {
                if(this->y() != '2')
                    pp->setStartPos(false);
                else
                    pp->setStartPos(true);
            }
    }    
    
    current_piece_->setCurrentField(this);
  }
  else
  {
    is_taken_ = false;
    current_piece_ = NULL;
  }

}
            
//------------------------------------------------------------------------------
Piece* Field::getCurrentPiece()
{
  return current_piece_;
}
    
//------------------------------------------------------------------------------
bool Field::isTaken()
{
  if(is_taken_)
    return true;

  return false;
}

//------------------------------------------------------------------------------
void Field::setTaken()
{
  is_taken_ = true;
}

//------------------------------------------------------------------------------
char Field::x()
{
  return x_;
} 

//------------------------------------------------------------------------------
char Field::y()
{
  return y_;
} 

//------------------------------------------------------------------------------ 
Field* Field::up()
{
  return up_;
} 

//------------------------------------------------------------------------------
Field* Field::down()
{
  return down_;
}

//------------------------------------------------------------------------------
Field* Field::left()
{
  return left_;
}
 
//------------------------------------------------------------------------------
Field* Field::right()
{
  return right_;
}
  
//------------------------------------------------------------------------------
Field* Field::upLeft()
{
  return Field::up_left_;
}

//------------------------------------------------------------------------------
Field* Field::upRight()
{
  return up_right_;
}
  
//------------------------------------------------------------------------------
Field* Field::downLeft()
{
  return down_left_;
}
 
//------------------------------------------------------------------------------
Field* Field::downRight()
{
  return down_right_;
}

//------------------------------------------------------------------------------  
void Field::setUp(Field* field){
  up_ = field;
}

//------------------------------------------------------------------------------  
void Field::setDown(Field* field)
{
  down_ = field;
}

//------------------------------------------------------------------------------
void Field::setLeft(Field* field)
{
  left_ = field;
}

//------------------------------------------------------------------------------
void Field::setRight(Field* field)
{
  right_ = field;
}

//------------------------------------------------------------------------------
void Field::setUpLeft(Field* field)
{
  up_left_ = field;
}

//------------------------------------------------------------------------------
void Field::setUpRight(Field* field)
{
  up_right_ = field;
}

//------------------------------------------------------------------------------
void Field::setDownLeft(Field* field)
{
  down_left_ = field;
}

//------------------------------------------------------------------------------
void Field::setDownRight(Field* field)
{
  down_right_ = field;
}

