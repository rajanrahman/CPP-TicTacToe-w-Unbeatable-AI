#ifndef moveForAI_H
#define moveForAI_H

/** This class is used by the AI class. What this class is that it essentially creates a move done by
the computer. The moves information (row coordinate, column cooridnate, and score) is stored. In the minimax 
algorithm, I will create a vector containing all these moves. The move that has the greatest score will be returned
as the best move in the AI class. 
*/


class moveForAI 
{
public:
	/**default constructor
	*/
	moveForAI();	

	/**Constructor thats sets score
	@param scor is used to set the score of the move for AI
	*/
	moveForAI(int scor);	

	int row;						//this is the row coordinate of the move
	int col;						//this is column coordinate of the move
	int score;						//this holds the score of the Mini Max algorithm which will be discussed more in the implementation
};

#endif // !AI_MOVE once
