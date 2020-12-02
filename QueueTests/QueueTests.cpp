#include "QueueTests.h"
#include "../Polynom/Polynom.h"
#include "../StringPolynom/StringPolynom.h"

void QueueTests::pushPop()
{
	const char errorName[] = "error in push and pop methods";
	const char methodName[] = "push and pop methods";

	cout << methodName << " test:" << endl;

	int expectedLen = 6;
	double expectedCoeff[] = { 0,1,2,3,4,5};
	int expectedDegrees[] = { 0,1,2,3,4,5 };

	DegreesPolynom** arr = new DegreesPolynom * [expectedLen];
	arr[0] = new DegreesPolynom(1, expectedDegrees, expectedCoeff);
	arr[1] = new DegreesPolynom(2, expectedDegrees, expectedCoeff);
	arr[2] = new Polynom(2, expectedCoeff);
	arr[3] = new Polynom(3, expectedCoeff);
	arr[4] = new StringPolynom(5, expectedDegrees, expectedCoeff);
	arr[5] = new StringPolynom(6, expectedDegrees, expectedCoeff);

	Queue received;

	//вставляем в очередь все элементы последовательно
	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i]);

	//проверяем длину очереди
	if (received.getLength() != expectedLen)
		throw exception(errorName);

	//извлекаем все элементы из очереди
	for (int i = 0; i < received.getLength(); i++)
	{
		DegreesPolynom* temp = received.pop();

		if(!( (*temp) == (*(arr[i])) ))
			throw exception(errorName);

		delete temp;
	}

	cout << methodName << " test completed" << endl;

	delete[] arr;
}

void QueueTests::pushPopIndex()
{
	const char errorName[] = "error in push and pop with index methods";
	const char methodName[] = "push and pop with index methods";

	cout << methodName << " test:" << endl;

	int expectedLen = 6;
	double expectedCoeff[] = { 0,1,2,3,4,5 };
	int expectedDegrees[] = { 0,1,2,3,4,5 };

	DegreesPolynom** arr = new DegreesPolynom * [expectedLen];
	arr[0] = new DegreesPolynom(1, expectedDegrees, expectedCoeff);
	arr[1] = new DegreesPolynom(2, expectedDegrees, expectedCoeff);
	arr[2] = new Polynom(2, expectedCoeff);
	arr[3] = new Polynom(3, expectedCoeff);
	arr[4] = new StringPolynom(5, expectedDegrees, expectedCoeff);
	arr[5] = new StringPolynom(6, expectedDegrees, expectedCoeff);

	Queue received;

	//вставляем в очередь все элементы последовательно
	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i],i);

	//проверяем длину очереди
	if (received.getLength() != expectedLen)
		throw exception(errorName);

	//извлекаем все элементы из очереди
	for (int i = received.getLength()-1; i >=0 ; i--)
	{
		DegreesPolynom* temp = received.pop(i);

		if (!((*temp) == (*(arr[i]))))
			throw exception(errorName);

		delete temp;
	}

	cout << methodName << " test completed" << endl;

	delete[] arr;
}



void QueueTests::search()
{
	const char errorName[] = "error in search()";
	const char methodName[] = "search()";

	cout << methodName << " test:" << endl;

	int expectedLen = 6;
	double expectedCoeff[] = { 0,1,2,3,4,5 };
	int expectedDegrees[] = { 0,1,2,3,4,5 };

	DegreesPolynom** arr = new DegreesPolynom * [expectedLen];
	arr[0] = new DegreesPolynom(1, expectedDegrees, expectedCoeff);
	arr[1] = new DegreesPolynom(2, expectedDegrees, expectedCoeff);
	arr[2] = new Polynom(2, expectedCoeff);
	arr[3] = new Polynom(3, expectedCoeff);
	arr[4] = new StringPolynom(5, expectedDegrees, expectedCoeff);
	arr[5] = new StringPolynom(6, expectedDegrees, expectedCoeff);

	Queue received;

	//вставляем в очередь все элементы последовательно
	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i]);

	//проводим поиск элементов в очереди
	for (int i = 0; i < received.getLength(); i++)
		if (received.search(arr[i]) != i)
			throw exception(errorName);

	cout << methodName << " test completed" << endl;

	delete[] arr;
}



void QueueTests::fileInputOutput()
{
	const char errorName[] = "error in file input-output operators";
	const char methodName[] = "file input-output operators";

	cout << methodName << " test:" << endl;

	int expectedLen = 6;
	double expectedCoeff[] = { 0,1,2,3,4,5 };
	int expectedDegrees[] = { 0,1,2,3,4,5 };

	DegreesPolynom** arr = new DegreesPolynom * [expectedLen];
	arr[0] = new DegreesPolynom(1, expectedDegrees, expectedCoeff);
	arr[1] = new DegreesPolynom(2, expectedDegrees, expectedCoeff);
	arr[2] = new Polynom(2, expectedCoeff);
	arr[3] = new Polynom(3, expectedCoeff);
	arr[4] = new StringPolynom(5, expectedDegrees, expectedCoeff);
	arr[5] = new StringPolynom(6, expectedDegrees, expectedCoeff);

	Queue received;

	//вставляем в очередь все элементы последовательно
	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i]);

	ofstream output("test.txt");
	output << received;
	output.close();

	ifstream input("test.txt");
	input >> received;
	input.close();

	//проверяем длину очереди
	if (received.getLength() != expectedLen)
		throw exception(errorName);

	//извлекаем все элементы из очереди
	for (int i = 0; i < received.getLength(); i++)
	{
		DegreesPolynom* temp = received.pop();

		if (!((*temp) == (*(arr[i]))))
			throw exception(errorName);

		delete temp;
	}

	cout << methodName << " test completed" << endl;

	delete[] arr;
}

void QueueTests::binaryInputOutput()
{
	const char errorName[] = "error in binary input-output operators";
	const char methodName[] = "binary input-output operators";

	cout << methodName << " test:" << endl;

	int expectedLen = 6;
	double expectedCoeff[] = { 0,1,2,3,4,5 };
	int expectedDegrees[] = { 0,1,2,3,4,5 };

	DegreesPolynom** arr = new DegreesPolynom * [expectedLen];
	arr[0] = new DegreesPolynom(1, expectedDegrees, expectedCoeff);
	arr[1] = new DegreesPolynom(2, expectedDegrees, expectedCoeff);
	arr[2] = new Polynom(2, expectedCoeff);
	arr[3] = new Polynom(3, expectedCoeff);
	arr[4] = new StringPolynom(5, expectedDegrees, expectedCoeff);
	arr[5] = new StringPolynom(6, expectedDegrees, expectedCoeff);

	Queue received;

	//вставляем в очередь все элементы последовательно
	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i]);

	fstream output("test.bin",ios::out | ios::trunc | ios::binary);
	received.write(output);
	output.close();

	fstream input("test.bin", ios::in | ios::binary);
	received.read(input);
	input.close();

	//проверяем длину очереди
	if (received.getLength() != expectedLen)
		throw exception(errorName);

	//извлекаем все элементы из очереди
	for (int i = 0; i < received.getLength(); i++)
	{
		DegreesPolynom* temp = received.pop();

		if (!((*temp) == (*(arr[i]))))
			throw exception(errorName);

		delete temp;
	}

	cout << methodName << " test completed" << endl;

	delete[] arr;
}
