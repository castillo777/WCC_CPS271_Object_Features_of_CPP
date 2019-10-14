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
#pragma once
#include <string>
#include <array>

const size_t rows = 3; // Sets rows for gameBoard array
const size_t columns = 3; // Sets columns for gameBoard array
const size_t maxNumOfPlayers = 2; // Sets max amount of players allowed on game
const size_t maxNumOfMoves = 9; // Sets max amount of moves allowed on game

class TicTacToe // Base class of Tic Tac Toe game
{
public:
	TicTacToe(); // default constructor
	void setGame(); // Introduces the game and stores each players name on playerList array
	void printGameBoard() const; // prints gameBoard aaray
	void getMove(); // Gathers players' desired position on gameBoard array
	void setMove(); // Stores players' moves into gameBoard array
	int movesTracker() const; // Keeps track of total moves on game by players
	bool isWinner() const; // Checks if there is a winner
	void getWinner(); // Gets winner name from playerList array
	void printWinner() const; // print name of winner
private:
	std::array< std::array<char, columns>, rows> gameBoard; // Creates gameBoard array
	std::array<std::string, maxNumOfPlayers> playerList; // Creates an array of string type to store players names
	int totalMoves; // Stores number of total moves of game
	int playerPosition; // Stores the position players will select on gameBoard array
	int playerIndex; // Stores index number of playerList array to keep track of players' turn
	std::string winner;	// Stores name of winner
};