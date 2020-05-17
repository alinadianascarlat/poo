  #define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

using namespace std;

class AvertismentDepasireGreutate {
public:
	const char* mesaj;
	AvertismentDepasireGreutate(const char* m) : mesaj(m) {}
};

class  DepasireGreutate {
public:
	const char* mesaj;
	DepasireGreutate(const char* m) : mesaj(m) {}
};


class Cantar {
protected:
	char* unitateMasura;
	double	greutateMax;


public:
	Cantar(char* unitateMasura, double greutateMax) {
		this->unitateMasura = new char[strlen(unitateMasura) + 1];
		strcpy(this->unitateMasura, unitateMasura);
		this->greutateMax = greutateMax;
	}

	void Cantareste(double cantitate) {
		if (cantitate <= greutateMax) {
			cout << " Greutatea indicata este: " << cantitate << unitateMasura;;
		}
		else {
			int diferenta = cantitate - greutateMax;
			double diferentaAdmisa = greutateMax / 10.0;
			if (diferenta <= diferentaAdmisa)
				throw AvertismentDepasireGreutate("Diferenta usoara ");
			else
				throw DepasireGreutate("Diferenta grava");
		}
	}
};



int main() {
	char unitateMasura[20];
	double cantitate;
	double greutateMax;
	cout << "Introdu greutatea maxima:";
	cin >> greutateMax;
	cout << "Introdu unitatea de masura a cantarului:";
	cin >> unitateMasura;
	Cantar* cantar = new Cantar(unitateMasura, greutateMax);
	try {
		cout << "Introdu cantitatea:";
		cin >> cantitate;
		cantar->Cantareste(cantitate);
	}
	catch (AvertismentDepasireGreutate avertisment) {
		cerr << "Atentie greutatea a fost depasita." << avertisment.mesaj;
	}
	catch (DepasireGreutate avertisment) {
		cerr << "Atentie greutatea a fost depasita." << avertisment.mesaj;
	}
	catch (...) {
		cerr << "Tratare eroare necunoscuta.";
	}
	 
}