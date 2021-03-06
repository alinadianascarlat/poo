#include<iostream>
#include<conio.h>

using namespace std;

// Cerinte:
// constructor de initializare cu numarator si numitor
// metoda de afisare ex: 2/3
// metoda de adunare cu alt numar rational
class NumereRationale {
private:
	int numarator;
	int numitor;

public:
	NumereRationale(int numarator, int numitor) {
		this->numarator = numarator;
		this->numitor = numitor;
	}

	void afisare() {
		cout << numarator << "/" << numitor << endl;
	}

	NumereRationale* inmulteste(NumereRationale* n) {
		NumereRationale* prod = new NumereRationale(this->numarator * n->numarator, this->numitor * n->numitor);
		return prod;
	}
	NumereRationale* aduna(NumereRationale* n) {
		int sumaNumartor = this->numarator * n->numitor + n->numarator * this->numitor;
		int sumaNumitor = this->numitor*n->numitor;

		//a/b + c/d = (a*d + c*b) / (b*d)
		//this   n
		NumereRationale* suma  = new NumereRationale(sumaNumartor, sumaNumitor);
		return suma;
	}
};

int main() {
	int numarator, numitor;

	// creeaza numarul rational
	NumereRationale* nr = new NumereRationale(4, 5);
	nr->afisare(); // 4/5

	NumereRationale* nr1 = new NumereRationale(2, 3);
	nr1->afisare();

	NumereRationale* nr2 = nr->inmulteste(nr1);
	nr2->afisare();

	// TEMA
	NumereRationale* nr3 = nr->aduna(nr1);
	nr3->afisare();
}
