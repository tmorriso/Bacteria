/********^***************^**********^***************^*******************
 * @author Tom Morrison
 * @date December 5, 2015
 * UserInput Class to keep track of the user's input while playing
 * Urban Dictionary game.
***************^************^*******************^************^*********/
#ifndef USERINPUT_H
#define USERINPUT_H
#include "Dictionary.h"
#include "Player.h"
#include "Word.h"
class UserInput 
{
  public:
	UserInput(std::string userInput); 
	std::string getUserInput();  
	void setUserInput(std::string);
	void determineAction();
	void rinput(std::string);
	
  private: 
	std::string userInput;
};
#endif
