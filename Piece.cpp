//------------------------------------------------------------------------------
// Piece.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "Piece.h"
#include "Player.h"
#include <stdio.h>


//------------------------------------------------------------------------------
const char Piece::p_types_[] =  "PRNBKQ";

//------------------------------------------------------------------------------
Piece::Piece(int id):
player_(NULL),
piece_id_(id)
{
}

//------------------------------------------------------------------------------
Piece::~Piece()
{
}

//------------------------------------------------------------------------------
void Piece::setCurrentField(Field* field)
{
  current_field_ = field;
}

//------------------------------------------------------------------------------
Field* Piece::getCurrentField()
{
  return current_field_;
}


//------------------------------------------------------------------------------
void Piece::setPlayer(Player* player)
{
  player_ = player;
}

//------------------------------------------------------------------------------
int Piece::getPieceId()
{
  return piece_id_;
}

//------------------------------------------------------------------------------
Player* Piece::getPlayer()
{
  return player_;
}

//------------------------------------------------------------------------------
bool Piece::operator==(Piece& src)
{
    Piece* source = &src;
    unsigned here = (unsigned)this;
    unsigned other = (unsigned)source;
    
    if(here == other)
        return true;
    
    return false;
}


