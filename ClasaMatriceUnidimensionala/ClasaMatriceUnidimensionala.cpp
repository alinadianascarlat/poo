#include <iostream>

using namespace std;
// Sa se implementeze tipul abstract Matrice care va retine matricea sub forma unui tablou
// unidimensional.Clasa va contine :
// Constructor de initializare
// Constructor de copiere
// Destructor
// Metode pentu citire si afisare
// Metoda pentru calcului normei


class Matrice {
private:
	int lines;
	int cols;
	int* m;

public:
	Matrice() {
		int lines = 0;
		int cols = 0;
		int* m = 0;
	}

	~Matrice() {
		cout << "Apel destructor matrice" << endl;
		delete m;
	}  

	Matrice(const Matrice* m1) {
		this->lines = lines;
		this->cols = cols;
		this->m = new int[lines * cols];
		for (int i = 0; i < lines * cols; i++) {
			this->m[i] = m1->m[i];
		}
		cout << "Apel constructor de copiere" << endl;
	}

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
	
	Matrice operator +(Matrice m);
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
	
	Matrice* m1 = new Matrice(m);

	delete m1;
	delete m;
}
