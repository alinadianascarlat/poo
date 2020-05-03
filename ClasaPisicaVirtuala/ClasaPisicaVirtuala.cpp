
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

using namespace std;

class Animal {

protected:
	char nume[100];

public:
	Animal(char* nume);
	virtual char* sunet();
	char* getNume();

};

class Pisica :public Animal {

public:
	Pisica(char* nume) :Animal(nume) {
	}

	char* sunet() {
		return (char*)"Miau !";
	}
};

class Caine : public Animal {

public:
	Caine(char* nume) : Animal(nume) {
	}

	char* sunet() {
		return (char*)"Ham!";
	}
};


int main() {

	Animal* animal[] = {
	new Pisica((char*)"Felix"),
	new Caine((char*)"Azorel"),
	new Pisica((char*)"Tom"),
	};
	for (int i = 0; i < 3; i++) {
		cout << animal[i]->getNume() << " : ";
		cout << animal[i]->sunet() << endl;

	}
}
