// Thomas Morrison
// October 21, 2015
// Lab 7
// Bacteria Growth Program

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	const int ROWS = 11;
	const int COLS = 2;
	
	double k = -1.0;
	double array[11][2];
	while (k < 0.0 || k>= 1.0) 
	{
		cout << "Enter a the constant of proportionality [0.0 - 1.0): ";
		cin >> k;
		if (k < 0.0 || k>= 1.0)
		{
			cout << "*** Invalid input; the value must be in the range [0.0 - 1.0): Try again " << endl;
		}
	}

	int initialPopulation = -1;
	while (initialPopulation < 1 || initialPopulation > 1000)
	{
		cout << "Enter the size of the initial population [1-1000]: ";
		cin >> initialPopulation;
		if (initialPopulation < 1 || initialPopulation > 1000)
		{
			cout << "*** Invalid input; the value must be in the range [0 - 1000]: Try again " << endl;
		}
	}
	for (int i = 0; i<ROWS; i++)
	{
		array[i][0]=(double) i;
		array[i][1]= initialPopulation * exp(k * (double) i);
	}
	
	cout << setw(34) << "Bacteria Growth Summary" << endl;
	cout << setw(14) << "Hours" << setw(20) << "Population" << endl;
	cout << setw(14) << "-----" << setw(20) << "----------" << endl;
	
	for (int i = 0; i < ROWS; i++)
	{
		cout << setw(12) << fixed << setprecision(0) <<array[i][0] << setw(20) << fixed << setprecision(3) << array[i][1] << endl;
	}

	return 0;
}




