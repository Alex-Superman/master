
#include "Queue.h"

//конструктор с параметром и по умолчанию
Queue::Node::Node(DegreesPolynom* polynom)
{
	_next = _prev = this;

	_data = polynom;
}