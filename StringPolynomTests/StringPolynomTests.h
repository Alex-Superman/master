#pragma once

#include "../StringPolynom/StringPolynom.h"

class StringPolynomTests
{
private:

	//����� �������� ������ �� �������, �������� � �������������
	char* createPolynomString(int size, int * degrees, double * coefficients);

public:

	//������������ ������������ �� ���������
	void defaultConstructor();

	//������������ ������������ � �����������
	void parametrConstructor();

	//������������ ������������ �����������
	void copyConstructor();

	//������������ ��������� ������������
	void assignmentOperator();



	//���� ������ ��������� ��������
	void setDegrees();

	//���� ������ ��������� �������������
	void setCoefficients();



	//���� ��������� ()
	void functionOperator();



	//���� ��������� ��������
	void sumOperator();

	//���� ��������� ���������
	void subOperator();



	//���� ���������� �����-������ ��� ��������� ������
	void fileOperators();

	//���� ���������� �����-������ ��� �������� ������
	void binaryOperators();

};

