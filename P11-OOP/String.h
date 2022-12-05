#pragma once
#include<iostream>

using namespace std;

class String
{
	char* str;

public:
	String();

	String(size_t size);

	String(const char* str);

	String(const String& obj);

	~String();

	void set();

	void set(const char* str);

	size_t length();

	void print();

};

String::String()
{
	str = new char[81];
	for (size_t i = 0; i < 81; i++)
	{
		str[i] = ' ';
	}
	str[81] = '\0';
}

String::String(size_t size)
{

}

String::String(const char* str)
{
}

String::String(const String& obj)
{
}

String::~String()
{

}

void String::set()
{
}

void String::set(const char* str)
{
}

size_t String::length()
{
	size_t length = 0;
	while (str[length++]);
	return length;
}

void String::print()
{
	cout << str << endl;
}