#include "PolynomTests.h"

//������������ ������������ �� ���������
void PolynomTests::defaultConstructor()
{
	const char errorName[] = "error in default constructor";
	const char methodName[] = "default constructor";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedDegree = 0;
	int expectedSize = expectedDegree+1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = 0;
		expectedCoefficients[i] = 0;
	}

	//������������� �������
	Polynom received;

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	//��������� ��������� ������ � ����������
	if (received.getDegree() != expectedDegree)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}

		if (received.DegreesPolynom::getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}

//������������ ������������ � �����������
void PolynomTests::parametrConstructor()
{
	const char errorName[] = "error in parametr constructor";
	const char methodName[] = "parametr constructor";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree+1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	Polynom received(expectedDegree, expectedCoefficients);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	if (received.getDegree() != expectedDegree)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}

		if (received.DegreesPolynom::getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}

//������������ ������������ �����������
void PolynomTests::copyConstructor()
{
	const char errorName[] = "error in copy constructor";
	const char methodName[] = "copy constructor";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	Polynom objForCopy(expectedDegree, expectedCoefficients), received(objForCopy);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	if (received.getDegree() != expectedDegree)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}

		if (received.DegreesPolynom::getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}

//������������ ��������� ������������
void PolynomTests::assignmentOperator()
{
	const char errorName[] = "error in assignment operator";
	const char methodName[] = "assignment operator";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	Polynom objForCopy(expectedDegree, expectedCoefficients), received =objForCopy;

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	if (received.getDegree() != expectedDegree)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}

		if (received.DegreesPolynom::getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}


//���� ������ ��������� ��������
void PolynomTests::setDegrees()
{
	const char errorName[] = "error in setDegrees()";
	const char methodName[] = "setDegrees()";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	Polynom received;
	received.setDegrees(expectedSize, expectedDegrees, expectedCoefficients);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	if (received.getDegree() != expectedDegree)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}

		if (received.DegreesPolynom::getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}

//���� ������ ��������� �������
void PolynomTests::setDegree()
{
	const char errorName[] = "error in setDegree()";
	const char methodName[] = "setDegree()";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������

	int degree = 7;
	double* expectedCoefficients = new double[degree+1];
	for (int i = 0; i < degree+1; i++)
	{
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}
	//������������� �������
	Polynom received(degree, expectedCoefficients);
	received.setDegree(5);

	int expectedDegree = 5;
	int expectedSize = 6;
	int* expectedDegrees = new int[expectedSize];
	for (int i = 0; i < expectedSize; i++)
		expectedDegrees[i] = i;

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	if (received.getDegree() != expectedDegree)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}

		if (received.DegreesPolynom::getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}

//���� ������ ��������� �������������
void PolynomTests::setCoefficients()
{
	const char errorName[] = "error in setCoefficients()";
	const char methodName[] = "setCoefficients()";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int degree = (int)(rand() % 10);
	int size = degree+1;
	int* degrees = new int[size];
	double* coefficients = new double[size];
	for (int i = 0; i < size; i++)
	{
		degrees[i] = i;
		coefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	Polynom received(degree, coefficients);
	//�������� ����������� �������� �� �����
	double* expectedCoefficients = new double[size];
	for (int i = 0; i < size; i++)
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	received.setCoefficients(expectedCoefficients);

	//���������� ���������� �������� � ���������
	for (int i = 0; i < received.getSize(); i++)
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] coefficients;
			delete[] degrees;

			throw exception(errorName);
		}

	delete[] expectedCoefficients;
	delete[] coefficients;
	delete[] degrees;

	cout << methodName << " test completed" << endl;
}



//���� ��������� ()
void PolynomTests::functionOperator()
{
	const char errorName[] = "error in operator()";
	const char methodName[] = "operator()";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int degree = (int)(rand() % 10);
	int size = degree+1;
	int* degrees = new int[size];
	double* coefficients = new double[size];

	double expected = 0;
	double x = (int)(rand() % 10);
	for (int i = 0; i < size; i++)
	{
		degrees[i] = i;
		coefficients[i] = (int)(rand() % 200 - 100);
		expected += coefficients[i] * pow(x, degrees[i]);
	}

	//������������� �������
	Polynom received(degree, coefficients);

	if (expected != received(x))
	{
		delete[] coefficients;
		delete[] degrees;

		throw exception(errorName);
	}

	delete[] coefficients;
	delete[] degrees;

	cout << methodName << " test completed" << endl;
}



//���� ��������� +
void PolynomTests::sumOperator()
{
	const char errorName[] = "error in operator+";
	const char methodName[] = "operator+";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	Polynom objForSum(expectedDegree, expectedCoefficients),received(objForSum+ objForSum);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	if (received.getDegree() != expectedDegree)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		expectedCoefficients[i] *= 2;

		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}

		if (received.DegreesPolynom::getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}

//���� ��������� -
void PolynomTests::subOperator()
{
	const char errorName[] = "error in operator-";
	const char methodName[] = "operator-";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	Polynom objForSub(expectedDegree, expectedCoefficients), received(objForSub - objForSub);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	if (received.getDegree() != expectedDegree)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		expectedCoefficients[i] =0;

		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}

		if (received.DegreesPolynom::getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}




//���� ���������� �����-������ ��� ��������� ������
void PolynomTests::fileOperators()
{
	const char errorName[] = "error in file input-output operators";
	const char methodName[] = "file input-output operators";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	Polynom objForFile(expectedDegree, expectedCoefficients), received;

	//���������� ������ � ����
	ofstream output("test.txt");
	output << objForFile;
	output.close();

	//��������� � ������ ������
	ifstream input("test.txt");
	input >> received;
	input.close();

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	if (received.getDegree() != expectedDegree)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}

		if (received.DegreesPolynom::getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}

//���� ���������� �����-������ ��� �������� ������
void PolynomTests::binaryOperators()
{
	const char errorName[] = "error in binary input-output operators";
	const char methodName[] = "binary input-output operators";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	Polynom objForFile(expectedDegree, expectedCoefficients), received;

	//���������� ������ � ����
	fstream output("test.bin", ios::out | ios::trunc | ios::binary);
	objForFile.write(output);
	output.close();

	//��������� � ������ ������
	fstream input("test.bin", ios::in | ios::binary);
	received.read(input);
	input.close();

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	if (received.getDegree() != expectedDegree)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}

		if (received.DegreesPolynom::getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}
