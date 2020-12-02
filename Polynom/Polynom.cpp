#include "Polynom.h"

//���������� �� ���������
Polynom::Polynom()
{
	//�������������� ��������� ������� ��������
	_size = 1;
	_degree = _size-1;
	
	_degrees = new int[_size];
	_degrees[0] = 0;
	
	_coefficients = new double[_size];
	_coefficients[0] = 0;
}

//����������� � �����������
Polynom::Polynom(int degree, double* coefficients)
{
	if (degree < 0)
		throw exception("�������� �������!");

	if (!coefficients)
		throw exception("������� ���������!");

	//�������� ��������� � ���� ������
	_degree = degree;
	_size = _degree + 1;

	_degrees = new int[_size];
	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
	{
		_degrees[i] = i;
		_coefficients[i] = coefficients[i];
	}
}

//����������� �����������
Polynom::Polynom(const Polynom& polynom)
{
	//�������� ���� �������� �������
	_degree = polynom._degree;
	_size = polynom._size;

	_degrees = new int[_size];
	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
	{
		_degrees[i] = polynom._degrees[i];
		_coefficients[i] = polynom._coefficients[i];
	}
}

//�������� ������������
Polynom& Polynom::operator=(const Polynom& polynom)
{
	//�������� ���� �������� �������
	_degree = polynom._degree;
	_size = polynom._size;

	delete[] _coefficients;
	delete[] _degrees;

	_degrees = new int[_size];
	_coefficients = new double[_size];
	for (int i = 0; i < _size; i++)
	{
		_degrees[i] = polynom._degrees[i];
		_coefficients[i] = polynom._coefficients[i];
	}

	return *this;

}



//��������� ������� ����������
int Polynom::getDegree()
{
	return _degree;
}



//��������� �������� ���������� ������ � �������� �������������
void Polynom::setDegrees(int size, int* degrees, double* coefficients)
{
	//�.�. ������� ������������� �� ������� �� degree, �� ������ �������� �� ������������

	//�� ���� �� ������ ��������� ������� ���������
	if (!coefficients)
		throw exception("������� ���������!");

	//������ �� ����� ���� �������������
	if (size <= 0)
		throw exception("�������� ������!");

	setDegree(size - 1);
	setCoefficients(coefficients);
}

//�������� ������� ����������
void Polynom::setDegree(int degree)
{
	if (degree < 0)
		throw exception("�������� �������!");

	//������� ������ � ����� ��������� ������� ����������
	int newSize = degree + 1;
	double* newCoefficints = new double[newSize];
	int* newDegrees = new int[newSize];

	//���� ����� �������� ������� ������ �������
	if (degree >= _degree)
	{
		//�� �� ������� ������� ������������� ��������� ��� ������������
		for (int i = 0; i < _size; i++)
		{
			newCoefficints[i] = _coefficients[i];
			newDegrees[i] = i;
		}
		//�������������� ������ ��������� ������
		for (int i = _size; i < newSize; i++)
		{
			newCoefficints[i] = 0;
			newDegrees[i] = i;
		}
	}
	else
	{
		//�� �� ������� ������� ������������� ��������� ��� ������������
		for (int i = 0; i < newSize; i++)
		{
			newCoefficints[i] = _coefficients[i];
			newDegrees[i] = i;
		}
	}

	_degree = degree;
	_size = newSize;

	delete[] _coefficients;
	delete[] _degrees;

	_coefficients = newCoefficints;
	_degrees = newDegrees;
}


//�������� �����������
Polynom Polynom::operator+(const Polynom& polynom)
{
	Polynom result;

	//���� ������� �������� ���������� ������ ������� �������� �������
	if (this->_degree >= polynom._degree)
	{
		//�� ������ ������� ������ ������� �������� �������
		result.setDegree(this->_degree);

		//��������� ��� ������������ �� �������� �������
		for (int i = 0; i < _size; i++)
			result._coefficients[i] = this->_coefficients[i];

		//���������� ��������������� ������������ �����������
		for (int i = 0; i < polynom._size; i++)
			result._coefficients[i] += polynom._coefficients[i];
	}
	else
	{
		//������ ��� �� �� �����, ��� � � ���������� ������, ������ ������� ������ � ������� ���������� �������
		result.setDegree(polynom._degree);

		for (int i = 0; i < polynom._size; i++)
			result._coefficients[i] = polynom._coefficients[i];

		for (int i = 0; i < _size; i++)
			result._coefficients[i] += this->_coefficients[i];
	}

	//���������� ������ �� �������������� ������ ��� ����, ����� ����� ���� ���������� ������������� ���������
	return result;
}

//��������� �����������
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

	//���������� ������ �� �������������� ������ ��� ����, ����� ����� ���� ���������� ������������� ���������
	return result;
}



//�������� ���������� (���������� �����)
Polynom Polynom::operator++()
{
	setDegree(_degree + 1);

	return *this;
}

//�������� ���������� (����������� �����)
Polynom Polynom::operator++(int)
{
	//���������� ����� ������ ������ �������� �������
	Polynom temp(*this);

	//����������� ������� �� �������
	setDegree(_degree + 1);

	return temp;
}

//�������� ���������� (���������� �����)
Polynom Polynom::operator--()
{
	//��������� ������� �� �������
	setDegree(_degree - 1);

	return *this;
}

//�������� ���������� (����������� �����)
Polynom Polynom::operator--(int)
{
	//���������� ����� ������ ������ �������� �������
	Polynom temp(*this);

	//��������� ������� �� �������
	setDegree(_degree - 1);

	return temp;
}


//������ �� ��������� �����
void Polynom::read(fstream& file)
{
	//���������, ����� ���� ��� ������
	if (!file.is_open())
		return;

	int size;
	double* coefficients;
	int temp;

	//��������� ������
	file.read((char*)&size, sizeof(int));

	if (size <= 0)
		throw exception("�������� ������!");

	//��������� �������� � �������: ����������� � ������� (������� ���������� � ��������� �� � ��������� �������)
	//��� ������� ��� ����, ����� ���������� ���������� ������ ����������� ������ ������� �� ������ � ���� �� �����
	coefficients = new double[size];
	for (int i = 0; i < size; i++)
	{
		file.read((char*)&coefficients[i], sizeof(double));
		file.read((char*)&temp, sizeof(int));
	}

	//������������� ��������� ��������
	setDegrees(size, nullptr, coefficients);
}

//������� ������ �� ����� - ����� ��� ������������ ������������
void Polynom::show()
{
	cout << "CLASS : Polynom" << endl;
	cout << (*this) << endl;
}

//������ � �������� ������
istream& operator>>(istream& stream, Polynom& polynom)
{
	int size;
	double* coefficients;

	//��������� ������
	stream >> size;

	if (size < 0)
		throw exception("�������� �������!");

	//��������� �������� � �������: ����������� (������� ����������� �������������)
	coefficients = new double[size];
	for (int i = 0; i < size; i++)
		stream >> coefficients[i];

	//������������� ������� � ������������
	polynom.setDegrees(size, nullptr, coefficients);

	return stream;
}

//������ � ��������� ������
ifstream& operator>>(ifstream& file, Polynom& polynom)
{
	int size;
	double* coefficients;
	int temp;

	//��������� �������
	file >> size;

	if (size < 0)
		throw exception("�������� �������!");

	//��������� �������� � �������: ����������� (������� ����������� �������������)
	coefficients = new double[size];
	for (int i = 0; i < size; i++)
	{
		file >> coefficients[i];
		file >> temp;
	}

	polynom.setDegrees(size, nullptr, coefficients);

	return file;
}
