//------------------------------------------------------------------------------
// CommandView.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef COMMANDVIEW_H
#define COMMANDVIEW_H

#include "Command.h"

class CommandView: public Command
{
  private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    CommandView (const CommandView& original);

    //--------------------------------------------------------------------------
    // Private assignment operator       
    //
    CommandView& operator= (const CommandView& original);  
    
  public:
        
    //--------------------------------------------------------------------------
    // Constructor               
    //
    CommandView(string name);
    
    //--------------------------------------------------------------------------
    // Destructor 
    //
    virtual ~CommandView();
    
    //--------------------------------------------------------------------------
    // Executes the action.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the action          
    //
    int execute(Game& board, vector<string>& params);
};

#endif  /* COMMANDVIEW_H */


