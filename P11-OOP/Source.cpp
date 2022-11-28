#include<iostream>

#include"Student.h"

using namespace std;

int main()
{
	Student st(20, "Vasya");
	//st.setAge(2000000);
	st.print(); //print(st)
	st.setMark(10);
	st.setMark(10);
	st.setMark(10);
	st.setMark(10);
	st.printMark();
	st.~Student();
	st.setMark(10);
	st.setMark(10);
	st.printMark();
	st.print();

	Student* st1 = new Student[2];
	st1[0].print();


	st1[0].setName("Yura");

	st1[0].print();

	delete[] st1;


	system("pause");
}