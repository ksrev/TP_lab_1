#include "Bus.h"

Bus::Bus() : Base("Автобус", "Не задано", "Не задано"), destination("Не задано"), countOfSeatst(0), allCount(0)
{
	cout << "Вызван конструктор Bus" << endl;
}

Bus::Bus(string mark, string model, string destination, int countOfSeatst, int allCount) :
	Base("Автобус", mark, model), destination(destination), countOfSeatst(countOfSeatst), allCount(allCount)
{
	cout << "Вызван конструктор Bus" << endl;
}

Bus::Bus(const Bus& bus) :
	Base(bus), destination(bus.destination), countOfSeatst(bus.countOfSeatst), allCount(bus.allCount)
{
	cout << "Вызван конструктор копирования Bus" << endl;
}

void Bus::inputFromConsole()
{
	Base::inputFromConsole();
	cout << "Введите конечный пукнт: ";
	getline(cin, destination);
	cout << "Введите количество сидячих мест: ";
	countOfSeatst = safeInput(1, INT32_MAX);
	cout << "Введите общее количество мест: ";
	allCount = safeInput(countOfSeatst, INT32_MAX);
}

void Bus::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	Base::inputFromFile(file, tmpS);
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	destination = tmpS;
	if (!getline(file, tmpS))
		throw err;
	
	countOfSeatst = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	allCount = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
}

void Bus::printToConsole()
{
	Base::printToConsole();
	cout << "Конечнй пункт " << destination << endl;
	cout << "Количество сидячих мест: " << countOfSeatst << endl;
	cout << "Общее количество мест: " << allCount << endl;
}

void Bus::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << destination << endl;
	out << countOfSeatst << endl;
	out << allCount << endl;
}

void Bus::change()
{
	Base::change();
	cout << "Введите новый конечный пукнт: ";
	getline(cin, destination);
	cout << "Введите новое количество сидячих мест: ";
	countOfSeatst = safeInput(1, INT32_MAX);
	cout << "Введите новое общее количество мест: ";
	allCount = safeInput(countOfSeatst, INT32_MAX);
}