//------------------------------------------------------------------------------
// Player.h
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

class Piece;

using std::vector;
using std::string;

typedef enum _Color_ 
{
    BLACK, WHITE, RED, GREEN, BLUE, YELLOW, ORANGE, BROWN
}Color;


class Player
{
  private:

    //--------------------------------------------------------------------------
    // Color of the player
    //
    Color color_;

    //--------------------------------------------------------------------------
    // Name of the player
    //
    string name_;

    //--------------------------------------------------------------------------
    // set of pieces for the player
    //
    vector<Piece*> piece_set_;
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Player (const Player& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Player& operator= (const Player& original);
    
    Piece* king_;

  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    Player(Color color, const string& name);

    //--------------------------------------------------------------------------
    // Destructor
     //
    ~Player();

    //--------------------------------------------------------------------------
    // Setter methods    
    //
    void setName(const string& name);
    void setColor(Color color);
    void addPieceToSet(Piece* piece);
    void setKing(Piece* piece);
    
    //--------------------------------------------------------------------------
    // Getter methods
    //
    string getName();
    Color getColor();
    string getFullName();
    vector<Piece*> getPieceSet();
    Piece* getKing();
    
    //--------------------------------------------------------------------------
    // Colors    
    //
    static const char* clrs[8];

};

#endif  /* PLAYER_H */




