#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char* argv[]) //name of method
{
	cout << argc << endl;
	if (argc != 3)
	{
		cout<<"Usage: " <<argv[0] << "num1 num2" << endl;
		exit(1);
}
cout << argv[1] << endl;
cout << argv[2] << endl;
return 0;


/* 
cout 
represents a destination (usuallly the screen ) to which the 

white space- used to seperate words and symbols in a  program 

identifiers:
- Can be a variable name, class name, constant, function name
- Can consist of letter, digits, or underscore '_'
- Case sensitive 
- C++ reserved words

Constants (2 types)

#define PI 3.145962

count++ = ++count Equivalent to: count = count + 1

shorting conversion you have to cast


*/
