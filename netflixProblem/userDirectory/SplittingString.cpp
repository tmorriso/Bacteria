#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void makeVector(string rating, vector<string>& vect);
int main() 
{
    string ratings = "1 2 3 4 5";
    vector<string> vec;
    makeVector(ratings, vec);
    
    for (int i = 0; i < vect.size(); i++)
    {
		cout << vec[i] << endl;
	}
    //istringstream iss(ratings);
    //string word;
    //vector<string> vec;
    //while(iss >> word)
    //{
	//	vec.push_back(word);
	//	cout << word <<endl;
	//}                 
}

void makeVector(string rating, vector<string>& vect)
{
	istringstream iss(rating);
    string word;
    while(iss >> word)
    {
		vect.push_back(word);
		cout << word <<endl;
	}   
	
}            
	
