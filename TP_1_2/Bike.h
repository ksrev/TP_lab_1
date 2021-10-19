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
	~Bike() { cout << "Вызван деструктор Bike" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();
};

