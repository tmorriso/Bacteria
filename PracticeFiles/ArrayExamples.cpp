// Array delete, add, etc...


#include <iostream>
using namespace std;

int main()
{
	const int MAX_SIZE = 5;
	int list[MAX_SIZE] = {99, 82, 67, 78, 66};
	int numToDelete = 67;
	int indexToDelete = 2;
	int numElements = MAX_SIZE;
	for (int i=indexToDelete+1; i<MAX_SIZE; i++)
	{
		list[i-1] = list[i];
	}
	numElements--;
	
	for (int i=0; i<numElements; i++)
	{
		//cout << "list[" << i << "] = " << list[i] << endl;
	}
	
	// add 42 to second spot in the list 
	int numToAdd = 42;
	int indexPlacer = 1;
	if (numElements < MAX_SIZE)
	{
		// ok we can do this
		for (int i=numElements; i>=indexPlacer; i--)
		{
			list[i] = list[i-1];
		}
		list[indexPlacer] = numToAdd;
		numElements++;
	}
	for (int i=indexToDelete+1; i<MAX_SIZE; i++)
	{
		list[i-1] = list[i];
	}
	numElements--;
	
	for (int i=0; i<numElements; i++)
	{
		cout << "list[" << i << "] = " << list[i] << endl;
	}
	// welcome to hell
	// add another element to the list 
	int yetAnotherAdd = 100;
	int newlist[MAX_SIZE*2];
	if (numElements == MAX_SIZE)
	{
		
		// this won't work newlist = list;
		for (int i = 0; i<numElements; i++)
		{
			newlist[i] = list[i];
		}
		newlist[numElements++] = yetAnotherAdd;
		//list = newlist;
	}
	for (int i=0; i<numElements; i++)
	{
		cout << "list[" << i << "] = " << newlist[i] << endl;
	}
	return 0;
}
