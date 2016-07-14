/**
 * Dictionary.h 
 * @author Tom Morrison
 * @version Fall 2015
 * project #2
 */
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Player.h"
#include "Word.h"
#include <vector>

class Dictionary 
{
  public:
	Dictionary(std::string word_list_file); 
	void readInWordList(std::string filename); 
	void readScoresToFile(std::string finalScores); 
	void enterPlayers(); 
	void printPlayers(); 
	void printWords();
	void printDefinitions();
	Player getReader(int num);
	Word getCurrentWord(int num);
	Player getWinner();
	void printScores();
	void setScores();
	std::string getScores();
	
  private: 
	std::vector<Word> wordList; 
	std::vector<Player> playerList;
	std::string playerID;
};
#endif
