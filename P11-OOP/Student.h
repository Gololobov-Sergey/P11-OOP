#pragma once
#include<iostream>
#include"Functions.h"

using namespace std;

class Student
{

	int age;
	char* name;
	int* mark;
	size_t sizeMark;

	void foo()
	{
		
	}

public:

	Student()
	{
		cout << "Constr" << endl;
		mark = nullptr;
		sizeMark = 0;
		name = nullptr;
		age = 0;
		setName("No name");
		/*name = new char[strlen("No name") + 1];
		strcpy_s(name, strlen("No name") + 1, "No name");*/
	}

	Student(int age, const char* n)
	{
		mark = nullptr;
		sizeMark = 0;
		setAge(age);
		setName(n);
		/*name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);*/
		cout << "Constr 2 param" << endl;

		/*age = age;
		this->age = 9;
		this->foo();

		return *this;*/
	}

	~Student()
	{
		delete[] mark;
		delete name;
		cout << "Destructor" << endl;
	}


	void setMark(int m)
	{
		push_back_Array(mark, sizeMark, m);
	}

	void printMark()
	{
		for (size_t i = 0; i < sizeMark; i++)
		{
			cout << mark[i] << ", ";
		}cout << endl;
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

