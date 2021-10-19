#include "Bus.h"

Bus::Bus() : Base("��������", "�� ������", "�� ������"), destination("�� ������"), countOfSeatst(0), allCount(0)
{
	cout << "������ ����������� Bus" << endl;
}

Bus::Bus(string mark, string model, string destination, int countOfSeatst, int allCount) :
	Base("��������", mark, model), destination(destination), countOfSeatst(countOfSeatst), allCount(allCount)
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
	cout << "������� �������� �����: ";
	getline(cin, destination);
	cout << "������� ���������� ������� ����: ";
	cin >> countOfSeatst; //todo inputInt
	cout << "������� ����� ���������� ����: ";
	cin >> allCount;//todo inputInt
}

void Bus::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
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
	cout << "������� ����� �������� �����: ";
	getline(cin, destination);
	cout << "������� ����� ���������� ������� ����: ";
	cin >> countOfSeatst; //todo inputInt
	cout << "������� ����� ����� ���������� ����: ";
	cin >> allCount;//todo inputInt
}