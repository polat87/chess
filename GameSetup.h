//------------------------------------------------------------------------------
// GameSetup.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef GAMESETUP_H
#define GAMESETUP_H

#include <iostream>
#include <string>
#include <exception>

#include "GameChess.h"

#define ERR_STR_INV -3
#define ERR_STR_COR -4
#define SUCCESS 0

using std::string;
using std::bad_alloc;

class GameChess;


class GameSetup
{
  private:
      
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    GameSetup(const GameSetup& source); 

    //--------------------------------------------------------------------------
    // Private assignment operator      
    //
    GameSetup &operator=(const GameSetup& source);    
    
    
  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    GameSetup();
    
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~GameSetup();
    
    //--------------------------------------------------------------------------
    // checks config string.      
    //
    static int checkConfigString(string& conf_str);

    
    //--------------------------------------------------------------------------
    // matches given type for the Initials of pieces.      
    //    
    static bool checkPieceType(char type);


    //--------------------------------------------------------------------------
    // performs syntax analysis for given string.      
    //       
    static bool performSyntaxAnalysis(string& conf_str);

    //--------------------------------------------------------------------------
    // checks if coordinates are true.    
    //           
    static bool checkCoords(char col, char row);

    //--------------------------------------------------------------------------
    // performs semantic analysis.  
    //               
    static bool performSemanticAnalysis(string& conf_str);
    
    //--------------------------------------------------------------------------
    // sets the game if everything is ok.      
    //       
    static int initGameBoard(string& conf_str);

    //--------------------------------------------------------------------------
    // creates the game      
    //       
    static int buildGameEnvironment(string& conf_str, GameChess** game) 
               throw (bad_alloc);    
    
    
    //--------------------------------------------------------------------------
    // adds pieces to the game      
    //       
    static int addPiecesToPlayers(Board* board, Player* white, 
                                  Player* black, string& conf_str);
    
    
    //--------------------------------------------------------------------------
    // constructs board for the game      
    //       
    static int createDefaultSet(Player& player) throw (bad_alloc);
    
    //--------------------------------------------------------------------------
    // returns an object of piece      
    //       
    static Piece* getPieceObject(char& piece_type);    
    
    
};


#endif /* GAMESETUP_H */

