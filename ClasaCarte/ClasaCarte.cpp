#include<iostream>
#include<conio.h>;

using namespace std;

class Carte {
private:
	char* nume;
	char* autor;
	int nrPag;
	double pret;

public:
	Carte(char* nume, char* autor, int nrPag, double pret) {
		this->nume = nume;
		this->autor = autor;
		this->nrPag = nrPag;
		this->pret = pret;
	}

	void afiseaza() {
		cout << "Cartea " << this->nume << " a autorului " << this->autor << " costa: " << this->pret << endl;
	}
};

int main() {
	char nume[40];
	char autor[40];
	int nrpag;
	double pret;
	cout << "Dati nume carte: ";
	cin >> nume;
	cout << "Dati autor carte: ";
	cin >> autor;
	cout << "Dati numar pagini: ";
	cin >> nrpag;
	cout << "Dati un pret: ";
	cin >> pret;

	Carte* carte = new Carte(nume, autor, nrpag, pret);
	carte->afiseaza();
}