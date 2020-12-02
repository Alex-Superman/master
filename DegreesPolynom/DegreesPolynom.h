
#pragma once

#include <iostream>
#include <fstream>

using namespace std;

//����� ���������� � �������� �������������
class DegreesPolynom
{
public:

	/*
	����������� �� ���������
	������� ��������� ������� ������� � ������������ ����
	*/
	DegreesPolynom();

	/*
	����������� � �����������
	������� ��������� ������� size �� ��������� degrees � �������������� coefficients
	�����, ������ �������� ����������� �� �����������
	args:
		size - ������ ����������
		degrees - ������ ��������
		coeff - ������ �������������
	����������:
		���� �������� ������� ���������
		���� ������ ������ ��� ����� ����
		���� ������ �������� �������� ������������� ������� ��� ����������� �������
	*/
	DegreesPolynom(int size, int * degrees, double* coefficients);

	/*
	����������� �����������
	������� ����� �������� ����������
	args:
		polynom - ���������� ������
	*/
	DegreesPolynom(const DegreesPolynom& polynom);

	/*
	�������� ������������
	������� ����� �������� ����������
	args:
		polynom - ���������� ������
	*/
	DegreesPolynom& operator=(const DegreesPolynom& polynom);

	//����������� ���������� - ���������� "����" ����� �������
	virtual ~DegreesPolynom();



	
	/*
	��������� ������� ����������
	���������� ����� ������� ��������
	return:
		����� �������� _size
	*/
	int getSize();

	/*
	��������� ������� �������� ����������
	return:
		����� ������� _degrees
	*/
	int * getDegrees();

	/*
	��������� ������� ���������� �� �������
	args:
		index - ����� ������� ����������
	return:
		����� ������� ��� ������� index
	����������:
		���� ������ ������� �� ������� ����������
	*/
	int getDegree(int index);

	/*
	��������� ������� ������������� ����������
	return:
		����� ������� _coefficients
	*/
	double* getCoefficients();

	/*
	�������� ��������������
	���������� ������ �� ����������� ��� ������� index
	args:
		index - ����� ������������
	return:
		������ �� ����������� ��� ������� index
	����������:
		���� index ������� �� ������� ����������
	*/
	double& operator[](int index);



	/*
	������ ��� ��������
	������������� ���������� ������ size, ������� degrees � ������������ coefficients
	�����, ������ �������� ����������� �� �����������
	args:
		size - ������ ����������
		degrees - ������ ��������
		coefficients - ������ �������������
	����������:
		���� �������� ������� ���������
		���� ������ ������ ��� ����� ����
		���� ������ �������� �������� ������������� ������� ��� ����������� �������
	*/
	virtual void setDegrees(int size, int* degrees, double* coefficients);

	/*
	������ ��� �������������
	������������� ���������� ������������ coefficients
	args:
		coefficients - ������ �������������
	����������:
		���� �������� ������� ���������
	*/
	virtual void setCoefficients(double * coefficients);



	/*
	�������� ��� ���������� ���������� ��� �������
	���������� �������� ���������� �� �
	args:
		x - �������� ���������� ����������
	return:
		��������� ���������� ����������
	*/
	double operator()(double x);



	/*
	�������� ��������
	args:
		polynom - ��������� �������
	return:
		������� - ��������� �������� �����������
	*/
	DegreesPolynom operator+(const DegreesPolynom& polynom);

	/*
	�������� ���������
	args:
		polynom - ���������� �������
	return:
		������� - ��������� ��������� �����������
	*/
	DegreesPolynom operator-(const DegreesPolynom& polynom);



	/*
	�������� ������ � ������� �����
	������� ��������� � ������� �����
	args:
		stream - ����� ������
		polynom - ��������� ���������
	return:
		������ �� ����� ������
	*/
	friend ostream& operator<<(ostream& stream, const DegreesPolynom& polynom);

	/*
	�������� ������ � �������� �����
	������� ��������� � �������� �����
	args:
		stream - ����� ������
		polynom - ��������� ���������
	return:
		������ �� ����� ������
	*/
	friend ofstream& operator<<(ofstream& stream, const DegreesPolynom& polynom);

	/*
	�������� ������ � �������� ������
	��������� ��������� � �������� ������
	args:
		stream - ����� ������
		polynom - ����������� ���������
	return:
		������ �� ����� �����
	����������:
		���� ������ ������ ��� ����� ����
		���� ������ �������� �������� ������������� ������� ��� ����������� �������
	*/
	friend istream& operator>>(istream& stream, DegreesPolynom& polynom);

	/*
	�������� ������ � ��������� ������
	��������� ��������� � ��������� ������
	args:
		stream - ����� ������
		polynom - ����������� ���������
	return:
		������ �� ����� �����
	����������:
		���� ������ ������ ��� ����� ����
		���� ������ �������� �������� ������������� ������� ��� ����������� �������
	*/
	friend ifstream& operator>>(ifstream& stream, DegreesPolynom& polynom);

	/*
	������ � �������� ����
	args:
		file - �������� ����
	����������:
		���� file �� ������
	*/
	void write(fstream& file);

	/*
	������ �� ��������� �����
	args:
		file - �������� ����
	����������:
		���� file �� ������
		���� ������ ������ ��� ����� ����
		���� ������ �������� �������� ������������� ������� ��� ����������� �������
	*/
	virtual void read(fstream& file);

protected:

	//���������� ��������� ����������
	int _size;

	//������ ��������
	int* _degrees;

	//������ �������������
	double* _coefficients;

	/*
	���������, ����� �� ������ ���� �������� �������������
	���������, ����� � ������� �� ���� ���������� �������������
	� ����� �� ���� ������������� �������������
	args:
		size - ������ �������
		degrees - ������ ��������
	return - true - ���� degrees ����� ���� �������� �������������
			 false - ���� degrees �� ����� ���� �������� �������������
	*/
	bool isArrayOfDegrees(int size, int* degrees);

	/*
	���������� ������� �������� ������ � �������� �������������
	���������� ���������� �������, ��� ����, ��� ������ �������� ��������
	���������� ����� ��������������� �������������
	����� ��������� ��� ����, ����� ������� � ������� ���� ����������� �� �����������
	args:
		size - ������ �������
		degrees - ������ ��������
		coeff - ������ �������������
	*/
	void sort(int size, int* degrees, double* coefficients);

};