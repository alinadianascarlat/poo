#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

using namespace std;

class Produs {
protected:
	char* nume;
	char* valab;
	int cantitate;
	int pret;

public:
	Produs(char* nume, char* valab, int cantitate, int pret) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

		this->valab = new char[strlen(valab) + 1];
		strcpy(this->valab, valab);

		this->cantitate = cantitate;
		this->pret = pret;
		cout << "Apel constructor Produs" <<endl;
	}

	~Produs() {
		delete[]nume;
		delete[]valab;
		cout << "Apel destructor Produs:";
	}

	Produs(const Produs& p) {
		nume = new char[strlen(p.nume) + 1];
		strcpy(nume, p.nume);

		valab = new char[strlen(p.valab) + 1];
		strcpy(valab, p.valab);

		cantitate = p.cantitate;
		pret = p.pret;

		cout << "Apel de copiere Produs:";
	}

	void virtual afisare() {
		cout << "Produs:" << endl;
		cout << "Nume produs:" << nume << endl;
		cout << "Valab produs:" << valab << endl;
		cout << "Cantitate produs:" << cantitate << endl;
		cout << "Pret produs:" << pret << endl;
	}

	Produs operator = (Produs& p) {
		cout << "Apel de atribuire Produs" << endl;
		if (this != &p) {

			delete[]nume;
			nume = new char[strlen(p.nume) + 1];
			strcpy(nume, p.nume);

			delete[]valab;
			valab = new char[strlen(p.valab) + 1];
			strcpy(valab, p.valab);

			cantitate = p.cantitate;
			pret = p.pret;
		}
		return *this;
	}

};

class Aliment : public Produs {
protected:
	char* cod;
	char* producator;

public:
	Aliment(char* nume, char* valab, int cantitate, int pret, char* cod, char* producator) :
		Produs(nume, valab, cantitate, pret) {

		this->cod = new char[strlen(cod) + 1];
		strcpy(this->cod, cod);

		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);

		cout << "Apel constructor Aliment" <<endl;
	}

	~Aliment() {
		cout << "Apel destructor Aliment:";
	}


	Aliment(const Aliment& a) : Produs(a.nume, a.valab, a.cantitate, a.pret) {

		cod = new char[strlen(a.cod) + 1];
		strcpy(cod, a.cod);

		producator = new char[strlen(a.producator) + 1];
		strcpy(producator, a.producator);

		cout << "Aple constructor de copiere Aliment:";
	}

	Aliment& operator = (Aliment& p) {

		cout << "Apel de atribuire Aliment:";
		if (this != &p) {
			delete[]cod;
			delete[]producator;

			cod = new char[strlen(p.cod) + 1];
			strcpy(cod, p.cod);

			producator = new char[strlen(p.producator) + 1];
			strcpy(producator, p.producator);
		}
		return*this;
	}

	void afisare() {
		cout << "Aliment:" << endl;
	}
};

class Bautura : public Produs {
protected:
	char* tip;

public:
	Bautura(char* nume, char* valab, int cantitate, int pret, char* tip) :
		Produs(nume, valab, cantitate, pret) {

		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
	}

	~Bautura() {
		cout << "Apel destructor";
	}

	Bautura(const Bautura& b) : Produs(b.nume, b.valab, b.cantitate, b.pret) {
		tip = new char[strlen(b.tip) + 1];
		strcpy(tip, b.tip);
		cout << "Apel de copiere Bautura";
	}

	Bautura& operator = (Bautura& p) {
		cout << "Apel de atribuire Bautura";
		if (this != &p) {
			delete[]tip;
			tip = new char[strlen(p.tip) + 1];
			strcpy(tip, p.tip);
			cout << "Apel de atribuire Bautura";
		}
		return*this;
	}

	void afisare() {
		cout << "Bautura:" << endl;
		cout << "tip:" << tip << endl;
	}
};

class Magazin {
	Produs* produse[50];
	int nrProduse = 0;
	char* categorie;

public:
	Magazin(char* categorie) {
		this->categorie = new char[strlen(categorie) + 1];
		strcpy(this->categorie, categorie);
	}

	void adaugaProdus(Produs* a) {
		produse[nrProduse] = a;
		nrProduse++;
	}

	void  afisare() {
		cout << "Magazin " << categorie << endl;
		for (int i = 0; i < nrProduse; i++) {
			produse[i]->afisare();
		}
	}
};

int main() {
	char nume[20];
	char valab[20];
	int pret;
	int cantitate;
	char tip[20];
	char categorie[20];
	char cod[20];
	char producator[20];

	cout << "Introduceti date despre aliment:" << endl;

	cout << "nume produs:";
	cin >> nume;

	cout << "valab produs:";
	cin >> valab;

	cout << "pret produs:";
	cin >> pret;

	cout << "cantitate produs:";
	cin >> cantitate;

	cout << "categorie magazin:";
	cin >> categorie;

	cout << "cod aliment:";
	cin >> cod;

	cout << "producator aliment:";
	cin >> producator;

	Aliment* a = new Aliment((char*)nume, (char*)valab, cantitate, pret, (char*)cod, (char*)producator);
	a->afisare();

	cout << "Tip bautura: ";
	cin >> tip;

	Bautura* b = new Bautura(nume, valab, cantitate, pret, tip);
	b->afisare();

	cout << "Magazin" << endl;
	Magazin* m = new Magazin((char*)"Ana");
	m->adaugaProdus(a);
	m->adaugaProdus(b);
	m->afisare();
}