//Student header file
#ifndef STUDENT_H
#define STUDENT_H
class Student
{
	// instance variables 
	private:
		std::string firstName; 
		std::string lastName;
		int age;
	// Functions
	public:
		Student();
		Student(std::string, std::string, int);
		std::string getLastName();
		void setLastName(std::string);
};
#endif
