#include<iostream>
#include<conio.h>

using namespace std;

//Sa se implementeze clasa Planeta(nume, raza, distanta fata de soare, durata perioade de rotatie
	//in jurul soarelui).Sa se implementeze apoi clasa SistemSolar care are un nume si lista
	//planetelor
class Planeta {
private:
	char* nume;
	float raza;
	float distanta;
	float durata;
	
public:
	Planeta(char* nume, float distanta, float raza, float durata) {
		this->nume = nume;
		this->raza = raza;
		this->distanta = distanta;
		this->durata = durata;
	}

	void afisare() {
		cout << 
	}
};