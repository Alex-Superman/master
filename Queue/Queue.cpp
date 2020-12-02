
#include "Queue.h"
#include <exception>

using namespace std;

//конструктор
Queue::Queue()
{
	_head = nullptr;
	_tail = nullptr;

	_length = 0;
}

//деструктор
Queue::~Queue()
{
	clear();
}

//получение длины очереди
int Queue::getLength()
{
	return _length;
}

//добавление в конец очереди
void Queue::push(DegreesPolynom* obj)
{
	if (!obj)
		throw exception("Nullptr!");

	//если список пуст
	if (!_length)
	{
		_head = _tail = new Node(obj);
	}
	else
	{
		//создаем узел следующим после последнего
		_tail->_next = new Node(obj);
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
void Queue::push(DegreesPolynom* obj, int index)
{
	if (!obj)
		throw exception("Nullptr!");

	if ((index < 0) || (index > _length))
		throw exception("Bad index!");

	if (index == _length)
	{
		push(obj);

		return;
	}

	//если список пуст
	if (!_length)
	{
		//"зацикливание"
		_head = _tail = new Node(obj);
	}
	else
	{
		//начальный узел - голова
		Node * temp = _head;

		//в этом цикле происходит обход всех узлов списка до узла под номером index
		for (int i = 0; i < index; i++)
			//переход к следующему узлу
			temp = temp->_next;

		//вставляем новый узел позади узла под номером index
		Node * prev = temp->_prev;

		//связываем узел под номером index-1 с новым
		prev->_next = new Node(obj);
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
DegreesPolynom* Queue::pop()
{
	if (!_length)
		throw exception("The Queue is empty!");

	//сохраняем данные головы списка
	DegreesPolynom* result = _head->_data;

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
DegreesPolynom* Queue::pop(int index)
{
	if (!_length)
		throw exception("The Queue is empty!");
	
	if ((index < 0) || (index >= _length))
		throw exception("Bad index!");

	DegreesPolynom* result;

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
		Node * temp = _head;

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
void Queue::clear()
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
void Queue::show()
{
	//начальный узел - голова
	Node * temp = _head;

	//в этом цикле происходит обход всех узлов списка и вывод их содержимого на экран
	for (int i = 0; i < _length; i++)
	{
		//вывод данных на экран
		temp->_data->show();

		cout << endl;
		
		//переход к следующему узлу
		temp = temp->_next;
	}
}

//поиск в очереди
int Queue::search(DegreesPolynom* obj)
{
	if (!obj)
		throw exception("Nullptr!");

	//начальный узел - голова
	Node * temp = _head;

	//в этом цикле происходит обход всех узлов списка
	for (int i = 0; i < _length; i++)
	{
		//если встречены нужные данные, то возвращаем индекс узла, в котором они лежат
		if ((*temp->_data) == (*obj))
			return i;

		//переход к следующему узлу
		temp = temp->_next;
	}

	return -1;
}

//запись в бинарный файл
void Queue::write(fstream& file)
{
	file.write((char*)&_length, sizeof(int));

	//начальный узел - голова
	Queue::Node* temp = _head;

	//в этом цикле происходит обход всех узлов списка
	for (int i = 0; i < _length; i++)
	{
		temp->_data->write(file);

		//переход к следующему узлу
		temp = temp->_next;
	}
}

//чтение из бинарного файла
void Queue::read(fstream& file)
{
	clear();

	int len;
	file.read((char*)&len,sizeof(int));

	//в этом цикле происходит обход всех узлов списка
	for (int i = 0; i < len; i++)
	{
		DegreesPolynom* obj = new DegreesPolynom;

		(*obj).read(file);

		push(obj);
	}
}

//вывод в обычный поток
ostream& operator<<(ostream& stream, Queue& queue)
{
	stream << queue._length << endl;

	//начальный узел - голова
	Queue::Node* temp = queue._head;

	//в этом цикле происходит обход всех узлов списка
	for (int i = 0; i < queue._length; i++)
	{
		stream << *(temp->_data) << endl;		

		//переход к следующему узлу
		temp = temp->_next;
	}

	return stream;
}

//чтение из обычного потока
istream& operator>>(istream& stream, Queue& queue)
{
	queue.clear();

	int len;
	stream >>len;

	//в этом цикле происходит обход всех узлов списка
	for (int i = 0; i < len; i++)
	{
		DegreesPolynom * obj = new DegreesPolynom;

		stream >> (*obj);

		queue.push(obj);
	}

	return stream;
}

//вывод в файловый поток
ofstream& operator<<(ofstream& stream, Queue& queue)
{
	stream << queue._length << endl;

	//начальный узел - голова
	Queue::Node* temp = queue._head;

	//в этом цикле происходит обход всех узлов списка
	for (int i = 0; i < queue._length; i++)
	{
		stream << *(temp->_data) << endl;

		//переход к следующему узлу
		temp = temp->_next;
	}

	return stream;
}

//чтение из файлового потока
ifstream& operator>>(ifstream& stream, Queue& queue)
{
	queue.clear();

	int len;
	stream >> len;

	//в этом цикле происходит обход всех узлов списка
	for (int i = 0; i < len; i++)
	{
		DegreesPolynom* obj = new DegreesPolynom;

		stream >> (*obj);

		queue.push(obj);
	}

	return stream;
}
