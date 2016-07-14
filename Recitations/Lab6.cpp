/*GET files from command line
OPEN the files and organize contents
CALCULATE average for each line
APPLY weight to average 
ADD weighted grade
to final grade
OUTPUT final grade
*/

// g++ Lab6.cpp -std=c++11
// ./a.out weights.txt grades.txt

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

int main(int argc, char* argv[])
{
	ifstream weights;
	ifstream grades;
	weights.open(argv[1]);
	grades.open(argv[2]);
	
	string grade;
	float sum = 0.0;
	float count = 0.0;
	float percent = 0.0;
	float weighted = 0.0;
	float finalGrade = 0.0;
	string percentString;
	
	while(grades >> grade)
	{
		
		sum += stoi(grade);
		count ++;
		
		if (grades.peek() == '\n' || grades.eof())
		{
			getline(weights, percentString);
			int index = percentString.find("  ");
			percent = stoi(percentString.substr(index+1));
			percent /= 100.0;
			weighted = (sum / count)*percent;
			finalGrade += weighted;
			count = 0.0;
			sum = 0.0; 
		}
	}
cout << "Final" << finalGrade << "%" << endl;
grades.close();
return 0; 
}		
			
			
		
