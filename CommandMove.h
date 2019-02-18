//------------------------------------------------------------------------------
// CommandMove.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef COMMANDMOVE_H
#define COMMANDMOVE_H

#include "Command.h"


class CommandMove: public Command
{
  private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    CommandMove (const CommandMove& original);
        
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    CommandMove& operator= (const CommandMove& original);
    
  public:
    //--------------------------------------------------------------------------
    // Constructor        
    //
    CommandMove(string name);
    
    //--------------------------------------------------------------------------
    // Destructor 
    //
    virtual ~CommandMove();

    //--------------------------------------------------------------------------
    // Executes the action.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the action
    //
    int execute(Game& board, vector<string>& params);
    
    //--------------------------------------------------------------------------
    // check if the move is valid 
    //
    bool checkIfCoordsValid(string& param);    

};

#endif  /* COMMANDMOVE_H */


