#include <iostream>
#include <conio.h>

using namespace std;

class Persoana {
protected:
	char* nume;

public:
	Persoana(char* nume) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		cout << "Apel constructor Persoana:" << endl;
	}

	Persoana(const Persoana& ob) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, ob.nume);
		cout << "Apel constructor copiere Persoana:" << endl;
	}

	~Persoana() {
		delete[]nume;
		cout << "Apel destructor Persoana:";
	}

	Persoana& operator = (const Persoana& ob) {
		if (this != &ob) {
			delete[]nume;
			this->nume = new char[strlen(ob.nume) + 1];
			strcpy(this->nume, ob.nume;
		}
		cout << "Apel operator = Persoana";
		return *this;
	}

	void print() {
		cout << "Nume:" << nume << endl;
	}
};

class Job {
protected:
	char* functie;

public:
	Job(char* funtie) {
		this->functie = new char[strlen(functie) + 1];
		strcpy(this->functie, functie);
		cout << "Apel constructor Job:" << endl;
	}

	Job(Job & ob){
		this->functie = new char[strlen(ob.functie) + 1];
		strcpy(this->functie, ob.functie);
		cout << "Apel constructor copiere Job:" << endl;
	}

	~Job(){
		delete[]functie;
		cout << "Apel destructor Job:" << endl;
	}

	Job &operator = (const Job &ob) {
		if (this != &ob) {
			delete[]functie;
			this->functie = new char[strlen(ob.functie) + 1];
			strcpy(this->functie, ob.functie);
		}
		cout << "Apel operator = Job";
		return *this;
	}

	void print() {
		cout << "functie:" << functie << endl;
	}
};

class Angajat :public Persoana, public Job {

protected:
	Angajat(char* nume, char* functie, int vechime = 0) :Persoana(nume), Job(functie) {
		this->vechime = vechime;
		cout << "Apel constructor Angajat" << endl;
	}

	Angajat(const Angajat& ob) :Job(ob), Persoana(ob) {
		vechime = ob.vechime;
		cout<<"Apel constructor"

	}
};


