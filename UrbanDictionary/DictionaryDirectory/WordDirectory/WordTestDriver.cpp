/**Test driver program to ensure Word class is mostly correct
 * ----------------------------------------------------------
 * @author Thomas Morrison
 * Run as: g++ -std=c++11 WordTestDriver.cpp
 * 	    ./a.out
 * ----------------------------------------------------------
*/
#include <iostream>
#include <string>
#include "Word.cpp"
using namespace std;

int main()
{
	Word w1 = Word();
	cout << "Test 1: should output:\n---\nThe word is: Unknown\n---\n";
	cout << "Your output:\n------------------  your output\n";
	cout << w1.wordToString() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 1 results: " << (w1.wordToString() == "The word is: Unknown" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;

	Word w2 = Word("Relax", "To take a break from exerting physical effort");
	cout << "Test 2: should output:\n---\nThe definition is: To take a break from exerting physical effort\n---\n";
	cout << "Your output:\n------------------  your output\n";
	cout << w2.definitionToString() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 2 results: " << (w2.definitionToString() == "The definition is: To take a break from exerting physical effort" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;
	
	cout << "Test 3: call to getWord should output:\n---\nRelax\n---\n";
	cout << "Your output:\n------------------  your output\n";
	cout << w2.getWord() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 3 results: " << (w2.getWord() == "Relax" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;
	
	cout << "Test 4: call to getDefinition should output:\n---\nTo take a break from exerting physical effort\n---\n";
	cout << "Your output:\n------------------  your output\n";
	cout << w2.getDefinition() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 4 results: " << (w2.getDefinition() == "To take a break from exerting physical effort" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;
	
	cout << "Test 5: call to setWord should output:\n---\nCookie Monster\n---\n";
	w2.setWord("Cookie Monster");
	cout << "Your output:\n------------------  your output\n";
	cout << w2.getWord() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 5 results: " << (w2.getWord() == "Cookie Monster" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;
	
	cout << "Test 6: call to setTitle should output:\n---\nFun with C++\n---\n";
	w2.setDefinition("Fun with C++");
	cout << "Your output:\n------------------  your output\n";
	cout << w2.getDefinition() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 6 results: " << (w2.getDefinition() == "Fun with C++" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;
	
	cout << "Test 7: private instance variables. The following lines should NOT compile:\n";
	//cout << b2.author << endl;
	//cout << b2.title << endl;


	return 0;
}
