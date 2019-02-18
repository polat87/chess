//------------------------------------------------------------------------------
// FileManager.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include "FileManager.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>

using std::ofstream;
using std::vector;
using std::string;

//------------------------------------------------------------------------------
FileManager::FileManager()
{
    
}

//------------------------------------------------------------------------------  
FileManager::~FileManager()
{
}


//------------------------------------------------------------------------------
int FileManager::saveDataToFile(Game& board, string& filename)
{
  ofstream out;
  time_t curr;
  tm local;
  time(&curr); 
  local=*(localtime(&curr)); 
  int s = 0;
  
  out.open(filename.c_str());
  
  if (out.is_open())
  {
      out << "[Event \""  << board.getActivePlayer()->getName() << " vs. ";
      out << board.getEnemy()->getName() << "\"]\n"; 
      out << "[Site \"Graz University of Technology, Austria\"] \n";
      out << "[Date \"" << local.tm_year + 1900 << ".";
      
      if(local.tm_mon<10)
      {
          out << "0" << local.tm_mon << "."; 
      }
      else
          out << local.tm_mon << "."; 
      
      out << local.tm_mday << "\"] \n";
      out << "[Round \"1\"] \n";
      out << "[White \"" << board.getActivePlayer()->getName() << "\"] \n";
      out << "[\"Black \"" << board.getEnemy()->getName() << "\"] \n";
      out << "[Result \"" << getResult(board) << "\"] \n";
      
      unsigned i,j=1;
      vector<string> data = board.getHistory();
      
      for(i=0; i < data.size(); i++)
      {
          if((s + data[i].size() + 3) >= 80)
          {
              out << "\n";
              s = 0;
          }
          
          if(!(i%2))
          {
              out <<  j++ << ". " << data[i];
              s += 3 + data[i].size();
          }
          else
          {
              out << " " << data[i] << " ";
              s += 2 + data[i].size();
          }
      }
      
      std::cout << "Game saved.\n";
  }
  else
      std::cout << "Error: Cannot save to file [" << filename << "].\n"; 

  out.close();
  
  return 0;
}

//------------------------------------------------------------------------------
string FileManager::getResult(Game& board)
{
    string result;
    int val = board.gameState();
    int win;

    if((win = board.getWinner()) >= 0)
    {
        if(win==0)
            result.append("0-1");
        else if(win==1)
            result.append("1-0");
        else
            result.append("1/2-1/2");
    }
    else if(val == RUNNING)
        result.append("*");

    return result;
}

