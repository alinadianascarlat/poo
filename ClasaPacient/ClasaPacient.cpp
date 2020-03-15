//Sa se implementeze clasa Pacient (nume, prenume, varsta, diagnostic). Clasa va contine:
//x Constructor de initializare
//x Constructor de copiere
//x Destructuctor
//x Metoda pentru citire
//x Metoda pentru afisare
//Sa se construiasca un tablou cu obiecte de tip Pacient si sa se ordoneze crescator dupa varsta

#include<iostream>
#include<conio.h>

using namespace std;

class Pacient {
private:
	char* nume;
	char* prenume;
	int* varsta;
	char* diagnostic;

public:
	Pacient(char* nume, char* prenume, int* varsta, char* diagnostic) {

		this->nume = nume;
		this->prenume = prenume;
		this->varsta = varsta;
		this->diagnostic = diagnostic;
		cout << "Apel constructor" << endl;
	}
	~Pacient() {
		cout << "Apel destructor" << endl;
}

	void print() {
		cout << "Pacient:" << nume << prenume << varsta <<diagnostic;
	}
	void read() {
		cout << "nume:";
		cin >> nume;
		cout << "prenume:";
		cin >> prenume;
		cout << "diagnostic:";
		cin >> diagnostic;
		cout << "varsta:";
		cin >> varsta;
	}
	
};
int main() {
	char nume_pacient;
	char prenume_pacient;
	int varsta_pacient;
	char diagnostic_pacient;
	Pacient* pacient = newPacient(nume, prenume, varsta, diagnostic);
	pacient->print();
	pacient->read();
}














