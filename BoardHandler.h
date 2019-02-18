//------------------------------------------------------------------------------
// BoardHandler.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef BOARDHANDLER_H
#define BOARDHANDLER_H

#include <vector>
#include <string>
class Game;
class Action;
class Field;
class Player;

using std::vector;
using std::string;

#define SACRIFICE "Error: No sacrifice allowed.\n" 


class BoardHandler
{
    private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    BoardHandler(const BoardHandler& source); 

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    BoardHandler &operator=(const BoardHandler& source);

public:

    //--------------------------------------------------------------------------
    // Constructor        
    //
    BoardHandler();

    //--------------------------------------------------------------------------
    // Destructor        
    //
    ~BoardHandler();

    //--------------------------------------------------------------------------
    // Handles the commands given by user.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the or error 
    //
    static int performAction(Game& board, string& start, string& target);
    
    //--------------------------------------------------------------------------
    // check if shah
    // @param Fiel
    // @return Integer representing the success of the or error 
    //
    static bool checkShah(Field& start, Field* king);
    static bool checkMate(Player* active, Field* king);
    static vector<Field*> calcNeighboursOfKing(Field* king);
    static bool isStaleMate(Player* active, Field* king);
    static bool isLegalMove(Field* start, Field* target, Player* enemy);    
    

};

#endif  /* BOARDHANDLER_H */

