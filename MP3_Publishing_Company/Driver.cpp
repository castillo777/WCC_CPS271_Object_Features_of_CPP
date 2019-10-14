/*
	Class: CPS 271
	Author: Sergio M. Castillo
	StudentID: @00620298
	Assigment No: MP3 - Pointers
	Purpose: Pubishing program that gathers and displays 
	the data related to books and tapes sold by the company.
	Program is implemented using the concepts of polymorphism.
*/
#include "Book.h"
#include "Tape.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printWelcomeMessage()
{
	cout << "---------------------------------" << endl
		 << "Welcome to our Publishing Program" << endl
		 << "---------------------------------" << endl
		 << endl;
}

int main()
{
	const int ARRAY_SIZE = 5;
	const int MAX_BOOKS = 3;
	const int MAX_TAPES = 2;

	Book commercialBook[MAX_BOOKS];
	Tape commercialTape[MAX_TAPES];

	Publication **ptrPub;

	ptrPub = new Publication*[ARRAY_SIZE];

	ptrPub[0] = &commercialBook[0];
	ptrPub[1] = &commercialBook[1];
	ptrPub[2] = &commercialBook[2];
	ptrPub[3] = &commercialTape[0];
	ptrPub[4] = &commercialTape[1];
	
	printWelcomeMessage();

	for (int i = 0; i < ARRAY_SIZE; i++)
		ptrPub[i]->readData();

	system("cls");

	printWelcomeMessage();

	for (int i = 0; i < ARRAY_SIZE; i++)
		ptrPub[i]->displayData();

	system("pause");
	return 0;
}