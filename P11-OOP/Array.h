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