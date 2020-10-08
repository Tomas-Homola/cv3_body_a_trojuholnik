#include <iostream>
#include <iomanip>

using namespace std;

class Bod
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
	void getX(float x);
	void getY(float y);
	void getZ(float z);
};

Bod::Bod()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

Bod::Bod(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Bod::getData(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Bod::printData() { cout << "Suradnice daneho bodu:\nx = " << this->x << ", y = " << this->y << ", z = " << this->z << endl; }

void Bod::getX(float x) { this->x = x; }

void Bod::getY(float y) { this->y = y; }

void Bod::getZ(float z) { this->z = z; }

int main()
{
	Bod bod1(1.2, 2.3, 3.4);
	Bod bod2;

	bod1.printData();
	bod1.getData(4, 5, 6);
	bod1.printData();
	
	cout << "Bod2:" << endl;
	bod2.printData();
	return(0);
}