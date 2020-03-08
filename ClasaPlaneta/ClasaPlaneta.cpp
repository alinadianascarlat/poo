#include<iostream>
#include<conio.h>

using namespace std;

// Sa se implementeze clasa Planeta(nume, raza, distanta fata de soare, durata perioade de rotatie in jurul soarelui).
// Sa se implementeze apoi clasa SistemSolar care are un nume si lista planetelor
class Planet {
private:
	char* name;
	float radius;
	float distance;
	float rotationTime;
	
public:
	Planet(char* name, float distance, float radius, float rotationTime) {
		this->name = name;
		this->radius = radius;
		this->distance = distance;
		this->rotationTime = rotationTime;
	}

	void print() {
		cout << "Planet: " << this->name << " with radius: " << radius;
	}
};

class SolarSystem {
private:
	char* name;
	Planet* planets[20];
	int numberOfPlanets;

public:
	SolarSystem(char* systemName) {
		this->name = systemName;
		this->numberOfPlanets = 0;
	}
	
	void addPlanet(Planet* p) {
		planets[numberOfPlanets] = p;
		numberOfPlanets++;
	}

	void printPlanets() {
		cout << "The solar sistem \"" << this->name << "\"" << " has the following plannets:" << endl;
		for (int i = 0; i < numberOfPlanets; i++) {
			planets[i]->print();
			cout << endl;
		}
	}
};


int main() {
	SolarSystem s((char*)"Sistem 1");
	Planet* earth = new Planet((char*)"Earth", 10, 10, 10);
	s.addPlanet(earth);
	s.addPlanet(new Planet((char*)"Neptun", 10, 10, 10));
	s.addPlanet(new Planet((char*)"Jupiter", 10, 10, 10));

	s.printPlanets();
	// The solar sistem "Sistem 1" has the following plannets:
	// - Earth
	// - Neptun
	// - Jupiter
}
