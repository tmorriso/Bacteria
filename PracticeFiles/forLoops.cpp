// For loops for understanding purposes 
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string newString =  "Zombi plane";
	string testString = "hello world";
	cout << testString[2] << endl;
	
	for (int i = 0; i <= 5; i++)
	{
		testString[i] = newString[i];	
	}
	cout << newString << endl;
	return 0; 
}
