//------------------------------------------------------------------------------
// PieceBishop.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//
 
#ifndef PIECEBISHOP_H_INCLUDED
#define PIECEBISHOP_H_INCLUDED

#include "Piece.h"

class PieceBishop: public Piece
{
   
  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    PieceBishop (const PieceBishop& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    PieceBishop& operator= (const PieceBishop& original);   

  public:
      
    //--------------------------------------------------------------------------
    // Constructor
    //
    PieceBishop();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~PieceBishop();

    //--------------------------------------------------------------------------
    // structs to move the Bishop
    // @params gets the Field and steps to move 
    //
    virtual int move(Field& target);      

    int moveRightUp(Field* target, unsigned& steps);
    int moveLeftUp(Field* target, unsigned& steps);
    int moveRightDown(Field* target, unsigned& steps);
    int moveLeftDown(Field* target, unsigned& steps);
    
  
    
};

#endif //PIECEBISHOP_H_INCLUDED


