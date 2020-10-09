#define _USE_MATH_DEFINES

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

	void changeX(float x) { this->x = x; } // zmena x suradnice
	void changeY(float y) { this->y = y; } // zmena y suradnice
	void changeZ(float z) { this->z = z; } // zmena z suradnice

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

class Trojuhlonik // class pre trojuholnik, este skusit spravit funkciu pre zmenu jednotlivych bodov
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
	void printUhly();
	void printTazisko();
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
	float x1, y1, z1; // suradnice pre vektor v1 -> body[1] a body[0]
	float x2, y2, z2; // suradnice pre vektor v2 -> body[2] a body[0]
	
	x1 = body[1].X() - body[0].X();
	y1 = body[1].Y() - body[0].Y();
	z1 = body[1].Z() - body[0].Z();

	x2 = body[2].X() - body[0].X();
	y2 = body[2].Y() - body[0].Y();
	z2 = body[2].Z() - body[0].Z();

	float nX = y1 * z2 - y2 * z1;
	float nY = x1 * z2 - x2 * z1;
	float nZ = x1 * y2 - x2 * y1;

	cout << "Suradnice normaly:\nx = " << nX << ", y = " << nY << ", z = " << nZ << endl;
}

void Trojuhlonik::printUhly()
{
	float theta0 = 0.0, theta1 = 0.0, theta2 = 0.0;
	float dist1 = sqrt((body[1].X() - body[0].X()) * (body[1].X() - body[0].X()) + (body[1].Y() - body[0].Y()) * (body[1].Y() - body[0].Y()) + (body[1].Z() - body[0].Z()) * (body[1].Z() - body[0].Z()));
	float dist2 = sqrt((body[2].X() - body[0].X()) * (body[2].X() - body[0].X()) + (body[2].Y() - body[0].Y()) * (body[2].Y() - body[0].Y()) + (body[2].Z() - body[0].Z()) * (body[2].Z() - body[0].Z()));
	float dist3 = sqrt((body[2].X() - body[1].X()) * (body[2].X() - body[1].X()) + (body[2].Y() - body[1].Y()) * (body[2].Y() - body[1].Y()) + (body[2].Z() - body[1].Z()) * (body[2].Z() - body[1].Z()));

	// vypocet urobeny cez kosinusovu vetu
	theta0 = (acos((dist1 * dist1 + dist2 * dist2 - dist3 * dist3) / (2 * dist1 * dist2)) / M_PI) * 180;
	theta1 = (acos((dist1 * dist1 + dist3 * dist3 - dist2 * dist2) / (2 * dist1 * dist3)) / M_PI) * 180;
	theta2 = (acos((dist2 * dist2 + dist3 * dist3 - dist1 * dist1) / (2 * dist2 * dist3)) / M_PI) * 180;
	
	cout << "Uhly trojuholnika:\nuhol 1 = " << theta0 << " stupnov\nuhol 2 = " << theta1 << " stupnov\nuhol 3 = " << theta2 << " stupnov" << endl;
}

void Trojuhlonik::printTazisko()
{
	float tX = (body[0].X() + body[1].X() + body[2].X()) / 3;
	float tY = (body[0].Y() + body[1].Y() + body[2].Y()) / 3;
	float tZ = (body[0].Z() + body[1].Z() + body[2].Z()) / 3;

	cout << "Suradnice taziska trojuholnika:\nx = " << tX << "\ny = " << tY << "\nz = " << tZ << endl;
}

int main()
{
	Bod bod0(1.0, 0.0, 0.0);
	Bod bod1(0.0, 1.0, 0.0);
	Bod bod2(0.0, 0.0, 1.0);

	Trojuhlonik trojuholnik1(bod0, bod1, bod2);
	trojuholnik1.printData();
	cout << "obvod trojuholnika: " << trojuholnik1.obvod() << endl;
	cout << "obsah trojuholnika: " << trojuholnik1.obsah() << endl;
	trojuholnik1.printNormala();
	trojuholnik1.printUhly();
	trojuholnik1.printTazisko();



	return(0);
}