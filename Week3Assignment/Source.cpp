//Peter Williams
//9-23-21

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
	string firstName;
	string lastName;
	int grade;
public:
	//Constructor
	Student()
	{
		firstName = "";
		lastName = "";
		grade = 0;
	}
	//Getters and Setters
	void setFirstName(string fn)
	{
		firstName = fn;
	}
	string getFirstName()
	{
		return firstName;
	}
	void setLastName(string ln)
	{
		lastName = ln;
	}
	string getLastName()
	{
		return lastName;
	}
	void setGrade(int g)
	{
		grade = g;
	}
	int getGrade()
	{
		return grade;
	}
};

int main()
{
	ifstream myFile("test.txt");
	vector<Student> fooStudents;
	vector<string> studentParts;
	string student;
	if (myFile.is_open())
	{
		while (getline(myFile, student))
		{
			//studentParts.push_back(student);
			cout << student << endl;
		}
	}
	else
	{
		cout << "unable to open";
	}
	/*for (int i = 0; i < studentParts.size(); i++)
	{
		cout << studentParts[i] << endl;
	}*/
}