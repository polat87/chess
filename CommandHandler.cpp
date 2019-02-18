//------------------------------------------------------------------------------
// CommandHandler.cpp
//
//
//
// Authors: 
// Goekhan Polat 0830690
//
//------------------------------------------------------------------------------
//

#include <memory>

#include "CommandHandler.h"
#include "UserInterface.h"
#include "Game.h"

#include "Command.h"
#include "CommandStatus.h"
#include "CommandView.h"
#include "CommandEcho.h"
#include "CommandQuit.h"
#include "CommandDraw.h"
#include "CommandHistory.h"
#include "CommandMove.h"
#include "CommandSave.h"
#include "CommandSetName.h"


using std::auto_ptr;

//------------------------------------------------------------------------------
const char* CommandHandler::cmds_name[] = {"status", "view", "echo", "quit",
                       "setname", "save", "move", "draw",
                       "history"}; 


//------------------------------------------------------------------------------
int CommandHandler::handleCommand(Game& board)
{
  int ret_val;
  vector<string> params;
  int cmd_id;
  string command = UserInterface::readString();

  if(!UserInterface::getToken(command, params))
  return NO_CMD;

  if((cmd_id = isCmdValid(command)) == -1)
  return ERR_CMD;
  
  if(cmd_id == MOVE)
  {
    if(board.gameState() == OVER)
      return GAME_FINISHED;      
    auto_ptr<Command> cmd (new CommandMove(cmds_name[MOVE]));
    ret_val = cmd->execute(board, params);    
  }    
  else if(cmd_id == DRAW)
  {
    auto_ptr<Command> cmd (new CommandDraw(cmds_name[DRAW]));
    ret_val = cmd->execute(board, params);
  } 
  else if(cmd_id == ECHO)
  {
      if(params.size() != 1)
          return ERR_USE;      
      auto_ptr<Command> cmd (new CommandEcho(cmds_name[ECHO]));
      ret_val = cmd->execute(board, params);
  }    
  else if(cmd_id == SETNAME)
  {
      if(params.size() != 1)
          return ERR_USE;      
    auto_ptr<Command> cmd (new CommandSetName(cmds_name[SETNAME]));
    ret_val = cmd->execute(board, params);
  }
  else if(cmd_id == SAVE)
  {
    auto_ptr<Command> cmd (new CommandSave(cmds_name[SAVE]));
    ret_val = cmd->execute(board, params);
  }
  else if(cmd_id == STATUS)
  {
    if(!params.empty())
      return ERR_USE;    
    auto_ptr<Command> cmd (new CommandStatus(cmds_name[STATUS]));
    ret_val = cmd->execute(board, params);
  }
  else if(cmd_id == VIEW)
  {
    if(!params.empty())
      return ERR_USE;    
    auto_ptr<Command> cmd (new CommandView(cmds_name[VIEW]));
    ret_val = cmd->execute(board, params);
  }
  else if(cmd_id == HISTORY)
  {
    if(!params.empty())
      return ERR_USE;    
    auto_ptr<Command> cmd (new CommandHistory(cmds_name[HISTORY]));
    ret_val = cmd->execute(board, params);
  }
  else
  {
    if(!params.empty())
      return ERR_USE;    
    auto_ptr<Command> cmd (new CommandQuit(cmds_name[QUIT]));
    ret_val = cmd->execute(board, params);      
  }    
  
  return ret_val;
}

//------------------------------------------------------------------------------
int CommandHandler::isCmdValid(string command)
{
  for(int i = 0; i < 9; i++)
  {
  if(areEqual(cmds_name[i], command))
    return i;
  }
  
  return -1;
}  

//------------------------------------------------------------------------------
bool CommandHandler::areEqual(string origin, string input)
{
  if(origin.size() != input.size())
  return false;

  char temp;
  
  for(unsigned int i = 0; i < origin.size(); i++)
  {
  temp = input[i];
  
  if((origin[i] != temp) && (origin[i] != temp + 32))
    return false;
  }

  return true;
}


