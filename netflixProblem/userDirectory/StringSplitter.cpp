#include <iostream>
#include <string>
#include <sstream>
#include <vector>
//using namespace std;

int main() 
{
    std::string rating = "1 2 3 4 5";
    
    std::istringstream iss(rating);
    std::string word;
    std::vector<int> ratings;
    while(iss >> word)
    {
		ratings.push_back(std::stoi(word));
		std::cout << word <<std::endl;
	} 
	for (int i = 0; i < ratings.size(); i++)
    {
		std::cout << ratings[i] << std::endl;
	}
	return 0;                
}
