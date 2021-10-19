#pragma once
#include "Base.h"
class Bus :
    public Base
{
private:
    string destination;
    int countOfSeatst, allCount;
public:
	Bus();
	Bus(string mark, string model, string destination, int countOfSeatst, int allCount);
	Bus(const Bus& bus);
	~Bus() { cout << "Вызван деструктор Bus" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();
};

