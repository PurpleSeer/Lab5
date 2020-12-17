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
		cout << "����������� �� ��������� Cat\n";
	}

	Cat(int a, int b, string c, string d) {
		this->height = a;
		this->weight = b;
		this->name = c;
		this->colors = d;
		cout << "����������� � ����������� Cat\n";
	}

	Cat(Cat& A) {
		this->height = A.height;
		this->weight = A.weight;
		this->name = A.name;
		this->colors = A.colors;
		cout << "����������� ���������� Cat\n";
	}

	virtual bool isA(string classname) {
		cout << "����������� ����� isA Cat\n";
		if (classname == CN)
			return 1;
		else
			return 0;
	}

	virtual string ClassName() {
		cout << "����������� ����� ClassName Cat\n";
		return CN;
	}

	void Method() {
		cout << "����� Cat\n";
	}

	virtual ~Cat() {
		cout << "���������� Cat\n";
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
		cout << "����������� �� ��������� My_cat\n";
	}

	My_cat(int a, int b, int c, string d) {
		this->colors = a;
		this->height = b;
		this->weight = c;
		this->name = d;
		cout << "����������� � ����������� My_cat\n";
	}

	My_cat(My_cat& C) {
		this->colors = C.colors;
		this->height = C.height;
		this->weight = C.weight;
		this->name = C.name;
		cout << "����������� ���������� My_cat\n";
	}

	bool isA(string classname) {
		cout << "������������� ����� isA My_cat\n";
		if (classname == CN)
			return 1;
		else
			return 0;
	}

	string ClassName() {
		cout << "������������� ����� ClassName My_cat\n";
		return CN;
	}

	void Method() {
		cout << "����� My_cat\n";
	}

	~My_cat() {
		cout << "���������� My_cat\n";
	}
};
