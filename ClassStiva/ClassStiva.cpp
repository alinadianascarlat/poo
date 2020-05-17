 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

using namespace std;
const int MAX = 10;

class AvertismentDepasireCapacitate {
public:
	const char* mesaj;
	AvertismentDepasireCapacitate(const char* m) : mesaj(m) {}
};

class AvertismentStivaGoala {
public:
	const char* mesaj;
	AvertismentStivaGoala(const char* m) : mesaj(m) {}
};

class Stiva {
private:
	int* elemente;
	int capacitate = 0;

public:
	Stiva() {
		elemente = new int[MAX];
	}

	bool isEmpty() {
		if (capacitate == 0)
			return true;
		return false;
	}

	void push(int numar) {
		if (capacitate >= MAX) {
			throw AvertismentDepasireCapacitate("Capacitate maxima atinsa.");
		}

		capacitate = capacitate + 1;
		elemente[capacitate] = numar;
	}

	int peek() {
		return elemente[capacitate];
	}

	int pop() {
		if (capacitate == 0) {
			throw AvertismentStivaGoala("Stiva este goala");
		}

		int rezultat = peek();
		capacitate = capacitate - 1;
		return rezultat;
	}
};


int main()
{
	Stiva* stiva = new Stiva();
	int capacitateMax;
	int n;
	int scot;
	try {
		cout << "Numarul de elemente: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			int el;
			cout << "Element = ";
			cin >> el;
			stiva->push(el);
		}
		cout << "Cate elemente vrei sa scoti:";
		cin >> scot;
		for (int i = 0; i < scot; i++) {
			int el = stiva->pop();
			cout << "Element = " << el<<endl;	
		}
	}
	catch (AvertismentDepasireCapacitate  er) {
		cerr << "Eroare " << er.mesaj;
	}
	catch (AvertismentStivaGoala  er) {
		cerr << "Eroare " << er.mesaj;
	}
	catch (...) {
		cerr << "Tratare eroare necunoscuta";
	}
};