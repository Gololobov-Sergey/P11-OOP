#include<iostream>
#include<fstream>

#include"Student.h"
#include"Area.h"
#include"Array.h"
#include"PhoneBook.h"
#include"String.h"
#include"House.h"
#include"Friend.h"
#include"Fraction.h"
#include"Apple.h"
#include"var.h"

using namespace std;

void fooo(String a)
{
	a.print();
}


int main()
{
	/*Apple a1("red", 12);
	Apple a2("green", 15);
	Kompot k;
	k = a1 + a2;
	cout << k << endl;
	{
		Apple a3("yellow", 13);
		k += a3;
		
	}
	cout << k << endl;*/

	/*int t = 9;
	void* pt = &t;
	*((int*)pt) = 888;
	cout << t << endl;*/

	/*var a = 4;
	var b = 5;
	var c = a + b;
	cout << c << endl;*/


	


	/*String str;
	String str1;
	str += str1;
	str += "tytut";

	string st;
	cout << st.max_size() << endl;*/

	/*if (k1 > k2)
	{

	}*/

	//cout.setf(ios::showpos);
	///// 12.12.2022 ////

	// ::  ?:  sizeof  . *
	//  +  -  ++  -- 
	// =, +, -, *, /, %, +=, -=, *=, /=, %=
	// !
	// >, <, ==, !=, >=, <=, &&, ||
	// type
	// [], (), >>, << 


	//Fraction f1(3, 1, 2);
	//Fraction f2(1, 5);
	////Fraction f3 = f1.sum(f2);
	////Fraction f3 = f1;
	////(f1++).print();
	////(++f1).print();
	////f3.print();
	//f1.print();
	//cin >> f1;

	//ofstream fff("fraction.txt");
	//fff << f1;

	//cout << f1 << endl;

	//f1(2, 9);

	//f1[1] = 100;


	//float t = f1;
	//cout << t << endl;

	/*if (f1 >= f2)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}*/

	////cout << 123 << endl;
	////cout << -123 << endl;

	//f2 = f1 * 4; // f1.op*(4)
	//f2 = 4 * f1; // 4.op(f1) !!!???


	//StaticArray<int, 5> a;

	A<int, double> a(10);
	cout << a.getA() << endl;


	//Array<int> a(5);
	//cin >> a;
	//a.setRandom(0, 9);
	//a.print();
	//cout << a << endl;
	/*Array<var> b(10);
	b.setRandom(0, 9);
	cout << b << endl;
	b = a;
	cout << b << endl;*/


	//a[3] = 100;
	//a.print();
	//cout << a["zero"] << endl;



	//Array b(20);

	//Array c = a + b;

	//a += b;

	//b = a; // b.operator=(a);

	//a.print();


	/*String s1("asdfghjik");
	String s2;
	char buff[20] = "fghgfddfg";
	s2 = "ertyuytre";
	s2 = s1;
	s2 = buff;
	s2.print();
	s2.set("mama");
	fooo(s2);
	s2.print();*/
	
	

	/*Array a(20);
	Visualisation vis;
	vis.printArrayInStars(a);*/

	/*A a(20);
	a.getA();

	A::B b(10);*/


	/*Temperature t(10);
	Humidity h(90);

	WeatherInformer(t, h);*/


	//House h;
	//flat* f1 = new flat();
	//flat* f2 = new flat();
	//f1->setSpace(60);
	//f2->setSpace(30);
	//f1->setNumber(330);
	//f2->setNumber(50);
	//Person* p1 = new Person("Vasya Pupkin", 30);
	//Person* p2 = new Person("Pupkin Vasya", 20);
	//Person* p3 = new Person("Vasya Pupkin", 30);
	//Person* p4 = new Person("Pupkin Vasya", 20);
	//f1->addPerson(p1);
	//f1->addPerson(p2);
	//f2->addPerson(p3);
	//f2->addPerson(p4);
	//h.addFlat(f1);
	//h.addFlat(f2);
	//fooo(h);
	////f1->printFull();
	////f2->printFull();


	///// 05.12.2022  ////////


	/*String str;
	str.print();

	String st1(-20);
	st1.print();

	String st2("sdfghjkl");
	st2.print();

	fooo(st2);
	fooo(50);*/






	/*string st = "dfgh";
	int b = 0;*/



	/*Array a(20);
	printArrayInStars(a);*/

	//a.setRandom();
	//a.print();
	///*a.resize(15);
	//a.print();*/
	//a.sort(noEvenFirstAsc);
	//a.print();
	

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



	/*cout << "Count: " << Student::getCount() << endl;
	cout << "LastID: " << Student::getLastID() << endl;

	{
		Student st(20, "Vasya");
		st.print();
		cout << "Count: " << Student::getCount() << endl;
		cout << "LastID: " << Student::getLastID() << endl;
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
	cout << "LastID: " << Student::getLastID() << endl;*/


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