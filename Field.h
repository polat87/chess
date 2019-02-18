//------------------------------------------------------------------------------
// Field.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef FIELD_H
#define FIELD_H

class Piece;

class Field
{
  private:
       
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Field(const Field& source); 

    //--------------------------------------------------------------------------
    // Private assignment operator      
    //
    Field &operator=(const Field& source);
    
    //--------------------------------------------------------------------------
    // points to the piece which on this     
    //    
    Piece* current_piece_;

    //--------------------------------------------------------------------------
    // show if the field is taken     
    //    
    bool is_taken_;
    
    //--------------------------------------------------------------------------
    // saves the next reachable field of this field     
    //    
    Field* up_;
    Field* down_;
    Field* left_;
    Field* right_;
    Field* up_left_; 
    Field* up_right_; 
    Field* down_left_; 
    Field* down_right_; 

    //--------------------------------------------------------------------------
    // saves the own position   
    //    
    char x_;
    char y_;
    
    
  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    Field(char x, char y);
    
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Field();
    
    
    
    //--------------------------------------------------------------------------
    // getters
    //
    Piece* getCurrentPiece();
    bool isTaken();
    void setTaken();
    char x();
    char y();
    
    Field* up();
    Field* down();
    Field* left();
    Field* right();
    Field* upLeft();
    Field* upRight();
    Field* downLeft();
    Field* downRight();
    
    //--------------------------------------------------------------------------
    // setters
    //
    void setCurrentPiece(Piece* piece);
    void setUp(Field* field);
    void setDown(Field* field);
    void setLeft(Field* field);
    void setRight(Field* field);
    void setUpLeft(Field* field);
    void setUpRight(Field* field);
    void setDownLeft(Field* field);
    void setDownRight(Field* field);   
    
};



#endif  /* FIELD_H */

