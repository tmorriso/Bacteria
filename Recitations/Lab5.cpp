/*
 * Thomas Morrison
 * October 7, 2015 
 * Lab 5 C++ Program for calculating change options from a vending machine
 * Pseudo Code: 
 * DISPLAY "Enter change (between 1 and 99): "
 * SET change to input
 * DISPLAY "change cents in coins"
 * SET Quarters = change divided by 25
 * DISPLAY "
 * SET remainder to changeLeft
 * Divide changeLeft by 10
 * SET remainder to changeLeft
 * Divide changeLeft by 5
 * SET remainder to changeLeft				
 * DISPLAY "changeLeft pennies" 
*/			

#include <iostream> 
using namespace std;

int QUARTER = 25;
int DIME = 10;
int NICKEL = 5;
int PENNY = 1;

int main()
{
	int changeLeft;
	int quarters; 
	int dimes;
	int nickels;
	int pennies; 
	int change;
	cout << "Enter change (1-99)";
	cin >> change;
	cout << change << " cents in coins: " << endl;
	if (change >= 1 && change <= 99)
		{
		quarters = change/ QUARTER;
		changeLeft = change % QUARTER;
		cout << quarters << " quarters" << endl;
	
		dimes = changeLeft/ 10;
		changeLeft = changeLeft % 10;
		cout << dimes << " dimes" << endl;
	
		nickels = changeLeft/ 10;
		changeLeft = changeLeft % 10;
		cout << nickels << " nickels and" << endl;
	cout << changeLeft << " pennies" << endl;
}
	else 
	{
		cout << "Invalid amount of change" << endl;
}
		
	return 0; 
}





