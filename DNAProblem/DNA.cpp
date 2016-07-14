/*
 * Thomas Morrison
 * October 9, 2015
 * Homework # 5
 * DNA comparison 
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	string mouse_line1;
	string mouse_line;
	ifstream mouse_file ( argv[1] );
	if (mouse_file.is_open()) // Ensure file opened properly
	{
		while ( getline(mouse_file,mouse_line) ) 
		{
			mouse_line1 = mouse_line; // How come I have to declare mouse_line1 = mouse_line?
		}
		mouse_file.close();
	}
	else cout << "Unable to open mouse file ";
	
	string human_line1;
	string human_line;
	ifstream human_file ( argv[2] );
	if (human_file.is_open()) 
	{
		while ( getline(human_file,human_line) ) 
		{
			human_line1 = human_line;
		}
		human_file.close();
	}
	else cout << "Unable to open human file ";
	
	string unknown_line;
	string unknown_line1; 
	ifstream unknown_file ( argv[3] );
	if (unknown_file.is_open()) 
	{
		while ( getline(unknown_file,unknown_line) ) 
		{
			unknown_line1 = unknown_line;
		}
		unknown_file.close();
	}
	else cout << "Unable to open unknown file ";
	
	// For loop to determine similarity score with mouse
	float hamming_distance = 0;
	for(int i=1; i <= mouse_line1.length(); i++)
	{
		if (mouse_line1[i] != unknown_line1[i])
		{
			hamming_distance++;
		}
	}
	float mouse_similarity_score = (mouse_line1.length() - hamming_distance)/mouse_line1.length();
	cout << "MouseCompare = " << mouse_similarity_score << endl;
	
	// For loop to determine similarity score with human
	float human_hamming_distance = 0;
	for(int i=0; i <= human_line1.length(); i++)
	{
		if (human_line1[i] != unknown_line1[i])
		{
			human_hamming_distance++;
		}
	}
	float human_similarity_score = (human_line1.length() - human_hamming_distance)/human_line1.length();
	cout << "HumanCompare = " << human_similarity_score << endl;
	
	if (human_similarity_score == mouse_similarity_score)
	{
		cout << "identity cannot be determined" << endl;
	}
	else if (human_similarity_score > mouse_similarity_score)
	{
		cout << "human" << endl;
	}
	else if (mouse_similarity_score > human_similarity_score)
	{
		cout << "mouse" << endl;
	}
	
	return 0;
}
