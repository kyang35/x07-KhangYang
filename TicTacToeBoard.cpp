#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/


//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
	if(turn == X)
	{
		turn = O;
	}
	else if(turn == O)
	{
		turn = X;
	}
	else 
	{
		turn = Invalid;
	}
}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j] = Blank;
		}
	}
	turn = X;

}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j] = Blank;
		}
	}
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	if(board[row][column] == Blank && turn == X)
	{
		board[row][column] = X;
		toggleTurn();
	}
	else if(board[row][column] == Blank && turn == O)
	{
		board[row][column] = O;
		toggleTurn();
	}
	else	
	{
		return Invalid;
	}
	
return board[row][column];
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if(board[row][column] == Blank){
		return Blank;
	}
	else if(board[row][column] !=Blank && board[row][column] != Invalid){
		return board[row][column];
	}
	else				
  		return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	if(board[1][1] == X && board[1][2] == X && board[1][3] == X)
 	{
		return X;
	}
	else if(board[1][1] == X && board[2][2] == X && board[3][3] == X)
 	{
		return X;
	}
	else if(board[1][1] == X && board[2][1] == X && board[3][1] == X)
 	{
		return X;
	}
	else if(board[3][1] == X && board[3][2] == X && board[3][3] == X)
	{
		return X;
	}
	else if(board[1][3] == X && board[2][3] == X && board[3][3] == X)
	{
		return X;
	}
	else if(board[3][1] == X && board[2][2] == X && board[1][3] == X)
	{
		return X;
	}
	else if(board[1][1] == O && board[1][2] == O && board[1][3] == O)
 	{
		return O;
	}
	else if(board[1][1] == O && board[2][2] == O && board[3][3] == O)
 	{
		return O;
	}
	else if(board[1][1] == O && board[2][1] == O && board[3][1] == O)
 	{
		return O;
	}
	else if(board[3][1] == O && board[3][2] == O && board[3][3] == O)
	{
		return O;
	}
	else if(board[1][3] == O && board[2][3] == O && board[3][3] == O)
	{
		return O;
	}
	else if(board[3][1] == O && board[2][2] == O && board[1][3] == O)
	{
		return O;
	}
	else
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{	
				if(board[i][j] == Blank)
				{
					return Invalid;
				}
				else
				{
					return Blank;
				}
			}
		}	
	}
  //return Invalid;
}
