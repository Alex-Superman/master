
#include "DegreesPolynomTests/DegreesPolynomTests.h"
#include "PolynomTests/PolynomTests.h"
#include "StringPolynomTests/StringPolynomTests.h"
#include "QueueTests/QueueTests.h"

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

	cout << endl;
	cout << "-----------------------------" << endl;
	cout << endl;

	{
		cout << "Queue tests:" << endl;

		QueueTests tester;

		try
		{
			tester.pushPop();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.pushPopIndex();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.search();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.fileInputOutput();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;

		try
		{
			tester.binaryInputOutput();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
		cout << endl;
	}

	int len = 6;
	double coeff[] = { 0,1,2,3,4,5 };
	int degrees[] = { 0,1,2,3,4,5 };

	DegreesPolynom** arr = new DegreesPolynom * [len];
	arr[0] = new DegreesPolynom(1, degrees, coeff);
	arr[1] = new DegreesPolynom(2, degrees, coeff);
	arr[2] = new Polynom(2, coeff);
	arr[3] = new Polynom(3, coeff);
	arr[4] = new StringPolynom(5, degrees, coeff);
	arr[5] = new StringPolynom(6, degrees, coeff);

	Queue queue;

	for (int i = 0; i < len; i++)
		queue.push(arr[i]);

	queue.show();

	system("pause");
	return 0;
}