//------------------------------------------------------------------------------
// GameSetup.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "GameSetup.h"
#include "Board.h"
#include "Field.h"
#include "GameChess.h"
#include "Player.h"

#include "Piece.h"
#include "PieceBishop.h"
#include "PieceKing.h"
#include "PieceKnight.h"
#include "PiecePawn.h"
#include "PieceQueen.h"
#include "PieceRook.h"

using std::bad_alloc;

//------------------------------------------------------------------------------
GameSetup::GameSetup()
{
}

//------------------------------------------------------------------------------
GameSetup::~GameSetup()
{
}


//------------------------------------------------------------------------------
int GameSetup::checkConfigString(string& conf_str)
{
  if(conf_str.size() % 3)
  {
    std::cout << "Error: setup string corrupt.\n";
    return ERR_STR_COR;
  }

  if(!performSyntaxAnalysis(conf_str))
  {
    std::cout << "Error: setup string invalid.\n";
    return ERR_STR_INV;
  }

  if(!performSemanticAnalysis(conf_str))
  {
    std::cout << "Error: setup string invalid.\n";
    return ERR_STR_INV;
  }
  
  return SUCCESS;
}

//------------------------------------------------------------------------------
bool GameSetup::checkPieceType(char type)
{
  for(int p = 0; p < 6; p++)
  {
    if(type == Piece::p_types_[p] || type == Piece::p_types_[p] + 32)
    {
       return true;
    }
  }
  
  return false;
}

//------------------------------------------------------------------------------
bool GameSetup::performSyntaxAnalysis(string& conf_str)
{
  for(unsigned int i = 0; i < conf_str.size(); i += 3)
  {
    if(!checkPieceType(conf_str[i]))
      return false;
    
    if(!checkCoords(conf_str[i + 1], conf_str[i + 2]))
      return false;
  }  
  
  return true;
}
  

//------------------------------------------------------------------------------
bool GameSetup::checkCoords(char col, char row)
{
  if(!(col >= 'a' && col <= 'h'))
    return false;
  
  if(!(row >= '1' && row <= '8'))
    return false;
  
  return true;
}

//------------------------------------------------------------------------------
bool GameSetup::performSemanticAnalysis(string& conf_str)
{
  for(unsigned int i = 0; i < conf_str.size()-3; i += 3)
  {
    for(unsigned int j = i + 3; j < conf_str.size(); j += 3)
    {
      if(conf_str[i + 1] == conf_str[j + 1] && conf_str[i + 2] == conf_str[j+2])
        return false;
    }
  }
  
  return true;
}


//------------------------------------------------------------------------------
int GameSetup::buildGameEnvironment(string& conf_str, GameChess** game) 
throw (bad_alloc)
{
  try{
    
  Point bounds = {8,8};    
  *game = new GameChess(bounds);
  
  
  Player* b_player = new Player(BLACK, Player::clrs[BLACK]);
  Player* w_player = new Player(WHITE, Player::clrs[WHITE]);

  (*game)->addPlayer(b_player);
  (*game)->addPlayer(w_player);

   if(conf_str.empty())
   {   
     createDefaultSet(*b_player);
     createDefaultSet(*w_player);
     (*game)->getGameBoard()->setupDefaultBoard(*b_player, *w_player);     
   }
   else
   {  
     addPiecesToPlayers((*game)->getGameBoard(), w_player, b_player, conf_str);
   }
  }catch(bad_alloc&)
  {
    throw;
  }
  return SUCCESS;
}
  
  
//------------------------------------------------------------------------------
int GameSetup::createDefaultSet(Player& player) throw (bad_alloc)
{
  try{
      player.addPieceToSet(new PieceRook());
      player.addPieceToSet(new PieceKnight());
      player.addPieceToSet(new PieceBishop());
      
      if(player.getColor() == WHITE)
      {
          PieceKing* king = new PieceKing();
          player.setKing(king);
          player.addPieceToSet(king);
          player.addPieceToSet(new PieceQueen());
      }
      else
      {
          player.addPieceToSet(new PieceQueen());
          PieceKing* king = new PieceKing();
          player.setKing(king);
          player.addPieceToSet(king);
      }
      
      player.addPieceToSet(new PieceBishop());
      player.addPieceToSet(new PieceKnight());
      player.addPieceToSet(new PieceRook());
      
      for(int i = 0; i < 8; i++)
      {
          player.addPieceToSet(new PiecePawn());
      }
  }catch(bad_alloc)
  {
      throw;
  }
  
  return SUCCESS;
}

//------------------------------------------------------------------------------
int GameSetup::addPiecesToPlayers(Board* board, Player* white, 
                                  Player* black, string& conf_str)
{
  Piece *p = NULL;
  Field* f = NULL;

  for(unsigned int i = 0; i < conf_str.size(); i += 3)
  {
  p = getPieceObject(conf_str[i]);
  
  if(conf_str[i] < 97)
  {  
    white->addPieceToSet(p);
    if(p->getPieceId() == KING)
    white->setKing(p);
  }
  else
  {
    black->addPieceToSet(p);
    if(p->getPieceId() == KING)
    black->setKing(p);
  }

  f= board->getField(conf_str[i + 1], conf_str[i + 2]);
  f->setCurrentPiece(p);
  }

  return SUCCESS;
}

//------------------------------------------------------------------------------
Piece* GameSetup::getPieceObject(char& piece_type)
{
  Piece* piece=NULL;
  
  char temp = piece_type;
  
  if(temp > 97)
  temp -= 32;

  switch(temp)
  {
  case 'R' :
    piece = new PieceRook();
    break;

  case 'N' :
    piece = new PieceKnight();
    break;    

  case 'Q' :
    piece = new PieceQueen();
    break;

  case 'K' :
    piece = new PieceKing();
    break;     

  case 'B' :
    piece = new PieceBishop();
    break;
  case 'P' :
    piece = new PiecePawn();
    break;     
  }

  return piece;
}

