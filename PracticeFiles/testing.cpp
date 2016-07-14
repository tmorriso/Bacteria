#include <iostream>

#include <fstream>

using namespace std;

int main(int argc, char *argv[] )

{

 ifstream in;

 in.open(argv[1]);

 if (in.is_open()) // Ensure file was opened properly

 {

 int value;

 while (in >> value) // Read until end of file

 cout << value << endl;

 in.close();

 }

 else

 cout << "Unable to load in the file" << endl;

}
