/** The AI class will contain the algorithm of how the computer will be playing against the user.
NOTE: I am using the Mini Max algorithm which will be talked out more in the implementation. Here is the link which I referenced:
SOURCE: https://neverstopbuilding-dropblog.herokuapp.com/minimax
*/

#ifndef AI_H
#define AI_H

#include "TicTacToe.h"
#include "moveForAI.h"

class AI : public TicTacToe, public moveForAI
{
public:
	/**Constructor for AI
	@param a is the TicTacToe class where it will be obtaining the board
	@param pos is either 1 if AI is first, 2 if human player goes first
	*/
	AI(TicTacToe &a, int pos);

	/**MINI MAX ALGORITHM - EXPLAINED THOUROUGHLY IN IMPLETMENTAION FILE
	@param a is the TicTacToe class where it is constantly be making changes to the board
	@player gets switched between AI and human, values are taken from humanPlayer and AIPlayer
	@return moveForAI which gets its row, col, score values initialized 
	*/
	moveForAI getBestMoves(TicTacToe &a, int player);

	/**sets the AI move onto the board, will be using setUserMove function from TicTacToe class
	@param a is TicTacToe class where the AI will be making changes on the board
	*/
	void setAIMoves(TicTacToe &a);
	
private:
	int humanPlayer;						//Will either be 1 if human goes first, 2 if human is second
	int AIPlayer;							//Will either be 1 if human goes secomd, 2 if human is first
	moveForAI *ptr;
};

#endif // !AI_H
