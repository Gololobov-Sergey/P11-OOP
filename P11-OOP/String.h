#pragma once
#include<iostream>

using namespace std;

class String
{
	char* str = nullptr;

public:
	String();

	explicit String(size_t size);

	String(const char* str);

	String(const String& obj);

	~String();

	String& operator=(const String& obj);

	void set();

	void set(const char* str);

	size_t length() const;

	void print();

	//TODO

	String operator+(const String& st);

	void operator+=(const String& st);


	// TODO2

	void clear();

	String& insert(size_t pos, size_t count, const char symbol);
	String& insert(size_t pos, const String& st);

	String& erase(size_t pos, size_t count);

	void push_back(const char symbol);

	String& append(const String& st);
	String& append(const String& st, size_t count);

	int compare(const String& st); // 1 0 -1

	String substr(size_t pos, size_t count);

	int find(const String& st);             //-1 not found
	int find(const String& st, size_t pos); //-1 not found

	auto operator<=>(const String& st);

	friend ostream& operator<<(ostream& out, const String& st);

	friend istream& operator>>(istream& in, String& st);

	char& operator[](size_t index);

};


String::String() : String(80) { }

String::String(size_t size)
{
	str = new char[size + 1];
	for (size_t i = 0; i < size + 1; i++)
	{
		str[i] = ' ';
	}
	str[size] = '\0';
}

String::String(const char* str)
{
	set(str);
}

String::String(const String& obj)
{
	set(obj.str);
}

String::~String()
{
	delete str;
}

String& String::operator=(const String& obj)
{
	if (this == &obj)
		return *this;
	set(obj.str);
	return *this;
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