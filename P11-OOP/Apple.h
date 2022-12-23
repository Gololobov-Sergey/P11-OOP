#pragma once
#include<iostream>
#include"Functions.h"

using namespace std;

class Kompot;

class Apple
{
	char* color;
	int diametr;

public:
	Apple();
	Apple(const char* color, int diametr);
	~Apple();
	Apple(const Apple& apple);
	Apple& operator=(const Apple& apple);
	Kompot operator+(const Apple & apple); 
	friend ostream& operator<<(ostream& out, const Apple& apple);
};

Apple::Apple() : color(nullptr), diametr(diametr) {}

Apple::Apple(const char* color, int diametr) : diametr(diametr)
{
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}

inline Apple::~Apple()
{
	delete color;
}

inline Apple::Apple(const Apple& apple)
{
}

inline Apple& Apple::operator=(const Apple& apple)
{
	if (this == &apple)
		return *this;

	delete color;

	this->diametr = apple.diametr;
	this->color = new char[strlen(apple.color) + 1];
	strcpy_s(this->color, strlen(apple.color) + 1, apple.color);

	return *this;
}

inline ostream& operator<<(ostream& out, const Apple& apple)
{
	out << "Apple : Color - " << apple.color << ", Diametr - " << apple.diametr;
	return out;
}




class Kompot
{
	Apple* apples;
	size_t size;

public:
	~Kompot();
	Kompot& operator=(const Kompot& kompot);
	void operator+=(const Apple & apple);
	friend ostream& operator<<(ostream& out, const Kompot& kompot);
};


inline Kompot::~Kompot()
{
	delete[] apples;
}

inline Kompot& Kompot::operator=(const Kompot& kompot)
{
	if (this == &kompot)
		return *this;

	delete[] apples;
	
	this->size = kompot.size;
	this->apples = new Apple[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		this->apples[i] = kompot.apples[i];
	}

	return *this;
}

void Kompot::operator+=(const Apple& apple)
{
	push_back_Array(apples, size, apple);
}



ostream& operator<<(ostream& out, const Kompot& kompot)
{
	out << "Kompot : " << endl;
	for (size_t i = 0; i < kompot.size; i++)
	{
		out << kompot.apples[i] << endl;
	}
	return out;
}

Kompot Apple::operator+(const Apple& apple)
{
	Kompot k;
	k += *this;
	k += apple;
	return k;
}