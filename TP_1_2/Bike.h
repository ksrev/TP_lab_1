#pragma once
#include "Base.h"
class Bike :
    public Base
{
private:
    string typeArea;
    double voluemeEnage, powerEnage;
public:
	Bike();
	Bike(string mark, string model, string typeArea, double voluemeEnage, double powerEnage);
	Bike(const Bike& bike);
	~Bike() { cout << "?????? ?????????? Bike" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getTypeArea() { return typeArea; }
	void setTypeArea(string _typeArea) { typeArea = _typeArea; }

	double getVoluemeEnage() { return voluemeEnage; }
	void setVoluemeEnage(double _voluemeEnage) { voluemeEnage = _voluemeEnage; }

	double getPowerEnage() { return powerEnage; }
	void setPowerEnage(double _powerEnage) { powerEnage = _powerEnage; }
};

