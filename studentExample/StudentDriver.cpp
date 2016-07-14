// driver for student example
#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
	Student liz = Student ("liz", "Boese", 7);
	cout << liz.getLastName() << endl;
}

