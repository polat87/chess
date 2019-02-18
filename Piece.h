//------------------------------------------------------------------------------
// Piece.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//
 
#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include "Game.h"
#include <iostream>
#include <cmath>

#define TGT_NOT_REACH -10
#define PIECE_ON_WAY  -11


class Field;
class Player;


typedef enum Chess_Pieces
{
    PAWN=0, ROOK, KNIGHT, BISHOP, KING, QUEEN
}Pieces;

class Piece
{
  protected:
    //--------------------------------------------------------------------------
    // points to the field on which the piece is set
    //      
    Field* current_field_;
    
    
    //--------------------------------------------------------------------------
    // pointer to owner
    //      
    Player* player_;   
       
        
  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Piece (const Piece& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Piece& operator= (const Piece& original);
    
    //--------------------------------------------------------------------------
    // identifies piece by number
    //      
    int piece_id_;     
    
  public:
      
    //--------------------------------------------------------------------------
    // Constructor
    //
    Piece(int id);

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Piece();
    
    virtual int move(Field& target)=0;
    
    //--------------------------------------------------------------------------
    // setters
    //
    void setCurrentField(Field* field);
    void setPlayer(Player* player);
    
            
    //--------------------------------------------------------------------------
    // getters
    //
    Field* getCurrentField();
    int getPieceId();
    Player* getPlayer();
    
    //--------------------------------------------------------------------------
    // array reserved for matches.      
    //       
    static const char p_types_[];

    //--------------------------------------------------------------------------
    // overloading operator to compare two piece objects     
    //           
    bool operator==(Piece& src);
    
    /*
bool Symbol::operator==(Symbol& rhs)const{
cout << "operator overloaded == " << rhs.name;
if (this->name==rhs.name)
return true;
return false;
}   */ 
    
};

#endif //PIECE_H_INCLUDED


