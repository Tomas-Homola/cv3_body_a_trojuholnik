#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Bod // class pre Bod
{
private:
	float x;
	float y;
	float z;

public:
	Bod(); // prazdny konstruktor
	Bod(float x, float y, float z); // ten druhy konstruktor

	void getData(float x, float y, float z); // funkcia na ziskanie dat
	void printData(); // funkcia na vypisanie dat

	void getX(float x) { this->x = x; } // zmena x suradnice
	void getY(float y) { this->y = y; } // zmena y suradnice
	void getZ(float z) { this->z = z; } // zmena z suradnice

	float X() { return this->x; } // vratenie x suradnice
	float Y() { return this->y; } // vratenie y suradnice
	float Z() { return this->z; } // vratenie z suradnice
};

Bod::Bod() // prazdny konstruktor
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

Bod::Bod(float x, float y, float z) // konstruktor s konkretnymi hodnotami
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Bod::getData(float x, float y, float z) // funkcia na ziskanie dat o bode
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Bod::printData() // funkcia na vypisanie dat o bode
{
	cout << "x = " << this->x << ", y = " << this->y << ", z = " << this->z << endl;
}

class Trojuhlonik // class pre trojuholnik
{
private:
	Bod body[3];

public:
	Trojuhlonik(); // prazdny konstruktor
	Trojuhlonik(Bod bod0, Bod bod1, Bod bod2); // druhy konstruktor

	void getData(Bod bod0, Bod bod1, Bod bod2); // funkcia pre nacitane dat
	void printData(); // funkcia pre vypisanie dat
	float obvod();
	float obsah();
	void printNormala();
	void printAngles();
};

Trojuhlonik::Trojuhlonik() // prazdny konstruktor
{
	this->body[0].getData(0.0, 0.0, 0.0);
	this->body[1].getData(0.0, 0.0, 0.0);
	this->body[2].getData(0.0, 0.0, 0.0);
}

Trojuhlonik::Trojuhlonik(Bod bod0, Bod bod1, Bod bod2) // konstruktor s konkretnymi bodmi
{
	this->body[0] = bod0;
	this->body[1] = bod1;
	this->body[2] = bod2;
}

void Trojuhlonik::getData(Bod bod0, Bod bod1, Bod bod2) // funkcia na priradenie bodov
{
	this->body[0] = bod0;
	this->body[1] = bod1;
	this->body[2] = bod2;
}

void Trojuhlonik::printData() // funkcia pre vypisanie suradnic jednotlivych bodov
{
	cout << "Body trojuholnika:\nBod1:" << endl;
	this->body[0].printData();
	cout << "Bod2:" << endl;
	this->body[1].printData();
	cout << "Bod3:" << endl;
	this->body[2].printData();
}

float Trojuhlonik::obvod()
{
	float dist1 = sqrt((body[1].X() - body[0].X())* (body[1].X() - body[0].X()) + (body[1].Y() - body[0].Y())* (body[1].Y() - body[0].Y()) + (body[1].Z() - body[0].Z())* (body[1].Z() - body[0].Z()));
	float dist2 = sqrt((body[2].X() - body[0].X()) * (body[2].X() - body[0].X()) + (body[2].Y() - body[0].Y()) * (body[2].Y() - body[0].Y()) + (body[2].Z() - body[0].Z()) * (body[2].Z() - body[0].Z()));
	float dist3 = sqrt((body[2].X() - body[1].X()) * (body[2].X() - body[1].X()) + (body[2].Y() - body[1].Y()) * (body[2].Y() - body[1].Y()) + (body[2].Z() - body[1].Z()) * (body[2].Z() - body[1].Z()));
	
	return (dist1 + dist2 + dist3);
}

float Trojuhlonik::obsah()
{
	float nX = 0.0, nY = 0.0, nZ = 0.0, dist = 0.0; // body pre vysledny vektor (normala ku v1 a v2) po vektorovom sucine; robi sa sucin vektorov v1 (z 0 do 1) a v2 (z 0 do 2)

	nX = body[1].Y() * body[2].Z() - body[2].Y() * body[1].Z();
	nY = body[1].X() * body[2].Z() - body[2].X() * body[1].Z();
	nZ = body[1].X() * body[2].Y() - body[2].X() * body[1].Y();

	dist = sqrt((nX - body[0].X()) * (nX - body[0].X()) + (nY - body[0].Y()) * (nY - body[0].Y()) + (nZ - body[0].Z()) * (nZ - body[0].Z()));

	return (dist / 2);
}

void Trojuhlonik::printNormala()
{
	float nX = 0.0, nY = 0.0, nZ = 0.0;

	nX = body[1].Y() * body[2].Z() - body[2].Y() * body[1].Z();
	nY = body[1].X() * body[2].Z() - body[2].X() * body[1].Z();
	nZ = body[1].X() * body[2].Y() - body[2].X() * body[1].Y();

	cout << "Suradnice normaly:\nx = " << nX << ", y = " << nY << ", z = " << nZ << endl;
}

void Trojuhlonik::printAngles()
{
}

int main()
{
	Bod bod0(0.0, 0.0, 0.0);
	Bod bod1(1.0, 0.0, 0.0);
	Bod bod2(0.0, 1.0, 0.0);

	Trojuhlonik trojuholnik1(bod0, bod1, bod2);
	trojuholnik1.printData();
	cout << "obvod trojuholnika: " << trojuholnik1.obvod() << endl;
	cout << "obsah trojuholnika: " << trojuholnik1.obsah() << endl;
	trojuholnik1.printNormala();




	return(0);
}