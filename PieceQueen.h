//------------------------------------------------------------------------------
// PieceQueen.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//
 
#ifndef PIECEQUEEN_H_INCLUDED
#define PIECEQUEEN_H_INCLUDED

#include "Piece.h"
#include "PieceRook.h"
#include "PieceBishop.h"

class PieceQueen: public Piece
{   
  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    PieceQueen (const PieceQueen& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    PieceQueen& operator= (const PieceQueen& original); 
 
  public:
      
    //--------------------------------------------------------------------------
    // Constructor
    //
    PieceQueen();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~PieceQueen();    
    
    //--------------------------------------------------------------------------
    // structs to move the Knight
    // @params gets the Field for moving
    //
    virtual int move(Field& target);
   
    int moveUp(Field* target, unsigned& steps);
    int moveDown(Field* target, unsigned& steps);
    int moveRight(Field* target, unsigned& steps);
    int moveLeft(Field* target, unsigned& steps);
    
    int moveRightUp(Field* target, unsigned& steps);
    int moveLeftUp( Field* target, unsigned& steps);
    int moveRightDown(Field* target, unsigned& steps);
    int moveLeftDown(Field* target, unsigned& steps);    
  
    
};

#endif //PIECEQUEEN_H_INCLUDED


