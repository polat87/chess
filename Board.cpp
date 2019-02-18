//------------------------------------------------------------------------------
// Board.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "Board.h"
#include "Field.h"
#include "Player.h"
#include "Piece.h"
#include <stdio.h>


//------------------------------------------------------------------------------
Board::Board(unsigned int num)
{
  char col = 'a';
  char row = '8';    
    
  for(unsigned int f = 0; f < num; f++)
  {
    Field* field = new Field(col, row);
    fields_.push_back(field);

    
    if(col == 'h')
    {
      col = 'a';
      row--;
    }
    else
    col++;
  }

    chainFieldsTogether();
}

//------------------------------------------------------------------------------
Board::~Board()
{
  vector<Field*>::iterator it;
  
  for(it = fields_.begin(); it != fields_.end(); it++)
  {
    delete *it; 
  }

}

//------------------------------------------------------------------------------
void Board::setupDefaultBoard(Player& black, Player& white)
{
  vector<Field*>::iterator field;
  vector<Piece*> b_pieces = black.getPieceSet();
          
  int i = 0;

  for(field = fields_.begin(); field != fields_.begin() + 48; field++)
  {
    if(i < 16)
      (*field)->setCurrentPiece(b_pieces[i++]);
    else
      (*field)->setCurrentPiece(NULL);        
  }   
  
  i = 15;
  vector<Piece*> w_pieces = white.getPieceSet(); 
  
  for(; field != fields_.end(); field++)
  {
    (*field)->setCurrentPiece(w_pieces[i--]);
  }    
      
}

//------------------------------------------------------------------------------
vector<Field*> Board::getFields()
{
  return fields_;
}
            

//------------------------------------------------------------------------------
void Board::chainFieldsTogether()
{
  chainLeftToRight();
  chainRightToLeft();
  chainUpToDown();
  chainDownToUp();
  chainAcross();
    
}

//------------------------------------------------------------------------------
void Board::chainLeftToRight()
{
  int nuller = 0;

  for(unsigned i = 0; i < fields_.size(); i++)
  {
    nuller++;
    
    if(nuller % 8 == 0)
      fields_.at(i)->setRight(NULL);
    else
      fields_.at(i)->setRight(fields_.at(i + 1));        
  }
}
   
//------------------------------------------------------------------------------
void Board::chainRightToLeft()
{

  for(unsigned i = 0; i < fields_.size(); i += 8)
  {  
    for(unsigned j = 0; j < 8; j++)
    {
      if(j == 0)
        fields_.at(i + j)->setLeft(NULL);
      else
        fields_.at(i + j)->setLeft(fields_.at(i + j - 1));
    }
  }
    
}
    
//------------------------------------------------------------------------------
void Board::chainUpToDown()
{
  int counter;
  Field* temp;

  for(unsigned i = 0; i < 8; i++)
  {
    counter = 0;
    temp = fields_.at(i);
    
    for(unsigned j = 0; j < 8; j++)
    {    
      if(j == 8)
          temp->setDown(NULL);
      else
      {
        temp->setDown(fields_.at(i+counter));
        temp = fields_.at(i+counter);
      }
      
      counter += 8;
    }
  }
}  

//------------------------------------------------------------------------------
void Board::chainDownToUp()
{
  int counter;
  Field* temp;

  for(unsigned i = 56; i < 64; i++)
  {
    counter=8;
    temp = fields_.at(i);
    
    for(unsigned j = 0; j < 8; j++)
    {    
      if(j == 7)
        temp->setUp(NULL);
      else
      {
        temp->setUp(fields_.at(i-counter));
        temp = fields_.at(i-counter);
      }
      
      counter += 8;
    }
  }
}  

//------------------------------------------------------------------------------
void Board::chainAcross()
{
  Field* cur;
  Field* temp;

  for(int i = 0; i < 64; i++)
  {
    cur = fields_.at(i);
    
    temp = cur->left();
    cur->setUpLeft(temp  ? temp->up() : NULL);            
    cur->setDownLeft(temp ? temp->down() : NULL);
    
    temp = cur->right();       
    cur->setUpRight(temp  ? temp->up() : NULL);        
    cur->setDownRight(temp ? temp->down() : NULL);        
  } 
}

   

//------------------------------------------------------------------------------
Field* Board::getField(char& x, char& y)
{
  for(unsigned i = 0; i < fields_.size() ; i++)
  {
    if(fields_.at(i)->x() == x && fields_.at(i)->y() == y)
      return fields_.at(i);
  }

  return NULL;
}

