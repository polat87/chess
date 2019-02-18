//------------------------------------------------------------------------------
// Action.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED


#include <iostream>
#include <string>

class Field;
class Piece;
class Board;

using std::string;


//-----------------------------------------------------------------------------
// Action Class
// class to create an Action
//
class Action
{
    private:

    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Action(const Action& source); 

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Action &operator=(const Action& source);
    
    Field& start_;
    Field& target_;
    
    string movement_;

public:

    //--------------------------------------------------------------------------
    // Constructor        
    //
    Action(Field& start, Field& target);

    //--------------------------------------------------------------------------
    // Destructor        
    //
    ~Action();

    //--------------------------------------------------------------------------
    // Handles the commands given by user.
    // @param board The board where action should be performed on
    // @return Integer representing the success of the or error 
    //
    
    
    //--------------------------------------------------------------------------
    // getter        
    //
    Field& getStart();
    Field& getTarget();
    string& getMovement();
    
    //--------------------------------------------------------------------------
    // for execute        
    //
    int execute();
    
    //--------------------------------------------------------------------------
    // check if are same targets
    // return ture or false      
    //
    bool sameTypes();
    
    //--------------------------------------------------------------------------
    // check if the target is free
    // return ture or false
    //
    bool isTargetFree();
    
    //--------------------------------------------------------------------------
    // detroy the piece        
    //
    int destroyPiece();
    
    //--------------------------------------------------------------------------
    // to note the movement of the piece        
    //
    void noteMovement(); 
    
};

#endif //ACTION_H_INCLUDED

