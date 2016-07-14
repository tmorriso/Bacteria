/***********************************************************************
 * UserInput.cpp This is where all the methods of the userInput class
 * are kept. There is only two methods in this class.
 * @author Tom Morrison
 * @date December 5, 2015
 * 
 **********************************************************************/
#include <string>
#include <iostream>
#include "Player.h"
#include "Word.h"
#include "Dictionary.h"
#include "UserInput.h"
using namespace std;

UserInput::UserInput(string input)
{
	userInput = input;
}

string UserInput::getUserInput()
{
	cout << "What would you like to do? Show scores (s), Select reader (r), quit (q)?" << endl;
	cin >> userInput;
	return userInput;
}

void UserInput::rinput(string r)
{
	
}

void UserInput::setUserInput(string input)
{
	userInput = input;
}

void UserInput::determineAction()
{
	
}
