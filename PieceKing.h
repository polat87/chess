//------------------------------------------------------------------------------
// PieceKing.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//
 
#ifndef PIECEKING_H_INCLUDED
#define PIECEKING_H_INCLUDED

#include "Piece.h"

class PieceKing: public Piece
{    
  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    PieceKing (const PieceKing& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    PieceKing& operator= (const PieceKing& original);    
 
  public:
      
    //--------------------------------------------------------------------------
    // Constructor
    //
    PieceKing();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~PieceKing();
    
     //--------------------------------------------------------------------------
    // structs to move the king
    // @params gets the Field and steps to move 
    //
    virtual int move(Field& target);
    
    int moveVertical(Field* target);
    int moveHorizontal(Field* target);
    int moveAcross(Field* target);
    
    
};

#endif //PIECEKING_H_INCLUDED


