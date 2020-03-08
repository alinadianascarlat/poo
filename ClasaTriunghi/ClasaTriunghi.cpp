#include<iostream>

using namespace std;

//calculeaza aria si perimetrul
class Triunghi {
private:
	int a;
	int b;
	int c;

public:
	Triunghi(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	void afisare() {
		cout << "perimetrul este :" << a << b << c << endl;
	}
};
 
int main() {
	// creeze un triunghi
	// afisezi la consola perimetru si aria
	Triunghi t(2, 3, 4);

	cout << "perimetrul = " << t.perimetru();
	// cout << "aria = " << t.aria();

	return 0;
}
