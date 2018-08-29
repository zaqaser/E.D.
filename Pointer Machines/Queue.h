#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <iostream>
using namespace std;
template <class K, class D>
class Queue
{
private:
	LinkedList<K,D> List;
public:
	Queue();
	void PushBack(K p_key, D p_dato);
	void Pop();
	K Top();
	void Print();
	~Queue();
};

#include "Queue.inl"

#endif
