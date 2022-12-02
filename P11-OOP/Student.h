#pragma once
#include<iostream>
#include"Functions.h"

using namespace std;

class Student
{
	const int id;
	int age;
	char* name;
	int* mark;
	size_t sizeMark;
	static int lastID;
	static int count;

	void foo()
	{
		
	}

public:

	Student() : id{++lastID }, age(0), mark{nullptr}, sizeMark{0}, name{nullptr}
	{
		cout << "Constr" << endl;
		setName("No name");
		count++;
	}

	Student(int age, const char* n): id(++lastID), age(age), mark{ nullptr }, sizeMark{ 0 }, name{ nullptr }
	{
		setAge(age);
		setName(n);
		cout << "Constr 2 param" << endl;
		count++;
	}

	~Student()
	{
		count--;
		delete[] mark;
		delete name;
		cout << "Destructor" << endl;
	}


	void setMark(int m)
	{
		push_back_Array(mark, sizeMark, m);
	}

	void printMark() const
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

	int getAge() const
	{
		return age;
	}

	const char* getName() const
	{
		return name;
	}

	void setName(const char* n)
	{
		delete name;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}

	void print() const;

	static int getCount()
	{
		return count;
	}

	static int getLastID()
	{
		return lastID;
	}

};

int Student::lastID = 0;
int Student::count = 0;


/*inline*/ void Student::print() const
{
	cout << "ID: " << id << ", Name: " << ((name) ? name : "No name") << ", Age: " << age << endl;
}

