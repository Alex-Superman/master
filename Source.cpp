
#include "DegreesPolynomTests/DegreesPolynomTests.h"
#include "PolynomTests/PolynomTests.h"
#include "StringPolynomTests/StringPolynomTests.h"

int main()
{
	setlocale(LC_ALL, "RU");

	{
		cout << "DegreesPolynom tests:" << endl;

		DegreesPolynomTests tester;

		try
		{
			tester.defaultConstructor();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.parametrConstructor();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;
		
		try
		{
			tester.copyConstructor();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.assignmentOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.setDegrees();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.setCoefficients();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.functionOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.sumOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.subOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.fileOperators();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.binaryOperators();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;
	}

	cout << endl;
	cout << "-----------------------------" << endl;
	cout << endl;

	{
		cout << "Polynom tests:" << endl;

		PolynomTests tester;

		try
		{
			tester.defaultConstructor();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.parametrConstructor();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.copyConstructor();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.assignmentOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.setDegrees();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.setDegree();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.setCoefficients();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.functionOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.sumOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.subOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.fileOperators();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.binaryOperators();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;
	}

	cout << endl;
	cout << "-----------------------------" << endl;
	cout << endl;

	{
		cout << "StringPolynom tests:" << endl;

		StringPolynomTests tester;

		try
		{
			tester.defaultConstructor();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.parametrConstructor();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.copyConstructor();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.assignmentOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.setDegrees();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.setCoefficients();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.functionOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.sumOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.subOperator();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.fileOperators();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.binaryOperators();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}