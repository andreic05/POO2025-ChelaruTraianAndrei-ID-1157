#include<iostream>

using namespace std;

class Fruct {
private:
	const int idFruct;
	static int numarFructe;
	char* nume;
	string culoare;
	float greutate;
	int lunaMaturitate;
	int nrSeminte;
	float* greutatiSeminte;

public:
	int getId() {
		return this->idFruct;
	}

	void setGreutate(float greutate) {
		if (greutate > 0) {
			(*this).greutate = greutate;//-> inseamna dereferentiere+accesare
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	char* getNume() {
		return this->nume;
	}

	void setNume(const char* nume) {
		if (strlen(nume) > 0) {
			if (this->nume != nullptr) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}

	void setCuloare(string culoare) {
		if (culoare.length() > 0) {
			this->culoare = culoare;
		}
	}

	void setGreutatiSeminte(int nrSeminte, float* greutatiSeminte) {
		if (nrSeminte > 0) {
			this->nrSeminte = nrSeminte;
			if (this->greutatiSeminte != nullptr) {
				delete[] this->greutatiSeminte;
			}
			this->greutatiSeminte = new float[nrSeminte];
			for (int i = 0; i < nrSeminte; i++) {
				this->greutatiSeminte[i] = greutatiSeminte[i];
			}
		}
	}

	float* getGreutatiSeminte() {
		return this->greutatiSeminte;
	}

	float getGreutateSamanta(int pozitie) {
		try {
			if (pozitie >= 0 && pozitie < nrSeminte) {
				return this->greutatiSeminte[pozitie];
			}
			throw exception();
		}
		catch (...) {
			cout << endl << "Index out of range" << endl;
		}
	}

	static int getNumarFructe() {
		return numarFructe;
	}

	Fruct() :idFruct(++numarFructe), culoare("Rosu") {
		//this->idFruct = 1; constatele nu pot fi initializate astfel
		//this->culoare = "Rosu";
		this->greutate = 0.6;
		this->lunaMaturitate = 6;
		this->nrSeminte = 0;
		this->greutatiSeminte = nullptr;
		this->nume = nullptr;
	}

	Fruct(const char* nume, string culoare, float greutate, int lunaMaturitate, int nrSeminte, const float* greutatiSeminte) :idFruct(++numarFructe) {
		this->culoare = culoare;
		this->greutate = greutate;
		this->lunaMaturitate = lunaMaturitate;
		this->nrSeminte = nrSeminte;

		this->greutatiSeminte = new float[nrSeminte];
		for (int i = 0; i < nrSeminte; i++) {
			this->greutatiSeminte[i] = greutatiSeminte[i];
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	Fruct(const Fruct& fruct) :idFruct(++numarFructe) {
		this->culoare = fruct.culoare;
		this->greutate = fruct.greutate;
		this->lunaMaturitate = fruct.lunaMaturitate;
		this->nrSeminte = fruct.nrSeminte;

		this->greutatiSeminte = new float[nrSeminte];
		for (int i = 0; i < nrSeminte; i++) {
			this->greutatiSeminte[i] = fruct.greutatiSeminte[i];
		}
		this->nume = new char[strlen(fruct.nume) + 1];
		strcpy_s(this->nume, strlen(fruct.nume) + 1, fruct.nume);
	}

	Fruct& operator=(const Fruct& fruct) { //constantele nu se pot modifica in operator
		this->culoare = fruct.culoare;
		this->greutate = fruct.greutate;
		this->lunaMaturitate = fruct.lunaMaturitate;
		this->nrSeminte = fruct.nrSeminte;

		if (this->greutatiSeminte != nullptr) delete[] this->greutatiSeminte;

		this->greutatiSeminte = new float[nrSeminte];
		for (int i = 0; i < nrSeminte; i++) {
			this->greutatiSeminte[i] = fruct.greutatiSeminte[i];
		}

		if (this->nume != nullptr) delete[] this->nume;
		this->nume = new char[strlen(fruct.nume) + 1];
		strcpy_s(this->nume, strlen(fruct.nume) + 1, fruct.nume);

		return *this; // this is for chaining f1 = f2 = f3 = f4
	}

	~Fruct() {
		if (this->nume != nullptr) delete[] this->nume;
		if (this->greutatiSeminte != nullptr) delete[] this->greutatiSeminte;
	}
};

int Fruct::numarFructe = 0;

void afisareFruct(Fruct& fruct) {
	cout << endl << "Id: " << fruct.getId() << ", Nume: " << fruct.getNume();
}

void main() {
	
	float* vector = new float[3] {0.1, 0.2, 0.3};
	

	Fruct mar("Mar", "Galben", 0.4, 8, 3, vector);

	delete[] vector;
	
	//Fruct mar2(mar);
	Fruct mar2 = mar;

	Fruct fructDefault;
	fructDefault = mar;

	afisareFruct(fructDefault);
	
	mar.getGreutateSamanta(10);
}

	// afisare, destructor, try catch, cativa operatori

	//discutie despre atribute constante
	//atribute statice
	//constructor de copiere
	// destructor
	//operator =(de atribuire)
	//alti operatori

