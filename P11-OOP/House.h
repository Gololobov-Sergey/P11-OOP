#pragma once
#include <iostream>
#include "Functions.h"

using namespace std;

class Person
{
	char* fullname;
	size_t age;

public:

	Person();

	Person(const char* fullname, int age);

	Person(const Person& obj);

	~Person();

	void print() const;

	void setFullName(const char* fullname);

	void setAge(size_t age);

	void setFullInfo(const char* full, size_t age);

	const char* getFullName() const;

	size_t getAge() const;
};

Person::Person() : Person("No name", 0) {}

Person::Person(const char* fullname, int age) : fullname{ nullptr }
{
	setFullName(fullname);
	setAge(age);
}

Person::Person(const Person& obj)
{
	this->fullname = nullptr;
	setAge(obj.age);
	setFullName(obj.fullname);
}

Person::~Person()
{
	delete this->fullname;
}

void Person::print() const
{
	cout << "Name - " << fullname << ", Age - " << age << endl;
}

void Person::setFullName(const char* fullname)
{
	delete this->fullname;
	this->fullname = new char[strlen(fullname) + 1];
	strcpy_s(this->fullname, strlen(fullname) + 1, fullname);
}

void Person::setAge(size_t age)
{
	this->age = age;
}

void Person::setFullInfo(const char* fullname, size_t age)
{
	setFullName(fullname);
	setAge(age);
}

const char* Person::getFullName() const
{
	return this->fullname;
}

size_t Person::getAge() const
{
	return this->age;
}

class flat
{
	Person** people;
	
	size_t number;   // номер квартиры
	size_t space;    // площадь, квадратные метры

public:

	size_t size;     // количество людей (размер массива)

	flat();

	flat(const flat& obj);

	~flat();

	size_t getAmountOfPeople() const;

	size_t getSpace() const;

	size_t getNumber() const;

	void setSpace(size_t space);

	void setNumber(size_t space);

	void printFlat() const; // выводит информацию о квартире

	void printFull() const; // выводит информацию о квартире включая жителей и их информацию

	void addPerson(Person* person);

	void addPerson(const char* fullname, size_t age);

	void delPerson(size_t num);

	void setPeople(Person** a);

	Person** getPeople();
};

flat::flat() : people{ nullptr }, size{ 0 }, number{ 0 }, space{ 0 } {}

flat::flat(const flat& obj)
{
	size = obj.size;
	number = obj.number;
	space = obj.space;
	people = new Person * [size];
	for (size_t i = 0; i < size; i++)
	{
		people[i] = new Person(obj.people[i]->getFullName(), obj.people[i]->getAge());
	}
}

flat::~flat()
{
	for (size_t i = 0; i < size; i++)
	{
		delete people[i];
	}
	delete[] people;
}

size_t flat::getAmountOfPeople() const
{
	return size;
}

size_t flat::getSpace() const
{
	return space;
}

size_t flat::getNumber() const
{
	return number;
}

void flat::setSpace(size_t space)
{
	this->space = space;
}

void flat::setNumber(size_t number)
{
	this->number = number;
}

void flat::printFlat() const
{
	cout << "Number - " << number << ", People - " << size << ", Space - " << space << endl;
}

void flat::printFull() const
{
	printFlat();
	for (size_t i = 0; i < size; i++)
	{
		cout << i + 1 << ". ";
		people[i]->print();
	}
}

void flat::addPerson(Person* person)
{
	push_back_Array(people, size, person);
}

void flat::addPerson(const char* fullname, size_t age)
{
	Person* a = new Person;
	a->setFullInfo(fullname, age);
	push_back_Array(people, size, a);
}

void flat::delPerson(size_t num)
{
	remove_Array(people, size, num - 1);
}

void flat::setPeople(Person** a)
{
	/*for (size_t i = 0; i < size; i++)
	{
		delete people[i];
	}
	delete[] people;*/
	people = a;
}

Person** flat::getPeople()
{
	return people;
}
class House
{
	flat** flats;
	size_t size;

public:
	House();

	House(const House& obj);

	~House();

	size_t getSize() const;

	void addFlat(flat* flat);

	void addFlat(size_t number, size_t space);

	flat** getFlat() const;

	void print() const;
};

House::House() : flats{ nullptr }, size{ 0 } {}

House::House(const House& obj)
{
	size_t len; // не получилось, не смог обратиться к классу человека, не давало доступ, хотелось бы на паре посмотреть как решить эту проблему
	size = obj.size;
	flats = new flat * [size];
	for (size_t i = 0; i < size; i++)
	{
		flats[i] = new flat;
		flats[i]->size = obj.flats[i]->size;
		flats[i]->setNumber(obj.flats[i]->getNumber());
		flats[i]->setSpace(obj.flats[i]->getSpace());
		len = obj.flats[i]->getAmountOfPeople();
		flats[i]->setPeople(new Person * [len]);
		for (size_t j = 0; j < len; j++)
		{
			flats[i]->getPeople()[j] = new Person(obj.getFlat()[i]->getPeople()[j]->getFullName(), obj.getFlat()[i]->getPeople()[j]->getAge());
		}
	}
}

House::~House()
{
	delete flats;
}

size_t House::getSize() const
{
	return size;
}

void House::addFlat(flat* flat)
{
	push_back_Array(flats, size, flat);
}

void House::addFlat(size_t number, size_t space)
{
	//flat* a = new flat;
	//a. // а как обратиться к классу человека если класс приватный? в классе с квартирами получилось, а тут почему-то не могу, не даёт доступа
	//push_back_Array(people, size, a);
}

inline flat** House::getFlat()const
{
	return flats;
}

inline void House::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		flats[i]->printFull();
	}
}





