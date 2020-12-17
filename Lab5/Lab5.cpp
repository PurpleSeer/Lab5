#include <iostream>
#include "PL.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "");

	Cat* Cat1 = new Cat();
	My_cat* My_cat1 = new My_cat();
	Cat* Cat2 = new My_cat();

	cout << "\nПроверка на принадлежность\n";
	cout << "\nС помощью метода Classname:\n";
	cout << Cat1->ClassName() << endl;
	cout << My_cat1->ClassName() << endl;
	cout << Cat2->ClassName() << endl;

	cout << "\nС помощью метода isA:\n";
	cout << Cat1->isA("Cat") << endl;
	cout << My_cat1->isA("My_cat") << endl;
	cout << Cat2->isA("Cat") << endl << endl;

	cout << "Проверка типов dynamic_cast:\n";

	My_cat* My_cat2 = dynamic_cast<My_cat*>(Cat2);
	cout << My_cat2->ClassName() << endl;
	My_cat2->Method();
	Cat2->Method();
	cout << endl;

	My_cat* My_cat3 = new My_cat;
	cout << "\nОпасное приведение типов:\n";
	if (Cat2->isA("Pear_Tree"))
		My_cat3 = (My_cat*)Cat2;
	cout << My_cat3->ClassName() << endl;

	return 0;
}
