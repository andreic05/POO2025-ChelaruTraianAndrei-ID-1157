#include<iostream>
#include<string>

using namespace std;

class ExceptieCustom : public exception {
public:
	ExceptieCustom(const char* mesaj) : exception(mesaj) {

	}

};

class Laptop
{
private:
	int memorie;
	string marca;
	float pret;
	static const float PRET_MINIM;


public:
	Laptop(int memorie, string marca, float pret) : memorie(memorie), marca(marca), pret(pret < PRET_MINIM ? PRET_MINIM : pret) {

	}

	Laptop() : memorie(0), marca("Nespecificat"), pret(PRET_MINIM) {

	}

	virtual void print(ostream& out) const {
		out << endl << "Memorie: " << this->memorie << endl << "Marca: " << this->marca << endl << "Pret: " << this->pret << endl;
	}

	friend ostream& operator<<(ostream& out, const Laptop& l) {
		l.print(out);

		return out;
	}


};

class LaptopGaming : public Laptop {
private:
	string placaVideo;
public:
	LaptopGaming() : Laptop(), placaVideo("Nespecificat") {

	}

	LaptopGaming(int memorie, string marca, float pret, string placaVideo) : Laptop(memorie, marca, pret), placaVideo(placaVideo) {

	}

	void print(ostream& out) const override {
		Laptop::print(out);
		out << "Placa Video: " << this->placaVideo << endl;
	}

	/*friend ostream& operator<<(ostream& out, const LaptopGaming& l) {
		out << (Laptop&)l << "Placa Video: " << l.placaVideo << endl;

		return out;
	}*/


};


const float Laptop::PRET_MINIM = 1;

void main() {
	LaptopGaming laptopGaming;
	
	cout << laptopGaming;
}