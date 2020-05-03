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
		cout << "Apel constructor Animal" << endl;
	}

	Animal(const Animal& ob) {
		this->nume = new char[strlen(ob.nume) + 1];
		strcpy(this->nume, nume);
		cout << "Apel constructor de copiere Animal" << endl;
	}

	~Animal() {
		delete[] nume;
		cout << "Apel destructor Animal";
	}

	void print() {
		cout << "Nume:" << nume << endl;
	}

	Animal& operator= (const Animal& ob) {
		if (this != &ob) {
			delete[]nume;
			this->nume = new char[strlen(ob.nume) + 1];
			strcpy(this->nume, ob.nume);
		}
		cout << "Apel operator = Animal" << endl;
		return *this;
	}
};

class Mamifer : virtual public Animal {
protected:
	int perioadaGestatie;

public:
	Mamifer(char* nume, int perioadaGestatie) : Animal(nume) {
		this->perioadaGestatie = perioadaGestatie;
		cout << "Apel constructor Mamifer" << endl;
	}

	Mamifer(const Mamifer& ob) : Animal(ob.nume) {
		this->perioadaGestatie = ob.perioadaGestatie;
		cout << "Apel constructor copiere Mamifer" << endl;
	}

	~Mamifer() {
		cout << "Apel destructor Mamifer" << endl;
	}

	void print() {
		Animal::print();
		cout << "Perioada gestatiei:" << perioadaGestatie << endl;
	}

	Mamifer& operator=(const Mamifer& ob) {
		if (this != &ob) {
			this->perioadaGestatie = ob.perioadaGestatie;
			Animal::operator=(ob);
		}
		cout << "Apel operator = Mamifer" << endl;
		return *this;
	}
};

class AnimalZburator : virtual public Animal {
protected:
	int altitudineZbor;

public:
	AnimalZburator(char* nume, int altitudineZbor) : Animal(nume) {
		this->altitudineZbor = altitudineZbor;
		cout << "Apel constructor AnimalZburator" << endl;
	}

	AnimalZburator(const AnimalZburator& ob) :Animal(nume) {
		this->altitudineZbor = ob.altitudineZbor;
		cout << "Apel constructor copiere AnimalZbor" << endl;
	}

	~AnimalZburator() {
		cout << "Apel destructor AnimalZburator" << endl;
	}

	AnimalZburator& operator= (const AnimalZburator& ob) {
		if (this != &ob) {
			this->altitudineZbor = ob.altitudineZbor;
			Animal::operator=(ob);
		}
		cout << "Apel operator = AnimalZburator" << endl;
		return *this;
	}

	void print() {
		Animal::print();
		cout << "AltitudineZbor: " << altitudineZbor << endl;
	}
};

class Liliac : public Mamifer, public AnimalZburator {
public:
	Liliac(char* nume, int perioadaGestatie, int altitudineZbor) :
		Mamifer(nume, perioadaGestatie), AnimalZburator(nume, altitudineZbor), Animal(nume) {

		cout << "Apel constructor Liliac" << endl;
	}

	~Liliac() {
		cout << "Apel destructor Liliac" << endl;
	}

	Liliac(const Liliac& ob) :Mamifer(ob), AnimalZburator(ob), Animal(ob) {
		cout << "Apel constructor copiere" << endl;
	}

	Liliac& operator= (const Liliac& ob) {
		if (this != &ob) {
			Mamifer::operator= (ob);
			AnimalZburator::operator= (ob);
		}
		cout << "Apel operator = Liliac" << endl;
		return *this;
	}

	void print() {
		Mamifer::print();
		AnimalZburator::print();
	}
};
int main() {
	Mamifer oaie((char*)"Oaie", 9);
	Mamifer turcana((char*)"Turcana", 7);

	oaie = turcana;
	oaie.print();


	AnimalZburator pasare((char*)"Pasare", 90);
	AnimalZburator rata((char*)"Rata", 80);

	pasare = rata;
	pasare.print();


	Liliac liliac((char*)"Liliac", 2, 6);
	Liliac corona((char*)"Corona", 4, 200);

	liliac = corona;
	liliac.print();


	return 0;
}