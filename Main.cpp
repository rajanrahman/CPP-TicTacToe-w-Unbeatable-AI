/**This tests out the prgogram and where the user will decide if he or she plays first or second*/

#include "TicTacToe.h"
#include "AI.h"
#include "moveForAI.h"
#include <iostream>

using namespace std;

int main()
{

	struct cellMove
	{
		cellMove() {};
		cellMove(int ro, int col, int dir) : cellRow(ro), cellColumn(col), cellDirect(dir) {}
		int cellRow;
		int cellColumn;
		int cellDirect;
	};

	cellMove mov(12, 100, 12);
	cellMove ne;
	ne = mov;













	TicTacToe play;														//TicTacToe obeject created
	AI* computer = NULL;												//AI pointer assigned to Null
	int setCol, setRow;													//coordinates for column and row the user puts 
	char whoFirst;														//user input that determines who first
	char playAnother;													//user input that determines if he or she wants to play again
	
	
	do
	{
		bool endGame = false;											//this well help indicate when the game is finished and if the user wants to play again
		play.resetBoard();
		play.printBoard();
		cout << "\nWelcome to TicTacToe, chose x to go first, b to go second " << endl;
		cin >> whoFirst;

		if (whoFirst == 'x')//do
		{																//This do while makes the human and AI play eachother until win or tie
			do
			{
				do
				{														//This do while checks for if the user chose an empty coordinate
					do
					{													//This do while checks for if the user chose a valid column coordinate
						cout << "\nHuman Player select your column: ";
						cin >> setCol;
						if (setCol < 0 || setCol > 3)
						{
							cout << "The coloumn you have chosen is invalid." << endl;
						}
					} while (setCol < 0 || setCol  >3);

					do
					{													//This do while checks for if the user chose a valid row coordinate
						cout << "\nSelect your row: ";
						cin >> setRow;
						if (setRow < 0 || setRow > 3)
						{
							cout << "The row you have chosen is invalid." << endl;
						}
					} while (setRow < 0 || setRow > 3);

					if (!play.validMove(setRow, setCol))
					{
						cout << "This space has been taken, please choose another one." << endl;
					}
				} while (!play.validMove(setRow, setCol));

				play.setUserMove(1, --setRow, --setCol);				//row and column are decremented by one because the user is choosing coordinates from (1-3, 1-3)
				play.printBoard();
				computer = new AI(play, 2);								//AI object made
				if (play.winner())
				{
					cout << "\nHuman Player has won the game" << endl;
					cout << "Press 'a' to play again" << endl;
					cin >> playAnother;
					delete computer;									//AI object released
					play.resetBoard();
					endGame = true;
				}

				else if (play.isTie())
				{
					cout << "\nIt's a Tie!" << endl;
					cout << "Press 'a' to play again" << endl;
					cin >> playAnother;
					delete computer;									//AI object released
					endGame = true;
				}

				else
				{
					computer->setAIMoves(play);							//AI makes its move
					play.printBoard();
					if (play.winner())
					{
						cout << "\nThe Computer has won the game" << endl;
						cout << "Press 'a' to play again" << endl;
						cin >> playAnother;
						delete computer;								//AI object released
						endGame = true;
		
					}

					else if (play.isTie())
					{
						cout << "\nIt's a Tie!" << endl;
						cout << "Press 'a' to play again" << endl;
						cin >> playAnother;
						delete computer;								//AI object released
						endGame = true;
					}
				}
			} while (!endGame);
		}

		else if (whoFirst == 'b')
		{
			do
			{															//This do while will make the computer and user play with eachother until someone wins
				computer = new AI(play, 1);								
				computer->setAIMoves(play);								//AI makes its move
				play.printBoard();
				if (play.winner())
				{
					cout << "\nThe Computer has won the game" << endl;
					cout << "Press 'a' to play again" << endl;
					cin >> playAnother;
					delete computer;
					endGame = true;
				}
				else if (play.isTie())
				{
					cout << "\nIt's a Tie!" << endl;
					cout << "Press 'a' to play again" << endl;
					cin >> playAnother;
					delete computer;										//AI object released
					endGame = true;
				}
				else 
				{
					do
					{														//This do while checks for if the user chose an empty coordinate
						do
						{													//This do while checks for if the user chose a valid column coordinate
							cout << "\nHuman Player select your column: ";
							cin >> setCol;
							if (setCol < 0 || setCol > 3)
							{
								cout << "The coloumn you have chosen is invalid." << endl;
							}
						} while (setCol < 0 || setCol  >3);

						do
						{													//This do while checks for if the user chose a valid row coordinate
							cout << "\nSelect your row: ";
							cin >> setRow;
							if (setRow < 0 || setRow > 3)
							{
								cout << "The row you have chosen is invalid." << endl;
							}
						} while (setRow < 0 || setRow > 3);

						if (!play.validMove(setRow, setCol))
						{
							cout << "This space has been taken, please choose another one." << endl;
						}
					} while (!play.validMove(setRow, setCol));

					play.setUserMove(2, --setRow, --setCol);				//row and column are decremented by one because the user is choosing coordinates from (1-3, 1-3)
					play.printBoard();
					if (play.winner())
					{
						cout << "\nHuman Player has won the game" << endl;
						cout << "Press 'a' to play again" << endl;
						cin >> playAnother;
						delete computer;									//AI object released
						endGame = true;
					}

					else if (play.isTie())
					{
						cout << "\nIt's a Tie!" << endl;
						cout << "Press 'a' to play again" << endl;
						cin >> playAnother;
						delete computer;									//AI object released
						endGame = true;
					}
				}
			} while (!endGame);
		}
	 } while (playAnother == 'a');

	system("pause");
	return 0;
}