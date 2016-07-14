// User.cpp
// Thomas Morrison
// November 15, 2015
// HW 8 Netflix Problem
//-----------------------------------
// Part 2 
// Purpose: to create the user class
//                to add users and their ratings
//-----------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <sstream> 

class User
{
	public:
		User()
		{}
		~User()
		{}
		User(std::string userid, std::string rating)
		{
			id = userid;
			// Make the incoming string into an array (ratings)
			std::istringstream iss(rating);
			std::string word;
			while(iss >> word)
				{
					ratings.push_back(std::stoi(word));
				} 
		}
		std::string getId()
		{
			return id;
		}
		int getRatingAt(int index)
		{
			return ratings[index];
		}
		void addRating(int rating)
		{
			ratings.push_back(rating);
		}
		int getNumRatings()
		{
			return ratings.size();
		}
		std::string toString()
		{
			return "User [user_id=" + id + "]";
		}
		void printRatings()
		{
			for (int i = 0; i < ratings.size(); i++)
			{
				std::cout << ratings[i] << " ";
			}
		}
		
	private:
		std::string id = "Unknown";
		std::vector<int> ratings;
};


//int main()
//{
/*
	// Create our class an add a few ints
	User tom = User ();
	tom.addRating(32);
	tom.addRating(42);
	tom.addRating(52);

	// Display the vector contents so far
	tom.DisplayVectorContents();
	
	// Get rating at index
	std::cout << tom.getRatingAt(2) << std::endl;
	
	//Get id 
	std::cout << tom.getId() << std::endl;
	
	//Get Number of Ratings
	std::cout << tom.getNumRatings() << std::endl;
	
	//To string 
	std::cout << tom.toString() << std:: endl;

	// Creates a copy of the classes container you can only really view whats in 
	// the classes vector container. What ever changes you make here wont effect the class.
	//std::vector<int> container1 = obj.GetCopyOfVector();
	// These elements wont be added as it's a copy of the container
	//container1.push_back(342);
	//container1.push_back(64);
	//container1.push_back(123);


	// Display the classes container to see show nothing was added.
	//obj.DisplayVectorContents();
*/
//	return 0;
//}

