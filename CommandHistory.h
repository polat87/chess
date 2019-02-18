//------------------------------------------------------------------------------
// CommandHistory.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef COMMANDHISTORY_H
#define COMMANDHISTORY_H

#include "Command.h"

class CommandHistory: public Command
{
  private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    CommandHistory (const CommandHistory& original);
        
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    CommandHistory& operator= (const CommandHistory& original);
    
  public:
    //--------------------------------------------------------------------------
    // Constructor        
    //
    CommandHistory(string name);
    
    //--------------------------------------------------------------------------
    // Destructor 
    //
    virtual ~CommandHistory();

    //--------------------------------------------------------------------------
    // Executes the action.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the action
    //
    int execute(Game& board, vector<string>& params);
};

#endif  /* COMMANDHISTORY_H */


