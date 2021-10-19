#include "Bus.h"

Bus::Bus() : Base("�������", "�� ������", "�� ������"), destination("�� ������"), countOfSeatst(0), allCount(0)
{
	cout << "������ ����������� Bus" << endl;
}

Bus::Bus(string mark, string model, string destination, int countOfSeatst, int allCount) :
	Base("�������", mark, model), destination(destination), countOfSeatst(countOfSeatst), allCount(allCount)
{
	cout << "������ ����������� Bus" << endl;
}

Bus::Bus(const Bus& bus) :
	Base(bus), destination(bus.destination), countOfSeatst(bus.countOfSeatst), allCount(bus.allCount)
{
	cout << "������ ����������� ����������� Bus" << endl;
}

void Bus::inputFromConsole()
{
	Base::inputFromConsole();
	cout << "������� �������� �����: ";
	getline(cin, destination);
	cout << "������� ���������� ������� ����: ";
	countOfSeatst = safeInput(1, INT32_MAX);
	cout << "������� ����� ���������� ����: ";
	allCount = safeInput(countOfSeatst, INT32_MAX);
}

void Bus::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	Base::inputFromFile(file, tmpS);
	string err = "���� �� ����� ���� ��������� ��������";
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
	cout << "������� ����� " << destination << endl;
	cout << "���������� ������� ����: " << countOfSeatst << endl;
	cout << "����� ���������� ����: " << allCount << endl;
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
	cout << "������� ����� �������� �����: ";
	getline(cin, destination);
	cout << "������� ����� ���������� ������� ����: ";
	countOfSeatst = safeInput(1, INT32_MAX);
	cout << "������� ����� ����� ���������� ����: ";
	allCount = safeInput(countOfSeatst, INT32_MAX);
}