#include "Bike.h"

Bike::Bike() : Base("Мотоцикл", "Не задано", "Не задано"), typeArea("Не задано"), voluemeEnage(0.0), powerEnage(0.0)
{
	cout << "Вызван конструктор Bike" << endl;
}

Bike::Bike(string mark, string model, string typeArea, double voluemeEnage, double powerEnage) :
	Base("Мотоцикл", mark, model), typeArea(typeArea), voluemeEnage(voluemeEnage), powerEnage(powerEnage)
{
	cout << "Вызван конструктор Bike" << endl;
}

Bike::Bike(const Bike& bike) :
	Base(bike), typeArea(bike.typeArea), voluemeEnage(bike.voluemeEnage), powerEnage(bike.powerEnage)
{
	cout << "Вызван конструктор копирования Bike" << endl;
}

void Bike::inputFromConsole()
{
	cout << "Введите метсность: ";
	getline(cin, typeArea);
	cout << "Введите объем двигателя: ";
	cin >> voluemeEnage; //todo inputDouble
	cout << "Введите мощность двигателя: ";
	cin >> powerEnage;//todo inputDouble
}

void Bike::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	typeArea = tmpS;
	if (!getline(file, tmpS))
		throw err;
	voluemeEnage = stod(tmpS); //todo add check
	if (!getline(file, tmpS))
		throw err;
	powerEnage = stod(tmpS); //todo add check
}

void Bike::printToConsole()
{
	Base::printToConsole();
	cout << "Тип местности: " << typeArea << endl;
	cout << "Объем двигателя: " << voluemeEnage << endl;
	cout << "Мощьность двигателя: " << powerEnage << endl;
}

void Bike::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << typeArea << endl;
	out << voluemeEnage << endl;
	out << powerEnage << endl;
}

void Bike::change()
{
	cout << "Введите новую метсность: ";
	getline(cin, typeArea);
	cout << "Введите новый объем двигателя: ";
	cin >> voluemeEnage; //todo inputDouble
	cout << "Введите новую мощность двигателя: ";
	cin >> powerEnage;//todo inputDouble
}