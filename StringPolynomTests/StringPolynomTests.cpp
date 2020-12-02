#include "StringPolynomTests.h"

char* StringPolynomTests::createPolynomString(int size, int* degrees, double* coefficients)
{
	//������� ������
	char * str = new char[10000];
	int k = 0;
	//����������� �� ���� ������������� ����������
	for (int i = 0; i < size; i++)
	{
		//������ ����������� ��������� � ������
		char* str_number = new char[100];
		_itoa_s(coefficients[i], str_number, 100, 10);

		//��������� ������������� ������������ ��������� � �������������� ������
		for (int j = 0; j < strlen(str_number); j++)
			str[k++] = str_number[j];
		delete[] str_number;

		str[k++] = '*';
		str[k++] = 'x';
		str[k++] = '^';

		str_number = new char[100];
		_itoa_s(degrees[i], str_number, 100, 10);
		for (int j = 0; j < strlen(str_number); j++)
			str[k++] = str_number[j];

		str[k++] = '+';

		delete[] str_number;
	}
	str[k - 1] = '\0';

	return str;
}

void StringPolynomTests::defaultConstructor()
{
	const char errorName[] = "error in default constructor";
	const char methodName[] = "default constructor";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = 0;
		expectedCoefficients[i] = 0;
	}
	char* expectedStr = createPolynomString(expectedSize, expectedDegrees, expectedCoefficients);

	//������������� �������
	StringPolynom received;

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}

		if (received.getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}
	}

	if (strcmp(expectedStr, received.getStr()))
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;
	delete[] expectedStr;

	cout << methodName << " test completed" << endl;
}

void StringPolynomTests::parametrConstructor()
{
	const char errorName[] = "error in parametr constructor";
	const char methodName[] = "parametr constructor";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = 10;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}
	char* expectedStr = createPolynomString(expectedSize, expectedDegrees, expectedCoefficients);

	//������������� �������
	StringPolynom received(expectedSize, expectedDegrees, expectedCoefficients);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}

		if (received.getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}
	}

	if (strcmp(expectedStr, received.getStr()))
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;
	delete[] expectedStr;

	cout << methodName << " test completed" << endl;
}

void StringPolynomTests::copyConstructor()
{
	const char errorName[] = "error in copy constructor";
	const char methodName[] = "copy constructor";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = 10;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}
	char* expectedStr = createPolynomString(expectedSize, expectedDegrees, expectedCoefficients);

	//������������� �������
	StringPolynom objForCopy(expectedSize, expectedDegrees, expectedCoefficients), received(objForCopy);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}

		if (received.getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}
	}

	if (strcmp(expectedStr, received.getStr()))
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;
	delete[] expectedStr;

	cout << methodName << " test completed" << endl;
}

void StringPolynomTests::assignmentOperator()
{
	const char errorName[] = "error in assignment operator";
	const char methodName[] = "assignment operator";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = 10;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}
	char* expectedStr = createPolynomString(expectedSize, expectedDegrees, expectedCoefficients);

	//������������� �������
	StringPolynom objForCopy(expectedSize, expectedDegrees, expectedCoefficients), received = objForCopy;

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}

		if (received.getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}
	}

	if (strcmp(expectedStr, received.getStr()))
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;
	delete[] expectedStr;

	cout << methodName << " test completed" << endl;
}

void StringPolynomTests::setDegrees()
{
	const char errorName[] = "error in setDegrees()";
	const char methodName[] = "setDegrees()";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = 10;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}
	char* expectedStr = createPolynomString(expectedSize, expectedDegrees, expectedCoefficients);

	//������������� �������
	StringPolynom received;
	received.setDegrees(expectedSize, expectedDegrees, expectedCoefficients);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}

		if (received.getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}
	}

	if (strcmp(expectedStr, received.getStr()))
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;
	delete[] expectedStr;

	cout << methodName << " test completed" << endl;
}

void StringPolynomTests::setCoefficients()
{
	const char errorName[] = "error in setCoefficients()";
	const char methodName[] = "setCoefficients()";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int size = 10;
	int* degrees = new int[size];
	double* coefficients = new double[size];
	for (int i = 0; i < size; i++)
	{
		degrees[i] = i;
		coefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	StringPolynom received(size, degrees, coefficients);
	
	double* expectedCoefficients = new double[size];
	for (int i = 0; i < size; i++)
		coefficients[i] = (int)(rand() % 200 - 100);
	received.setCoefficients(expectedCoefficients);

	char* expectedStr = createPolynomString(size, degrees, expectedCoefficients);

	for (int i = 0; i < received.getSize(); i++)
		if (received[i] != expectedCoefficients[i])
		{
			delete[] coefficients;
			delete[] degrees;
			delete[] expectedStr;
			delete[] expectedCoefficients;

			throw exception(errorName);
		}

	if (strcmp(expectedStr, received.getStr()))
	{
		delete[] coefficients;
		delete[] degrees;
		delete[] expectedStr;
		delete[] expectedCoefficients;

		throw exception(errorName);
	}

	delete[] coefficients;
	delete[] degrees;
	delete[] expectedStr;
	delete[] expectedCoefficients;

	cout << methodName << " test completed" << endl;
}

void StringPolynomTests::functionOperator()
{
	const char errorName[] = "error in operator()";
	const char methodName[] = "operator()";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int size = 10;
	int* degrees = new int[size];
	double* coefficients = new double[size];
	double expected = 0;
	double x = 2;
	for (int i = 0; i < size; i++)
	{
		degrees[i] = i;
		coefficients[i] = (int)(rand() % 200 - 100);
		expected += coefficients[i] * pow(x, degrees[i]);
	}

	//������������� �������
	StringPolynom received(size, degrees, coefficients);

	if (received(x) != expected)
	{
		delete[] coefficients;
		delete[] degrees;
		
		throw exception(errorName);
	}

	delete[] coefficients;
	delete[] degrees;

	cout << methodName << " test completed" << endl;
}

void StringPolynomTests::sumOperator()
{
	const char errorName[] = "error in operator+";
	const char methodName[] = "operator+";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = 10;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	StringPolynom objForSum(expectedSize, expectedDegrees, expectedCoefficients), received(objForSum + objForSum);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
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

		if (received.getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	char* expectedStr = createPolynomString(expectedSize, expectedDegrees, expectedCoefficients);

	if (strcmp(expectedStr, received.getStr()))
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;
	delete[] expectedStr;

	cout << methodName << " test completed" << endl;
}

void StringPolynomTests::subOperator()
{
	const char errorName[] = "error in operator-";
	const char methodName[] = "operator-";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = 10;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	StringPolynom objForSub(expectedSize, expectedDegrees, expectedCoefficients), received(objForSub - objForSub);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		expectedCoefficients[i] = 0;

		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}

		if (received.getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;

			throw exception(errorName);
		}
	}

	char* expectedStr = createPolynomString(expectedSize, expectedDegrees, expectedCoefficients);

	if (strcmp(expectedStr, received.getStr()))
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;
	delete[] expectedStr;

	cout << methodName << " test completed" << endl;
}

void StringPolynomTests::fileOperators()
{
	const char errorName[] = "error in input-output operators";
	const char methodName[] = "input-output operators";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = 10;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}
	char* expectedStr = createPolynomString(expectedSize, expectedDegrees, expectedCoefficients);

	//������������� �������
	StringPolynom objForFile(expectedSize, expectedDegrees, expectedCoefficients), received;

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
		delete[] expectedStr;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}

		if (received.getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}
	}

	if (strcmp(expectedStr, received.getStr()))
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;
	delete[] expectedStr;

	cout << methodName << " test completed" << endl;
}

void StringPolynomTests::binaryOperators()
{
	const char errorName[] = "error in input-output operators";
	const char methodName[] = "input-output operators";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = 10;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}
	char* expectedStr = createPolynomString(expectedSize, expectedDegrees, expectedCoefficients);

	//������������� �������
	StringPolynom objForFile(expectedSize, expectedDegrees, expectedCoefficients), received;

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
		delete[] expectedStr;

		throw exception(errorName);
	}

	for (int i = 0; i < received.getSize(); i++)
	{
		if (received[i] != expectedCoefficients[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}

		if (received.getDegree(i) != expectedDegrees[i])
		{
			delete[] expectedCoefficients;
			delete[] expectedDegrees;
			delete[] expectedStr;

			throw exception(errorName);
		}
	}

	if (strcmp(expectedStr, received.getStr()))
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;
		delete[] expectedStr;

		throw exception(errorName);
	}

	delete[] expectedCoefficients;
	delete[] expectedDegrees;
	delete[] expectedStr;

	cout << methodName << " test completed" << endl;
}
