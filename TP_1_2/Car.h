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
	~Car() { cout << "Вызван деструктор Car" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();
};

