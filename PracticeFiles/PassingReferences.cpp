// Example Passing references
#include <iostream> 
using namespace std;

void swap(int& a, int& b);
void swap(char& a, char& b);
void swap(int&, int&, char&);
void swap(char&, int&, int&); 

int main()
{
	int x = 5;
	int y = 6;
	cout << "main() &x = " << &x << endl;
	swap(x,y); 
	cout << "main() x = " << x << endl;
	cout << "main() y = " << y << endl;
	return 0;
}
void swap(int& a, int& b) 
{
	int temp = a;
	a = b;
	b = temp;
	cout << " swap() &a = " << &a << endl;
	cout << " swap() a = " << a << endl;
	cout << " swap() b = " << b << endl;
}
void swap(char& a, char& b) 
{
	char temp = a;
	a = b;
	b = temp;
}



