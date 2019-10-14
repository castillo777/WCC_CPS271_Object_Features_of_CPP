/*
Class: CPS 271
Author: Sergio M. Castillo
StudentID: @00620298
Assigment No: MP1 - TTT
Purpose: Tic Tac Toe game that gathers the names
of two plyers, moves, and displays the name of a
winner if any.
*/

// Header files
#include "TicTacToe.h"
#include <iostream>
#include <algorithm>

using namespace std;

TicTacToe::TicTacToe()	// default constructor
{
	char arrayElement = '1';
	//	initializes gameBoardArray starting from 1 to 9
	for (unsigned int i = 0; i < gameBoard.size(); i++)
	{
		for (unsigned int j = 0; j < gameBoard.size(); j++)
			gameBoard[i][j] = arrayElement++;
	}	// end outer for loop

	totalMoves = 0;

	playerIndex = 0;

	playerPosition = 0;

	winner = "";
} // end default constructor

void TicTacToe::setGame()
{
	cout << "Welcome to the Tic Tac Toe Game!"
		 << endl << endl;

	int playerNumber = 1;

	for (unsigned int i = 0; i < playerList.size(); i++)
	{
		cout << "Enter name for player " << playerNumber << ": ";
		getline(cin, playerList[i]);

		playerNumber++;
	} // end for loop

	cout << endl << endl; // start new line of output
} // end function setGame


void TicTacToe::printGameBoard() const
{
	const size_t playerWithXSign = 0;
	const size_t playerWithOSign = 1;

	for (unsigned int i = 0; i < gameBoard.size(); i++)
	{			
		for (unsigned int j = 0; j < gameBoard.size(); j++)
			cout << "|" << gameBoard[i][j];		
		
		cout << "|" << endl;
	} // end outer for loop	

	cout << endl << endl << playerList[playerWithXSign] << ", your symbol is X!"
		 << endl << playerList[playerWithOSign] << ", your symbol is O!"
		 << endl << endl;
} // end function printGameBoard

void TicTacToe::getMove()
{	
	int static currentPlayerTurn = 0;
	int static futurePlayerTurn = 1;

	playerIndex = currentPlayerTurn;

	cout << playerList[playerIndex] << ", enter your desired position (1-9): ";
	cin >> playerPosition;
	cout << endl;

	while (playerPosition <= 0 || !playerPosition >= 10) // Makes sure player doesn't choose a number out of bounds
	{
		cout << "You have entered an invalid position. "
		     << "Please, enter a valid position starting from number 1 and ending on number 9: ";
		cin >> playerPosition;
		cout << endl;
	} // end while

	swap(currentPlayerTurn, futurePlayerTurn); // Swaps players' turns
}

void TicTacToe::setMove()
{	
	switch (playerPosition)
	{
	case 1:
		if (playerIndex == 0)
			gameBoard[0][0] = 'X';
		else
			gameBoard[0][0] = 'O';
		break;
	case 2:
		if (playerIndex == 0)
			gameBoard[0][1] = 'X';
		else
			gameBoard[0][1] = 'O';
		break;
	case 3:
		if (playerIndex == 0)
			gameBoard[0][2] = 'X';
		else
			gameBoard[0][2] = 'O';
		break;
	case 4:
		if (playerIndex == 0)
			gameBoard[1][0] = 'X';
		else
			gameBoard[1][0] = 'O';
		break;
	case 5:
		if (playerIndex == 0)
			gameBoard[1][1] = 'X';
		else
			gameBoard[1][1] = 'O';
		break;
	case 6:
		if (playerIndex == 0)
			gameBoard[1][2] = 'X';
		else
			gameBoard[1][2] = 'O';
		break;
	case 7:
		if (playerIndex == 0)
			gameBoard[2][0] = 'X';
		else
			gameBoard[2][0] = 'O';
		break;
	case 8:
		if (playerIndex == 0)
			gameBoard[2][1] = 'X';
		else
			gameBoard[2][1] = 'O';
		break;
	case 9:
		if (playerIndex == 0)
			gameBoard[2][2] = 'X';
		else
			gameBoard[2][2] = 'O';
		break;
	} // end switch

	totalMoves++;
} // end function setMove

int TicTacToe::movesTracker() const
{
	return totalMoves;
} // End function movesTracker


bool TicTacToe::isWinner() const
{
	if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2])
		return true;
	else if (gameBoard[2][0] == gameBoard[1][1] && gameBoard[2][0] == gameBoard[0][2])
		return true;
	else if (gameBoard[0][0] == gameBoard[0][1] && gameBoard[0][0] == gameBoard[0][2])
		return true;
	else if (gameBoard[1][0] == gameBoard[1][1] && gameBoard[1][0] == gameBoard[1][2])
		return true;
	else if (gameBoard[2][0] == gameBoard[2][1] && gameBoard[2][0] == gameBoard[2][2])
		return true;
	else if (gameBoard[0][0] == gameBoard[1][0] && gameBoard[0][0] == gameBoard[2][0])
		return true;
	else if (gameBoard[0][1] == gameBoard[1][1] && gameBoard[0][1] == gameBoard[2][1])
		return true;
	else if (gameBoard[0][2] == gameBoard[1][2] && gameBoard[0][2] == gameBoard[2][2])
		return true;

	return false;
} // End function isWinner

void TicTacToe::getWinner()
{
	winner = playerList[playerIndex];
}

void TicTacToe::printWinner() const
{
	cout << "Congratulations, " << winner << "! You have won!"
		 << endl << endl;
} // End function printWinner