#pragma once
#include<iostream>

using namespace std;


class Array
{
	int* array;
	int size;

public:
	Array() : array{ nullptr }, size{ 0 } {}
	explicit Array(int size) : array{ nullptr }, size{ size } 
	{
		if (size <= 0)
		{
			size = 0;
			return;
		}
		array = new int[size] {0};
	}

	Array(const Array& obj)
	{
		size = obj.size;
		array = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			array[i] = obj.array[i];
		}
	}

	~Array()
	{
		delete[] array;
	}

	void setRandom(int min = 0, int max = 9) const
	{
		for (size_t i = 0; i < size; i++)
		{
			array[i] = rand() % (max - min + 1) + min;
		}
	}

	void print() const
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

