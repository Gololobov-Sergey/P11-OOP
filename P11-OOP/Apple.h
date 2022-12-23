#pragma once

class Kompot;

class Apple
{
	char* color;
	int diametr;

public:

	Kompot operator+(const Apple & apple);
};


class Kompot
{
	Apple* kompot;

public:

	void operator+=(const Apple & apple);
};