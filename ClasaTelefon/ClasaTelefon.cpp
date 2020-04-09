#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Telefon {
protected:
	int numar;
	char* model;

public:
	Telefon(int numar, char* model) {
		this->numar = numar;

		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
	}

	void apelare() {
		cout << "Apelare numar: " << this->numar;
	}

	void raspuns() {
		cout << "Ati sunat la:";
	}

	Telefon(const Telefon& t) {
		model = new char[strlen(t.model) + 1];
		strcpy(model, t.model);

		cout << "Apel de copiere Telefon " << endl;
	}

	Telefon& operator = (Telefon& t) {
		cout << "Apel de atribuire Telefon " << endl;
		if (this != &t) {
			delete[]model;

			model = new char[strlen(t.model) + 1];
			strcpy(model, t.model);
		}
		return*this;
	}
};

class TelefonFix : public Telefon {
protected:
	char* retea;

public:
	TelefonFix(char* retea, int numar, char* model) : Telefon(numar, model) {
		this->retea = new char[strlen(retea) + 1];
		strcpy(this->retea, retea);
	}

	void afisare() {
		cout << "Reteaua telefonului este:" << this->retea;
	}

	TelefonFix(const TelefonFix& t1) : Telefon(t1.numar, t1.model) {
		retea = new char[strlen(t1.retea) + 1];
		strcpy(retea, t1.retea);

		cout << "Apel de copiere TelefonFix " << endl;
	}

	TelefonFix& operator=(TelefonFix& t1) {
		cout << "Apel de atribuire Telefon " << endl;
		if (this != &t1) {
			delete[]model;
			delete[]retea;

			model = new char[strlen(t1.model) + 1];
			strcpy(model, t1.model);

			retea = new char[strlen(t1.retea) + 1];
			strcpy(retea, t1.retea);

			numar = t1.numar;
		}
		return *this;
	}
};

class TelefonMobil : public Telefon {
protected:
	char* tehnologie;
	char* autonomie;

public:
	TelefonMobil(int numar, char* model, char* tehnologie, char* autonomie): Telefon(numar, model) {
		this->tehnologie = new char[strlen(tehnologie) + 1];
		strcpy(this->tehnologie, tehnologie);

		this->autonomie = new char[strlen(autonomie) + 1];
		strcpy(this->autonomie,autonomie);
	}
	void afisare() {
		cout << "Afiseaza cat timp tine bateria:" << endl;
		cout << "Afiseaza tehnologia utilizata:" << endl;
	}
	TelefonMobil(const TelefonMobil& t2) :Telefon(t2.numar, t2.model) {
		tehnologie = new char[strlen(t2.tehnologie) + 1];
		strcpy(tehnologie, t2.tehnologie);
		autonomie = new char[strlen(t2.autonomie) + 1];
		strcpy(autonomie, t2.autonomie);
	}

	TelefonMobil& operator=(TelefonMobil& t2) {
		cout << "Apel de atribuire TelefonMobil:" << endl;

		if (this != &t2)
			delete[]tehnologie;
		delete[]autonomie;

		tehnologie = new char[strlen(t2.tehnologie) + 1];
		strcpy(tehnologie, t2.tehnologie);

		autonomie = new char[strlen(t2.autonomie) + 1];
		strcpy(autonomie, t2.autonomie);
	}
};

int main() {
	int numar;
	char model[20];
	char retea[20];
	char tehnologie[20];
	char autonomie[20];

	cout << "Numar:";
	cin >> numar;

	cout << "Model:";
	cin >> model;

	cout << "Retea:";
	cin >> retea;

	cout << "Autonomie:";
	cin >> autonomie;

	cout << "Tehnologie:";
	cin >> tehnologie;

	cout << "Telefon";
	Telefon* t = new Telefon(numar, model);
	t->apelare();

	cout << "TelefonFix" << endl;
	TelefonFix* t1 = new TelefonFix(retea, numar, model);
	t1->afisare();

	cout << "TelefonMobil" << endl;
	TelefonMobil* t2 = new TelefonMobil(numar, model, tehnologie, autonomie);
	t2->afisare();
}
