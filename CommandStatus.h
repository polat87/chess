//------------------------------------------------------------------------------
// CommandStatus.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef COMMANDSTATUS_H
#define COMMANDSTATUS_H

#include "Command.h"

class CommandStatus: public Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor    
    //
    CommandStatus (const CommandStatus& original);

    //--------------------------------------------------------------------------
    // Private assignment operator            
    //
    CommandStatus& operator= (const CommandStatus& original);        
    
  public:
    //--------------------------------------------------------------------------
    // Constructor            
    //
    CommandStatus(string name);

    //--------------------------------------------------------------------------
    // Destructor 
    //
    virtual ~CommandStatus();

    //--------------------------------------------------------------------------
    // Executes the action.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the action      
    //
    int execute(Game& board, vector<string>& params);    
};

#endif  /* COMMANDSTATUS_H */

