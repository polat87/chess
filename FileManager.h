//------------------------------------------------------------------------------
// FileManager.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Game;

using std::string;

class FileManager
{
    private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    FileManager(const FileManager& source); 

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    FileManager &operator=(const FileManager& source);

public:

    //--------------------------------------------------------------------------
    // Constructor        
    //
    FileManager();

    //--------------------------------------------------------------------------
    // Destructor        
    //
    ~FileManager();

    //--------------------------------------------------------------------------
    // Handles the commands given by user.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the or error 
    //
    static int saveDataToFile(Game& board, string& filename);
    
    //--------------------------------------------------------------------------
    // Returns the result of the game.
    // @param board The board to identify the result
    // @return result in form of string
    //
    static string getResult(Game& board);    
            
    
};

#endif  /* FILEMANAGER_H */

