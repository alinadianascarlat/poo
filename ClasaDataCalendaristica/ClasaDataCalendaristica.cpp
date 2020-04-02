#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<conio.h>

using namespace std;

class DataCalendaristica {
private:
	int zi;
	int luna;
	int an;

public:
	DataCalendaristica() {}
	DataCalendaristica(int zi, int luna, int an) {
		this->zi = zi;
		this->luna = luna;
		this->an = an;
	}
	int get_zi() {
		return this->zi;
	}
	int get_luna() {
		return this->luna;
	}
	int get_an() {
		return this->an;
	}

	void print() {
		cout << "Zi: " << zi << endl;
		cout << "Luna: " << luna << endl;
		cout << "An: " << an << endl<<endl;
	}
};

class Persoana {
private:
	char* nume;
	char* prenume;
	DataCalendaristica data_nasterii;

public:
	Persoana(char* nume, char* prenume, DataCalendaristica data_nasterii) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

		this->prenume = new char[strlen(prenume) + 1];
		strcpy(this->prenume, prenume);

		this->data_nasterii = data_nasterii;
	}

	void afisare() {
		cout << "Nume: " << nume << endl;
		cout << "Prenume: " << prenume << endl;
		cout << "Data Nasterii:"<<endl; 
		data_nasterii.print();
	}

	int calculeazaVarsta(DataCalendaristica data_curenta) {
		int varsta;
		if (data_curenta.get_luna() - data_nasterii.get_luna() > 0)
			varsta = data_curenta.get_an() - data_nasterii.get_an();

		if (data_curenta.get_luna() - data_nasterii.get_luna() == 0)
		{
			if (data_curenta.get_zi() - data_nasterii.get_zi() < 0)
				varsta = data_curenta.get_an() - data_nasterii.get_an() - 1;
			else
				varsta = data_curenta.get_an() - data_nasterii.get_an();
		}

		if(data_curenta.get_luna() - data_nasterii.get_luna() < 0)
			varsta = data_curenta.get_an() - data_nasterii.get_an() - 1;

		return varsta;
	}
};

DataCalendaristica CreareData()
{
	int zi_curenta, luna_curenta, an_curent;
	cout << "Zi:";
	cin >> zi_curenta;
	cout << "Luna:";
	cin >> luna_curenta;
	cout << "An:";
	cin >> an_curent;

	DataCalendaristica* data_curenta = new DataCalendaristica(zi_curenta, luna_curenta, an_curent);
	return *data_curenta;
}

Persoana CrearePersoana()
{
	char nume_persoana[20];
	char prenume_persoana[20];
	DataCalendaristica  data_nasterii;
	cout << "Introdu data de nastere:" << endl;
	data_nasterii = CreareData();

	cout << "Nume persoana: ";
	cin >> nume_persoana;
	cout << "Prenume persoana: ";
	cin >> prenume_persoana;

	Persoana* persoana = new Persoana(nume_persoana, prenume_persoana, data_nasterii);
	cout << "Afisare persoana" << endl;
	persoana->afisare();
	return *persoana;
}
int main() {
	Persoana persoana = CrearePersoana();
	cout << "Data curenta " << endl;
	DataCalendaristica data_curenta = CreareData();
	cout << "Varsta persoanei este: " << persoana.calculeazaVarsta(data_curenta);
}
