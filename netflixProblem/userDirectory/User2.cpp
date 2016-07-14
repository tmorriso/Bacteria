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
#include <iomanip>
#include <cstring>
#include "User.h"

using namespace std; 

User::User()
{
	id = "unkown";
	
}

User::User(string userid, string rating)
{
	id = userid;
	istringstream iss(rating);
	string word;
	while(iss >> word)
	{
		//int integer = stoi (word);
		ratings.push_back(stoi(word));
	} 
}

string User::getId()
{
	return id;
}

int User::getRatingAt(int index)
{
	return ratings[index]; 
}

void User::addRating(int rating)
{
	ratings.push_back(rating);
}

int User::getNumRatings()
{
	return ratings.size();
}

string User::toString()
{
	return "User [user_id=" + id + "]";
}

void User::printRatings()
{
	for (int i = 0; i < ratings.size(); i++)
			{
				cout << ratings[i] << " ";
			}
}

