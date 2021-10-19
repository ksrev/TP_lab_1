#include "Car.h"

Car::Car() : Base("Автомобиль", "Не задано", "Не задано"), color("Не задано"), typeKPP("Не задано"), voluemeEnage(0.0)
{
	cout << "Вызван конструктор Car" << endl;
}

Car::Car(string mark, string model, string color, string typeKPP, double voluemeEnage) : 
	Base("Автомобиль", mark, model), color(color), typeKPP(typeKPP), voluemeEnage(voluemeEnage)
{
	cout << "Вызван конструктор Car" << endl;
}

Car::Car(const Car& car) :
	Base(car), color(car.color), typeKPP(car.typeKPP), voluemeEnage(car.voluemeEnage)
{
	cout << "Вызван конструктор копирования Car" << endl;
}

void Car::inputFromConsole()
{
	cout << "Введите новый цвет: ";
	getline(cin, color);
	cout << "Введите новый тип КПП: ";
	getline(cin, typeKPP);
	cout << "Введите новый объем двигателя: ";
	cin >> voluemeEnage; //todo inputDouble
}

void Car::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	color = tmpS;
	if (!getline(file, tmpS))
		throw err;
	typeKPP = tmpS;
	if (!getline(file, tmpS))
		throw err;
	voluemeEnage = stod(tmpS); //todo add check
}

void Car::printToConsole()
{
	Base::printToConsole();
	cout << "Цвет: " << color << endl;
	cout << "Тип КПП: " << typeKPP << endl;
	cout << "Объем двигателя: " << voluemeEnage << endl;
}

void Car::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << color << endl;
	out << typeKPP << endl;
	out << voluemeEnage << endl;
}

void Car::change()
{
	cout << "Введите новый цвет: ";
	getline(cin, color);
	cout << "Введите новый тип КПП: ";
	getline(cin, typeKPP);
	cout << "Введите новый объем двигателя: ";
	cin >> voluemeEnage; //todo inputDouble
}