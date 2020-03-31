//supraincarcarea operatorilor ++ Si -- in cadrul numerelor complexe

#include<iostream>
using namespace std;

class Complex {

private:
	float re;
	float im;

public:
	Complex(float re = 0, float im = 0) {
		this->re = re;
		this->im = im;
	}

	void afisare();

	void operator++() {
		re += 1;
		cout << "preincrementare" << endl;
	}

	void operator++(int n) {
		re += 1;
		cout << "postincrementare" << endl;
	}

	Complex operator+(Complex a){
		Complex c(this->re + a.re, this->im + a.im);
		return c;
	}
};

void Complex::afisare() {
	cout << re << " + i * " << im << endl;
}

int main() {
	//Complex z(4, 5);
	//z.afisare();
	//++z;
	//z.afisare();
	//z++;
 //	z.afisare(); 

	Complex z1(1, 2);
	Complex z2(3, 4);
	Complex z3 = z1 + z2;
	z3.afisare();
}