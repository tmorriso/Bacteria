#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char* argv[]) 
{
	int x = 5;
	double y = x;
	cout << "x = " <<x << endl;
	cout << "y = " <<y << endl;
	string name = "COOkie Monster";
	cout << name.length() <<endl;
	cout << name[3] << endl ;
	cout << name.substr(4,6) << endl;
	//cout << "Liz" + "Boese" << endl;
	cout << name + "Liz" << endl;
	cout << argv[0] << endl;
	cout << argv[1] << endl; 
	int score = stoi (argv[1]);
	return 0;
}


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
