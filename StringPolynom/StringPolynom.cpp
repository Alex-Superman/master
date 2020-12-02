#include "StringPolynom.h"

void StringPolynom::rewriteStr()
{
	delete[] _str;
	//������� ������
	_str = new char[10000];
	int k = 0;
	//����������� �� ���� ������������� ����������
	for (int i = 0; i < _size; i++)
	{
		//������ ����������� ��������� � ������
		char* str_number = new char[100];
		_itoa_s(_coefficients[i], str_number, 100, 10);

		//��������� ������������� ������������ ��������� � �������������� ������
		for (int j = 0; j < strlen(str_number); j++)
			_str[k++] = str_number[j];
		delete[] str_number;

		_str[k++] = '*';
		_str[k++] = 'x';
		_str[k++] = '^';

		str_number = new char[100];
		_itoa_s(_degrees[i], str_number, 100, 10);
		for (int j = 0; j < strlen(str_number); j++)
			_str[k++] = str_number[j];

		_str[k++] = '+';

		delete[] str_number;
	}
	_str[k - 1] = '\0';
}

StringPolynom::StringPolynom() : DegreesPolynom()
{
	_str = nullptr;
	rewriteStr();
}

StringPolynom::StringPolynom(int size, int* degrees, double* coeff) : DegreesPolynom(size, degrees, coeff)
{
	_str = nullptr;
	rewriteStr();
}

StringPolynom::StringPolynom(const StringPolynom& Obj)
{
	//�������� ��� ��������� �������� �������
	_size = Obj._size;

	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
		_coefficients[i] = Obj._coefficients[i];

	_degrees = new int[_size];
	for (int i = 0; i < _size; i++)
		_degrees[i] = Obj._degrees[i];

	_str = nullptr;
	rewriteStr();
}

StringPolynom& StringPolynom::operator=(const StringPolynom& Obj)
{
	delete[] _degrees;
	delete[] _coefficients;

	//�������� ��� ���� �������� �������
	_size = Obj._size;

	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
		_coefficients[i] = Obj._coefficients[i];

	_degrees = new int[_size];
	for (int i = 0; i < _size; i++)
		_degrees[i] = Obj._degrees[i];

	rewriteStr();

	return *this;
}

StringPolynom::~StringPolynom()
{
	delete[] _str;
}



char* StringPolynom::getStr()
{
	char* copy = new char[strlen(_str) + 1];
	strcpy_s(copy, strlen(_str) + 1, _str);

	return copy;
}




void StringPolynom::setDegrees(int size, int* degrees, double* coeff)
{
	DegreesPolynom::setDegrees(size, degrees, coeff);

	rewriteStr();
}

void StringPolynom::setCoefficients(double* coeff)
{
	DegreesPolynom::setCoefficients(coeff);

	rewriteStr();
}



//�������� ��������
StringPolynom StringPolynom::operator+(const StringPolynom& obj)
{
	//������������ ���������� ���������� ��������
	int resultSize = _size + obj._size;
	for (int i = 0; i < _size; i++)
		for (int j = 0; j < obj._size; j++)
			//���� ��������� ����������� ��������
			if (_degrees[i] == obj._degrees[j])
				resultSize--;

	int* resultDegrees = new int[resultSize];

	int i = 0, j = 0, k = 0;
	//��������� � �������������� ������ �������� ������������� �������� (����� �� ���� ���� ���������� �������� � �������)
	while ((i < _size) && (j < obj._size))
		if (_degrees[i] < obj._degrees[j])
			resultDegrees[k++] = _degrees[i++];
		else
			if (_degrees[i] > obj._degrees[j])
				resultDegrees[k++] = obj._degrees[j++];
			else
			{
				resultDegrees[k++] = _degrees[i++];
				j++;
			}
	while (i < _size)
		resultDegrees[k++] = _degrees[i++];
	while (j < obj._size)
		resultDegrees[k++] = obj._degrees[j++];

	//��������� ������ �������������
	double* resultCoeffs = new double[resultSize];
	for (int o = 0; o < resultSize; o++)
		resultCoeffs[o] = 0;

	//��������� � ����� ������������ �� ������� ����������
	for (int o = 0; o < _size; o++)
		for (int s = 0; s < resultSize; s++)
			if (_degrees[o] == resultDegrees[s])
				resultCoeffs[s] += _coefficients[o];

	//��������� � ����� ������������ �� ������� ����������
	for (int o = 0; o < obj._size; o++)
		for (int s = 0; s < resultSize; s++)
			if (obj._degrees[o] == resultDegrees[s])
				resultCoeffs[s] += obj._coefficients[o];

	//���������� �������������� ������
	return StringPolynom(resultSize, resultDegrees, resultCoeffs);
}

//�������� ���������
StringPolynom StringPolynom::operator-(const StringPolynom& obj)
{
	//������������ ���������� ���������� ���������
	int resultSize = _size + obj._size;
	for (int i = 0; i < _size; i++)
		for (int j = 0; j < obj._size; j++)
			//���� ��������� ����������� ��������
			if (_degrees[i] == obj._degrees[j])
				resultSize--;

	int* resultDegrees = new int[resultSize];

	int i = 0, j = 0, k = 0;
	//��������� � �������������� ������ �������� ������������� �������� (����� �� ���� ���� ���������� �������� � �������)
	while ((i < _size) && (j < obj._size))
		if (_degrees[i] < obj._degrees[j])
			resultDegrees[k++] = _degrees[i++];
		else
			if (_degrees[i] > obj._degrees[j])
				resultDegrees[k++] = obj._degrees[j++];
			else
			{
				resultDegrees[k++] = _degrees[i++];
				j++;
			}

	while (i < _size)
		resultDegrees[k++] = _degrees[i++];

	while (j < obj._size)
		resultDegrees[k++] = obj._degrees[j++];

	//��������� ������ �������������
	double* resultCoeffs = new double[resultSize];
	for (int o = 0; o < resultSize; o++)
		resultCoeffs[o] = 0;

	//��������� � ����� ������������ �� ������� ����������
	for (int o = 0; o < _size; o++)
		for (int s = 0; s < resultSize; s++)
			if (_degrees[o] == resultDegrees[s])
				resultCoeffs[s] += _coefficients[o];

	//��������� � ����� ������������ �� ������� ����������
	for (int o = 0; o < obj._size; o++)
		for (int s = 0; s < resultSize; s++)
			if (obj._degrees[o] == resultDegrees[s])
				resultCoeffs[s] -= obj._coefficients[o];

	//���������� �������������� ������
	return StringPolynom(resultSize, resultDegrees, resultCoeffs);
}



//������ � �������� ������
istream& operator>>(istream& stream, StringPolynom& obj)
{
	int size;
	double* coeff;
	int* degrees;

	//��������� ������
	stream >> size;

	if (size <= 0)
		throw exception("�������� ������!");

	//��������� �������� � �������: ����������� � �������
	coeff = new double[size];
	degrees = new int[size];
	for (int i = 0; i < size; i++)
	{
		stream >> coeff[i];
		stream >> degrees[i];
	}

	//������������� ��������� ��������
	obj.setDegrees(size, degrees, coeff);

	return stream;
}

//������ � ��������� ������
ifstream& operator>>(ifstream& stream, StringPolynom& obj)
{
	int size;
	double* coeff;
	int* degrees;

	//��������� ������
	stream >> size;

	if (size <= 0)
		throw exception("�������� ������!");

	//��������� �������� � �������: ����������� � �������
	coeff = new double[size];
	degrees = new int[size];
	for (int i = 0; i < size; i++)
	{
		stream >> coeff[i];
		stream >> degrees[i];
	}

	//������������� ��������� ��������
	obj.setDegrees(size, degrees, coeff);

	return stream;
}

//������ �� ��������� �����
void StringPolynom::read(fstream& file)
{
	//���������, ����� ���� ��� ������
	if (!file.is_open())
		return;

	int size;
	double* coeff;
	int* degrees;

	//��������� ������
	file.read((char*)&size, sizeof(int));

	if (size <= 0)
		throw exception("�������� ������!");

	//��������� �������� � �������: ����������� � �������
	coeff = new double[size];
	degrees = new int[size];
	for (int i = 0; i < size; i++)
	{
		file.read((char*)&coeff[i], sizeof(double));
		file.read((char*)&degrees[i], sizeof(int));
	}

	//������������� ��������� ��������
	setDegrees(size, degrees, coeff);
}
