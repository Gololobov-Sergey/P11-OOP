#include<iostream>

#include"Student.h"
#include"Area.h"
#include"Array.h"

using namespace std;


int main()
{
	/*cout << "Count: " << Student::getCount() << endl;
	cout << "LastID: " << Student::getLastID() << endl;

	{
		Student st(20, "Vasya");
		cout << "Count: " << Student::getCount() << endl;
		cout << "LastID: " << Student::getLastID() << endl;
		{
			Student st1(20, "Vasyasss");
			cout << "Count: " << Student::getCount() << endl;
			cout << "LastID: " << Student::getLastID() << endl;
		}
		cout << "Count: " << Student::getCount() << endl;
		cout << "LastID: " << Student::getLastID() << endl;
	}
	cout << "Count: " << Student::getCount() << endl;
	cout << "LastID: " << Student::getLastID() << endl;
	Student st(20, "Vasya");
	cout << "Count: " << Student::getCount() << endl;
	cout << "LastID: " << Student::getLastID() << endl;*/


	/*Student st(20, "Vasya");
	st.print();*/
	

	const Array a(10);
	a.setRandom();
	a.print();


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