#pragma once
#include <iostream>


using namespace std;

class Humidity;

class Temperature
{
	int temp;

public:
	Temperature(int temp) : temp(temp)	{}

	friend void WeatherInformer(Temperature t, Humidity h);
};


class Humidity
{
	int humidity;

public:
	Humidity(int humidity) : humidity(humidity) {}

	friend void WeatherInformer(Temperature t, Humidity h);
};


void WeatherInformer(Temperature t, Humidity h)
{
	cout << "Temp: " << t.temp << " " << char(248) << "C" << endl;
	cout << "Hum : " << h.humidity << " %" << endl;
}



template<class T1, class T2>
class A
{
	T1 x;
public:
	template<class T2>
	class B
	{
		T2 b;

	public:
		B() {}
		B(int b) : b(b) {}
		int getB() { return b; }
	};
	B<T2> b;

	B<T1> b1;


	A(int a) : b(a) {}

	int getA() { return b.getB(); }

};