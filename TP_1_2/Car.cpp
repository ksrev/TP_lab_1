#include "Car.h"

Car::Car() : Base("Ŕâňîěîáčëü", "Íĺ çŕäŕíî", "Íĺ çŕäŕíî"), color("Íĺ çŕäŕíî"), typeKPP("Íĺ çŕäŕíî"), voluemeEnage(0.0)
{
	cout << "Âűçâŕí ęîíńňđóęňîđ Car" << endl;
}

Car::Car(string mark, string model, string color, string typeKPP, double voluemeEnage) : 
	Base("Ŕâňîěîáčëü", mark, model), color(color), typeKPP(typeKPP), voluemeEnage(voluemeEnage)
{
	cout << "Âűçâŕí ęîíńňđóęňîđ Car" << endl;
}

Car::Car(const Car& car) :
	Base(car), color(car.color), typeKPP(car.typeKPP), voluemeEnage(car.voluemeEnage)
{
	cout << "Âűçâŕí ęîíńňđóęňîđ ęîďčđîâŕíč˙ Car" << endl;
}

void Car::inputFromConsole()
{
	Base::inputFromConsole();
	cout << "Введите цвет: ";
	getline(cin, color);
	cout << "Введите тип КПП: ";
	getline(cin, typeKPP);
	cout << "Введите объем двигателя: ";
	voluemeEnage = safeInput(1.0, (double)INT32_MAX);
}

void Car::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	Base::inputFromFile(file, tmpS);
	string err = "Ôŕéë íĺ ěîćĺň áűňü ęîđđĺęňíî ďđî÷čňŕí";
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
	cout << "Öâĺň: " << color << endl;
	cout << "Ňčď ĘĎĎ: " << typeKPP << endl;
	cout << "Îáúĺě äâčăŕňĺë˙: " << voluemeEnage << endl;
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
	cout << "Ââĺäčňĺ íîâűé öâĺň: ";
	getline(cin, color);
	cout << "Ââĺäčňĺ íîâűé ňčď ĘĎĎ: ";
	getline(cin, typeKPP);
	cout << "Ââĺäčňĺ íîâűé îáúĺě äâčăŕňĺë˙: ";
	voluemeEnage = safeInput(1.0, (double)INT32_MAX);
}
