
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <conio.h>

using namespace std;

class Animal {
protected:
	char* nume;

public:
	Animal(char* nume) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}

	virtual char* sunet() {
		return (char*)"Nu stiu";
	}

	char* getNume() {
		return nume;
	}
};

class Pisica :public Animal {
public:
	Pisica(char* nume) :Animal(nume) {
	}

	char* sunet() {
		return (char*)"Miau !";
	}
};

class Caine : public Animal {
public:
	Caine(char* nume) : Animal(nume) {
	}

	char* sunet() {
		return (char*)"Ham!";
	}
};

int main() {
	Animal* a = new Animal((char*)"Jerry");
	Animal* t = new Pisica((char*)"Tom");
	Animal* c = new Caine((char*)"Azor");

	cout << a->getNume() << " : " << a->sunet() << endl;
	cout << t->getNume() << " : " << t->sunet() << endl;
	cout << c->getNume() << " : " << c->sunet() << endl;
}