#include "Polynom.h"

/*������������ ������ 1*/

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

	//������� ������ � ����� ��������� ������� ����������
	double* newCoefficints = new double[degree + 1];

	//���� ����� �������� ������� ������ �������
	if (degree >= _degree)
	{
		//��� ���������� ������� ���������� ����������� ������������ ����� ����

		//�� �� ������� ������� ������������� ��������� ��� ������������
		for (int i = 0; i < _degree + 1; i++)
			newCoefficints[i] = _coefficients[i];
		//�������������� ������ ��������� ������
		for (int i = _degree + 1; i < degree + 1; i++)
			newCoefficints[i] = 0;
	}
	else
	{
		//��� ���������� ������� ���������� ������� ������������ ���������

		//����� ��������� ��� ������������ ����� ���������
		for (int i = 0; i < degree + 1; i++)
			newCoefficints[i] = _coefficients[i];
	}

	//��������� ����� ������ ������������� � �������
	delete[] _coefficients;
	_coefficients = newCoefficints;
	_degree = degree;
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
char * Polynom::toString()
{
	//������� �������������� ������
	char* str = new char[1000];
	int k = 0;
	//����������� �� ���� ������������� ����������
	for (int i = 0; i <= _degree; i++)
	{
		//������ ����������� ��������� � ������
		char* str_number = new char[100];
		_itoa_s(_coefficients[i], str_number, 100, 10);

		//��������� ������������� ������������ ��������� � �������������� ������
		for (int j = 0; j < strlen(str_number); j++)
			str[k++] = str_number[j];

		str[k++] = ' ';

		delete[] str_number;
	}
	str[k] = '\0';

	return str;
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

/*������������ ������ 2*/

//�������� ��������
Polynom Polynom::operator+(const Polynom& polynom)
{
	Polynom result;

	//���� ������� �������� ���������� ������ ������� �������� �������
	if (this->_degree >= polynom._degree)
	{
		//�� ������ ������� ������ ������� �������� �������
		result.setDegree(this->_degree);

		//��������� ��� ������������ �� �������� �������
		for (int i = 0; i < this->_degree + 1; i++)
			result._coefficients[i] = this->_coefficients[i];

		//���������� ��������������� ������������ �����������
		for (int i = 0; i < polynom._degree + 1; i++)
			result._coefficients[i] += polynom._coefficients[i];
	}
	else
	{
		//������ ��� �� �� �����, ��� � � ���������� ������, ������ ������� ������ � ������� ���������� �������
		result.setDegree(polynom._degree);

		for (int i = 0; i < polynom._degree + 1; i++)
			result._coefficients[i] = polynom._coefficients[i];

		for (int i = 0; i < this->_degree + 1; i++)
			result._coefficients[i] += this->_coefficients[i];
	}

	//���������� �������������� ������ ��� ����, ����� ����� ���� ���������� ������������� ���������
	return result;
}

//�������� ���������
Polynom Polynom::operator-(const Polynom& polynom)
{
	Polynom result;

	//���� ������� �������� ���������� ������ ������� �������� �������
	if (this->_degree >= polynom._degree)
	{
		//�� ������ ������� ������ ������� �������� �������
		result.setDegree(this->_degree);

		//��������� ��� ������������ �� �������� �������
		for (int i = 0; i < this->_degree + 1; i++)
			result._coefficients[i] = this->_coefficients[i];

		//�������� ��������������� ������������ �����������
		for (int i = 0; i < polynom._degree + 1; i++)
			result._coefficients[i] -= polynom._coefficients[i];
	}
	else
	{
		//������ ��� �� �� �����, ��� � � ���������� ������, ������ ������� ������ � ������� ���������� �������
		result.setDegree(polynom._degree);

		for (int i = 0; i < polynom._degree + 1; i++)
			result._coefficients[i] = -polynom._coefficients[i];

		for (int i = 0; i < this->_degree + 1; i++)
			result._coefficients[i] += this->_coefficients[i];
	}

	//���������� �������������� ������ ��� ����, ����� ����� ���� ���������� ������������� ���������
	return result;
}

//�������� ���������� (���������� �����)
Polynom operator++(Polynom& polynom)
{
	polynom.setDegree(polynom._degree + 1);

	return polynom;
}

//�������� ���������� (����������� �����)
Polynom operator++(Polynom& polynom, int)
{
	//���������� ����� ������ ������ �������� �������
	Polynom temp(polynom);

	//����������� ������� �� �������
	polynom.setDegree(polynom._degree + 1);

	return temp;
}

//�������� ���������� (���������� �����)
Polynom operator--(Polynom& polynom)
{
	//��������� ������� �� �������
	polynom.setDegree(polynom._degree - 1);

	return polynom;
}

//�������� ���������� (����������� �����)
Polynom operator--(Polynom& polynom, int)
{
	//���������� ����� ������ ������ �������� �������
	Polynom temp(polynom);

	//��������� ������� �� �������
	polynom.setDegree(polynom._degree - 1);

	return temp;
}

//�������� ��� ���������� ���������� ��� �������
double Polynom::operator()(double x)
{
	//���������� ����������� �������� �������� �� �
	return compute(x);
}

//�������� ��������������
double& Polynom::operator[](int degree)
{
	if ((degree < 0) || (degree > _degree))
		throw exception("Bad index");

	//���������� ����������� ��� ������� degree
	return _coefficients[degree];
}

//�������� ������������
Polynom& Polynom::operator=(const Polynom& polynom)
{
	delete[] _coefficients;

	//�������� ���������� �������� ������� � �������
	_degree = polynom._degree;
	_coefficients = new double[_degree + 1];
	for (int i = 0; i < _degree + 1; i++)
		_coefficients[i] = polynom._coefficients[i];

	return *this;

}

