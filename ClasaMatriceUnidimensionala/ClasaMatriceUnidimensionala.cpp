#include <iostream>

using namespace std;
//Sa se implementeze tipul abstract Matrice care va retine matricea sub forma unui tablou
//unidimensional.Clasa va contine :
// Constructor de initializare
// Constructor de copiere
//Destructor
//Metode pentu citire si afisare
//Metoda pentru calcului normei


class Matrice {
private:
	int lines;
	int cols;
	int* m;

public:
	void read() {
		cout << "lines = ";
		cin >> lines;

		cout << "cols = ";
		cin >> cols;

		this->m = new int[lines * cols];
		cout << "Introduceti matricea:" << endl;

		int k = 0;
		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < cols; j++) {
				cout << "m[" << i << "][" << j << "] = ";
				cin >> m[k];
				k++;
			}
		}
	}

	void print() {
		for (int i = 0; i < lines * cols; i++) {
			cout << m[i] << " ";
			if (i != 0 && (i + 1) % cols == 0) {
				cout << endl;
			}
		}
	}

	int numberOfLines() {
		return lines;
	}

	int numberOfColums() {
		return cols;
	}
};

int main()
{
	Matrice* m = new Matrice();

	m->read();
	// citesti numarul de linii si coloane
	// citesti matricea si o salvezi intr-un tablou unidimensional

	m->print(); // iti afiseaza sub forma de matrice
	//  1 2 3
	//  3 4 5

	int lines = m->numberOfLines();
	//getLines = numberOflines returneaza nr de linii
	int cols = m->numberOfColums();
}
