#pragma once

#include "../Polynom/Polynom.h"

class PolynomTests
{
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

	//���� ������ ��������� �������
	void setDegree();

	//���� ������ ��������� �������������
	void setCoefficients();



	//���� ��������� ()
	void functionOperator();



	//���� ��������� ��������
	void sumOperator();

	//���� ��������� ���������
	void subOperator();

	//��������� � ��������� ��������� �������� �� ������ setDegree()
	//������� �� ��� ������ �����������



	//���� ���������� �����-������ ��� ��������� ������
	void fileOperators();

	//���� ���������� �����-������ ��� �������� ������
	void binaryOperators();
};

