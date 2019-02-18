//------------------------------------------------------------------------------
// CommandDraw.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef COMMANDDRAW_H
#define COMMANDDRAW_H

#define DRAW_USAGE "Usage: draw [decline].\n"
#define DRAW_DECLINE " declined the draw offer.\n"
#define END_DRAW "The game ends in a draw.\n"
#define NO_OFFER "Error: No draw offered.\n"
#define SUGGEST " suggests a draw.\n"
#define UNANS_OFFER "Error: Unanswered draw offer.\n" 

#include "Command.h"

class CommandDraw: public Command
{
  private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    CommandDraw (const CommandDraw& original);
        
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    CommandDraw& operator= (const CommandDraw& original);
    
    
  public:
    //--------------------------------------------------------------------------
    // Constructor        
    //
    CommandDraw(string name);
    
    //--------------------------------------------------------------------------
    // Destructor 
    //
    virtual ~CommandDraw();

    //--------------------------------------------------------------------------
    // Executes the action.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the action
    //
    int execute(Game& board, vector<string>& params);
    
    //--------------------------------------------------------------------------
    // getter 
    //
    bool getAnswer(vector<string>& param);
    
};

#endif  /* COMMANDDRAW_H */


