//------------------------------------------------------------------------------
// Player.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "Player.h"
#include "Piece.h"


const char* Player::clrs[] = {"Black", "White", "Red", "Green",
                              "Blue", "Yellow", "Orange", "Brown"};

//------------------------------------------------------------------------------
Player::Player(Color color, const string& name):
color_(color),
name_(name)
{
}

//------------------------------------------------------------------------------
Player::~Player()
{
}

//------------------------------------------------------------------------------
void Player::setName(const string& name)
{
  name_ = name;
}

//------------------------------------------------------------------------------
void Player::setColor(Color color)
{
  color_ = color;
}

//------------------------------------------------------------------------------
string Player::getName()
{
  return name_;
}

//------------------------------------------------------------------------------
Color Player::getColor()
{
  return color_;
}

//------------------------------------------------------------------------------
string Player::getFullName()
{
  string ret_string = name_;
   
  ret_string.push_back('(');
  ret_string.append(clrs[color_]);
  ret_string.push_back(')');
  
  return ret_string;  
}

//------------------------------------------------------------------------------
void Player::addPieceToSet(Piece* piece)
{  
  piece->setPlayer(this);
  piece_set_.push_back(piece);
}

//------------------------------------------------------------------------------
vector<Piece*> Player::getPieceSet()
{
  return piece_set_;
}
   
//------------------------------------------------------------------------------
Piece* Player::getKing(){
  return king_;
}

//------------------------------------------------------------------------------
void Player::setKing(Piece* piece)
{ 
  king_ = piece;
}
