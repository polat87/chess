//------------------------------------------------------------------------------
// UserInterface.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "UserInterface.h"

using std::cin;

//------------------------------------------------------------------------------
UserInterface::UserInterface()
{
}

//------------------------------------------------------------------------------
UserInterface::~UserInterface()
{
}

//------------------------------------------------------------------------------
string UserInterface::readString()
{
  string input;
  getline(cin, input);
  
  return input;
}

//------------------------------------------------------------------------------
bool UserInterface::getToken(string& command, vector<string>& tokens)
{
    string temp;
    bool empty = true;
    
    for(unsigned i = 0; i < command.length(); i++)
    {
        if(command[i] == ' ')
        {           
            tokens.push_back(temp);
            temp.clear();
        }
        else
        {
            temp.push_back(command[i]);
            if(empty)
               empty = false; 
        }
    }
    
    if(empty)
        return false;
    
    tokens.push_back(temp);    
    command.clear();
    command = tokens[0];
    tokens.erase(tokens.begin()); 

    
  return true;
}
