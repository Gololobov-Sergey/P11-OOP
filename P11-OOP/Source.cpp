#include<iostream>

#include"Student.h"

using namespace std;

int main()
{
	Student st(20, "Vasya");
	//st.setAge(2000000);
	st.print();


	Student* st1 = new Student[2];
	st1[0].print();


	st1[0].setName("Yura");

	st1[0].print();


	f3 = f1.add(f2);

	system("pause");
}