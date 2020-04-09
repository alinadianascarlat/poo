#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

class JucatorFotbal {
private:
	char* nume;
	char* prenume;
	int numar;

public:
	
	JucatorFotbal(char* nume, char* prenume, int numar) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

		this->prenume = new char[strlen(prenume) + 1];
		strcpy(this->prenume, prenume);

		this->numar = numar;
	}

	void afisare() {
		cout << "Nume jucator:" << nume << endl;
		cout << "Prenume jucator:" << prenume << endl;
		cout << "Numar jucator:" << numar << endl;
	 }
};

class Echipa {
private:
	JucatorFotbal* jucatori[11];
	char* nume;
	int numar_jucatori = 11;

public:
	Echipa(char* numeEchipa, JucatorFotbal* jucatoriFotbal[11]) {
		this->nume = new char[strlen(numeEchipa) + 1];
		strcpy(this->nume, numeEchipa);
		for (int i = 0; i < numar_jucatori; i++)
			jucatori[i] = jucatoriFotbal[i];
	}

	~Echipa() {
		cout << "Apel destructor" << endl;
	}

	void afisare() {
		cout << endl;
		cout << "Numar jucatori:" << numar_jucatori << endl;
		cout << "Nume echipa:" << nume << endl;
		cout << "Fotbalisti:" << endl;
		for (int i = 0; i < numar_jucatori; i++) {
			this->jucatori[i]->afisare();
		}
	}
};

void main() {
	char nume_jucator[20];
	char prenume_jucator[20];
	char nume_echipa[20]
		;
	JucatorFotbal* jucatori[11];

	cout << "Nume echipa: ";
	cin >> nume_echipa;

	for (int i = 0; i < 11; i++) {
		cout << "Nume jucator " << i << ": ";
		cin >> nume_jucator;
		cout << "Prenume jucator " << i << ": ";
		cin >> prenume_jucator;
		jucatori[i] = new JucatorFotbal(nume_jucator, prenume_jucator, i);
	}

	Echipa* echipa = new Echipa(nume_echipa, jucatori);

	echipa->afisare();
}
