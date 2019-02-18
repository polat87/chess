//------------------------------------------------------------------------------
// Command.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//
 
#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "UserInterface.h"

using std::string;
using std::vector;


class Command
{
  public:
      
    //--------------------------------------------------------------------------
    // Constructor
    //
    Command(string name);

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Command();

    //--------------------------------------------------------------------------
    // Executes the action.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the action
    //
    virtual int execute(Game& board, vector<string>& params) = 0;
    
    //--------------------------------------------------------------------------
    // Getter Methods
    //
    const string& getName ();

  private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Command (const Command& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Command& operator= (const Command& original);
    
    //--------------------------------------------------------------------------
    // Name of this command
    //
    const string command_name_;
};

#endif //COMMAND_H_INCLUDED

