#include "PolynomTests.h"
#include <exception>
#include <iostream>

using namespace std;

//���� ��� ������������ �� ���������
void defaultConstructorTest()
{
	Polynom P;

	cout << "Default constructor test:" << endl;
	cout << "Excpected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << 0 << " \t\t " << P.getDegree() << endl;
	cout << "Coefficient:" << endl;
	cout << 0 << " \t\t " << P.getCoefficient(0) << endl;

	//����������� �� ��������� ������ ��������� ��������� ������� 0 � � �������� ��������������
	if (P.getDegree() != 0)
		throw exception("Invalid degree value in the default constructor");

	if(P.getCoefficient(0) != 0)
		throw exception("Invalid coefficient value in the default constructor");

	cout << "The default constructor was tested successfully!" << endl;
}

//���� ��� ������������ � �����������
void parametrConstructorTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;
	

	//����������� � ����������� ������ ��������� ��������� �� �������� degree � �������������� coefficients

	Polynom P(degree,coefficients);

	cout << "Parametr constructor test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << degree << " \t\t " << P.getDegree() << endl;
	cout << "Coefficients:" << endl;
	for(int i = 0;i<degree+1;i++)
		cout << coefficients[i] << " \t\t " << P.getCoefficient(i) << endl;

	//������� ������� ������ ��������� � degree
	if (P.getDegree() != degree)
		throw exception("Invalid degree value in the parametr constructor");

	//������������ ������ ��������� � coefficients
	for(int i = 0;i<degree+1;i++)
		if (P.getCoefficient(i) != coefficients[i])
			throw exception("Invalid coefficient value in the parametr constructor");

	//����������� � ����������� ������ ����������� ����������, ���� ������� ������������� �������
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

	//����������� � ����������� ������ ����������� ����������, ���� �� ���� ������ ������� ���������
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

//���� ��� ������������ �����������
void copyConstructorTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;

	//����������� � ����������� ������ ��������� ��������� �� �������� degree � �������������� coefficients

	Polynom P(degree, coefficients), P2(P);

	cout << "Copy constructor test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << P.getDegree() << " \t\t " << P2.getDegree() << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < P.getDegree() + 1; i++)
		cout << P.getCoefficient(i) << " \t\t " << P2.getCoefficient(i) << endl;

	//������� ����������� ������ ���������
	if (P2.getDegree() != P.getDegree())
		throw exception("Bad degree in copy constructor");

	//������������ ������ ���������
	for (int i = 0; i < P.getDegree() + 1; i++)
		if (P2.getCoefficient(i) != P.getCoefficient(i))
			throw exception("Bad coefficients in copy constructor");

	cout << "The copy constructor was tested successfully!" << endl;
}

//���� ��� ������� �������
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

	//����� ������ ���������� �������� ������� ������ degree
	if (P.getDegree() != degree)
		throw exception("Bad degree in setDegree()");

	//��� ������������ ������ ��������� ����
	for (int i = 0; i < degree + 1; i++)
		if (P.getCoefficient(i) != 0)
			throw exception("Bad coefficient in setDegree()");

	//����� ������ ����������� ���������� ��� ������� ���������� ������������� �������
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

//���� ��� ������� �������������
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

	//������������ �������� ������ ��������� � ��������������, ����������� � �����
	for (int i = 0; i < degree + 1; i++)
		if (P.getCoefficient(i) != coefficients[i])
			throw exception("Bad coefficient in setCoefficients");

	delete[] coefficients;
	coefficients = nullptr;

	//����� ������ ����������� ����������, ���� �� ���� ������ ������� ���������
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

//���� ��� ������� ������ ������������
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

		//��� ������������� �������� ������ ��������� � �������� ����������
		if (P.getCoefficient(i) != i)
			throw exception("Bad value in setCoefficient()");
	}
	delete[] coefficients;

	//����� ������ ����������� ����������, ���� ������� ������������� �������
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

	//����� ������ ����������� ����������, ���� ������� �������, ����������� ������� ����������
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

//���� ��� ������ ���������� ����������
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
