//------------------------------------------------------------------------------
// CommandHandler.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

#define ERR_CMD -1
#define ERR_USE -11
#define NO_CMD  -3
#define GAME_FINISHED -22


typedef enum Cmds
{
    STATUS=0, VIEW, ECHO, QUIT, SETNAME, SAVE, MOVE, DRAW, HISTORY
}Cmds;


class Game;

class CommandHandler
{
    private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    CommandHandler(const CommandHandler& source); 

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    CommandHandler &operator=(const CommandHandler& source);

public:

    //--------------------------------------------------------------------------
    // Constructor        
    //
    CommandHandler();

    //--------------------------------------------------------------------------
    // Destructor        
    //
    ~CommandHandler();

    //--------------------------------------------------------------------------
    // Handles the commands given by user.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the or error 
    //
    static int handleCommand(Game& board);

    //--------------------------------------------------------------------------
    // Checks if the command is valid.
    // @param command which should be checked
    // @return Integer representing a number for id of the command otherwise -1     
    //
    static int isCmdValid(string command);
    
    //--------------------------------------------------------------------------
    // Compares two strings of equality
    // @param two strings to be compared.
    // @return boolean true if equal otherwise false    
    //
    static bool areEqual(string str1, string str2);

    //--------------------------------------------------------------------------
    // All the command which are accepted  
    //
    static const char* cmds_name[9];    
};


#endif  /* COMMANDHANDLER_H */


