
#include "Queue.h"
#include <exception>

using namespace std;

//�����������
Queue::Queue()
{
	_head = nullptr;
	_tail = nullptr;

	_length = 0;
}

//����������
Queue::~Queue()
{
	clear();
}

//��������� ����� �������
int Queue::getLength()
{
	return _length;
}

//���������� � ����� �������
void Queue::push(DegreesPolynom* obj)
{
	if (!obj)
		throw exception("Nullptr!");

	//���� ������ ����
	if (!_length)
	{
		_head = _tail = new Node(obj);
	}
	else
	{
		//������� ���� ��������� ����� ����������
		_tail->_next = new Node(obj);
		//��������� ��� � ��������� �����
		_tail->_next->_prev = _tail;

		//����������� ��������� ������ - ������ ����� ������� �������� ���������
		_tail = _tail->_next;

		//��������� ����� � ������ ������ ��� ������������
		_tail->_next = _head;
		_head->_prev = _tail;
	}

	_length++;
}

//���������� �� ������
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

	//���� ������ ����
	if (!_length)
	{
		//"������������"
		_head = _tail = new Node(obj);
	}
	else
	{
		//��������� ���� - ������
		Node * temp = _head;

		//� ���� ����� ���������� ����� ���� ����� ������ �� ���� ��� ������� index
		for (int i = 0; i < index; i++)
			//������� � ���������� ����
			temp = temp->_next;

		//��������� ����� ���� ������ ���� ��� ������� index
		Node * prev = temp->_prev;

		//��������� ���� ��� ������� index-1 � �����
		prev->_next = new Node(obj);
		prev->_next->_prev = prev;

		//��������� ���� ��� ������� index � �����
		temp->_prev = prev->_next;
		prev->_next->_next = temp;

		//���� ������� ����������� ������ ������ ������, �� �������� ��������� �� ������
		if (!index)
			_head = temp->_prev;
	}

	_length++;
}

//���������� �� ������ �������
DegreesPolynom* Queue::pop()
{
	if (!_length)
		throw exception("The Queue is empty!");

	//��������� ������ ������ ������
	DegreesPolynom* result = _head->_data;

	//���� � ������ ���� �������
	if (_length == 1)
	{
		//������� ������
		delete[] _head;
		//�������� ��������� ������ � ������
		_head = _tail = nullptr;
	}
	else
	{
		//����������� ��������� ������ �� ���� ������� ������
		//������ ������� �������� ��������� �������
		_head = _head->_next;

		//������� "������" ������
		delete _head->_prev;

		//��������� ������ � �����
		_head->_prev = _tail;
		_tail->_next = _head;
	}

	_length--;

	return result;
}

//���������� �� ������
DegreesPolynom* Queue::pop(int index)
{
	if (!_length)
		throw exception("The Queue is empty!");
	
	if ((index < 0) || (index >= _length))
		throw exception("Bad index!");

	DegreesPolynom* result;

	//���� � ������ ���� �������
	if (_length == 1)
	{
		//���������� ������ �� ������
		result = _head->_data;

		//������� �������� ����
		delete _head;
		_head = _tail = nullptr;
	}
	else
	{

		//��������� ���� - ������
		Node * temp = _head;

		//� ���� ����� ���������� ����� ���� ����� ������ �� ���� ��� ������� index
		for (int i = 0; i < index; i++)
			//������� � ���������� ����
			temp = temp->_next;

		//���������� ���� �� ������
		temp->_next->_prev = temp->_prev;
		temp->_prev->_next = temp->_next;

		//���� ���������� ���������� ������
		if (!index)
			//�� ����������� ��������� ������ �� ������� ������
			_head = _head->_next;

		//���� ���������� ���������� ������
		if (index == _length - 1)
			//�� ����������� ��������� ������ �� ������� �����
			_tail = _tail->_prev;

		result = temp->_data;
		delete temp;
	}

	_length--;

	return result;
}

//������� ������
void Queue::clear()
{

	//�������� � ������
	Node* temp = _tail;

	//��������� ��� �������� �� ���������� �� �������
	for (int i = _length; i > 1; i--)
	{
		//��������� �� ���� ���� � ������� ������
		temp = temp->_prev;

		//������� ����, ������� ����� � ������� ������
		delete temp->_next;
	}

	//� ����� �������� ���������� ������ �������� ����, ������� �������� ������� ������ ���
	delete _head;

	_head = _tail = nullptr;

	_length = 0;
}

//����� �� �������
void Queue::show()
{
	//��������� ���� - ������
	Node * temp = _head;

	//� ���� ����� ���������� ����� ���� ����� ������ � ����� �� ����������� �� �����
	for (int i = 0; i < _length; i++)
	{
		//����� ������ �� �����
		temp->_data->show();

		cout << endl;
		
		//������� � ���������� ����
		temp = temp->_next;
	}
}

//����� � �������
int Queue::search(DegreesPolynom* obj)
{
	if (!obj)
		throw exception("Nullptr!");

	//��������� ���� - ������
	Node * temp = _head;

	//� ���� ����� ���������� ����� ���� ����� ������
	for (int i = 0; i < _length; i++)
	{
		//���� ��������� ������ ������, �� ���������� ������ ����, � ������� ��� �����
		if ((*temp->_data) == (*obj))
			return i;

		//������� � ���������� ����
		temp = temp->_next;
	}

	return -1;
}

//������ � �������� ����
void Queue::write(fstream& file)
{
	file.write((char*)&_length, sizeof(int));

	//��������� ���� - ������
	Queue::Node* temp = _head;

	//� ���� ����� ���������� ����� ���� ����� ������
	for (int i = 0; i < _length; i++)
	{
		temp->_data->write(file);

		//������� � ���������� ����
		temp = temp->_next;
	}
}

//������ �� ��������� �����
void Queue::read(fstream& file)
{
	clear();

	int len;
	file.read((char*)&len,sizeof(int));

	//� ���� ����� ���������� ����� ���� ����� ������
	for (int i = 0; i < len; i++)
	{
		DegreesPolynom* obj = new DegreesPolynom;

		(*obj).read(file);

		push(obj);
	}
}

//����� � ������� �����
ostream& operator<<(ostream& stream, Queue& queue)
{
	stream << queue._length << endl;

	//��������� ���� - ������
	Queue::Node* temp = queue._head;

	//� ���� ����� ���������� ����� ���� ����� ������
	for (int i = 0; i < queue._length; i++)
	{
		stream << *(temp->_data) << endl;		

		//������� � ���������� ����
		temp = temp->_next;
	}

	return stream;
}

//������ �� �������� ������
istream& operator>>(istream& stream, Queue& queue)
{
	queue.clear();

	int len;
	stream >>len;

	//� ���� ����� ���������� ����� ���� ����� ������
	for (int i = 0; i < len; i++)
	{
		DegreesPolynom * obj = new DegreesPolynom;

		stream >> (*obj);

		queue.push(obj);
	}

	return stream;
}

//����� � �������� �����
ofstream& operator<<(ofstream& stream, Queue& queue)
{
	stream << queue._length << endl;

	//��������� ���� - ������
	Queue::Node* temp = queue._head;

	//� ���� ����� ���������� ����� ���� ����� ������
	for (int i = 0; i < queue._length; i++)
	{
		stream << *(temp->_data) << endl;

		//������� � ���������� ����
		temp = temp->_next;
	}

	return stream;
}

//������ �� ��������� ������
ifstream& operator>>(ifstream& stream, Queue& queue)
{
	queue.clear();

	int len;
	stream >> len;

	//� ���� ����� ���������� ����� ���� ����� ������
	for (int i = 0; i < len; i++)
	{
		DegreesPolynom* obj = new DegreesPolynom;

		stream >> (*obj);

		queue.push(obj);
	}

	return stream;
}
