#pragma once

#include "../Polynom.h"

/*������������ ������ 1*/

//������������ ��� getter'�� �� �������, �.�. ��� ����������� ���

//���� ��� ������������ �� ���������
void defaultConstructorTest();

//���� ��� ������������ � �����������
void parametrConstructorTest();

//���� ��� ������������ �����������
void copyConstructorTest();

//���� ��� ������� �������
void setDegreeTest();

//���� ��� ������� �������������
void setCoefficientsTest();

//���� ��� ������� ������ ������������
void setCoefficientTest();

//���� ��� ������ ���������� ����������
void computeTest();

/*������������ ������ 2*/

//���� ��������� +
void addOperatorTest();

//���� ��������� -
void subOperatorTest();

//���� ��������� ++ (�������)
void prefixIncrementOperatorTest();

//���� ��������� ++ (��������)
void postfixIncrementOperatorTest();

//���� ��������� -- (�������)
void prefixDecrementOperatorTest();

//���� ��������� -- (��������)
void postfixDecrementOperatorTest();

//���� ��������� ()
void functionOperatorTest();

//���� ��������� []
void indexOperatorTest();

//���� ��������� =
void assignmentOperatorTest();

/*������������ ������ 3*/

//���� �����-������ � �������� ����
void binaryInputOutputTest();

//���� �����-������ � ��������� ����
void fileInputOutputTest();