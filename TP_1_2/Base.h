#pragma once
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Base
{
private:
	string typeObj, mark, model;
public:
	Base(string typeObj, string mark, string model);
	Base(const Base& base);
	~Base() { cout << "Вызван деструктор Base" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getTypeObj() { return typeObj; }
};

