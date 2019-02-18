//------------------------------------------------------------------------------
// PieceKnight.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//
 
#ifndef PIECEKNIGHT_H_INCLUDED
#define PIECEKNIGHT_H_INCLUDED

#include "Piece.h"

class PieceKnight: public Piece
{
  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    PieceKnight (const PieceKnight& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    PieceKnight& operator= (const PieceKnight& original);    

  public:
      
    //--------------------------------------------------------------------------
    // Constructor
    //
    PieceKnight();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~PieceKnight();
       
    //--------------------------------------------------------------------------
    // structs to move the Knight
    // @params gets the Field for moving
    //
    virtual int move(Field& target);
    
    //--------------------------------------------------------------------------
    // structs to check if the move is posible
    // @params gets the Field for check
    //
    int calcPossibility(Field* target);    
    
};

#endif //PIECEKNIGHT_H_INCLUDED


