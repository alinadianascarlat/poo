#include<iostream>
#include<conio.h>

using namespace std;

class Complex {

private:
	float re;
	float im;

public:
	Complex(float r = 0, float m = 0) {
		r = re;
		m = im;
		cout << "Apel constructor"<<re<<""<<im<<endl;
	}
	void afisare() {
		cout<< re <<" +i" << im << endl;

}

};
void main() {
	Complex z(1, 2);
	z.afisare();
}