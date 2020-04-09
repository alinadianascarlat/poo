#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<conio.h>

using namespace std;

class Persoana {
protected:
	char* nume;
	char* prenume;
	int varsta;

public:
	Persoana(char* nume, char* prenume, int varsta) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

		this->prenume = new char[strlen(prenume) + 1];
		strcpy(this->prenume, prenume);

		this->varsta = varsta;
	}

	void afisare() {
		cout << "Nume: " << nume << endl;
		cout << "Prenume: " << prenume << endl;
		cout << "Varsta:" << varsta << endl;
	}

	void setNume(char* n) {
		delete this->nume;
		this->nume = new char[strlen(n) + 1];
		strcpy(this->nume, n);
	}
	Persoana(const Persoana& p) {
		nume = new char[strlen(p.nume) + 1];
		strcpy(nume, p.nume);

		prenume = new char[strlen(p.prenume) + 1];
		strcpy(prenume, p.prenume);

		varsta = p.varsta;
		cout << "Apel de copiere Persoana" << endl;
	}

	Persoana& operator = (Persoana& p) {
		cout << "Apel de atribuire Persoana " << endl;
		if (this != &p) {
			delete[]nume;
			nume = new char[strlen(p.nume) + 1];
			strcpy(nume, p.nume);
			varsta = p.varsta;
		}
		return*this;
	}
};

class Angajat : public Persoana {
protected:
	char* functie;
	float salariu;

public:
	Angajat(char* nume, char* prenume, int varsta, char* functie, float salariu)
		:Persoana(nume, prenume, varsta) {
		this->salariu = salariu;

		this->functie = new char[strlen(functie) + 1];
		strcpy(this->functie, functie);
	}

	Angajat(const Angajat& a) : Persoana(a.nume, a.prenume, a.varsta) {
		salariu = a.salariu;
		functie = new char[strlen(a.functie) + 1];
		strcpy(functie, a.functie);
		cout << "Apel constructor de copiere Angajat" << endl;
	}

	Angajat& operator= (Angajat& p) {
		cout << "Apel de atribuire Angajat " << endl;
		if (this != &p) {
			delete[]nume;
			delete[]prenume;
			delete[]functie;
			nume = new char[strlen(p.prenume) + 1];
			strcpy(prenume, p.prenume);

			nume = new char[strlen(p.nume) + 1];
			strcpy(nume, p.nume);

			nume = new char[strlen(p.functie) + 1];
			strcpy(functie, p.functie);

			varsta = p.varsta;
		}
		return*this;
	}

	void afisare() {
		Persoana::afisare();

		cout << "Functia: " << functie << endl;
		cout << "Salariu: " << salariu << endl;
	}
};

int main() {
	char nume_persoana[20];
	char prenume_persoana[20];
	int varsta_persoana;
	
	cout << "nume persoana: ";
	cin >> nume_persoana;
	cout << "prenume persoana: ";
	cin >> prenume_persoana;
	cout << "varsta persoana: ";
	cin >> varsta_persoana;
	
	char functie_angajat[20] = "pensionar";

	cout << "Persoana" << endl;
	Persoana* p = new Persoana(nume_persoana, prenume_persoana, varsta_persoana);
	p->afisare();

	cout << "Angajat" << endl;
	Angajat* a1 = new Angajat(nume_persoana, prenume_persoana,
		varsta_persoana, functie_angajat, 5000);
	a1->afisare();
	
	cout << "Persoana ca angajat" << endl;
	Persoana* a2 = new Angajat(nume_persoana, prenume_persoana,
		varsta_persoana, functie_angajat, 5000);
	a2->afisare();
}
