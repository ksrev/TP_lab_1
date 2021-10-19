#include "fabric.h"

Base* createObj(string name)
{
	if (name == "Автомобиль")
		return new Car();
	if (name == "Автобус")
		return new Bus();
	if (name == "Мотоцикл")
		return new Bike();
	string err = "Тип объекта не распознан";
	throw err;
}