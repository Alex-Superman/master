#include "PolynomTests.h"
#include <exception>
#include <iostream>

using namespace std;

//тест для конструктора по умолчанию
void defaultConstructorTest()
{
	Polynom P;

	cout << "Default constructor test:" << endl;
	cout << "Excpected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << 0 << " \t\t " << P.getDegree() << endl;
	cout << "Coefficient:" << endl;
	cout << 0 << " \t\t " << P.getCoefficient(0) << endl;

	//конструктор по умолчанию должен создавать многочлен степени 0 и с нулевыми коэффициентами
	if (P.getDegree() != 0)
		throw exception("Invalid degree value in the default constructor");

	if(P.getCoefficient(0) != 0)
		throw exception("Invalid coefficient value in the default constructor");

	cout << "The default constructor was tested successfully!" << endl;
}

//тест для конструктора с параметрами
void parametrConstructorTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;
	

	//конструктор с параметрами должен создавать многочлен со степенью degree и коэффициентами coefficients

	Polynom P(degree,coefficients);

	cout << "Parametr constructor test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << degree << " \t\t " << P.getDegree() << endl;
	cout << "Coefficients:" << endl;
	for(int i = 0;i<degree+1;i++)
		cout << coefficients[i] << " \t\t " << P.getCoefficient(i) << endl;

	//степень объекта должна совпадать с degree
	if (P.getDegree() != degree)
		throw exception("Invalid degree value in the parametr constructor");

	//коэффициенты должны совпадать с coefficients
	for(int i = 0;i<degree+1;i++)
		if (P.getCoefficient(i) != coefficients[i])
			throw exception("Invalid coefficient value in the parametr constructor");

	//конструктор с параметрами должен выбрасывать исключение, если указана отрицательная степень
	try
	{
		Polynom P(-1, coefficients);

		throw exception("A constructor with parameters can take a negative degree");
	}
	catch (const exception& error)
	{
		if (strcmp(error.what(), "Negative degree of the polynom"))
			throw;
	}

	delete[] coefficients;
	coefficients = nullptr;

	//конструктор с параметрами должен выбрасывать исключение, если на вход пришел нулевой указатель
	try
	{
		Polynom P(1, coefficients);

		throw exception("A constructor with parameters can take a nullptr array of coefficients");
	}
	catch (const exception& error)
	{
		if (strcmp(error.what(), "Array of coefficients equals to nullptr"))
			throw;
	}

	cout << "The paramets constructor was tested successfully!" << endl;

}

//тест для конструктора копирования
void copyConstructorTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;

	//конструктор с параметрами должен создавать многочлен со степенью degree и коэффициентами coefficients

	Polynom P(degree, coefficients), P2(P);

	cout << "Copy constructor test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << P.getDegree() << " \t\t " << P2.getDegree() << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < P.getDegree() + 1; i++)
		cout << P.getCoefficient(i) << " \t\t " << P2.getCoefficient(i) << endl;

	//степени многочленов должны совпадать
	if (P2.getDegree() != P.getDegree())
		throw exception("Bad degree in copy constructor");

	//коэффициенты должны совпадать
	for (int i = 0; i < P.getDegree() + 1; i++)
		if (P2.getCoefficient(i) != P.getCoefficient(i))
			throw exception("Bad coefficients in copy constructor");

	cout << "The copy constructor was tested successfully!" << endl;
}

//тест для сеттера степени
void setDegreeTest()
{
	int degree = 5;

	Polynom P;
	P.setDegree(degree);

	cout << "setDegree() test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << degree << " \t\t " << P.getDegree() << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < degree + 1; i++)
		cout << 0 << " \t\t " << P.getCoefficient(i) << endl;

	//метод должен установить значение степени равное degree
	if (P.getDegree() != degree)
		throw exception("Bad degree in setDegree()");

	//все коэффициенты должны равняться нулю
	for (int i = 0; i < degree + 1; i++)
		if (P.getCoefficient(i) != 0)
			throw exception("Bad coefficient in setDegree()");

	//метод должен выбрасывать исключение при попытке установить отрицательную степень
	try
	{
		P.setDegree(-1);

		throw exception("A setDegree() can take a negative degree");
	}
	catch (const exception& error)
	{
		if (strcmp(error.what(), "Negative degree of the polynom"))
			throw;
	}

	cout << "The setDegree() was tested successfully!" << endl;
}

//тест для сеттера коэффициентов
void setCoefficientsTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = 0;

	Polynom P(degree, coefficients);

	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;
	P.setCoefficients(coefficients);
	
	cout << "setCoefficients() test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < P.getDegree() + 1; i++)
		cout << coefficients[i] << " \t\t " << P.getCoefficient(i) << endl;

	//коэффициенты полинома должны совпадать с коэффициентами, переданными в метод
	for (int i = 0; i < degree + 1; i++)
		if (P.getCoefficient(i) != coefficients[i])
			throw exception("Bad coefficient in setCoefficients");

	delete[] coefficients;
	coefficients = nullptr;

	//метод должен выбрасывать исключение, если на вход пришел нулевой указатель
	try
	{
		P.setCoefficients(coefficients);

		throw exception("A setCoefficients() can take a nullptr array of coefficients");
	}
	catch (const exception& error)
	{
		if (strcmp(error.what(), "Array of coefficients equals to nullptr"))
			throw;
	}

	cout << "The setCoefficients() was tested successfully!" << endl;

}

//тест для сеттера одного коэффициента
void setCoefficientTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = 0;

	Polynom P(degree, coefficients);

	cout << "setCoefficient() test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < degree + 1; i++)
	{
		P.setCoefficient(i, i);
		
		cout << i << " \t\t " << P.getCoefficient(i) << endl;

		//все установленные значения должны совпадать с входными значениями
		if (P.getCoefficient(i) != i)
			throw exception("Bad value in setCoefficient()");
	}
	delete[] coefficients;

	//метод должен выбрасывать исключение, если указана отрицательная степень
	try
	{
		P.setCoefficient(1, -1);

		throw exception("A getCoefficient() can take a negative degree");
	}
	catch (const exception& error)
	{
		if (strcmp(error.what(), "Bad degree"))
			throw;
	}

	//метод должен выбрасывать исключение, если указана степень, превышающая степень многочлена
	try
	{
		P.setCoefficient(1, degree + 2);

		throw exception("A getCoefficient() can take a bad degree");
	}
	catch (const exception& error)
	{
		if (strcmp(error.what(), "Bad degree"))
			throw;
	}

	cout << "The setCoefficient() was tested successfully!" << endl;

}

//тест для метода вычисления многочлена
void computeTest()
{
	double x = 2;
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = 1;

	Polynom P(degree, coefficients);
	
	cout << "compute() test for x = 2:" << endl;
	cout << "Excpected \t Actually" << endl;
	cout << 63 << " \t\t " << P.compute(x) << endl;
	

	if (P.compute(x) != 63)
		throw exception("Bad value in compute()");

	cout << "The compute() was tested successfully!" << endl;
}
