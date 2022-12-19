#pragma once
#include<iostream>
#include<cassert>

using namespace std;

class Array;

class Visualisation
{
	bool info = false;

public:
	void printArrayInStars(Array a);

	//void print(Array a)
	//{
	//	//a.array = nullptr;
	//}

	friend class Array;
};


class Array
{
	int* array;
	size_t size;

public:
	Array();

	explicit Array(size_t size);

	Array(const Array& obj);

	~Array();

	Array& operator=(const Array& obj);

	void setRandom(int min, int max) const;

	void print() const;

	void resize(size_t newSize);

	size_t getSize() const;

	int at(size_t index) const;

	void sort(bool (*method)(int, int)) const;

	//friend void printArrayInStars(Array a);

	//friend class Visualisation;

	friend void Visualisation::printArrayInStars(Array a);

	void mmm();

	// TODO

	Array operator+(const Array& a);

	void operator+=(const Array& a);

	int& operator[](int index);

	int& operator[](const char* key);

	friend ostream& operator<<(ostream& out, const Array& a);

	friend istream& operator>>(istream& in, Array& a);

};

Array::Array() : array{ nullptr }, size{ 0 } {}


Array::Array(size_t size) : array{ nullptr }, size{ size }
{
	array = new int[size] {0};
}


Array::Array(const Array& obj)
{
	size = obj.size;
	array = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = obj.array[i];
	}
}

Array::~Array()
{
	delete[] array;
}

Array& Array::operator=(const Array& obj)
{
	if (this == &obj)
		return *this;

	delete[] array;

	size = obj.size;
	array = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = obj.array[i];
	}

	return *this;
}


void Array::setRandom(int min = 0, int max = 9) const
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % (max - min + 1) + min;
	}
}

void Array::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void Array::resize(size_t newSize)
{
	int* newArray = new int[newSize] {0};
	for (size_t i = 0; i < ((newSize < size) ? newSize : size); i++)
	{
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
	size = newSize;
}

size_t Array::getSize() const
{
	return size;
}

int Array::at(size_t index) const
{
	assert(index < size && "Invalid index");
	return array[index];
}

void Array::sort(bool(*method)(int, int)) const
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (method(array[j], array[j + 1]))
				swap(array[j], array[j + 1]);
		}
	}
}

int& Array::operator[](int index)
{
	return array[index];
}

int& Array::operator[](const char* key)
{
	if (strcmp(key, "zero") == 0)
		return array[0];
}


Array Array::operator+(const Array& a)
{
	Array result(size + a.size);

	for (size_t i = 0; i < size; i++)
	{
		result.array[i] = array[i];
	}
	for (size_t i = 0; i < a.size; i++)
	{
		result.array[size + i] = a.array[i];
	}

	return result;
}


void Array::operator+=(const Array& a)
{
	*this = *this + a;
}

ostream& operator<<(ostream& out, const Array& a)
{
	for (size_t i = 0; i < a.size; i++)
	{
		out << a.array[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, Array& a)
{
	for (size_t i = 0; i < a.size; i++)
	{
		in >> a.array[i];
	}
	return in;
}


void Visualisation::printArrayInStars(Array a)
{
	cout << "=================" << endl;
	cout << a.size << endl;
}



void Array::mmm()
{
	Visualisation visual;
	visual.info = true;
}