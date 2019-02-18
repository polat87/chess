//------------------------------------------------------------------------------
// PieceRook.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//
 
#ifndef PIECEROOK_H_INCLUDED
#define PIECEROOK_H_INCLUDED

#include "Piece.h"

class PieceRook: public Piece
{
  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    PieceRook (const PieceRook& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    PieceRook& operator= (const PieceRook& original);    

  public:
      
    //--------------------------------------------------------------------------
    // Constructor
    //
    PieceRook();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~PieceRook();

    //--------------------------------------------------------------------------
    // structs to move the Knight
    // @params gets the Field for moving
    //
    virtual int move(Field& target);
    int moveUp(Field* target, unsigned& steps);
    int moveDown(Field* target, unsigned& steps);
    int moveRight(Field* target, unsigned& steps);
    int moveLeft(Field* target, unsigned& steps);        

};

#endif //PIECEROOK_H_INCLUDED


