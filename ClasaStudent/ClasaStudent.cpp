#include<iostream>
#include<conio.h>

using namespace std;

//citire si afisare clasa student
//void citire(Student &x)
//cout << "nume:";
//cin >> x.nume;

class Student {
public:
	char* nume;
	char* prenume;

	void citeste_nume(char* nume, char* prenume);
	void afisare_nume();
};
void Student::citeste_nume(char* student_nume, char* student_prenume) {
	strcpy_s(this->nume, student_nume);
	strcpy_s(this->prenume, student_prenume);

}
void Student::afisare_nume() {
	cout << "Numele studentului este: " << nume << endl;
}

int main() {
	
	char student_nume[20];
	char student_prenume[20];
	cout << "numele studentului";
	cin >> student_nume;
	cout <<"prenume student";
	cin >> student_prenume;
}
