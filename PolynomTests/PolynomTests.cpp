#include "PolynomTests.h"

//тестирование конструктора по умолчанию
void PolynomTests::defaultConstructor()
{
	const char errorName[] = "error in default constructor";
	const char methodName[] = "default constructor";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта
	int expectedDegree = 0;
	int expectedSize = expectedDegree+1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = 0;
		expectedCoefficients[i] = 0;
	}

	//инициализация объекта
	Polynom received;

	//сравнение ожидаемых данных и полученных
	if (received.getSize() != expectedSize)
	{
		delete[] expectedCoefficients;
		delete[] expectedDegrees;

		throw exception(errorName);
	}

	//сравнение ожидаемых данных и полученных
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

//тестирование конструктора с параметрами
void PolynomTests::parametrConstructor()
{
	const char errorName[] = "error in parametr constructor";
	const char methodName[] = "parametr constructor";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree+1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//инициализация объекта
	Polynom received(expectedDegree, expectedCoefficients);

	//сравнение ожидаемых данных и полученных
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

//тестирование конструктора копирования
void PolynomTests::copyConstructor()
{
	const char errorName[] = "error in copy constructor";
	const char methodName[] = "copy constructor";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//инициализация объекта
	Polynom objForCopy(expectedDegree, expectedCoefficients), received(objForCopy);

	//сравнение ожидаемых данных и полученных
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

//тестирование оператора присваивания
void PolynomTests::assignmentOperator()
{
	const char errorName[] = "error in assignment operator";
	const char methodName[] = "assignment operator";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//инициализация объекта
	Polynom objForCopy(expectedDegree, expectedCoefficients), received =objForCopy;

	//сравнение ожидаемых данных и полученных
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


//тест метода изменения степеней
void PolynomTests::setDegrees()
{
	const char errorName[] = "error in setDegrees()";
	const char methodName[] = "setDegrees()";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//инициализация объекта
	Polynom received;
	received.setDegrees(expectedSize, expectedDegrees, expectedCoefficients);

	//сравнение ожидаемых данных и полученных
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

//тест метода изменения степени
void PolynomTests::setDegree()
{
	const char errorName[] = "error in setDegree()";
	const char methodName[] = "setDegree()";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта

	int degree = 7;
	double* expectedCoefficients = new double[degree+1];
	for (int i = 0; i < degree+1; i++)
	{
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}
	//инициализация объекта
	Polynom received(degree, expectedCoefficients);
	received.setDegree(5);

	int expectedDegree = 5;
	int expectedSize = 6;
	int* expectedDegrees = new int[expectedSize];
	for (int i = 0; i < expectedSize; i++)
		expectedDegrees[i] = i;

	//сравнение ожидаемых данных и полученных
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

//тест метода изменения коэффициентов
void PolynomTests::setCoefficients()
{
	const char errorName[] = "error in setCoefficients()";
	const char methodName[] = "setCoefficients()";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта
	int degree = (int)(rand() % 10);
	int size = degree+1;
	int* degrees = new int[size];
	double* coefficients = new double[size];
	for (int i = 0; i < size; i++)
	{
		degrees[i] = i;
		coefficients[i] = (int)(rand() % 200 - 100);
	}

	//инициализация объекта
	Polynom received(degree, coefficients);
	//изменяем изначальные значения на новые
	double* expectedCoefficients = new double[size];
	for (int i = 0; i < size; i++)
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	received.setCoefficients(expectedCoefficients);

	//сравниваем полученные значения и ожидаемые
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



//тест оператора ()
void PolynomTests::functionOperator()
{
	const char errorName[] = "error in operator()";
	const char methodName[] = "operator()";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта
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

	//инициализация объекта
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



//тест оператора +
void PolynomTests::sumOperator()
{
	const char errorName[] = "error in operator+";
	const char methodName[] = "operator+";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//инициализация объекта
	Polynom objForSum(expectedDegree, expectedCoefficients),received(objForSum+ objForSum);

	//сравнение ожидаемых данных и полученных
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

//тест оператора -
void PolynomTests::subOperator()
{
	const char errorName[] = "error in operator-";
	const char methodName[] = "operator-";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//инициализация объекта
	Polynom objForSub(expectedDegree, expectedCoefficients), received(objForSub - objForSub);

	//сравнение ожидаемых данных и полученных
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




//тест операторов ввода-вывода для текстовых файлов
void PolynomTests::fileOperators()
{
	const char errorName[] = "error in file input-output operators";
	const char methodName[] = "file input-output operators";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//инициализация объекта
	Polynom objForFile(expectedDegree, expectedCoefficients), received;

	//записываем объект в файл
	ofstream output("test.txt");
	output << objForFile;
	output.close();

	//считываем в другой объект
	ifstream input("test.txt");
	input >> received;
	input.close();

	//сравнение ожидаемых данных и полученных
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

//тест операторов ввода-вывода для бинарных файлов
void PolynomTests::binaryOperators()
{
	const char errorName[] = "error in binary input-output operators";
	const char methodName[] = "binary input-output operators";

	cout << methodName << " test:" << endl;

	//создание входных данных для объекта

	int expectedDegree = (int)(rand() % 10);
	int expectedSize = expectedDegree + 1;
	int* expectedDegrees = new int[expectedSize];
	double* expectedCoefficients = new double[expectedSize];
	for (int i = 0; i < expectedSize; i++)
	{
		expectedDegrees[i] = i;
		expectedCoefficients[i] = (int)(rand() % 200 - 100);
	}

	//инициализация объекта
	Polynom objForFile(expectedDegree, expectedCoefficients), received;

	//записываем объект в файл
	fstream output("test.bin", ios::out | ios::trunc | ios::binary);
	objForFile.write(output);
	output.close();

	//считываем в другой объект
	fstream input("test.bin", ios::in | ios::binary);
	received.read(input);
	input.close();

	//сравнение ожидаемых данных и полученных
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
