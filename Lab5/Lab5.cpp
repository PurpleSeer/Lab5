#include <iostream>
#include "Cat.h"

using namespace std;

class Base {
public:
	Base() {
		cout << "Конструктор по умолчанию Base\n";
	}

	Base(Base* obj) {
		cout << "Конструктор *obj Base\n";
	}

	Base(Base& obj) {
		cout << "Конструктор &obj Base\n";
	}
	virtual ~Base() {
		cout << "Деструктор Base\n";
	}
};

class Desc : public Base {
public:
	Desc() {
		cout << "Конструктор по умолчанию Desc\n";
	}

	Desc(Desc* obj) {
		cout << "Конструктор *obj Desc\n";
	}

	Desc(Desc& obj) {
		cout << "Конструктор &obj Desc\n";
	}
	~Desc() {
		cout << "Деструктор Desc\n";
	}
};

void func1(Base obj) { //принимает объект
	cout << "Функция 1\n";
}

void func2(Base* obj) {//принимает указатель на объект
	cout << "*Функция 2\n";
}

void func3(Base& obj) {//принимает ссылку на объект
	cout << "&Функция 3\n";
}


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

	cout << "\nПередача объектов как параметров в функции:\n\n";
	cout << "Base:\n\n";
	Base base1 = new Base();
	func1(base1);
	cout << endl;
	Base* base2 = new Base();
	func2(base2);
	cout << endl;
	Base base3 = new Base();
	func3(base3);
	cout << endl;

	cout << "Desc:\n\n";
	Base desc1 = new Desc();
	func1(desc1);
	cout << endl;
	Base* desc2 = new Desc();
	func2(desc2);
	cout << endl;
	Base desc3 = new Desc();
	func3(desc3);
	cout << endl;


	return 0;
}
