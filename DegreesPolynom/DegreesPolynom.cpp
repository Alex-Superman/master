#include "DegreesPolynom.h"

#include <exception>
#include <cmath>


//���������, ����� �� ������ ���� �������� �������������
bool DegreesPolynom::isArrayOfDegrees(int size, int* degrees)
{
	//��������� ������ ������� ������� ��������
	for (int i = 0; i < size; i++)
	{
		//� ������� �� ������ ���� ������������� ��������
		if (degrees[i] < 0)
			return false;

		//��������� � ������� ������� ���������� ��������
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				continue;

			//� ������� �� ������ ���� ������������� ��������
			if (degrees[i] == degrees[j])
				return false;
		}
	}

	return true;
}

//���������� ������� �������� � ������� �����������
void DegreesPolynom::sort(int size, int* degrees, double * coefficients)
{
	//���������� �������

	//��� ������� �������� �������
	for (int i = 0; i < size; i++) 
	{
		//���� ����������� ����� ��������� ���������
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
			if (degrees[j] < degrees[minIndex])
				minIndex = j;

		//������ ������� ������� � �����������
		int swap = degrees[minIndex];
		degrees[minIndex] = degrees[i];
		degrees[i] = swap;

		//�����, ������ ��������������� ������������
		double swap2 = coefficients[minIndex];
		coefficients[minIndex] = coefficients[i];
		coefficients[i] = swap2;
	}
}


//����������� �� ���������
DegreesPolynom::DegreesPolynom()
{
	//������� ������� �� ������ ������������ 0
	_size = 1;
	
	_degrees = new int[_size];
	_degrees[0] = 0;
	
	_coefficients = new double[_size];
	_coefficients[0] = 0;
}

//����������� � �����������
DegreesPolynom::DegreesPolynom(int size, int* degrees, double* coefficients)
{
	_degrees = nullptr;
	_coefficients = nullptr;

	//������������� ������ ���������
	setDegrees(size, degrees, coefficients);
}

//����������� �����������
DegreesPolynom::DegreesPolynom(const DegreesPolynom& polynom)
{
	//�������� ��� ��������� �������� �������
	_size = polynom._size;

	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
		_coefficients[i] = polynom._coefficients[i];

	_degrees = new int[_size];
	for (int i = 0; i < _size; i++)
		_degrees[i] = polynom._degrees[i];
}

//�������� ������������
DegreesPolynom& DegreesPolynom::operator=(const DegreesPolynom& Obj)
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

	return *this;
}

//����������
DegreesPolynom::~DegreesPolynom()
{
	delete[] _coefficients;
	delete[] _degrees;
}


//��������� ������� ����������
int DegreesPolynom::getSize()
{
	return _size;
}

//��������� ������� ��������
int* DegreesPolynom::getDegrees()
{
	int * copyDegrees = new int[_size];
	for (int i = 0; i < _size; i++)
		copyDegrees[i] = _degrees[i];

	return copyDegrees;
}

//��������� ������� �� �������
int DegreesPolynom::getDegree(int index)
{
	if ((index < 0) || (index >= _size))
		throw exception("bad index");

	return _degrees[index];
}

//��������� ������� �������������
double* DegreesPolynom::getCoefficients()
{
	double* copyCoeff = new double[_size];
	for (int i = 0; i < _size; i++)
		copyCoeff[i] = _coefficients[i];

	return copyCoeff;
}


//��������� ����������
void DegreesPolynom::setDegrees(int size, int* degrees, double* coefficients)
{

	//�� ���� �� ������ ��������� ������� ���������
	if (!coefficients)
		throw exception("nullptr");

	if (!degrees)
		throw exception("nullptr");

	//������ �� ����� ���� �������������
	if (size <= 0)
		throw exception("bad size");

	//������ ������ ��������������� �����������
	if (!isArrayOfDegrees(size, degrees))
		throw exception("bad array of degrees");

	delete[] _degrees;
	delete[] _coefficients;

	//�������� ������ � ������� ������
	_size = size;

	_degrees = new int[_size];
	for (int i = 0; i < _size; i++)
		_degrees[i] = degrees[i];

	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
		_coefficients[i] = coefficients[i];

	sort(_size, _degrees, _coefficients);
}

//��������� ������� �������������
void DegreesPolynom::setCoefficients(double* coefficients)
{
	if (!coefficients)
		throw exception("nullptr");

	for (int i = 0; i < _size; i++)
		_coefficients[i] = coefficients[i];
}



//�������� ���������� �������
double DegreesPolynom::operator()(double x)
{
	double sum = 0;

	for (int i = 0; i < _size; i++)
		sum += pow(x, _degrees[i]) * _coefficients[i];

	return sum;
}

//�������� ��������������
double& DegreesPolynom::operator[](int index)
{
	if ((index < 0) || (index >= _size))
		throw exception("bad index");

	return _coefficients[index];
}



//�������� ��������
DegreesPolynom DegreesPolynom::operator+(const DegreesPolynom& obj)
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
	for (int o = 0; o < _size;o++)
		for (int s = 0; s < resultSize; s++)
			if (_degrees[o] == resultDegrees[s])
				resultCoeffs[s] += _coefficients[o];

	//��������� � ����� ������������ �� ������� ����������
	for (int o = 0; o < obj._size; o++)
		for (int s = 0; s < resultSize; s++)
			if (obj._degrees[o] == resultDegrees[s])
				resultCoeffs[s] += obj._coefficients[o];

	//���������� �������������� ������
	return DegreesPolynom(resultSize,resultDegrees,resultCoeffs);
}

//�������� ��������
DegreesPolynom DegreesPolynom::operator-(const DegreesPolynom& obj)
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
	return DegreesPolynom(resultSize, resultDegrees, resultCoeffs);
}


//����� � ������� �����
ostream& operator<<(ostream& stream, const DegreesPolynom& obj)
{
	//������� ��������� � �����
	for (int i = 0; i < obj._size - 1; i++)
		stream << obj._coefficients[i] << "*x^" << obj._degrees[i] << " + ";

	stream << obj._coefficients[obj._size - 1] << "*x^" << obj._degrees[obj._size - 1];

	return stream;
}

//����� � �������� �����
ofstream& operator<<(ofstream& stream, const DegreesPolynom& obj)
{
	//������� � �������� ����� ������, � ����� ������ ������� ���������� � �������: ����������� � �������
	stream << obj._size << " ";

	for (int i = 0; i < obj._size; i++)
		stream << obj._coefficients[i] << " " << obj._degrees[i] << " ";

	return stream;
}

//������ � �������� ������
istream& operator>>(istream& stream, DegreesPolynom& obj)
{
	int size;
	double* coeff;
	int* degrees;

	//��������� ������
	stream >> size;

	if (size <= 0)
		throw exception("bad size");

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
ifstream& operator>>(ifstream& stream, DegreesPolynom& obj)
{
	int size;
	double* coeff;
	int* degrees;

	//��������� ������
	stream >> size;

	if (size <= 0)
		throw exception("bad size");

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

//������ � �������� ����
void DegreesPolynom::write(fstream& file)
{
	//���������, ����� ���� ��� ������
	if (!file.is_open())
		return;

	//������� � �������� ���� ������, � ����� ������ ������� ���������� � �������: ����������� � �������
	file.write((char*)&_size, sizeof(int));
	for (int i = 0; i < _size; i++)
	{
		file.write((char*)&_coefficients[i], sizeof(double));
		file.write((char*)&_degrees[i], sizeof(int));
	}
}

//������ �� ��������� �����
void DegreesPolynom::read(fstream& file)
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
		throw exception("bad size");

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



//�������� ��������� "�����"
bool DegreesPolynom::operator==(const DegreesPolynom& polynom)
{
	//���� ������� �� ���������
	if (_size != polynom._size)
		return false;

	//���� �� ��������� ������������ ��� �������
	for (int i = 0; i < _size; i++)
		if ((_degrees[i] != polynom._degrees[i]) || (_coefficients[i] != polynom._coefficients[i]))
			return false;

	return true;
}

//������� ������ �� ����� - ����� ��� ������������ ������������
void DegreesPolynom::show()
{
	cout << "CLASS : DegreesPolynom" << endl;
	cout << (*this) << endl;
}
