//------------------------------------------------------------------------------
// GameChess.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef GAMECHESS_H
#define	GAMECHESS_H

#include "Game.h"

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;


class GameChess: public Game
{
  private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    GameChess (const GameChess& original);
        
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    GameChess& operator= (const GameChess& original);  
  

  public:
      
    //---------------------------------------------------------------------------
    // Constructor
    //
    GameChess(Point& bounds);
    
    //--------------------------------------------------------------------------
    // Destructor 
    //
    virtual ~GameChess();

    //---------------------------------------------------------------------------
    // The game will be run.
    // @return 0 if the game is over 
    //
    virtual int run();
    
    int gameState();
    
    //--------------------------------------------------------------------------
    // setter methods 
    //
    void setGameStatus(int state);    
};

#endif	/* GAMECHESS_H */


