//------------------------------------------------------------------------------
// CommandEcho.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef COMMANDECHO_H
#define COMMANDECHO_H

#include "Command.h"

class CommandEcho: public Command
{
  private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    CommandEcho (const CommandEcho& original);
        
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    CommandEcho& operator= (const CommandEcho& original);
    
  public:
    //--------------------------------------------------------------------------
    // Constructor        
    //
    CommandEcho(string name);
    
    //--------------------------------------------------------------------------
    // Destructor 
    //
    virtual ~CommandEcho();

    //--------------------------------------------------------------------------
    // Executes the action.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the action
    //
    int execute(Game& board, vector<string>& params);
};

#endif  /* COMMANDECHO_H */


