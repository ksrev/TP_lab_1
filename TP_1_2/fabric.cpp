#include "fabric.h"

Base* createObj(string name)
{
	if (name == "����������")
		return new Car();
	if (name == "�������")
		return new Bus();
	if (name == "��������")
		return new Bike();
	string err = "��� ������� �� ���������";
	throw err;
}