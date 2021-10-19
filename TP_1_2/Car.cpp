#include "Car.h"

Car::Car() : Base("����������", "�� ������", "�� ������"), color("�� ������"), typeKPP("�� ������"), voluemeEnage(0.0)
{
	cout << "������ ����������� Car" << endl;
}

Car::Car(string mark, string model, string color, string typeKPP, double voluemeEnage) : 
	Base("����������", mark, model), color(color), typeKPP(typeKPP), voluemeEnage(voluemeEnage)
{
	cout << "������ ����������� Car" << endl;
}

Car::Car(const Car& car) :
	Base(car), color(car.color), typeKPP(car.typeKPP), voluemeEnage(car.voluemeEnage)
{
	cout << "������ ����������� ����������� Car" << endl;
}

void Car::inputFromConsole()
{
	Base::inputFromConsole();
	cout << "������� ����� ����: ";
	getline(cin, color);
	cout << "������� ����� ��� ���: ";
	getline(cin, typeKPP);
	cout << "������� ����� ����� ���������: ";
	voluemeEnage = safeInput(1.0, (double)INT32_MAX);
}

void Car::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	Base::inputFromFile(file, tmpS);
	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	color = tmpS;
	if (!getline(file, tmpS))
		throw err;
	typeKPP = tmpS;
	if (!getline(file, tmpS))
		throw err;
	voluemeEnage = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Car::printToConsole()
{
	Base::printToConsole();
	cout << "����: " << color << endl;
	cout << "��� ���: " << typeKPP << endl;
	cout << "����� ���������: " << voluemeEnage << endl;
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
	Base::change();
	cout << "������� ����� ����: ";
	getline(cin, color);
	cout << "������� ����� ��� ���: ";
	getline(cin, typeKPP);
	cout << "������� ����� ����� ���������: ";
	voluemeEnage = safeInput(1.0, (double)INT32_MAX);
}