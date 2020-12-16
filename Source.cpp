
#include "DegreesPolynomTests/DegreesPolynomTests.h"
#include "QueueTests/QueuePolynomTests/QueuePolynomTests.h"
#include "QueueTests/QueueIntTests/QueueIntTests.h"
#include "Queue/Queue.h"

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
		cout << "Queue<DegreesPolynom> tests:" << endl;

		QueuePolynomTests tester;

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
	}

	cout << endl;
	cout << "-----------------------------" << endl;
	cout << endl;

	{
		cout << "Queue<int> tests:" << endl;

		QueueIntTests tester;

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
	}

	system("pause");
	return 0;
}