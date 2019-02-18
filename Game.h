//------------------------------------------------------------------------------
// Game.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <string>
#include "Player.h"

class Action;
class Piece;
class Player;
class Board;

using std::vector;
using std::string;


typedef enum _States_
{
    RUNNING = 20, STALEMATE, WIN, SHAH, OVER
}States;


typedef struct _Point_
{
  int x_coord;
  int y_coord;
}Point;


class Game
{
      
  private:
    //-------------------------------------------------------------------------
    // Offset to add at calculation
    //
    Point bounds_;
 
    //--------------------------------------------------------------------------
    // name of the row
    //
    char first_row_name_;
    
    //--------------------------------------------------------------------------
    // name of the column
    //
    char first_column_name_;
    
    //--------------------------------------------------------------------------
    // store increase of the row
    //
    bool increase_row_char_;
    
    //--------------------------------------------------------------------------
    // store increase of the column
    //
    bool increase_column_char_;
    
    //--------------------------------------------------------------------------
    // pieces of the game
    //
    Board* game_board_;
    
    


protected:
    //--------------------------------------------------------------------------
    // active player
    //
    Player* active_player_;        

    //--------------------------------------------------------------------------
    // players of the game
    //
    vector<Player*> players_;

    //--------------------------------------------------------------------------
    // saves the history of moves
    //
    vector<string> history_;

    
    //--------------------------------------------------------------------------
    // show status of the game
    //
    int game_status_;
    
    //--------------------------------------------------------------------------
    // offer a draw
    //
    bool draw_offer_;    

    //--------------------------------------------------------------------------
    // saves the identity of winner in case of win
    //
    int winner_;      

    
   public:
    
    //---------------------------------------------------------------------------
    // Constructor
    //
    Game(Point& bounds, char first_row_name,
     char first_column_name, bool increase_row_char,
     bool increase_column_char);

    //---------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Game();
    
    
    //---------------------------------------------------------------------------
    // The game will be run.
    // @return 0 if the game is over 
    //
    virtual int run() = 0;
    
    //---------------------------------------------------------------------------
    // Shows the active state of the game-board.
    //
    void showBoard();

    //--------------------------------------------------------------------------
    // Prints separation line for the board.
    //
    void printSepLine(int width);

    //---------------------------------------------------------------------------
    // Shows the full name of the active player on game.
    //
    void getStatus();

    //--------------------------------------------------------------------------
    // Setter Methods.
    //
    void addPlayer(Player* player);

    //--------------------------------------------------------------------------
    // Getter Methods.
    //
    bool getIncColChar();
    bool getIncRowChar();
    char getFirstRowName();
    char getFirstColName();
    Player* getActivePlayer();
    Player* getEnemy();
    Point getBounds();
    Board* getGameBoard();
    vector<string> getHistory();
    int showHistory(); 
    
       
    
    //---------------------------------------------------------------------------
    // setter
    // 
    //    
    void addToHistory(string& draw); 
    void setDrawOffer(bool val);
    void changeTurn();
    void setGameStatus(int state);
    
    //---------------------------------------------------------------------------
    // check if a player offered a draw
    // 
    bool isDrawOffered();
    
    int gameState();
    
    void setWinner(int winner);    
    int getWinner();
};

#endif  /* GAME_H */

