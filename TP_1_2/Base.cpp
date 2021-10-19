#include "Base.h"

Base::Base(string typeObj, string mark, string model) : typeObj(typeObj), mark(mark), model(model)
{
	cout << "������ ����������� Base" << endl;
}

Base::Base(const Base& base) : typeObj(base.typeObj), mark(base.mark), model(base.model)
{
	cout << "������ ����������� ����������� Base" << endl;
}

void Base::inputFromConsole()
{
	cout << "������� �����: ";
	getline(cin, mark);
	cout << "������� ������: ";
	getline(cin, model);
}

void Base::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
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
	cout << "�����: " << mark << endl;
	cout << "������: " << model << endl;
}

void Base::printToFile(ostream& out)
{
	out << typeObj << endl;
	out << mark << endl;
	out << model << endl;
}

void Base::change()
{
	cout << "������� ����� �����: ";
	getline(cin, mark);
	cout << "������� ����� ������: ";
	getline(cin, model);
}