#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Material {
protected:
	int cota;
	char* titlu;

public:
	Material(int cota, char* titlu) {
		this->titlu = new char[strlen(titlu) + 1];
		strcpy(this->titlu, titlu);
		cout << "Apel destructor Materiale: ";
	}

	Material(const Material& m) {
		this->titlu = new char[strlen(m.titlu) + 1];
		strcpy(titlu, m.titlu);
		cota = m.cota;
		cout << "Apel Constructor de copiere Materiale";
	}

	~Material() {
		delete[]titlu;
		cout << "Apel destructor Materiale";
	}

	void virtual afisare() {
		cout << "Titlu:" << titlu << endl;
		cout << "Cota:" << cota << endl;
	}

	Material& operator = (Material& m) {
		cout << "Apel de atribuire Materiale";
		if (this != &m) {
			delete[] titlu;
			titlu = new char[strlen(m.titlu) + 1];
			strcpy(titlu, m.titlu);
			cota = m.cota;
		}
		return*this;
	}
};

class Carte : public Material {
protected:
	char* specialitatea;

public:
	Carte(int cota, char* titlu, char* specialitatea) :Material(cota, titlu) {
		this->specialitatea = new char[strlen(specialitatea) + 1];
		strcpy(this->specialitatea, specialitatea);
		cout << "Apel constructor Carti";
	}

	Carte(const Carte& s) : Material(s.cota, s.titlu) {
		strcpy(specialitatea, s.specialitatea);
		cout << "Apel constructor de copiere Carti";
	}

	~Carte() {
		delete[]specialitatea;
		cout << "Apel destructor Carti";
	}

	void afisare() {
		Material::afisare();
		cout << "Specialitatea:" << specialitatea << endl;
	}

	Carte& operator = (Carte& p) {
		cout << "Apel de atribuire Carti:";
		if (this != &p) {
			delete[]specialitatea;
			specialitatea = new char[strlen(p.specialitatea) + 1];
			strcpy(specialitatea, p.specialitatea);
		}
		return*this;
	}
};

class Revista : public Material {
protected:
	char* editura;

public:
	Revista(int cota, char* titlu, char* editura) : Material(cota, titlu) {
		this->editura = new char[strlen(editura) + 1];
		strcpy(this->editura, editura);
		cout << "Apel constructor Reviste";
	}

	Revista(const Revista& e) :Material(e.cota, e.titlu) {
		editura = new char[strlen(editura) + 1];
		strcpy(editura, e.editura);
		cout << "Apel constructor de copiere Reviste";
	}

	~Revista() {
		delete[]editura;
		cout << "Apel destructor Reviste";
	}

	void afisare() {
		Material::afisare();
		cout << "Editura:" << editura << endl;
	}

	Revista& operator = (Revista& e) {
		cout << "Apel atribuire Reviste";
		if (this != &e) {
			delete[]editura;
			editura = new char[strlen(editura) + 1];
			strcpy(editura, e.editura);
		}
		return*this;
	}
};

class Cd : public Material {
protected:
	char* memorie;

public:
	Cd(int cota, char* titlu, char* memorie) : Material(cota, titlu) {
		this->memorie = new char[strlen(memorie) + 1];
		strcpy(this->memorie, memorie);
		cout << "Apel constructor Cd:";
	}

	Cd(const Cd& m) : Material(m.cota, m.titlu) {
		memorie = new char[strlen(m.memorie) + 1];
		strcpy(memorie, m.memorie);
		cout << "Apel constructor de copiere Cd:";
	}

	~Cd() {
		cout << "Apel destructor Cd:";
	}

	void afisare() {
		Material::afisare();
		cout << "Memorie:" << memorie << endl;
	}

	Cd& operator= (Cd& m) {
		cout << "Apel de atribuire Cd:";
		if (this != &m) {
			delete[]memorie;
			memorie = new char[strlen(m.memorie) + 1];
			strcpy(memorie, m.memorie);
		}
		return*this;
	}
};

class Biblioteca {
	Material* materiale[100];
	int nrMateriale = 0;
	char* nume;

public:
	Biblioteca(char* nume) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

	}
	
	void adaugaCarte(Carte* c) {
		materiale[nrMateriale] = c;
		nrMateriale++;
	}

	void adaugaRevista(Revista* r1) {
		materiale[nrMateriale] = r1;
		nrMateriale++;
	}

	void adaugaCd(Cd* d) {
		materiale[nrMateriale] = d;
		nrMateriale++;
	}

	void afiseaza() {
		cout << "Biblioteca " << nume;
		for (int i = 0; i < nrMateriale; i++) {
			materiale[i]->afisare();
		}
	}
};

int main() {
	int cota;
	char titlu[20];
	char specialitatea[20];
	char editura[20];
	char memorie[20];

	cout << "cota:";
	cin >> cota;
	cout << "titlu:";
	cin >> titlu;
	cout << "specialitatea:";
	cin >> specialitatea;
	cout << "editura:";
	cin >> editura;
	cout << "memorie:";
	cin >> memorie;

	cout << "Carti:" << endl;
	Carte* c = new Carte(cota, titlu, specialitatea);
	c->afisare();

	cout << "Reviste:" << endl;
	Revista* r1 = new Revista(cota, titlu, editura);
	r1->afisare();

	cout << "Cd:" << endl;
	Cd* d = new Cd(cota, titlu, memorie);
	d->afisare();

	cout << "Biblioteca:" << endl;
	Biblioteca* b = new Biblioteca((char*)"Alyssa");
	b->adaugaCarte(c);
	b->adaugaRevista(r1);
	b->adaugaCd(d);
	b->afiseaza();
}
