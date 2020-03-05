#include<iostream>
#include<conio.h>

using namespace std;

class Complex {
private:
	float re;
	float im;

public:
	Complex(float r = 0, float m = 0) {
		re = r;
		im = m;
		cout << "Apel constructor" << re << " " << im << endl;
	}

	void afisare(int z = 9) {
		cout << re <<" + i * " << im << endl;
		cout << "z = " << z;
	}
};

void main() {
	Complex z;
	z.afisare(5);
}
