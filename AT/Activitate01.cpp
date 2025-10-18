#include <iostream>

using namespace std;

struct Carte {
	char* autor;
	int nrPagini;
};

void afisareCarte(Carte carte) {
	cout << endl << "Cartea scrisa de " << carte.autor << " are " << carte.nrPagini << " pagini.";
}

int suma() {
	int dim = 5;
	int numere[] = { 1, 2, 3, 4, 5 };

	int sum = 0;
	for (int i = 0; i < dim; i++) {
		sum += numere[i];
	}


	return sum;
}

void afisareVector(int* vector, int dim) {
	cout << endl << "Vectorul este: [";
	for (int i = 0; i < dim - 1; i++) {
		cout << vector[i] << ", ";
	}
	cout << vector[dim-1] << "]";
}

int pozitieMaxim(int* vector, int dim) {
	int poz = 0;
	for (int i = 1; i < dim; i++) {
		if (vector[poz] < vector[i]) {
			poz = i;
		}
	}

	return poz;
}

void stergereMaximDePePozitie(int** vector, int* dim, int poz) {
	int* vectorAux = new int[*dim - 1];
	int k = 0;
	for (int i = 0; i < *dim; i++) {
		if (poz != i) {
			vectorAux[k++] = (*vector)[i];
		}
	}

	(*dim)--;
	delete[](*vector);
	(*vector) = vectorAux;
}

void main() {
	cout << endl << "Primul seminar de POO";

	Carte carte1;
	carte1.nrPagini = 250;
	carte1.autor = new char[strlen("Popescu")+1];
	strcpy_s(carte1.autor, strlen("Popescu") +1, "Popescu");

	afisareCarte(carte1);

	delete[] carte1.autor;
	
	cout << endl << "Suma numerelor este " << suma();

	/*
	char buffer[50];

	cout << endl << "Introdu adresa: ";
	// cin >> buffer;
	cin.getline(buffer, 50);
	char* adresa = new char[strlen(buffer) + 1];
	strcpy_s(adresa, strlen(buffer) + 1, buffer);

	cout << endl << "Adresa introdusa este: " << adresa;
	delete[] adresa; */

	int dim = 3;
	int* numere = new int[dim];
	
	for (int i = 0; i < dim; i++) {
		cout << endl << "Vector[" << i << "]: ";
		cin >> numere[i];
	}

	afisareVector(numere, dim);
	cout << endl << "Pozitia maximului in vector este: " << pozitieMaxim(numere, dim);
	stergereMaximDePePozitie(&numere, &dim, pozitieMaxim(numere, dim));
	afisareVector(numere, dim);

	delete[] numere;
}