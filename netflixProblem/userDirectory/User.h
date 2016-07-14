//User header file
#ifndef USER_H
#define USER_H
#include <vector> // Not sure why this has to be included... Doesn't work with out it.
class User
{
	// instance variables 
	private:
		std::string id;
		std::vector<int> ratings; 
		
	// Functions
	public:
		User();
		User(std::string, std::string);
		std::string getId();
		int getRatingAt(int index);
		void addRating(int rating);
		int getNumRatings();
		std::string toString();
		void printRatings();
		int getSimilarity(User otherUser); // HW 9 Part 3 determine similarity between users
};
#endif
