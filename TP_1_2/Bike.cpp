#include "Bike.h"

Bike::Bike() : Base("��������", "�� ������", "�� ������"), typeArea("�� ������"), voluemeEnage(0.0), powerEnage(0.0)
{
	cout << "������ ����������� Bike" << endl;
}

Bike::Bike(string mark, string model, string typeArea, double voluemeEnage, double powerEnage) :
	Base("��������", mark, model), typeArea(typeArea), voluemeEnage(voluemeEnage), powerEnage(powerEnage)
{
	cout << "������ ����������� Bike" << endl;
}

Bike::Bike(const Bike& bike) :
	Base(bike), typeArea(bike.typeArea), voluemeEnage(bike.voluemeEnage), powerEnage(bike.powerEnage)
{
	cout << "������ ����������� ����������� Bike" << endl;
}

void Bike::inputFromConsole()
{
	Base::inputFromConsole();
	cout << "������� ���������: ";
	getline(cin, typeArea);
	cout << "������� ����� ���������: ";
	voluemeEnage = safeInput(1.0, (double)INT32_MAX);
	cout << "������� �������� ���������: ";
	powerEnage = safeInput(1.0, (double)INT32_MAX);
}

void Bike::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	Base::inputFromFile(file, tmpS);
	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	typeArea = tmpS;
	if (!getline(file, tmpS))
		throw err;
	voluemeEnage = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	powerEnage = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Bike::printToConsole()
{
	Base::printToConsole();
	cout << "��� ���������: " << typeArea << endl;
	cout << "����� ���������: " << voluemeEnage << endl;
	cout << "��������� ���������: " << powerEnage << endl;
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
	Base::change();
	cout << "������� ����� ���������: ";
	getline(cin, typeArea);
	cout << "������� ����� ����� ���������: ";
	voluemeEnage = safeInput(1.0, (double)INT32_MAX);
	cout << "������� ����� �������� ���������: ";
	powerEnage = safeInput(1.0, (double)INT32_MAX);
}