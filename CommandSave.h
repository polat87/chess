//------------------------------------------------------------------------------
// CommandSave.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef COMMANDSAVE_H
#define COMMANDSAVE_H

#include "Command.h"

class CommandSave: public Command
{
  private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    CommandSave (const CommandSave& original);
        
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    CommandSave& operator= (const CommandSave& original);
    
  public:
    //--------------------------------------------------------------------------
    // Constructor        
    //
    CommandSave(string name);
    
    //--------------------------------------------------------------------------
    // Destructor 
    //
    virtual ~CommandSave();

    //--------------------------------------------------------------------------
    // Executes the action.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the action
    //
    int execute(Game& board, vector<string>& params);
};

#endif  /* COMMANDSAVE_H */


