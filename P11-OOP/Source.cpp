#include<iostream>

#include"Student.h"
#include"Area.h"
#include"Array.h"
#include"PhoneBook.h"
#include"String.h"

using namespace std;

void fooo(String a)
{
	a.print();
}


int main()
{

	///// 05.12.2022  ////////


	/*String str;
	str.print();*/

	/*String st1(20);
	st1.print();

	String st2("sdfghjkl");
	st2.print();

	fooo(st2);*/
	//fooo(50);






	/*string st = "dfgh";
	int b = 0;*/



	/*const Array a(10);
	a.setRandom();
	a.print();
	fooo(a);
	a.print();*/

	

	/*PhoneBook b;
	b.add("Vasya", 123456789);
	Abonent* a = new Abonent("Petya", 987654321);
	b.add(a);
	b.print();


	PhoneBook b1(b);
	b1.print();*/

	//Student st(20, "Vasya");
	//st.print();

	///////1
	//Student st1(st);
	//st1.print();


	/////2
	/////fooo(st);

	//st.print();



	//cout << "Count: " << Student::getCount() << endl;
	//cout << "LastID: " << Student::getLastID() << endl;

	{
		//Student st(20, "Vasya");
		//st.print();
		//cout << "Count: " << Student::getCount() << endl;
		//cout << "LastID: " << Student::getLastID() << endl;
		{
			Student st1;
			st1.print();
			cout << "Count: " << Student::getCount() << endl;
			cout << "LastID: " << Student::getLastID() << endl;
		}
		cout << "Count: " << Student::getCount() << endl;
		cout << "LastID: " << Student::getLastID() << endl;
	}
	cout << "Count: " << Student::getCount() << endl;
	cout << "LastID: " << Student::getLastID() << endl;

	Student st(20, "Vasya");
	st.print();
	cout << "Count: " << Student::getCount() << endl;
	cout << "LastID: " << Student::getLastID() << endl;


	/*Student st(20, "Vasya");
	st.print();*/
	

	/*const Array a(10);
	a.setRandom();
	a.print();*/


	//Area::Rectangle_OnDiagonalAndAngle(12.2f, 'a');

	/*Student* st1 = new Student[2];
	st1[0].print();


	st1[0].setName("Yura");

	st1[0].print();

	delete[] st1;*/

	/*int a1 = 9.2;
	int a2(9.2);
	int a3{ (int)9.2 };*/



	system("pause");
}