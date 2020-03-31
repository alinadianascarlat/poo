
#include<iostream>
using namespace std;

class Polinom {
private:
	int* elem;
	int dim;

public:
	Polinom(int* elem, int dim) {
		this->elem = elem;
		this->dim = dim;
	}

	Polinom operator+(Polinom p) {
		int* v = new int[p.dim];
		for (int i = 0; i < this->dim; i++)
			v[i] = this->elem[i] + p.elem[i];

		Polinom rez(v, this->dim);

		return rez;
	}

	Polinom operator*(Polinom p) {
		int* v = new int[p.dim + this->dim - 1];
		for (int i = 0; i < p.dim + this->dim; i++) {
			v[i] = 0;
		}

		for (int i = 0; i < p.dim; i++) {
			for (int j = 0; j < this->dim; j++)
			{
				v[i+j] += p.elem[i] * this->elem[j];
			}
		}

		Polinom rez(v, p.dim + this->dim - 1);
		return rez;
	}

	void afiseaza() {
		for (int i = 0; i < this->dim; i++)
			cout << this->elem[i] << " ";
		cout << endl;
	}
};

void main() {
	int a1[] = { 1, 2, 3, 4 };
	int a2[] = { 1, 2, 3, 4 };

	Polinom p1(a1, 4);
	Polinom p2(a2, 4);

	Polinom p3 = p1 + p2; // Polinom p3 = p1.operator+(p2);
	p3.afiseaza();

	Polinom p4 = p1 * p2;
	p4.afiseaza();

	int a[] = { 1, 2, 3, 4 };
	int b[] = { 5, 6, 7, 8 };

	int c[4];



	//for (int i = 0; i < 4; i++)
	//	c[i] = a[i] + b[i];

	//for (int i = 0; i < 4; i++)
	//	cout << c[i] << endl;

}