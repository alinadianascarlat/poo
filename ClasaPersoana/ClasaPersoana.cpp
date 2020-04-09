#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<conio.h>

using namespace std;

class Persoana {                //afisare nume, prenume,varsta persoana
private:
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
};

int main() {
	char nume_persoana[20];
	char prenume_persoana[20];
	int varsta_persoana;
	char noul_nume[20];
	
	cout << "nume persoana: ";
	cin >> nume_persoana;
	cout << "prenume persoana: ";
	cin >> prenume_persoana;
	cout << "varsta persoana: ";
	cin >> varsta_persoana;

	Persoana* p = new Persoana(nume_persoana, prenume_persoana, varsta_persoana);
	p->afisare();

	cout << "noul nume: ";
	cin >> noul_nume;
	p->setNume(noul_nume);

	p->afisare();
}
