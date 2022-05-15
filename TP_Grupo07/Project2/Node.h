#include "Capp.h"
template <class Generic>
class Node
{
public:
	Generic date;
	Node<Generic>* next;
	Node(Generic date) {
		this->date = date;
		next = nullptr;
	}
};
