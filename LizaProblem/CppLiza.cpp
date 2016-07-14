// Thomas Morrison
// October 16 2015
// Homework Assignment 6
// Psychologist Eliza Program
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	ifstream responses;
	responses.open(argv[1]);
	const int MAX_NUM_RESPONSES = 100; 
	const int NUM_COLUMNS = 2;
	string responseArray[MAX_NUM_RESPONSES][NUM_COLUMNS]; // Declare a string array for responses
	string response_line;
	int num_keywords;
	
	if (responses.is_open()) // Ensure file opened properly
	{
		for(int i = 0; getline(responses,response_line);i++) 
		{
			int index = response_line.find("@");
			int endIndex = response_line.find("\n");
			responseArray[i][0] = response_line.substr(0,index); // Populate the first column of the array with the keywords
			responseArray[i][1] = response_line.substr(index+1, endIndex); // Populate the second column of the array with the responses
		}
		num_keywords = sizeof(responseArray[0])/2; // Determine the size of the array 
		responses.close();
	}
	else cout << "Unable to open file ";
	string reply = "unknown";
	string user_input;
	while (user_input != "q") // Run through the while loop to answer the user's question
	{
		cout << "what question do you have about C++?.";
		cin >> user_input;
		for (int i = 0; i<= num_keywords; i++)
		{
			if (responseArray[i][0] == user_input)
			{
				reply = responseArray[i][1];
			}
		}
		if (reply == "unknown") // Determine if the question is a keyword 
		{
			cout << "Sorry, I don't know. What else can we talk about?"<< endl;
		}
		else 
		{
			cout << reply << endl;
		}
		reply = "unknown";	
	}
	return 0;
}
	
