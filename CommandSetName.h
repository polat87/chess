//------------------------------------------------------------------------------
// CommandSetName.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef COMMANDSETNAME_H
#define COMMANDSETNAME_H

#include "Command.h"

class CommandSetName: public Command
{
  private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    CommandSetName (const CommandSetName& original);
        
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    CommandSetName& operator= (const CommandSetName& original);
    
  public:
    //--------------------------------------------------------------------------
    // Constructor        
    //
    CommandSetName(string name);
    
    //--------------------------------------------------------------------------
    // Destructor 
    //
    virtual ~CommandSetName();

    //--------------------------------------------------------------------------
    // Executes the action.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the action
    //
    int execute(Game& board, vector<string>& params);
};

#endif  /* COMMANDSETNAME_H */


