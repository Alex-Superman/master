
#include "Queue.h"

//����������� � ���������� � �� ���������
Queue::Node::Node(DegreesPolynom* polynom)
{
	_next = _prev = this;

	_data = polynom;
}