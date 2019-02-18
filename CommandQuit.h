//------------------------------------------------------------------------------
// CommandQuit.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef COMMANDQUIT_H
#define COMMANDQUIT_H

#include "Command.h"


class CommandQuit: public Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    CommandQuit (const CommandQuit& original);
    //--------------------------------------------------------------------------
    // Private assignment operator     
    //
    CommandQuit& operator= (const CommandQuit& original);  
    
  public:
        
    //--------------------------------------------------------------------------
    // Constructor
    //
    CommandQuit(string name);

    //--------------------------------------------------------------------------
    // Destructor         
    //
    virtual ~CommandQuit();

    //--------------------------------------------------------------------------
    // Executes the action.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the action  
    //
    int execute(Game& board, vector<string>& params);
};

#endif  /* COMMANDQUIT_H */




