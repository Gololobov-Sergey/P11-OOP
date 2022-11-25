#pragma once
#include<iostream>

using namespace std;

class Student
{

	int age;
	char* name;

public:

	Student()
	{
		cout << "Constr" << endl;
		//name = nullptr;
		age = 0;
		name = new char[strlen("No name") + 1];
		strcpy_s(name, strlen("No name") + 1, "No name");
	}

	Student(int a, const char* n)
	{
		age = a;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		cout << "Constr 2 param" << endl;
	}

	void setAge(int a)
	{
		if (a > 120)
			age = 0;
		else
			age = a;
	}

	int getAge()
	{
		return age;
	}

	const char* getName()
	{
		return name;
	}

	void setName(const char* n)
	{
		delete name;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}

	void print();

};


/*inline*/ void Student::print()
{
	cout << "Name: " << ((name) ? name : "No name") << ", Age: " << age << endl;
}


Fraction add(Fraction f);