#include <iostream>

using namespace std;

class Matrice {
private:
	int lines;
	int cols;
	int* m;

public:
	Matrice() {
		this->lines = 0;
		this->cols = 0;
	}

	Matrice(int l, int c) {
		this->lines = l;
		this->cols = c;
		this->m = new int[lines * cols];
	}

	~Matrice() {
		cout << "Apel destructor" << endl;
		delete m;
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
		cout << endl;
	}

	Matrice operator+(Matrice& input) {
		Matrice* rezultat = new Matrice(lines, cols);

		for (int i = 0; i < lines * cols; i++) {
			rezultat->m[i] = this->m[i] + input.m[i];
		}

		return *rezultat;
	}

	Matrice operator*(Matrice& input) {
		Matrice* rezultat = new Matrice(lines, cols);

		for (int i = 0; i < lines * cols; i++) {
			rezultat->m[i] = 0;
		}

		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < cols; j++) {
				for (int k = 0; k < lines; k++) {
					rezultat->m[i * cols + j] += this->m[i * cols + k] * input.m[k * cols + j];
				}
			}
		}

		return *rezultat;
	}

	int operator[](int index) {
		return m[index];
	}

	Matrice operator=(Matrice& input) {
		return input;
	}
};



int main()
{
	Matrice m1;
	m1.read();

	Matrice m2;
	m2.read();

	Matrice m3 = m1 + m2;
	cout << "Matricea suma" << endl;
	m3.print();

	Matrice m4 = m1 * m2;
	cout << "Matricea produs" << endl;
	m4.print();

	cout << "Elementul de pe pozitia 0: " << m4[0] << endl;
}
