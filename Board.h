//------------------------------------------------------------------------------
// Board.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Player;
class Field;
class Piece;


class Board
{
  private:
      
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Board(const Board& source); 

    //--------------------------------------------------------------------------
    // Private assignment operator      
    //
    Board &operator=(const Board& source);    

    //--------------------------------------------------------------------------
    // bitmap for the board and move algorithms
    //
    bool board_map_[8][8];
    
    //--------------------------------------------------------------------------
    // container for the fields
    //    
    vector<Field*> fields_;

    

  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    Board(unsigned int num);
    
    //--------------------------------------------------------------------------
    // Destructor
    //
    ~Board();
    
    //--------------------------------------------------------------------------
    // getter
    //
    vector<Field*> getFields();   
    Field* getField(char& x, char& y);
    
    //--------------------------------------------------------------------------
    // default setup for board
    //
    void setupDefaultBoard(Player& black, Player& white);

    //--------------------------------------------------------------------------
    // chains fields together
    //
    void chainFieldsTogether();    
    
    //--------------------------------------------------------------------------
    // chains left to right
    //    
    void chainLeftToRight();
    //--------------------------------------------------------------------------
    // chains right to left
    //    
    void chainRightToLeft(); 

    //--------------------------------------------------------------------------
    // chains up to down
    //    
    void chainUpToDown();
    
    //--------------------------------------------------------------------------
    // chains down top
    //
    void chainDownToUp();
    
    //--------------------------------------------------------------------------
    // chains across
    //
    void chainAcross();
    
};

#endif  /* BOARD_H */


