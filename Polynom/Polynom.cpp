#include "Polynom.h"
#include <iostream>

using namespace std;

//���������� �� ���������
Polynom::Polynom()
{
	//�������������� ��������� ������� ��������
	_degree = 0;
	
	//� �������� � ���� ������ ���� ������� - ����� ������ � ������ ����
	_coefficients = new double[_degree + 1];
	_coefficients[0] = 0;
}

//����������� � �����������
Polynom::Polynom(int degree, double* coefficients)
{
	//������ ������� ������ ���� �� 1 ������, ��� ������� ����������
	//�.�. ������� ���������� - ������������ ������� ���������, ��������� � ���������
	//�.�. ��� ������� 9 ��������� ����� ��������� 10 ��������� - �� 0 �� 9 ������� ������������

	if (degree < 0)
		throw exception("Negative degree of the polynom");

	if (!coefficients)
		throw exception("Array of coefficients equals to nullptr");

	//��������� ������� �� ���������
	_degree = degree;

	//�������� ��� ������������ �� �������� ������� � ��� ������
	_coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		_coefficients[i] = coefficients[i];
}

//����������� �����������
Polynom::Polynom(const Polynom& polynom)
{
	//������� ����� �������� �������

	//�������� ������� ��������
	_degree = polynom._degree;

	//�������� ��� ������������ �� �������� ������� � ��� ������
	_coefficients = new double[_degree + 1];
	for (int i = 0; i < _degree + 1; i++)
		this->_coefficients[i] = polynom._coefficients[i];
}

//����������
Polynom::~Polynom()
{
	delete[] _coefficients;
}



//������� - ����� ��� ��������� ����� ������

//��������� ������� ����������
int Polynom::getDegree()
{
	return _degree;
}

//��������� ������� �������������
double* Polynom::getCoefficients()
{
	//�������� ���������� ������� ������������� 
	double* coefficientsCopy = new double[_degree + 1];
	for (int i = 0; i < _degree + 1; i++)
		coefficientsCopy[i] = _coefficients[i];

	//���������� �����
	return coefficientsCopy;
}

//��������� ������������ ��� ������� degree
double Polynom::getCoefficient(int degree)
{
	if ((degree < 0) || (degree > _degree))
		throw exception("Bad degree");

	return _coefficients[degree];
}



//������� - ������, ����������� ��� ��������� ����� ������

//�������� ������� ����������
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

//�������� ������������ ����������
void Polynom::setCoefficients(double* coefficients)
{
	if (!coefficients)
		throw exception("Array of coefficients equals to nullptr");

	for (int i = 0; i < _degree + 1; i++)
		this->_coefficients[i] = coefficients[i];
}

//�������� ����������� ��� ������� degree
void Polynom::setCoefficient(double coefficient, int degree)
{
	if ((degree < 0) || (degree > _degree))
		throw exception("Bad degree");

	_coefficients[degree] = coefficient;
}



//����� ����������� ���������� �� �����
void Polynom::show()
{
	for (int i = _degree; i > 0; i--)
		cout << _coefficients[i] << "*x^" << i << " + ";
	cout << _coefficients[0] << "*x^0";
}

//��������� �������� ����������
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
