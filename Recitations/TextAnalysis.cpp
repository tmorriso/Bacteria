// TextAnalysis
// Lab 8

#include <string>
#include <iostream>

using namespace std;

int getNumWords(string theString);
int getNumSentences(string theString);

int main(int argc, char* argv[]) 
{
	string theString = "This is a cool string. I like strings? String cheese is tasty! String string string.";
	cout << "String: " << theString << endl;
	cout << "Number of sentences: " << getNumSentences(theString) << endl;
	cout << "Number of words: " << getNumWords(theString) << endl;
}

int getNumWords(string str)
{
	int count = 0;
	for(int i=0; i < str.length(); i++)
	{
		if(str[i] == ' ')
		{
		count++;
	}
}
	
	return count + 1;
}

int getNumSentences(string str)
{
	int count = 0;
	for(int i=0; i <str.length(); i++)
	{
		if(str[i] == '?'|| str[i] == '!' || str[i] == '.')
		{
			count++;
		}
	}
	return count;
}
	
