#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
using namespace std;

class Cursa {
protected:
	char* plecare;

public:
	char* dest;
	int ora;
	int numar;
	Cursa(int numar, char* plecare, char* dest, int ora) {
		this->plecare = new char[strlen(plecare) + 1];
		strcpy(this->plecare, plecare);

		this->dest = new char[strlen(dest) + 1];
		strcpy(this->dest, dest);

		this->numar = numar;
		this->ora = ora;
		//cout << "Apel constructor Cursa";
	}

	~Cursa() {
		//cout << "Apel destructor Cursa";
	}

	Cursa(const Cursa& c) {
		plecare = new char[strlen(plecare) + 1];
		strcpy(plecare, c.plecare);

		dest = new char[strlen(dest) + 1];
		strcpy(dest, c.dest);

		numar = c.numar;
		ora = c.ora;
		//cout << "Apel constructor de copiere";
	}

	Cursa& operator = (Cursa& c) {
		//cout << "Apel de atribuire Cursa" << endl;
		if (this != &c) {
			delete[]plecare;
			delete[]dest;

			plecare = new char[strlen(c.plecare) + 1];
			strcpy(plecare, c.plecare);

			dest = new char[strlen(c.dest) + 1];
			strcpy(dest, c.dest);

			numar = c.numar;
			ora = c.ora;
		}
		return*this;
	}

	void afiseaza() {
		cout << "numar:" << numar << endl;
		cout << "plecare:" << plecare << endl;
		cout << "dest:" << dest << endl;
		cout << "ora:" << ora << endl;
	}

};

class Transport {
	Cursa* curse[100];
	int nrCurse = 0;
	char* nume;

public:
	Transport(char* nume) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}

	void adaugaCursa(Cursa* c) {
		curse[nrCurse] = c;
		nrCurse++;
	}

	bool cautareCursa(int numar) {
		bool gasit = false;
		for (int i = 0; i < nrCurse; i++) {
			Cursa* c = curse[i];
			if (c->numar == numar)
				gasit = true;
		}
		return gasit;
	}

	void listareCurse() {
		for (int i = 0; i < nrCurse; i++) {
			curse[i]->afiseaza();
		}
	}

	void ordonareCursa() {
		for (int i = 0; i < nrCurse - 1; i++)
			for (int j = i + 1; j < nrCurse; j++)
				if (curse[i]->ora > curse[j]->ora ||
					(curse[i]->ora == curse[j]->ora && curse[i]->dest > curse[j]->dest)) {
					Cursa* aux = curse[i];
					curse[i] = curse[j];
					curse[j] = aux;
				}
	}
};

int main() {
	int nrTotal;
	int numar;
	char plecare[20];
	char dest[20];
	int ora;
	cout << "Introduceti numarul total de curse:";
	cin >> nrTotal;
	Transport* t = new Transport((char*)"Normandia");

	for (int i = 0; i < nrTotal; i++) {
		cout << "Introduceti numarul cursei:";
		cin >> numar;
		cout << "Introduceti punctul de plecare:";
		cin >> plecare;
		cout << "Introduceti punctul de destinatie:";
		cin >> dest;
		cout << "Introduceti ora de plecare si sosire:";
		cin >> ora;
		cout << "Introduceti date despre cursa:" << endl;

		Cursa* c = new Cursa(numar, plecare, dest, ora);
		t->adaugaCursa(c);
	}

	cout << "Introduceti numarul dupa care cauti cursa:" << endl;
	cin >> numar;
	t->cautareCursa(numar);
	t->listareCurse();
    t->ordonareCursa();
}