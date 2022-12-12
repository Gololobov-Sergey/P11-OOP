#pragma once
#include<iostream>
#include<iomanip>
#include<Windows.h>


using namespace std;

enum Color
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



template<class T>
void setArray(T* arr, int size, int min = 0, int max = 9)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

template<class T>
T* push_back_Array(T*& a, size_t& size, const T& value)
{
	T* temp = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = a[i];
	}
	temp[size] = value;
	delete[] a;
	size++;
	a = temp;
	return temp;
}

template<class T>
T* remove_Array(T*& a, size_t& size, size_t pos)
{
	if (pos < 0 || pos > size - 1)
		return a;
	T* temp = new T[size - 1];
	for (size_t i = 0; i < pos; i++)
	{
		temp[i] = a[i];
	}
	for (size_t i = pos + 1; i < size; i++)
	{
		temp[i - 1] = a[i];
	}
	delete[] a;
	size--;
	a = temp;
	return temp;
}


bool asc(int a, int b)
{
	return a > b;
}

bool desc(int a, int b)
{
	return a < b;
}

bool noEvenFirstAsc(int a, int b)
{
	if (a % 2 == 1 && b % 2 == 0)
		return false;
	if (a % 2 == 0 && b % 2 == 1)
		return true;
	return asc(a, b);
}