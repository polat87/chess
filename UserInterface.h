//------------------------------------------------------------------------------
// UserInterface.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using std::string;
using std::vector;

class UserInterface
{
  private:
      
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    UserInterface(const UserInterface& source); 

    //--------------------------------------------------------------------------
    // Private assignment operator      
    //
    UserInterface &operator=(const UserInterface& source);    

  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    UserInterface();
    
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~UserInterface();
    
    //--------------------------------------------------------------------------
    // Reads string from standard input.      
    //
    static string readString();
 
    //--------------------------------------------------------------------------
    // Splits a string in commands and in paramaters.     
    static bool getToken(string& command, vector<string>& tokens);

};

#endif  /* USERINTERFACE_H */


