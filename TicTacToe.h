#ifndef TicTacToe_H
#define TicTacToe_H

class TicTacToe
{

protected:
	char board[3][3];		//2D array that is essentially the board of the game
	int column;				//moves are done by coordinates, this holds the column coordinate
	int row;				//this holds the row coordinate
	char player;			//this indicates if the human or AI went first

public:
	/**Default (and only) constructor for TicTacToe. This essentially creates the board filled with ' '
	no argument is taken
	*/
	TicTacToe();

	/**This function makes the move on the board, both human and AI uses this
	@param playr is the indication of player X or player O
	@param ro is the row where the move is
	@param col is the column of where the move is
	*/
	void setUserMove(int playr, int ro, int col);

	/** This function returns the character based on the current board, used for AI class and not found in main
	@param ro is the row of the move coordinate
	@param col is the column of the move coordinate
	@return X if the board is has X occupied, O if O is occupied, ' ' if nothing is occupied
	*/
	char getUserMove(int ro, int col);

	/** Prints board */
	void printBoard();

	/** All the values in board become empty spaces*/
	void resetBoard();

	/**This function determines the winner based on all ths possible combinations of how a win can happen
	@return true if win is found, false otherwise
	*/
	bool winner();

	/** This function determines if its a tie
	@return true if no win and all spaces are filled, false if win or all spaces are not filled
	*/
	bool isTie();

	/**This function determines if the human player did not pick a value that has been taken already
	@param ro is the row of the move coordinate
	@param col is the column of the move coordinate
	@return true if the human picked a move that has empty space, false if move is occupied by X or O
	*/
	bool validMove(int ro, int col);

	/**This function determines if the first player won or second player won, or tie. Not found in main, used for AI class
	@return 1 is X player won, 2 if O player won, 0 if tue
	*/
	int whoWon();
};


#endif #pragma once
