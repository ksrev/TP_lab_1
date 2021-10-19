#include "Bus.h"

Bus::Bus() : Base("Мотоцикл", "Не задано", "Не задано"), destination("Не задано"), countOfSeatst(0), allCount(0)
{
	cout << "Вызван конструктор Bus" << endl;
}

Bus::Bus(string mark, string model, string destination, int countOfSeatst, int allCount) :
	Base("Мотоцикл", mark, model), destination(destination), countOfSeatst(countOfSeatst), allCount(allCount)
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
	cout << "Введите конечный пукнт: ";
	getline(cin, destination);
	cout << "Введите количество сидячих мест: ";
	cin >> countOfSeatst; //todo inputInt
	cout << "Введите общее количество мест: ";
	cin >> allCount;//todo inputInt
}

void Bus::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	destination = tmpS;
	if (!getline(file, tmpS))
		throw err;
	countOfSeatst = stoi(tmpS); //todo add check
	if (!getline(file, tmpS))
		throw err;
	allCount = stoi(tmpS); //todo add check
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
	cout << "Введите новый конечный пукнт: ";
	getline(cin, destination);
	cout << "Введите новое количество сидячих мест: ";
	cin >> countOfSeatst; //todo inputInt
	cout << "Введите новое общее количество мест: ";
	cin >> allCount;//todo inputInt
}