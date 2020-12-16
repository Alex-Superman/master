#include "QueuePolynomTests.h"
#include "../../DegreesPolynom/DegreesPolynom.h"

void QueuePolynomTests::pushPop()
{
	const char errorName[] = "error in push and pop methods";
	const char methodName[] = "push and pop methods";

	cout << methodName << " test:" << endl;

	int expectedLen = 6;
	double expectedCoeff[] = { 0,1,2,3,4,5};
	int expectedDegrees[] = { 0,1,2,3,4,5 };

	DegreesPolynom* arr = new DegreesPolynom [expectedLen];
	arr[0] = DegreesPolynom(1, expectedDegrees, expectedCoeff);
	arr[1] = DegreesPolynom(2, expectedDegrees, expectedCoeff);
	arr[2] = DegreesPolynom(3, expectedDegrees, expectedCoeff);
	arr[3] = DegreesPolynom(4, expectedDegrees, expectedCoeff);
	arr[4] = DegreesPolynom(5, expectedDegrees, expectedCoeff);
	arr[5] = DegreesPolynom(6, expectedDegrees, expectedCoeff);

	Queue<DegreesPolynom> received;

	//вставляем в очередь все элементы последовательно
	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i]);

	//проверяем длину очереди
	if (received.getLength() != expectedLen)
		throw exception(errorName);

	//извлекаем все элементы из очереди
	for (int i = 0; i < received.getLength(); i++)
	{
		DegreesPolynom temp = received.pop();

		if(!(temp == arr[i]))
			throw exception(errorName);
	}

	cout << methodName << " test completed" << endl;

	delete[] arr;
}

void QueuePolynomTests::pushPopIndex()
{
	const char errorName[] = "error in push and pop with index methods";
	const char methodName[] = "push and pop with index methods";

	cout << methodName << " test:" << endl;

	int expectedLen = 6;
	double expectedCoeff[] = { 0,1,2,3,4,5 };
	int expectedDegrees[] = { 0,1,2,3,4,5 };

	DegreesPolynom* arr = new DegreesPolynom[expectedLen];
	arr[0] = DegreesPolynom(1, expectedDegrees, expectedCoeff);
	arr[1] = DegreesPolynom(2, expectedDegrees, expectedCoeff);
	arr[2] = DegreesPolynom(3, expectedDegrees, expectedCoeff);
	arr[3] = DegreesPolynom(4, expectedDegrees, expectedCoeff);
	arr[4] = DegreesPolynom(5, expectedDegrees, expectedCoeff);
	arr[5] = DegreesPolynom(6, expectedDegrees, expectedCoeff);

	Queue<DegreesPolynom> received;

	//вставляем в очередь все элементы последовательно
	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i],i);

	//проверяем длину очереди
	if (received.getLength() != expectedLen)
		throw exception(errorName);

	//извлекаем все элементы из очереди
	for (int i = received.getLength()-1; i >=0 ; i--)
	{
		DegreesPolynom temp = received.pop(i);

		if (!(temp == arr[i]))
			throw exception(errorName);
	}

	cout << methodName << " test completed" << endl;
}



void QueuePolynomTests::search()
{
	const char errorName[] = "error in search()";
	const char methodName[] = "search()";

	cout << methodName << " test:" << endl;

	int expectedLen = 6;
	double expectedCoeff[] = { 0,1,2,3,4,5 };
	int expectedDegrees[] = { 0,1,2,3,4,5 };

	DegreesPolynom* arr = new DegreesPolynom[expectedLen];
	arr[0] = DegreesPolynom(1, expectedDegrees, expectedCoeff);
	arr[1] = DegreesPolynom(2, expectedDegrees, expectedCoeff);
	arr[2] = DegreesPolynom(3, expectedDegrees, expectedCoeff);
	arr[3] = DegreesPolynom(4, expectedDegrees, expectedCoeff);
	arr[4] = DegreesPolynom(5, expectedDegrees, expectedCoeff);
	arr[5] = DegreesPolynom(6, expectedDegrees, expectedCoeff);

	Queue<DegreesPolynom> received;

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