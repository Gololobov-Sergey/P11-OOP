#pragma once
#include<iostream>
#include"Functions.h"

using namespace std;

class Abonent
{
    char* info;
    long long number;
public:
    Abonent() : info{ nullptr }, number(1)
    {
    }
    Abonent(const char* a, long long num)
    {
        setInfo(a);
        ((num <= 0) ? number = 1 : number = num);
    }
    Abonent(const Abonent& obj)
    {
        info = nullptr;
        setInfo(obj.info);
        setNumber(obj.number);
    }
    ~Abonent()
    {
        delete info;
    }

    void setInfo(const char* n)
    {
        delete[] info;
        info = new char[strlen(n) + 1];
        strcpy_s(info, strlen(n) + 1, n);
    }

    char* getInfo() const
    {
        return info;
    }

    void setNumber(long long a)
    {
        if (a <= 0)
        {
            return;
        }
        number = a;
    }

    long long getNumber() const
    {
        return number;
    }

    void print() const
    {
        cout << ((info) ? info : "No name") << " - " << number << endl;
    }
};
class PhoneBook
{
    Abonent** telephones;
    size_t size;
public:
    PhoneBook() : telephones{ nullptr }, size(0)
    {

    }

    PhoneBook(const PhoneBook& obj)
    {
        size = obj.size;
        telephones = new Abonent* [size];
        for (size_t i = 0; i < size; i++)
        {
            telephones[i] = new Abonent(obj.telephones[i]->getInfo(), obj.telephones[i]->getNumber());
        }
    }

    ~PhoneBook()
    {
        for (size_t i = 0; i < size; i++)
        {
            delete telephones[i];
        }
        delete[] telephones;
    }

    void printsize()
    {
        cout << size << endl;
    }

    size_t getSize() const
    {
        return size;
    }

    void print() const
    {
        for (size_t i = 0; i < size; i++)
        {
            telephones[i]->print();
        }
    }

    void add(Abonent* a)
    {
        push_back_Array(telephones, size, a);
    }

    void add(const char* name, long long num)
    {
        Abonent* a = new Abonent;
        a->setInfo(name);
        a->setNumber(num);
        push_back_Array(telephones, size, a);
    }
};
