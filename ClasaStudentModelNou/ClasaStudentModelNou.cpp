#include<iostream>
#include<conio.h>

using namespace std;    //afisare nume, prenume, varsta,nota student

class Student {
private:
	char* nume;
	char* prenume;
	int varsta;
	int nota;

public:
	Student(char* nume, char* prenume, int varsta, int nota) {
		this->nume = nume;
		this->prenume = prenume;
		this->varsta = varsta;
		this->nota = nota;
	}

	void afisare() {
		cout << "Nume" << nume << endl;
		cout << "Prenume" << prenume << endl;
		cout << "Varsta" << varsta << endl;
		cout << "Nota" << nota << endl;
	}
	
};
int main() {
	char nume_student[20];
	char prenume_student[20];
	int nota_student;
	int varsta_student;
	cout << "nume student :";
	cin >> nume_student;
	cout << "prenume student :";
	cin >> prenume_student;
	cout << "varsta student :";
	cin >> varsta_student;
	cout << "nota student :";
	cin >> nota_student;

}