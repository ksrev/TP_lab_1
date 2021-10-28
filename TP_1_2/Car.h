#pragma once
#include "Base.h"

class Car :
    public Base
{
private:
    string color, typeKPP;
    double voluemeEnage;
public:
	Car();
	Car(string mark, string model, string color, string typeKPP, double voluemeEnage);
	Car(const Car& car);
	~Car() { cout << "Âûçâàí äåñòðóêòîð Car" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getColor() { return color; }
	void setColor(string _color) { color = _color; }

	string getTypeKPP() { return typeKPP; }
	void setTypeKPP(string _typeKPP) { typeKPP = _typeKPP; }

	double getVoluemeEnage() { return voluemeEnage; }
	void setVoluemeEnage(double _voluemeEnage) { voluemeEnage = _voluemeEnage; }
};

