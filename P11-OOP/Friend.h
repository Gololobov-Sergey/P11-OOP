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