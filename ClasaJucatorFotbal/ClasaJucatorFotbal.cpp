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

void main() {
	char nume_jucator[20];
	char prenume_jucator[20];
	char numar_jucator;

	cout << "nume persoana: ";
	cin >> nume_jucator;
	cout << "prenume persoana: ";
	cin >> prenume_jucator;
	cout << "numar persoana:";
	cin >> numar_jucator;

}


class Antrenor {
private:
	char* nume;
	char* prenume;
	int varsta;

public:
	Antrenor(char* nume, char* prenume, int varsta) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

		this->prenume = new char[strlen(prenume) + 1];
		strcpy(this->prenume, prenume);

		this->varsta = varsta;
	}
	void afisare() {
		cout << "Nume antrenor:" << nume << endl;
		cout << "Prenume antrenor:" << prenume << endl;
		cout << "Varsta antrenor:" << varsta << endl;
	}
	void citeste() {
		cout << "Antrenor fotbal:" << nume << prenume << varsta << endl;
	}
	~Antrenor() {
		cout << "Apel destructor:" << endl;
	}	
};

class Echipa {
private:
	JucatorFotbal* jucatori;
	Antrenor antrenor;
	char* nume;
	int numar_jucatori;
	
public:
	Echipa(int nrJucatori, char* numeEchipa, JucatorFotbal* jucatoriFotbal, Antrenor antr) {
		this->nume = new char[strlen(numeEchipa) + 1];
		strcpy(this->nume, numeEchipa);
		numar_jucatori = nrJucatori;
		this->jucatori = new JucatorFotbal[nrJucatori];
		for (int i = 0; i < numar_jucatori; i++) {
			this->jucatori[i] = jucatoriFotbal[i];
		}
		this->antrenor = antr;
	}
		~Echipa() {
			cout << "Apel destructor" << endl;
		}
		void afisare() {
			cout << "Numar jucatori:" << numar_jucatori << endl;
			cout << "Nume echipa:" << nume << endl;
			cout << "Antrenor:";
			antrenor.afisare();
			cout << "Fotbalisti:";
			for (int i = 0; i < numar_jucatori; i++) {
				this->jucatori[i].afisare();
			}
		}
};