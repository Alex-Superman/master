#pragma once

#include "../Queue/Queue.h"

//класс тестировани€ очереди
class QueueTests
{
public:

	//тест обычной вставки и извлечени€
	void pushPop();

	//тест вставки и извлечени€ по номеру
	void pushPopIndex();



	//тест поиска 
	void search();



	//теста ввода-вывода с обычными файлами
	void fileInputOutput();

	//теста ввода-вывода с бинарными файлами
	void binaryInputOutput();

};

