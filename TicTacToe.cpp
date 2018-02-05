#include "tictactoe.h"
#include <iostream>

using namespace std;

/**Default (and only) constructor for TicTacToe. This essentially creates the board filled with ' '
no argument is taken
*/
TicTacToe::TicTacToe()
{

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			board[x][y] = ' ';
		}
	}

}

/**This function determines if the human player did not pick a value that has been taken already
@param ro is the row of the move coordinate
@param col is the column of the move coordinate
@return true if the human picked a move that has empty space, false if move is occupied by X or O
*/
bool TicTacToe::validMove(int ro, int col)
{
	if (board[ro - 1][col - 1] == ' ')			// ro and col get subtracted 1 because the user sees a coordinate system (1-3, 1-3) to make things easier for them
	{
		return true;
	}
	else
		return false;
}

/**This function makes the move on the board, both human and AI uses this
@param playr is the indication of player X or player O
@param ro is the row where the move is
@param col is the column of where the move is
*/
void TicTacToe::setUserMove(int playr, int ro, int col)
{
	player = playr;
	row = ro;
	column = col;
	if (player == 1)
		board[row][column] = 'X';
	else if (player == 2)
		board[row][column] = 'O';
	else if (player == 0)						// this else if is used by the AI class only, which will be explained why in the AI functionality
		board[row][column] = ' ';
}

/** This function returns the character based on the current board, used for AI class and not found in main
@param ro is the row of the move coordinate
@param col is the column of the move coordinate
@return X if the board is has X occupied, O if O is occupied, ' ' if nothing is occupied
*/
char TicTacToe::getUserMove(int ro, int col)
{
	if (board[ro][col] == 'X')
		return 'X';

	else if (board[ro][col] == 'O')
		return 'O';

	else
		return ' ';
}

/**This function determines the winner based on all ths possible combinations of how a win can happen
@return true if win is found, false otherwise
*/
bool TicTacToe::winner()
{

	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
	{
		return true;
	}
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		return true;
	}
	else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
	{
		return true;
	}
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
	{
		return true;
	}
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
	{
		return true;
	}
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
	{
		return true;
	}
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
	{
		return true;
	}
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
	{
		return true;
	}
	else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
	{
		return true;
	}
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
	{
		return true;
	}
	else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
	{
		return true;
	}
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
	{
		return true;
	}
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
	{
		return true;
	}
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
	{
		return true;
	}
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
	{
		return true;
	}
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
	{
		return true;
	}
	else return false;
}

/** This function determines if its a tie
@return true if no win and all spaces are filled, false if win or all spaces are not filled*/
bool TicTacToe::isTie()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;


}

/** Prints board */
void TicTacToe::printBoard()
{
	cout << "\n  1   2   3\n";
	cout << "1 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
	cout << " ---|---|---\n";
	cout << "2 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
	cout << " ---|---|---\n";
	cout << "3 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2];
}

/** All the values in board become empty spaces*/
void TicTacToe::resetBoard()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			board[x][y] = ' ';
		}
	}
}

/**This function determines if the first player won or second player won, or tie. Not found in main, used for AI class
@return 1 is X player won, 2 if O player won, 0 if tue
*/
int TicTacToe::whoWon()
{
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
	{
		return 1;
	}
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		return 1;
	}
	else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
	{
		return 1;
	}
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
	{
		return 1;
	}
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
	{
		return 1;
	}
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
	{
		return 1;
	}
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
	{
		return 1;
	}
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
	{
		return 1;
	}
	else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
	{
		return 2;
	}
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
	{
		return 2;
	}
	else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
	{
		return 2;
	}
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
	{
		return 2;
	}
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
	{
		return 2;
	}
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
	{
		return 2;
	}
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
	{
		return 2;
	}
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
	{
		return 2;
	}
	else if (isTie())
	{
		return 0;
	}
}