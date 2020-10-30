#include "PolynomTests.h"
#include <exception>
#include <iostream>

using namespace std;

/*������������ ������ 1*/

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

	delete[] coefficients;
	coefficients = nullptr;

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

/*������������ ������ 2*/

//���� ��������� +
void addOperatorTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;

	Polynom P(degree, coefficients);

	//����������� ��������� � ����� �����
	Polynom result = P + P;

	cout << "operator + test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << degree << " \t\t " << result.getDegree() << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < result.getDegree() + 1; i++)
		cout << 2 * coefficients[i] << " \t\t " << result.getCoefficient(i) << endl;

	//������� ����� ������ ��������� degree
	if(result.getDegree() != degree)
		throw exception("Bad degree in operator +");

	//������������ ������ ��������� � ����������
	for (int i = 0; i < degree + 1; i++)
		if (result.getCoefficient(i) != 2*coefficients[i])
			throw exception("Bad coefficient in operator +");

	cout << "The operator + was tested successfully!" << endl;
}

//���� ��������� -
void subOperatorTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;

	Polynom P(degree, coefficients);

	//�������� �� ���������� ������ ����
	Polynom result = P - P;

	cout << "operator - test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << degree << " \t\t " << result.getDegree() << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < result.getDegree() + 1; i++)
		cout << 0 << " \t\t " << result.getCoefficient(i) << endl;

	//������� ����� ������ ��������� degree
	if (result.getDegree() != degree)
		throw exception("Bad degree in operator -");

	//������������ ������ ��������� � ����������
	for (int i = 0; i < degree + 1; i++)
		if (result.getCoefficient(i) != 0)
			throw exception("Bad coefficient in operator -");

	cout << "The operator - was tested successfully!" << endl;
}

//���� ��������� ++ (�������)
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

//���� ��������� ++ (��������)
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

//���� ��������� -- (�������)
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

//���� ��������� -- (��������)
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

//���� ��������� ()
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

//���� ��������� []
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

		//��� ������������� �������� ������ ��������� � �������� ����������
		if (P[i] != i)
			throw exception("Bad value in operator []");
	}
	delete[] coefficients;

	cout << "The operator []  was tested successfully!" << endl;
}

//���� ��������� =
void assignmentOperatorTest()
{
	int degree = 5;
	double* coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = i;

	//����������� � ����������� ������ ��������� ��������� �� �������� degree � �������������� coefficients

	Polynom P(degree, coefficients), P2 = P;

	cout << "Operator = test:" << endl;
	cout << "Expected \t Actually" << endl;
	cout << "Degree:" << endl;
	cout << P.getDegree() << " \t\t " << P2.getDegree() << endl;
	cout << "Coefficients:" << endl;
	for (int i = 0; i < P.getDegree() + 1; i++)
		cout << P.getCoefficient(i) << " \t\t " << P2.getCoefficient(i) << endl;

	//������� ����������� ������ ���������
	if (P2.getDegree() != P.getDegree())
		throw exception("Bad degree in Operator =");

	//������������ ������ ���������
	for (int i = 0; i < P.getDegree() + 1; i++)
		if (P2.getCoefficient(i) != P.getCoefficient(i))
			throw exception("Bad coefficients in Operator =");

	cout << "The Operator = was tested successfully!" << endl;
}