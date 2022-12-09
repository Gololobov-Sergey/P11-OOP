#pragma once
#include<iostream>

using namespace std;

class String
{
	char* str;

public:
	String();

	explicit String(size_t size);

	explicit String(const char* str);

	String(const String& obj);

	~String();

	void set();

	void set(const char* str);

	size_t length() const;

	void print();

};

String::String()
{
	str = new char[(size_t)81];
	for (size_t i = 0; i < (size_t)81; i++)
	{
		str[i] = ' ';
	}
	str[(size_t)80] = '\0';
}

String::String(size_t size)
{
	str = new char[size + 1];
	for (size_t i = 0; i < size + 1; i++)
	{
		str[i] = ' ';
	}
	str[size] = '\0';
}

String::String(const char* str) : str(nullptr)
{
	set(str);
}

String::String(const String& obj)
{
	size_t size = obj.length();
	str = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		str[i] = obj.str[i];
	}
}

String::~String()
{
	delete str;
}


void String::set()
{
	char name[1024];
	cin.getline(name, 1024);
	set(name);
}

void String::set(const char* name)
{
	delete str;
	size_t length = 0;
	while (name[length++]);
	str = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		str[i] = name[i];
	}
}

size_t String::length() const
{
	size_t length = 0;
	while (str[length++]);
	return length;
}

void String::print()
{
	cout << str << endl;
}