/*
Class: CPS 271
Author: Sergio M. Castillo
StudentID: @00620298
Assigment No: MP1 - TTT
Purpose: Tic Tac Toe game that gathers the names
of two plyers, moves, and displays the name of a
winner if any.
*/

#include "TicTacToe.h"
#include <iostream>

using namespace std;

int main()
{	
	TicTacToe myTicTacToeGame; //object of TicTacToe class
	
	myTicTacToeGame.setGame();

	while (!myTicTacToeGame.isWinner() && myTicTacToeGame.movesTracker() < maxNumOfMoves)
	{
		myTicTacToeGame.printGameBoard();
		myTicTacToeGame.getMove();
		myTicTacToeGame.setMove();		
		
		if (myTicTacToeGame.isWinner())
		{
			myTicTacToeGame.getWinner();
			myTicTacToeGame.printGameBoard();
			myTicTacToeGame.printWinner();

			system("pause");
			return 0;
		} //end if statement	
	
	} //end while loop

	myTicTacToeGame.printGameBoard();

	cout << "There is a draw! No winners at this time."
		<< endl << endl;

	system("pause");
	return 1;
}