// Thomas Morrison
// October 25 2015
// Assignment 8
// Crypting and decrypting messages using c++

#include <iostream>
#include <typeinfo>
#include <fstream>

using namespace std;
string readFile(string x);
// Function to read in the file as a string and output the contents as a string
char encryptChar(char letter, int offSet);
// Encrypts a char by the specified offset
char decryptChar(char letter, int offSet);
// Decrypts a char by the specified offset
string encryptMessage(string content, int offSet);
// Encrypts the entire message
string decryptMessage(string content, int offSet);
// Decrypts the entire message
void writeToFile(string finalMessage, string fileType, string originalFileName);
// Write to file function

int main(int argc, char* argv[])
{ 
	string encryptedMessage;
	string decryptedMessage;
	string messageFinal;
	string fileContent;
	string crypt = string(argv[1]); // convert char to a string
	int ioffSet = atoi(argv[2]);
	//cout<<"argv[1] is of type: "<<typeid(crypt).name()<<endl; // checks file type
	fileContent = readFile(argv[3]);
	
	
	if (crypt == "-e")
	{
		cout << "Encrypting file: " << argv[3] << endl;
		cout << fileContent << endl;
		encryptedMessage = encryptMessage(fileContent, ioffSet);
		cout << encryptedMessage << endl;
		messageFinal = encryptedMessage;
	}
	else if (crypt == "-d")
	{
		cout << "Decrypting file: " << argv[3] << endl;
		cout << fileContent << endl;
		decryptedMessage = decryptMessage(fileContent, ioffSet);
		cout << decryptedMessage << endl;
		messageFinal = decryptedMessage;
	}
	else 
	{
		cout << "Invalid input for argv[1]" << endl;
	}
	writeToFile(messageFinal, crypt, argv[3]);
	return 0;
}

// Functions Below Here ....................
string readFile(string x)
{
	string message_line;
	ifstream message;
	message.open(x);
	if (message.is_open()) // Ensure file opened properly
	{
		getline(message,message_line);
	}
	
	return (message_line);
	//message.close(x);	
}

char encryptChar(char letter, int offSet)
{
	char newLetter;
	if (letter > 96 && letter < 123) // Lower Case Letters
	{
		if (letter + offSet > 122)
		{
			newLetter = letter + offSet - 26;
		}
		else 
		{
			newLetter = letter + offSet;
		}
	}
	else if (letter > 64 && letter < 91) // Capital Letters
	{
		if (letter + offSet > 90 )
		{
			newLetter = letter + offSet - 26;
		}
		else 
		{
			newLetter = letter + offSet;
		}
	
	}
	else // If character is not in the Alhpabet it remains the same.
	{
		newLetter = letter;
	}
		
	return (newLetter);
}

char decryptChar(char letter, int offSet)
{
	char newLetter;
	if (letter > 96 && letter < 123) // Lower Case Letters
	{
		if (letter - offSet < 96)
		{
			newLetter = letter - offSet + 26;
		}
		else 
		{
			newLetter = letter - offSet;
		}
	}
	else if (letter > 64 && letter < 91) // Capital Letters
	{
		if (letter - offSet < 64 )
		{
			newLetter = letter - offSet + 26;
		}
		else 
		{
			newLetter = letter - offSet;
		}
	
	}
	else // If character is not in the Alhpabet it remains the same.
	{
		newLetter = letter;
	}
		
	return (newLetter);
}
// Function to encryptMessage
string encryptMessage(string content, int offSet)
{
	int messageLength;
	messageLength = content.size() - 1;
	for (int i = 0; i <= messageLength; i++)
	{
		content[i] = encryptChar(content[i], offSet);
	}
	
	return content;
	
}
// Function to decrypt message
string decryptMessage(string content, int offSet)
{
	int messageLength;
	messageLength = content.size() - 1;
	for (int i = 0; i <= messageLength; i++)
	{
		content[i] = decryptChar(content[i], offSet);
	}
	
	return content;
}
// Write to file function
void writeToFile(string finalMessage, string fileType, string originalFileName)
{
	ofstream fout;
	string newFileName;
		if (fileType == "-e")
		{
			newFileName = originalFileName + ".enc";
		}
		else if (fileType == "-d")
		{
			newFileName = originalFileName + ".dec";
		}
fout.open(newFileName);

	if (fout.is_open()) // Ensure file was opened properly
	{
		fout << finalMessage << endl;
		fout.close();
		
	}
	else
	{
		cout << "Unable to write to file \"message.txt" "" << endl;
	}
}
	
	
