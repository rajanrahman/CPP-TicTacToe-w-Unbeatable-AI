#include "AI.h"
#include <vector>

/**Constructor for AI
@param a is the TicTacToe class where it will be obtaining the board
@param pos is either 1 if AI is first, 2 if human player goes first
*/
AI::AI(TicTacToe &a, int pos)// : ptr(new moveForAI())
{
	if (pos == 2)				//pos will be initialized to 2 in main in the case where the human player chooses to go first
	{
		humanPlayer = 1;
		AIPlayer = 2;
	}
	else if (pos == 1)			//pos will be initialized to 1 in main in the case where the human player chooses to go second
	{
		humanPlayer = 2;
		AIPlayer = 1;
	}

	ptr = new moveForAI();
}

/**sets the AI move onto the board, will be using setUserMove function from TicTacToe class
@param a is TicTacToe class where the AI will be making changes on the board
*/

void AI::setAIMoves(TicTacToe &a)
{
	moveForAI best = getBestMoves(a, AIPlayer);												//
	a.setUserMove(AIPlayer, best.row, best.col);
}

/**MINI MAX ALGORITHM

SOURCE: https://neverstopbuilding-dropblog.herokuapp.com/minimax

@param a is the TicTacToe class where it is constantly be making changes to the board
@player gets switched between AI and human, values are taken from humanPlayer and AIPlayer
@return moveForAI which is the best move the AI can make,its row, col, score values initialized

the Mini Max algorithm works by having the AI choose the best possible move based on how many points the AI can get. +10 i the AI wins, -10 loses, 0 tie
the Mini Max algorithm pretty much plays the game with its self (recursuion), storing the amount of points of each gamne. Each game will be stored by through the object moveForAI and
be stored in a vector. I will go through the vector and return the object that has the greatest score as the best move. 
*/

moveForAI AI::getBestMoves(TicTacToe &a, int player)
{
	if (a.winner() || a.isTie())							//this if statement is for when a winner or tie is present 
	{
		if (a.whoWon() == AIPlayer)
			return moveForAI(10);							//when AI is winner then return move with score 10. The row and column coordinates are irrelevant since theres a win and no more moves will be taken
		else if (a.whoWon() == humanPlayer)
			return moveForAI(-10);							//when huaman is winner then return move with score -10. The row and column coordinates are irrelevant since theres a lost and no more moves will be taken
		else if (a.whoWon() == 0)
			return moveForAI(0);							//when theres a tie return move with a score of 0. The row and column coordinates are irrelevant since no moves will be taken
	}

	std::vector <moveForAI> possibleMoves;					//this vector will be used to hold all the possible moves the AI will make determined by whats on the board

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)							//nested for loop to get all possible spaces of the board
		{
			if (a.getUserMove(i, j) == ' ')					//if the space is empty, the AI will make the move and store
			{
				moveForAI AImove;
				AImove.row = i;								//row coordinate is obtained
				AImove.col = j;								//column coordinate is obtained
				a.setUserMove(player, i, j);				//The move is set onto the board
				if (player == humanPlayer)
					AImove.score = getBestMoves(a, AIPlayer).score;		//recursion, we get the best move of the next player (AI in this case). Then we take its score
				else if (player == AIPlayer)
					AImove.score = getBestMoves(a, humanPlayer).score;	//recursion, we get the best move of the next player (AI in this case). Then we take its score

				possibleMoves.push_back(AImove);						//vector size increases with the move that was made stored

				a.setUserMove(0, i, j);									//because the algorithm makes actual changes to the board, I have to reset the spot so it doesn't show in the board
			}
		}
	}
	int bestMove = 0;							//the following code will get the best move (the move that gives us the most points). bestMove will be an int value that tells us the index of the vector where the best move is at
	if (player == AIPlayer)
	{
		int bestScore = -10;					//bestScore is intitialized -10 because we are looking for moves better than that for AI. 
		for (int x = 0; x < possibleMoves.size(); x++)
		{										// the for loop tests each of the values in the vector AImoves		
			if (possibleMoves[x].score > bestScore)
			{
				bestMove = x;					//as soon as it finds a better score than -10, the bestMove will change to the x in the loop, and the best score will be that score it compared to
				bestScore = possibleMoves[x].score;
			}
		}
	}
	else if (player == humanPlayer)				//the following code does the same as above. However, this is when the current player is human
	{
		int bestScore = 10;						//bestScore is intitialized 10 because we want the human player to have a score with the least amount of points (0 or -10). 
		for (int x = 0; x < possibleMoves.size(); x++)
		{
			if (possibleMoves[x].score < bestScore)
			{
				bestMove = x;					//as soon as it finds a lesser score than 10, the bestMove will change to the x in the loop, and the best score will be that score it compared to
				bestScore = possibleMoves[x].score;
			}
		}
	}
	return possibleMoves[bestMove];
}