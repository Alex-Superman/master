#include "PolynomTests.h"
#include <exception>
#include <iostream>

using namespace std;

/*Лабораторная работа 1*/

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

	delete[] coefficients;
	coefficients = nullptr;

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

/*Лабораторная работа 2*/

//тест оператора +
void addOperatorTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;

	Polynom P(degree, coefficients);

	//складывыаем многочлен с самим собой
	Polynom result = P + P;

	cout << "operator + test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << degree << " \t\t " << result.getDegree() << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < result.getDegree() + 1; i++)
		cout << 2 * coefficients[i] << " \t\t " << result.getCoefficient(i) << endl;

	//степень суммы должна равняться degree
	if(result.getDegree() != degree)
		throw exception("Bad degree in operator +");

	//коэффициенты должны совпадать с ожидаемыми
	for (int i = 0; i < degree + 1; i++)
		if (result.getCoefficient(i) != 2*coefficients[i])
			throw exception("Bad coefficient in operator +");

	cout << "The operator + was tested successfully!" << endl;
}

//тест оператора -
void subOperatorTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;

	Polynom P(degree, coefficients);

	//отнимаем из многочлена самого себя
	Polynom result = P - P;

	cout << "operator - test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << degree << " \t\t " << result.getDegree() << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < result.getDegree() + 1; i++)
		cout << 0 << " \t\t " << result.getCoefficient(i) << endl;

	//степень суммы должна равняться degree
	if (result.getDegree() != degree)
		throw exception("Bad degree in operator -");

	//коэффициенты должны совпадать с ожидаемыми
	for (int i = 0; i < degree + 1; i++)
		if (result.getCoefficient(i) != 0)
			throw exception("Bad coefficient in operator -");

	cout << "The operator - was tested successfully!" << endl;
}

//тест оператора ++ (префикс)
void prefixIncrementOperatorTest()
{
	Polynom p;
	++p;

	cout << "operator ++(prefix) test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << 1 << "\t\t" << p.getDegree() << endl;

	if (p.getDegree() != 1)
		throw exception("Bad degree in operator ++ (prefix)");

	cout << "The operator ++(prefix) was tested successfully!" << endl;
}

//тест оператора ++ (постфикс)
void postfixIncrementOperatorTest()
{
	Polynom p;
	p++;

	cout << "operator ++(postfix) test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << 1 << "\t\t" << p.getDegree() << endl;

	if (p.getDegree() != 1)
		throw exception("Bad degree in operator ++ (postfix)");

	cout << "The operator ++(postfix) was tested successfully!" << endl;
}

//тест оператора -- (префикс)
void prefixDecrementOperatorTest()
{
	double coefficients[2] = { 0,1 };
	Polynom p(1, coefficients);
	--p;

	cout << "operator --(prefix) test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << 0 << "\t\t" << p.getDegree() << endl;

	if (p.getDegree() != 0)
		throw exception("Bad degree in operator -- (prefix)");

	cout << "The operator --(prefix) was tested successfully!" << endl;
}

//тест оператора -- (постфикс)
void postfixDecrementOperatorTest()
{
	double coefficients[2] = { 0,1 };
	Polynom p(1, coefficients);
	p--;

	cout << "operator --(postfix) test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << 0 << "\t\t" << p.getDegree() << endl;

	if (p.getDegree() != 0)
		throw exception("Bad degree in operator -- (postfix)");

	cout << "The operator --(postfix) was tested successfully!" << endl;
}

//тест оператора ()
void functionOperatorTest()
{
	double x = 2;
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = 1;

	Polynom P(degree, coefficients);

	cout << "operator () test for x = 2:" << endl;
	cout << "Excpected \t Actually" << endl;
	cout << 63 << " \t\t " << P(x) << endl;


	if (P(x) != 63)
		throw exception("Bad value in operator ()");

	cout << "The operator () was tested successfully!" << endl;
}

//тест оператора []
void indexOperatorTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;

	Polynom P(degree, coefficients);

	cout << "operator [] test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < degree + 1; i++)
	{

		cout << i << " \t\t " << P[i] << endl;

		//все установленные значения должны совпадать с входными значениями
		if (P[i] != i)
			throw exception("Bad value in operator []");
	}
	delete[] coefficients;

	cout << "The operator []  was tested successfully!" << endl;
}

//тест оператора =
void assignmentOperatorTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;

	//конструктор с параметрами должен создавать многочлен со степенью degree и коэффициентами coefficients

	Polynom P(degree, coefficients), P2 = P;

	cout << "Operator = test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << P.getDegree() << " \t\t " << P2.getDegree() << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < P.getDegree() + 1; i++)
		cout << P.getCoefficient(i) << " \t\t " << P2.getCoefficient(i) << endl;

	//степени многочленов должны совпадать
	if (P2.getDegree() != P.getDegree())
		throw exception("Bad degree in Operator =");

	//коэффициенты должны совпадать
	for (int i = 0; i < P.getDegree() + 1; i++)
		if (P2.getCoefficient(i) != P.getCoefficient(i))
			throw exception("Bad coefficients in Operator =");

	cout << "The Operator = was tested successfully!" << endl;
}