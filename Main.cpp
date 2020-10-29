
#include <iostream>
#include "Polynom/PolynomTests/PolynomTests.h"

using namespace std;



int main()
{
	try
	{
		defaultConstructorTest();
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		parametrConstructorTest();
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		copyConstructorTest();
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		setDegreeTest();
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		setCoefficientsTest();
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		setCoefficientTest();
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	try
	{
		computeTest();
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	cout << endl;
	char c;
	cout << "Click any button:" << endl;
	cin >> c;

	return 0;
}