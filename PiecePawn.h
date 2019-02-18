//------------------------------------------------------------------------------
// PiecePawn.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef PIECEPAWN_H_INCLUDED
#define PIECEPAWN_H_INCLUDED

#include "Piece.h"

class PiecePawn: public Piece
{
    
  public:
      
    //--------------------------------------------------------------------------
    // Constructor
    //
    PiecePawn();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~PiecePawn();
    
    //--------------------------------------------------------------------------
    // structs to move the Knight
    // @params gets the Field for moving
    //
    virtual int move(Field& target);
    int moveStraight(Field* target, unsigned y_distance);
    int moveAcross(Field* target);
    
    //--------------------------------------------------------------------------
    // setter method
    //
    void setStartPos(bool pos);
    
    //--------------------------------------------------------------------------
    // check if the piece is on start position
    //
    bool onStartPos();

  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    PiecePawn (const PiecePawn& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    PiecePawn& operator= (const PiecePawn& original);    
    
    //--------------------------------------------------------------------------
    // check if the piece is on start position
    //
    bool start_pos_;
    
    friend class PieceQueen;
    
};

#endif //PIECEPAWN_H_INCLUDED


