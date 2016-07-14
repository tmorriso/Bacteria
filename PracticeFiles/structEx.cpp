// Struct Example
#include <vector>
#include <iostream>
using namespace std;

const int MAX_NUM_INGREDIENTS = 10;
struct Candy
{
	string name;
	string description;
	double weight;
	string ingredients[MAX_NUM_INGREDIENTS];
	vector<string> stuffers;
};

int main()
{
	Candy kitkat;
	kitkat.name = "KitKat";
	kitkat.description = " Good tasting wafer-ish thing";
	kitkat.weight = .75; 
	
	// Add to vector
	kitkat.ingredients[0] = "Love";
	kitkat.ingredients[1] = "Chocolate";
	
	// Print
	cout << kitkat.name << endl;
	
	
	return 0;
}
	
