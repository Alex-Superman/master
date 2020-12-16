#include "QueueIntTests.h"

void QueueIntTests::pushPop()
{
	const char errorName[] = "error in push and pop methods";
	const char methodName[] = "push and pop methods";

	cout << methodName << " test:" << endl;

	int expectedLen = 6;
	double expectedCoeff[] = { 0,1,2,3,4,5};
	int expectedDegrees[] = { 0,1,2,3,4,5 };

	int* arr = new int [expectedLen];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	arr[5] = 5;

	Queue<int> received;

	//вставляем в очередь все элементы последовательно
	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i]);

	//проверяем длину очереди
	if (received.getLength() != expectedLen)
		throw exception(errorName);

	//извлекаем все элементы из очереди
	for (int i = 0; i < received.getLength(); i++)
	{
		int temp = received.pop();

		if(!(temp == arr[i]))
			throw exception(errorName);
	}

	cout << methodName << " test completed" << endl;

	delete[] arr;
}

void QueueIntTests::pushPopIndex()
{
	const char errorName[] = "error in push and pop with index methods";
	const char methodName[] = "push and pop with index methods";

	cout << methodName << " test:" << endl;

	int expectedLen = 6;
	double expectedCoeff[] = { 0,1,2,3,4,5 };
	int expectedDegrees[] = { 0,1,2,3,4,5 };

	int* arr = new int[expectedLen];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	arr[5] = 5;

	Queue<int> received;

	//вставляем в очередь все элементы последовательно
	for (int i = 0; i < expectedLen; i++)
		received.push(arr[i],i);

	//проверяем длину очереди
	if (received.getLength() != expectedLen)
		throw exception(errorName);

	//извлекаем все элементы из очереди
	for (int i = received.getLength()-1; i >=0 ; i--)
	{
		int temp = received.pop(i);

		if (!(temp == arr[i]))
			throw exception(errorName);
	}

	cout << methodName << " test completed" << endl;
}



void QueueIntTests::search()
{
	const char errorName[] = "error in search()";
	const char methodName[] = "search()";

	cout << methodName << " test:" << endl;

	int expectedLen = 6;
	double expectedCoeff[] = { 0,1,2,3,4,5 };
	int expectedDegrees[] = { 0,1,2,3,4,5 };

	int* arr = new int[expectedLen];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	arr[5] = 5;

	Queue<int> received;

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