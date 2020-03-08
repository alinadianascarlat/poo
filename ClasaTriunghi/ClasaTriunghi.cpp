#include <iostream>

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

	int perimetru() {
		return a + b + c;
	}

	int aria() {
		return a * b * c;
	}
	
	bool poateFiiTriunghi() {
		return a + b > c || a + c > b || b + c > a;

		//if (a + b > c || a + c > b || b + c > a)
		//	return true;
		//else
		//	return false;
	}
};

 
int main() {
	// creeze un triunghi
	// afisezi la consola perimetru si aria
	Triunghi t(2, 3, 4);
   
	cout << "perimetrul = " << t.perimetru() << endl;
	cout << "aria = " << t.aria() << endl;
	cout << "poate fi triunghi: " << t.poateFiiTriunghi() << endl;

	return 0;
}
