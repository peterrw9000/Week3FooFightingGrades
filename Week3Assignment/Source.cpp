//Peter Williams
//9-23-21

#include <iostream>
#include <fstream>
#include <sstream>
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
	ifstream myFile("example.txt");
	vector<Student> fooStudents;
	string student;
	if (myFile.is_open())
	{
		int locOfSpace;
		while (getline(myFile, student))
		{
			int count = 0;
			string part2;
			string part3;
			string first;
			string last;
			string gr;
			int grade;
			locOfSpace = student.find(' ');
			first = student.substr(0, locOfSpace);
			part2 = student.substr(locOfSpace, student.length());
			locOfSpace = part2.find(' ');
			last = part2.substr(0, locOfSpace);
			part3 = part2.substr(locOfSpace, student.length());
			locOfSpace = part3.find(' ');
			gr = part3.substr(0, locOfSpace);
			try
			{
				grade = std::stoi(gr);
			}
			catch (exception e)
			{
				cout << "convertion errors";
			}
			fooStudents[count].setFirstName(first);
			fooStudents[count].setLastName(last);
			fooStudents[count].setGrade(grade);
			count++;
		}
	}
	else
	{
		cout << "unable to open";
	}
	/*for (int o = 0; o < fooStudents.size(); o++)
	{
		cout << fooStudents[o].getFirstName() << " " << fooStudents[o].getLastName() << " " << fooStudents[o].getGrade() << endl;
	}*/
	int total = 0;
	int sized = fooStudents.size();
	for (int i = 0; i < sized - 1; i++)
	{
		for (int s = 0; s < sized - i - 1; s++)
		{
			if (fooStudents[s].getGrade() < fooStudents[s + 1].getGrade())
			{
				swap(fooStudents[s], fooStudents[s + 1]);
			}
		}
	}
	//cout << endl;
	for (int o = 0; o < fooStudents.size(); o++)
	{
		cout << fooStudents[o].getFirstName() << " " << fooStudents[o].getLastName() << " "  << fooStudents[o].getGrade() << endl;
		total = total + fooStudents[o].getGrade();
	}
	cout << endl << total/fooStudents.size() << endl;
}