#pragma once

#include <iostream>
#include <exception>

using namespace std;

//Класс очереди
template <typename T>
class Queue
{
private:

	//класс узла
	/*
	Класс сделан вложенным для того, чтобы оградить пользователя от 
	внутреннего механизма работы очереди. 
	*/
	class Node
	{
		friend class Queue;

		//объект, хранящийся в узле
		T _data;

		//указатели на следующий и предыдущий элементы
		Node* _next, * _prev;

	public:

		//конструктор с параметром
		Node(T data) : _data(data)
		{
			_next = _prev = this;
		}

	};

	//длина очереди
	int _length;

	//указатели на начало и конец списка (очереди)
	Node * _head, *_tail;

public:
	
	//конструктор по умолчанию
	Queue();

	//деструктор
	~Queue();

	//получение длины очереди
	//return:
	//	значение длины очереди
	int getLength();

	//добавление в конец очереди
	//args:
	//	data - вставляемый объект
	void push(T data);

	//добавление по индексу
	//args:
	//	data - вставляемый объект
	//  index - индекс вставки
	//исключения:
	//	если index выходит за пределы очереди
	void push(T data, int index);

	//извлечение из начала очереди
	//return:
	//	первый элемент очереди
	//исключения:
	//	если очередь уже пуста
	T pop();

	//извлечение по индексу
	//return:
	//	элемент очереди под номером index
	//исключения:
	//	если очередь уже пуста
	//	если индекс выходит за пределы очереди
	T pop(int index);

	//очистка очереди
	void clear();

	//поиск по структуре
	//args:
	//	data - искомый объект
	//return:
	//	индекс, под которым находится объект data в очереди
	int search(T data);
	


	//вывод на консоль
	void show();
};



//конструктор
template <typename T>
Queue<T>::Queue()
{
	_head = nullptr;
	_tail = nullptr;

	_length = 0;
}

//деструктор
template <typename T>
Queue<T>::~Queue()
{
	clear();
}

//получение длины очереди
template <typename T>
int Queue<T>::getLength()
{
	return _length;
}

//добавление в конец очереди
template <typename T>
void Queue<T>::push(T data)
{
	//если список пуст
	if (!_length)
	{
		_head = _tail = new Node(data);
	}
	else
	{
		//создаем узел следующим после последнего
		_tail->_next = new Node(data);
		//связываем его с последним узлом
		_tail->_next->_prev = _tail;

		//передвигаем указатель хвоста - теперь новый элемент является последним
		_tail = _tail->_next;

		//связываем хвост и голову списка для зацикливания
		_tail->_next = _head;
		_head->_prev = _tail;
	}

	_length++;
}

//добавление по номеру
template <typename T>
void Queue<T>::push(T data, int index)
{

	if ((index < 0) || (index > _length))
		throw exception("Bad index!");

	if (index == _length)
	{
		push(data);

		return;
	}

	//если список пуст
	if (!_length)
	{
		//"зацикливание"
		_head = _tail = new Node(data);
	}
	else
	{
		//начальный узел - голова
		Node* temp = _head;

		//в этом цикле происходит обход всех узлов списка до узла под номером index
		for (int i = 0; i < index; i++)
			//переход к следующему узлу
			temp = temp->_next;

		//вставляем новый узел позади узла под номером index
		Node* prev = temp->_prev;

		//связываем узел под номером index-1 с новым
		prev->_next = new Node(data);
		prev->_next->_prev = prev;

		//связываем узел под номером index с новым
		temp->_prev = prev->_next;
		prev->_next->_next = temp;

		//если вставка происходила вместо головы списка, то изменяем указатель на голову
		if (!index)
			_head = temp->_prev;
	}

	_length++;
}

//извлечение из начала очереди
template <typename T>
T Queue<T>::pop()
{
	if (!_length)
		throw exception("The Queue is empty!");

	//сохраняем данные головы списка
	T result = _head->_data;

	//если в списке один элемент
	if (_length == 1)
	{
		//удаляем голову
		delete[] _head;
		//зануляем указатели головы и хвоста
		_head = _tail = nullptr;
	}
	else
	{
		//передвигаем указатель головы на одну позицию вперед
		//теперь головой является следующий элемент
		_head = _head->_next;

		//удаляем "старую" голову
		delete _head->_prev;

		//связываем голову и хвост
		_head->_prev = _tail;
		_tail->_next = _head;
	}

	_length--;

	return result;
}

//извлечение по номеру
template <typename T>
T Queue<T>::pop(int index)
{
	if (!_length)
		throw exception("The Queue is empty!");

	if ((index < 0) || (index >= _length))
		throw exception("Bad index!");

	T result;

	//если в списке один элемент
	if (_length == 1)
	{
		//запоминаем данные из головы
		result = _head->_data;

		//удаляем головной узел
		delete _head;
		_head = _tail = nullptr;
	}
	else
	{

		//начальный узел - голова
		Node* temp = _head;

		//в этом цикле происходит обход всех узлов списка до узла под номером index
		for (int i = 0; i < index; i++)
			//переход к следующему узлу
			temp = temp->_next;

		//извлечение узла из списка
		temp->_next->_prev = temp->_prev;
		temp->_prev->_next = temp->_next;

		//если происходит извлечение головы
		if (!index)
			//то передвигаем указатель головы на позицию вперед
			_head = _head->_next;

		//если происходит извлечение хвоста
		if (index == _length - 1)
			//то передвигаем указатель хвоста на позицию назад
			_tail = _tail->_prev;

		result = temp->_data;
		delete temp;
	}

	_length--;

	return result;
}

//очистка списка
template <typename T>
void Queue<T>::clear()
{

	//начинаем с хвоста
	Node* temp = _tail;

	//пробегаем все элементы от последнего до второго
	for (int i = _length; i > 1; i--)
	{
		//двигаемся на один узел в сторону головы
		temp = temp->_prev;

		//удаляем узел, который стоит в стороне хвоста
		delete temp->_next;
	}

	//в конце остается нетронутым только головной узел, поэтому остается удалить только его
	delete _head;

	_head = _tail = nullptr;

	_length = 0;
}

//вывод на консоль
template <typename T>
void Queue<T>::show()
{
	//начальный узел - голова
	Node* temp = _head;

	//в этом цикле происходит обход всех узлов списка и вывод их содержимого на экран
	for (int i = 0; i < _length; i++)
	{
		//вывод данных на экран
		cout << temp->_data << endl;

		//переход к следующему узлу
		temp = temp->_next;
	}
}

//поиск в очереди
template <typename T>
int Queue<T>::search(T data)
{
	//начальный узел - голова
	Node* temp = _head;

	//в этом цикле происходит обход всех узлов списка
	for (int i = 0; i < _length; i++)
	{
		//если встречены нужные данные, то возвращаем индекс узла, в котором они лежат
		if (temp->_data == data)
			return i;

		//переход к следующему узлу
		temp = temp->_next;
	}

	return -1;
}