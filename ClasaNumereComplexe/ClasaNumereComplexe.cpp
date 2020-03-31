

#include<iostream>
#include<conio.h>

using namespace std;

class Complex {
private:
	int re;
	int im;
	//declarare, definire constructor
	//apelare destructor
public:
	Complex() {
		re = 5;
		im = 5;
		cout << "Apel constructor: " << re << "" << im << endl;
	}
	Complex(int r, int i) {
		re = r;
		im = i;
		cout << "Apel constructor parametrii: " << re << "" << im << endl;
	}
	
	~Complex() {
		cout << "Apel destructor " << re << "" << im << endl;
	}

	void afis() {
		cout << re << " + i * " << im << endl;
	}
	
};

void main() {
	Complex c1;
	Complex c2(1, 2);
	c1.afis();
	c2.afis();

	//delete c1;
	//delete c2;
}
