#include "Polynom.h"
#include <iostream>

using namespace std;

//конструкто по умолчанию
Polynom::Polynom()
{
	//инициализируем многочлен нулевой степенью
	_degree = 0;
	
	//и помещаем в него только один элемент - самый первый и равный нулю
	_coefficients = new double[_degree + 1];
	_coefficients[0] = 0;
}

//конструктор с параметрами
Polynom::Polynom(int degree, double* coefficients)
{
	//размер массива должен быть на 1 больше, чем степень многочлена
	//т.к. степень многочлена - максимальная степень одночлена, входящего в многочлен
	//т.е. при степени 9 многочлен будет содержать 10 слагаемых - от 0 до 9 степени включительно

	if (degree < 0)
		throw exception("Negative degree of the polynom");

	if (!coefficients)
		throw exception("Array of coefficients equals to nullptr");

	//сохраняем степень из аргумента
	_degree = degree;

	//копируем все коэффициенты из входного массива в наш объект
	_coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		_coefficients[i] = coefficients[i];
}

//конструктор копирования
Polynom::Polynom(const Polynom& polynom)
{
	//создаем копию входного объекта

	//копируем степень полинома
	_degree = polynom._degree;

	//копируем все коэффициенты из входного объекта в наш объект
	_coefficients = new double[_degree + 1];
	for (int i = 0; i < _degree + 1; i++)
		this->_coefficients[i] = polynom._coefficients[i];
}

//деструктор
Polynom::~Polynom()
{
	delete[] _coefficients;
}



//геттеры - нужны для получения полей класса

//получение степени многочлена
int Polynom::getDegree()
{
	return _degree;
}

//получение массива коэффициентов
double* Polynom::getCoefficients()
{
	//копируем содержимое массива коэффициентов 
	double* coefficientsCopy = new double[_degree + 1];
	for (int i = 0; i < _degree + 1; i++)
		coefficientsCopy[i] = _coefficients[i];

	//возвращаем копию
	return coefficientsCopy;
}

//получение коэффициента при степени degree
double Polynom::getCoefficient(int degree)
{
	if ((degree < 0) || (degree > _degree))
		throw exception("Bad degree");

	return _coefficients[degree];
}



//сеттеры - методы, необходимые для установки полей класса

//изменить степень многочлена
void Polynom::setDegree(int degree)
{
	if (degree < 0)
		throw exception("Negative degree of the polynom");

	_degree = degree;

	delete[] _coefficients;
	_coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		_coefficients[i] = 0;
}

//изменить коэффициенты многочлена
void Polynom::setCoefficients(double* coefficients)
{
	if (!coefficients)
		throw exception("Array of coefficients equals to nullptr");

	for (int i = 0; i < _degree + 1; i++)
		this->_coefficients[i] = coefficients[i];
}

//изменить коэффициент при степени degree
void Polynom::setCoefficient(double coefficient, int degree)
{
	if ((degree < 0) || (degree > _degree))
		throw exception("Bad degree");

	_coefficients[degree] = coefficient;
}



//вывод содержимого многочлена на экран
void Polynom::show()
{
	for (int i = _degree; i > 0; i--)
		cout << _coefficients[i] << "*x^" << i << " + ";
	cout << _coefficients[0] << "*x^0";
}

//вычислить значение многочлена
double Polynom::compute(double x)
{
	double polynomValue = 0, singleTermValue = 1;
	for (int i = 0; i < _degree + 1; i++)
	{
		polynomValue += singleTermValue * _coefficients[i];

		singleTermValue *= x;
	}

	return polynomValue;
}
