#pragma once
#include<iostream>

using namespace std;

enum class TYPE
{
	NOTYPE = -1, INT, DOUBLE, STRING
};

class var
{
	void* value = nullptr;
	TYPE type = TYPE::NOTYPE;

public:
	var() {}

	var(int val) : type(TYPE::INT) 
	{
		value = new int;
		*(int*)value = val;
	}

	var(double val) : type(TYPE::DOUBLE)
	{
		value = new double;
		*(double*)value = val;
	}

	var(const char* val) : type(TYPE::STRING)
	{
		value = new char[strlen(val)+1];
		strcpy_s((char*)value, strlen(val) + 1, val);
	}

	var operator+(const var& val)
	{
		switch (this->type)
		{
		case TYPE::NOTYPE:
			break;
		case TYPE::INT:
			switch (val.type)
			{
			case TYPE::NOTYPE:
				break;
			case TYPE::INT:
			{
				int a = *(int*)this->value + *(int*)val.value;
				return var(a);
			}
			case TYPE::DOUBLE:
			{
				int a = *(int*)this->value + *(double*)val.value;
				return var(a);
			}
			case TYPE::STRING:
				break;
			default:
				break;
			}
			break;
		case TYPE::DOUBLE:
			break;
		case TYPE::STRING:
			break;
		default:
			break;
		}
	}

	friend ostream& operator<<(ostream& out, const var& var);
};

ostream& operator<<(ostream& out, const var& var)
{
	switch (var.type)
	{
	case TYPE::NOTYPE:
		break;
	case TYPE::INT:
		out << *(int*)var.value;
		break;
	case TYPE::DOUBLE:
		break;
	case TYPE::STRING:
		break;
	default:
		break;
	}
	return out;
}