#//------------------------------------------------------------------------------
#// Filename: Makefile
#// Description: Makefile for ass3
#// Authors:  Goekhan Polat 0830690, Martin Viereckl 1031014, 
#//           Clemens Stary 1131980
#// Tutor: Christoph Woergoetter
#// Group: 3955
#// Created: 09.03.2012
#// Last change: 11.03.2012
#//------------------------------------------------------------------------------


# define name of executable file 
TITLE = ass3

SUBMISSION = $(TITLE).zip

# define compiler flags 
CC = g++
CFLAGS = -Wall -o   $(DEBUG)
LDFLAGS = 
DEBUG = -g


# define all objects influenced
OBJECTS = main.o Command.o Game.o Piece.o Player.o UserInterface.o \
	  GameChess.o GameSetup.o Board.o Field.o Action.o BoardHandler.o\
	  CommandView.o CommandEcho.o CommandQuit.o CommandStatus.o \
	  CommandSetName.o CommandDraw.o CommandSave.o CommandHistory.o\
	  CommandMove.o CommandHandler.o \
	  PieceBishop.o PieceKing.o PieceKnight.o PiecePawn.o PieceQueen.o\
	  PieceRook.o FileManager.o
	  


.PHONY : all clean debug valgrind archive

# make ass3
$(TITLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^
	

run : $(TITLE) 
	./$(TITLE) 

valgrind : $(TITLE)
	valgrind --tool=memcheck --leak-check=full ./$< $(P0) $(P1)

clean :
	rm -f *.o *.zip *.ref *.txt *.out *.py  $(TITLE) 
	
submission :
	zip $(SUBMISSION) *.cpp *.h *.pdf Makefile
