#pragma once

#include "../DegreesPolynom/DegreesPolynom.h"

//��������� �� �������
class StringPolynom : public DegreesPolynom
{
public:

	/*
	����������� �� ���������
	������� ��������� ������� ������� � ������������ ����
	*/
	StringPolynom();

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
	StringPolynom(int size, int* degrees, double* coefficients);

	/*
	����������� �����������
	������� ����� �������� ����������
	args:
		polynom - ���������� ������
	*/
	StringPolynom(const StringPolynom& polynom);

	/*
	�������� ������������
	������� ����� �������� ����������
	args:
		polynom - ���������� ������
	*/
	StringPolynom& operator=(const StringPolynom& polynom);

	//����������� ���������� - ���������� "����" ����� �������
	virtual ~StringPolynom();



	/*
	��������� ������
	return:
		����� ������ _str
	*/
	char* getStr();



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
	virtual void setDegrees(int size, int* degrees, double* coefficients) override;

	/*
	������ ��� �������������
	������������� ���������� ������������ coefficients
	args:
		coefficients - ������ �������������
	����������:
		���� �������� ������� ���������
	*/
	virtual void setCoefficients(double* coefficients) override;



	/*
	�������� ��������
	args:
		polynom - ��������� �������
	return:
		������� - ��������� �������� �����������
	*/
	StringPolynom operator+(const StringPolynom& polynom);

	/*
	�������� ���������
	args:
		polynom - ���������� �������
	return:
		������� - ��������� ��������� �����������
	*/
	StringPolynom operator-(const StringPolynom& polynom);



	//��������� ������ ���������� ���������� ������ ��� ���������� � ��������������

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
	friend istream& operator>>(istream& stream, StringPolynom& polynom);

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
	friend ifstream& operator>>(ifstream& stream, StringPolynom& polynom);

	/*
	������ �� ��������� �����
	args:
		file - �������� ����
	����������:
		���� file �� ������
		���� ������ ������ ��� ����� ����
		���� ������ �������� �������� ������������� ������� ��� ����������� �������
	*/
	virtual void read(fstream& file) override;

protected:

	/*
	����� ���������� ������
	������������ _str
	*/
	void rewriteStr();

	//������ � �����������
	char* _str;
};

