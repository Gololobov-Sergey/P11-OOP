#pragma once
#include<iostream>
#include<cassert>
#include"Fraction.h"

using namespace std;

//class Array;
//
//class Visualisation
//{
//	bool info = false;
//	
//
//public:
//	void printArrayInStars(Array a);
//
//	//void print(Array a)
//	//{
//	//	//a.array = nullptr;
//	//}
//
//	friend class Array;
//};


template<class T>
class Array;

template<class T>
ostream& operator<<(ostream& out, const Array<T>& a);

template<class T>
istream& operator>>(istream& in, Array<T>& a);


template<class T>
class Array
{
	T* array;
	size_t size;

public:
	Array();

	explicit Array(size_t size);

	Array(const Array<T>& obj);

	~Array();

	Array<T>& operator=(const Array<T>& obj);

	void setRandom(T min, T max) const;

	void print() const;

	void resize(size_t newSize);

	size_t getSize() const;

	T at(size_t index) const;

	void sort(bool (*method)(T, T)) const;

	//friend void printArrayInStars(Array a);

	//friend class Visualisation;

	//friend void Visualisation::printArrayInStars(Array a);

	//void mmm();

	// TODO

	Array<T> operator+(const Array<T>& a);

	void operator+=(const Array<T>& a);

	T& operator[](int index);

	T& operator[](const char* key);

	friend ostream& operator<< <T>(ostream& out, const Array& a);

	friend istream& operator>> <T>(istream& in, Array& a);

};

template<class T>
Array<T>::Array() : array{ nullptr }, size{ 0 } {}

template<class T>
Array<T>::Array(size_t size) : array{ nullptr }, size{ size }
{
	array = new T[size];
}

template<class T>
Array<T>::Array(const Array& obj)
{
	size = obj.size;
	array = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = obj.array[i];
	}
}

template<class T>
Array<T>::~Array()
{
	delete[] array;
}

template<class T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this == &obj)
		return *this;

	delete[] array;

	size = obj.size;
	array = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = obj.array[i];
	}

	return *this;
}

template<class T>
void Array<T>::setRandom(T min, T max) const
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % (int)(max - min + 1) + min;
	}
}

template<>
void Array<double>::setRandom(double min, double max) const
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % (int)(max - min + 1) + min + 0.001;
	}
}

template<>
void Array<Fraction>::setRandom(Fraction min, Fraction max) const
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = Fraction(rand() % (max.get_whole() - min.get_whole() + 1) + min.get_whole());
	}
}

template<class T>
void Array<T>::print() const
{
	cout << "Array: " << typeid(T).name() << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

template<class T>
void Array<T>::resize(size_t newSize)
{
	T* newArray = new T[newSize] {0};
	for (size_t i = 0; i < ((newSize < size) ? newSize : size); i++)
	{
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
	size = newSize;
}

template<class T>
size_t Array<T>::getSize() const
{
	return size;
}

template<class T>
T Array<T>::at(size_t index) const
{
	assert(index < size && "Invalid index");
	return array[index];
}

template<class T>
void Array<T>::sort(bool(*method)(T, T)) const
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

template<class T>
T& Array<T>::operator[](int index)
{
	return array[index];
}

template<class T>
T& Array<T>::operator[](const char* key)
{
	if (strcmp(key, "zero") == 0)
		return array[0];
}

template<class T>
Array<T> Array<T>::operator+(const Array<T>& a)
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

template<class T>
void Array<T>::operator+=(const Array<T>& a)
{
	*this = *this + a;
}

template<class T>
ostream& operator<<(ostream& out, const Array<T>& a)
{
	for (size_t i = 0; i < a.size; i++)
	{
		out << a.array[i] << " ";
	}
	return out;
}


template<class T>
istream& operator>>(istream& in, Array<T>& a)
{
	for (size_t i = 0; i < a.size; i++)
	{
		in >> a.array[i];
	}
	return in;
}


//void Visualisation::printArrayInStars(Array a)
//{
//	cout << "=================" << endl;
//	cout << a.size << endl;
//}
//
//
//
//void Array::mmm()
//{
//	Visualisation visual;
//	visual.info = true;
//}


template<class T, size_t size>
class StaticArray
{
	T data[size];

public:
	StaticArray()
	{
			
	}

};