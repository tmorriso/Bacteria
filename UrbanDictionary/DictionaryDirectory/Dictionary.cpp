/***********************************************************************
 * Dictionary.cpp 
 * The Dictionary class keep track of the words and players while playing
 * Urban Dictionary Game.
 * @author Tom Morrison
 * @date December 5, 2015
 * Project #2
 **********************************************************************/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Player.h"
#include "Word.h"
#include "Dictionary.h"
using namespace std;

Dictionary::Dictionary(string wordFilename)
{
	readInWordList(wordFilename);
}

void Dictionary::readInWordList(string filename)
{
	ifstream infile;
	infile.open(filename.c_str());
	string line;
	int count = 0;
	
	if (infile.is_open())
	{
		cout << "Reading in word list from file: " << filename << endl;
		while ( getline (infile, line) )
		{
			int comma_pos = line.find(",");
					
			string wrd = line.substr(0, comma_pos);
			string def = line.substr(comma_pos+1); 			

			// create new Word object
			Word word(wrd, def);
			
			// add Word object to vector
			wordList.push_back(word);
			
			count++;
		}
		cout << count << " words read in. Closing word list file." << endl;
		infile.close();
	}
}

void Dictionary::readScoresToFile(string finalScores)
{
	ofstream fout;
	string newFileName = "scoresheet.txt";
	fout.open(newFileName);
	if (fout.is_open()) // Ensure file was opened properly
	{
		cout << "Reading scores to file" << endl;
		fout << finalScores << endl;
		fout.close();
	}
	else
	{
		cout << "Unable to write to file \"scoresheet.txt" "" << endl;
	}
	cout << "***********************************************" << endl;
}

void Dictionary::enterPlayers()
{
	int count = 1;
	while (playerID != "s")
	{
		cout << "Enter Player"<<count<<"'s ID or hit 's' for Start!" <<endl;
		cin >> playerID;
		if (playerID != "s")
		{
			Player player(playerID, 0);
			playerList.push_back(player);
			count ++;
		}
		else
		{
			cout << "Game is starting!! GET READY TO LAUGH!!" << endl;
		}
	}

	
}

void Dictionary::printPlayers()
{
	for (int i=0; i<playerList.size(); i++)
	{
		cout << "Player" << i+1 << playerList.at(i).toString() << endl;
	}
}

void Dictionary::printWords()
{
	for (int i=0; i<wordList.size(); i++)
	{
		Word word = wordList.at(i);
		cout << word.wordToString() << endl;
	}
}

void Dictionary::printDefinitions()
{
	for (int i=0; i<wordList.size(); i++)
	{
		Word definition = wordList.at(i);
		cout << definition.definitionToString() << endl;
	}
}

/** --------------------------------------------------------------------
 * Return the "reader" 
 * @param player_list
 * @return Player who is the "reader"
 * ---------------------------------------------------------------------
**/

Player Dictionary::getReader(int num)
{
	Player reader = playerList[num];
	return reader;
}

Word Dictionary::getCurrentWord(int num)
{
	Word currentWord = wordList[num];
	return currentWord;
}

Player Dictionary::getWinner()
{
	Player winner;
	int winnerScore = 0;
	int currentPlayerScore;
	cout << "***********************************************" << endl;
	cout << "The Winner IS: " << endl;
	for (int i=0; i < playerList.size(); i++)
	{
		currentPlayerScore = playerList[i].getScore();
		if (currentPlayerScore > winnerScore)
		{
			winner = playerList[i];
		}
		
	}
	cout << winner.getId() << endl;
	cout << "***********************************************" << endl;
	
}

void Dictionary::printScores()
{
	cout << "The scores are: " << endl;
	for (int i = 0; i < playerList.size(); i++)
	{
		cout << playerList[i].getScore() << endl;
	}
}

void Dictionary::setScores()
{
	int score;
	for (int i =0; i < playerList.size(); i++)
	{
		cout << "Enter " << playerList[i].getId() << "'s score" << endl;
		cin >> score;
		playerList[i].setScore(score);
	}
}

string Dictionary::getScores()
{
	cout << "***********************************************" << endl;
	cout << "The Final Scores Are: " << endl;
	string scoreList;
	for (int i=0; i < playerList.size(); i++)
	{
		cout << playerList[i].getId() << "  " << playerList[i].getScore() << " Points" << endl;
		scoreList += playerList[i].getId() + "," +to_string(playerList[i].getScore()) + "; ";
	}
	cout << "***********************************************" << endl;
	return scoreList; 
}

