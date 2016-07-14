/**
 * @author Tom Morrison
 * @version December 5, 2015
 * Project #2
 * Compile via Command Line: g++ -std=c++11 UrbanDictionaryDriver.cpp Player.cpp Dictionary.cpp Word.cpp UserInput.cpp
 * Run via Command Line: ./a.out words.txt
 */
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Player.h"
#include "Word.h"
#include "Dictionary.h"
#include "UserInput.h"
using namespace std;

int main (int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: " << argv[0] << " wordfilename " << endl;
		exit(1);
	}
	string wordListFilename(argv[1]);
	Dictionary dictionary(wordListFilename);
	
	dictionary.enterPlayers();
	
	cout << "Player List:" << endl;
	dictionary.printPlayers();
	
	string choice;
	UserInput input("Unknown");
	choice = input.getUserInput();
	int count = 0;
	string finalScores = "Unknown";
	while (choice != "q")
	{
		if (choice == "r")
		{
			Player reader = dictionary.getReader(count);
			cout << "The Reader is: "<< reader.getId() << endl;
			Word currentWord(dictionary.getCurrentWord(count));
			cout << reader.getId() << currentWord.wordToString()<< endl;
			cout << currentWord.definitionToString()<< endl;
			cout << "Set Player's Scores!!" << endl;
			dictionary.setScores();
			count ++;
		}
		else if (choice == "s")
		{
			cout << "Score Check" << endl;
			dictionary.printPlayers();
		}
		choice = input.getUserInput();
		
	}
	finalScores = dictionary.getScores();
	dictionary.getWinner();
	dictionary.readScoresToFile(finalScores);
	cout << "Goodbye!" << endl;
	
}
