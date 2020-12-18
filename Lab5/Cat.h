#pragma once

#include <iostream>
using namespace std;

class Cat {

private:
	string CN = "Cat";

public:
	int height, weight;
	string name,colors;

	Cat() {
		this->height = 0;
		this->weight = 0;
		this->name = "";
		this->colors = "";
		cout << "Конструктор по умолчанию Cat\n";
	}

	Cat(int a, int b, string c, string d) {
		this->height = a;
		this->weight = b;
		this->name = c;
		this->colors = d;
		cout << "Конструктор с параметрами Cat\n";
	}

	Cat(Cat& A) {
		this->height = A.height;
		this->weight = A.weight;
		this->name = A.name;
		this->colors = A.colors;
		cout << "Конструктор копирующий Cat\n";
	}

	virtual bool isA(string classname) {
		cout << "Виртуальный метод isA Cat\n";
		if (classname == CN)
			return 1;
		else
			return 0;
	}

	virtual string ClassName() {
		cout << "Виртуальный метод ClassName Cat\n";
		return CN;
	}

	void Method() {
		cout << "Метод Cat\n";
	}

	virtual ~Cat() {
		cout << "Деструктор Cat\n";
	}

};

class My_cat :public Cat {

private:
	string CN = "My_cat";

public:

	My_cat() {
		this->height = 70;
		this->weight = 6;
		this->name = "Tisha";
		this->colors ="red & white";
		cout << "Конструктор по умолчанию My_cat\n";
	}

	My_cat(int a, int b, int c, string d) {
		this->colors = a;
		this->height = b;
		this->weight = c;
		this->name = d;
		cout << "Конструктор с параметрами My_cat\n";
	}

	My_cat(My_cat& C) {
		this->colors = C.colors;
		this->height = C.height;
		this->weight = C.weight;
		this->name = C.name;
		cout << "Конструктор копирующий My_cat\n";
	}

	bool isA(string classname) {
		cout << "Невиртуальный метод isA My_cat\n";
		if (classname == CN)
			return 1;
		else
			return 0;
	}

	string ClassName() {
		cout << "Невиртуальный метод ClassName My_cat\n";
		return CN;
	}

	void Method() {
		cout << "Метод My_cat\n";
	}

	~My_cat() {
		cout << "Деструктор My_cat\n";
	}
};
