// Files
#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
	string line;
	ifstream myfile ("messages.txt");
	if (myfile)
	{
		int linenum = 0;
		while (! myfile.eof())
		{
			getline(myfile, line);
			cout << ++linenum << " " << line << '\n'; // '\n' = endl 
		}
		myfile.close();
	}
	else cout << "Unable to open file\n";
	return 0;
}
