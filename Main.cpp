
#include "Polynom/PolynomTests/PolynomTests.h"


int main()
{
	/*Лабораторная работа 1*/

	try
	{
		defaultConstructorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		parametrConstructorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		copyConstructorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		setDegreeTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		setCoefficientsTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		setCoefficientTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		computeTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	/*Лабораторная работа 2*/

	try
	{
		assignmentOperatorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		addOperatorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		subOperatorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		prefixIncrementOperatorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		postfixIncrementOperatorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		prefixDecrementOperatorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		postfixDecrementOperatorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		functionOperatorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		indexOperatorTest();
		cout << endl;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	cout << "Click any button:" << endl;
	char c;
	cin >> c;

	return 0;
}