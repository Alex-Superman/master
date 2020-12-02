#include "DegreesPolynomTests.h";

//������������ ������������ �� ���������
void DegreesPolynomTests::defaultConstructor()
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

	//������������� �������
	DegreesPolynom received;

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
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

		if (received.getDegree(i) != expectedDegrees[i])
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
void DegreesPolynomTests::parametrConstructor()
{
	const char errorName[] = "error in parametr constructor";
	const char methodName[] = "parametr constructor";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = (int)(rand() % 10);
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	DegreesPolynom received(expectedSize, expectedDegrees, expectedCoefficients);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
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

		if (received.getDegree(i) != expectedDegrees[i])
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
void DegreesPolynomTests::copyConstructor()
{
	const char errorName[] = "error in copy constructor";
	const char methodName[] = "copy constructor";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = (int)(rand() % 10);
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	DegreesPolynom objForCopy(expectedSize, expectedDegrees, expectedCoefficients), received(objForCopy);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
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

		if (received.getDegree(i) != expectedDegrees[i])
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
void DegreesPolynomTests::assignmentOperator()
{
	const char errorName[] = "error in assignment operator";
	const char methodName[] = "assignment operator";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = (int)(rand() % 10);
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	DegreesPolynom objForCopy(expectedSize, expectedDegrees, expectedCoefficients), received = objForCopy;

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
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

		if (received.getDegree(i) != expectedDegrees[i])
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
void DegreesPolynomTests::setDegrees()
{
	const char errorName[] = "error in parametr constructor";
	const char methodName[] = "parametr constructor";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = (int)(rand() % 10);
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	DegreesPolynom received;
	received.setDegrees(expectedSize, expectedDegrees, expectedCoefficients);

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
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

		if (received.getDegree(i) != expectedDegrees[i])
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
void DegreesPolynomTests::setCoefficients()
{
	const char errorName[] = "error in setCoefficients()";
	const char methodName[] = "setCoefficients()";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int size = (int)(rand() % 10);
	int* degrees = new int[size];
	double* coefficients = new double[size];
	for (int i = 0; i < size; i++)
	{
		degrees[i] = i;
		coefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	DegreesPolynom received(size, degrees, coefficients);
	//�������� ����������� �������� �� �����
	double* expectedCoefficients = new double[size];
	for(int i =0;i<size;i++)
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
void DegreesPolynomTests::functionOperator()
{
	const char errorName[] = "error in operator()";
	const char methodName[] = "operator()";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int size = (int)(rand() % 10);
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
	DegreesPolynom received(size, degrees, coefficients);

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
void DegreesPolynomTests::sumOperator()
{
	const char errorName[] = "error in + operator";
	const char methodName[] = "+ operator";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = (int)(rand() % 10);
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	DegreesPolynom objForSum(expectedSize, expectedDegrees, expectedCoefficients), received(objForSum + objForSum);

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

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}

//���� ��������� -
void DegreesPolynomTests::subOperator()
{
	const char errorName[] = "error in - operator";
	const char methodName[] = "- operator";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = (int)(rand() % 10);
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	DegreesPolynom objForSub(expectedSize, expectedDegrees, expectedCoefficients), received(objForSub - objForSub);

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

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}




//���� ���������� �����-������ ��� ��������� ������
void DegreesPolynomTests::fileOperators()
{
	const char errorName[] = "error in file input-output operators";
	const char methodName[] = "file input-output operators";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = (int)(rand() % 10);
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	DegreesPolynom objForFile(expectedSize, expectedDegrees, expectedCoefficients),received;

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

	for (int i = 0; i < received.getSize(); i++)
	{
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

	delete[] expectedCoefficients;
	delete[] expectedDegrees;

	cout << methodName << " test completed" << endl;
}

//���� ���������� �����-������ ��� �������� ������
void DegreesPolynomTests::binaryOperators()
{
	const char errorName[] = "error in binary input-output operators";
	const char methodName[] = "binary input-output operators";

	cout << methodName << " test:" << endl;

	//�������� ������� ������ ��� �������
	int expectedSize = (int)(rand() % 10);
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//������������� �������
	DegreesPolynom objForFile(expectedSize, expectedDegrees, expectedCoefficients), received;

	//���������� ������ � ����
	fstream output("test.bin", ios::out | ios::trunc | ios::binary);
	objForFile.write(output);
	output.close();

	//��������� � ������ ������
	fstream input("test.bin",ios::in | ios::binary);
	received.read(input);
	input.close();

	//��������� ��������� ������ � ����������
	if (received.getSize() != expectedSize)
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

		if (received.getDegree(i) != expectedDegrees[i])
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
