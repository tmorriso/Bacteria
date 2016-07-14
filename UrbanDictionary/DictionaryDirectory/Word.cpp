// Word.cpp 
// Thomas Morrison
// November 29, 2015
// Project 2 
//--------------------------------------
// Purpose: Word Class to keep track of 
//             words, definitions,  and 
//                           sentences.
//--------------------------------------

#include <iostream>
#include <string>
#include "Word.h" 
using namespace std;

Word::Word()
{
	word = "Unknown";
	definition = "Unknown";
}
Word::Word(string wrd, string def)
{
	word = wrd;
	definition = def;
}
string Word::getWord()
{
	return word;
}
string Word::getDefinition()
{
	return definition; 
}
void Word::setWord(string wrd)
{
	word = wrd;
}
void Word::setDefinition(string def)
{
	definition = def;
}
string Word::wordToString()
{
	return ", your word is " + word;
}
string Word::definitionToString()
{
	return "The definition is: " + definition;
}
