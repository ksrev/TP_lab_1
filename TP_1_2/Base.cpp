#include "Base.h"

Base::Base(string typeObj, string mark, string model) : typeObj(typeObj), mark(mark), model(model)
{
	cout << "Вызван конструктор Base" << endl;
}

Base::Base(const Base& base) : typeObj(base.typeObj), mark(base.mark), model(base.model)
{
	cout << "Вызван конструктор копирования Base" << endl;
}

void Base::inputFromConsole()
{
	cout << "Введите марку: ";
	getline(cin, mark);
	cout << "Введите модель: ";
	getline(cin, model);
}

void Base::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	mark = tmpS;
	if (!getline(file, tmpS))
		throw err;
	model = tmpS;
}

void Base::printToConsole()
{
	cout << typeObj << endl;
	cout << "Марка: " << mark << endl;
	cout << "Модель: " << model << endl;
}

void Base::printToFile(ostream& out)
{
	out << typeObj << endl;
	out << mark << endl;
	out << model << endl;
}

void Base::change()
{
	cout << "Введите новую марку: ";
	getline(cin, mark);
	cout << "Введите новую модель: ";
	getline(cin, model);
}