// pointer deref

#include <iostream>
using namespace std;

int main()
{
	int num = 25; 
	int *intptr;
	intptr = &num;
	cout << intptr<<endl; // prints 0x4a00 

	cout << *intptr<< endl; // prints 25
	
	return 0;
}

