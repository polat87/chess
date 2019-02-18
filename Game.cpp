//------------------------------------------------------------------------------
// Game.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "Game.h"
#include "Player.h"
#include "Piece.h"
#include "Action.h"
#include "UserInterface.h"
#include "CommandHandler.h"
#include "Board.h"
#include "Field.h"


//------------------------------------------------------------------------------
Game::Game(Point& bounds, char first_row_name,
  char first_column_name, bool increase_row_char,
  bool increase_column_char):
  bounds_(bounds),
  first_row_name_(first_row_name),
  first_column_name_(first_column_name),
  increase_row_char_(increase_row_char),
  increase_column_char_(increase_column_char),
  game_status_(RUNNING),        
  draw_offer_(false),
  winner_(-1)
{
  game_board_ = new Board(bounds.x_coord*bounds.y_coord);

}

//------------------------------------------------------------------------------
Game::~Game()
{
  vector<Player*>::iterator pl_it;
  vector<Piece*>::iterator pi_it;
  
  for(pl_it = players_.begin(); pl_it < players_.end(); pl_it++)
  {
    vector<Piece*> piece_set = (*pl_it)->getPieceSet();
    
    for(pi_it = piece_set.begin(); pi_it != piece_set.end(); pi_it++)
    {
      delete *pi_it;
    }
    
  delete *pl_it;
  }
  
  delete game_board_;
}

//------------------------------------------------------------------------------
Player* Game::getActivePlayer()
{
  return active_player_;
}

Player* Game::getEnemy()
{
  if(active_player_ == players_[0])
    return players_[1];
  else
    return players_[0];  
}
  
//------------------------------------------------------------------------------
Point Game::getBounds()
{
  return bounds_;
}

  
//------------------------------------------------------------------------------
void Game::addPlayer(Player* player)
{
  if(player->getColor() == WHITE)
    active_player_ = player;
  
  players_.push_back(player);
}

//------------------------------------------------------------------------------
void Game::showBoard()
{
  char first_col = first_column_name_;

  std::cout << " |";

  for(int i = 0; i < bounds_.x_coord; i++)
  {
  first_col += (i == 0 ? 0 : (1*(increase_column_char_ ? 1: -1)));    
  std::cout << first_col << "|";
  }
  
  std::cout << " \n";  
  printSepLine(bounds_.x_coord + 1);
  
  char first_row = first_row_name_;
 
  vector<Field*> fields = this->getGameBoard()->getFields();
  vector<Field*>::iterator it = fields.begin();
  
  char letter;
  int id;
  
  for(int i = 0; i < bounds_.y_coord; i++)
  {
  first_row += (i == 0 ? 0 : (1*(increase_row_char_? 1: -1))); 
  std::cout << first_row << "|";
    
  for(int j = 0; j < bounds_.y_coord; j++)
  {
    if((*it)->isTaken())
    {
      id = (*it)->getCurrentPiece()->getPieceId();
      letter = Piece::p_types_[id];

      if((*it)->getCurrentPiece()->getPlayer()->getColor() == BLACK)
        letter += 32;
      std::cout << letter << "|";
    }
    else
      std::cout << " |";      

    (*it++);
  }

  std::cout << " \n";
  printSepLine(bounds_.y_coord + 1);
  }

}
  
//------------------------------------------------------------------------------
void Game::printSepLine(int width)
{
  for(int i = 0; i < width; i++)
  {
  std::cout << "-+";
  }
  std::cout << " \n";    
}

//------------------------------------------------------------------------------
void Game::getStatus()
{
  std::cout << "current player: "<< getActivePlayer()->getFullName() << "\n";
}
  
//------------------------------------------------------------------------------
int Game::showHistory()
{
  
  unsigned i,j = 1;
  
  for(i = 0; i < history_.size(); i++)
  {
    if(!(i % 2))
    std::cout << j++ << "." << history_[i];
    else
    std::cout  << " " <<  history_[i] << "\n";
  }
  
  if(history_.size() % 2)
      std::cout << "\n";  
  
  return 0;
}

//------------------------------------------------------------------------------
void Game::addToHistory(string& draw)
{
  
  history_.push_back(draw);
}

//------------------------------------------------------------------------------
void Game::changeTurn()
{
  if(active_player_ == players_[0])
    active_player_ = players_[1];
  else
    active_player_ = players_[0];
}

//------------------------------------------------------------------------------
void Game::setDrawOffer(bool val)
{
    draw_offer_ = val;   
    this->changeTurn();
}  

//------------------------------------------------------------------------------
int Game::gameState()
{
  return game_status_;
}

//------------------------------------------------------------------------------
void Game::setGameStatus(int state)
{
  game_status_ = state;
}

//------------------------------------------------------------------------------
bool Game::isDrawOffered()
{
  return draw_offer_;
}

//------------------------------------------------------------------------------
bool Game::getIncColChar()
{
  return increase_column_char_;
}

//------------------------------------------------------------------------------
bool Game::getIncRowChar()
{
  return increase_row_char_;
}

//------------------------------------------------------------------------------
char Game::getFirstRowName()
{
  return first_row_name_;
}

//------------------------------------------------------------------------------
char Game::getFirstColName()
{
  return first_column_name_;
}

//------------------------------------------------------------------------------
Board* Game::getGameBoard()
{
  return game_board_;
}

//------------------------------------------------------------------------------
vector<string> Game::getHistory()
{
  return history_;
}

//------------------------------------------------------------------------------
void Game::setWinner(int winner)
{
    winner_ = winner;
}


//------------------------------------------------------------------------------
int Game::getWinner()
{
    return winner_;
}

