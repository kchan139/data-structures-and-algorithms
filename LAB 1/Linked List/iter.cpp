template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T> *pList, bool begin)
{
	this->pList = pList;
	if (begin == true)
	{
		if (this->pList == NULL)
		{
			this->current = NULL;
			this->index = -1;
		}
		else
		{
			this->current = this->pList->head;
			this->index = 0;
		}
	}
	else
	{
		this->current = NULL;
		this->index = (this->pList->count == 0) ? (this->pList->size()) : 0;
	}
}

template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator=(const Iterator &iterator)
{
	this->pList = iterator.pList;
	this->current = iterator.current;
	this->index = iterator.index;
	return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
	if (this->current == NULL)
		throw std::out_of_range("Segmentation fault!");
	else if (this->current == this->pList->head)
	{
		this->current = NULL;
		this->pList->removeAt(this->index);
		this->index = -1;
	}
	else
	{
		Node *prev = this->pList->head;
		while (prev->next != this->current)
			prev = prev->next;
		this->current = prev;
		this->pList->removeAt(this->index);
		--this->index;
	}
}

template <class T>
void SLinkedList<T>::Iterator::set(const T &e)
{
	if (this->current == NULL)
		throw std::out_of_range("Segmentation fault!");
	else
		this->pList->set(this->index, e);
}

template <class T>
T &SLinkedList<T>::Iterator::operator*()
{
	if (this->current == NULL)
		throw std::out_of_range("Segmentation fault!");
	return this->current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
{
	/*
        Operator not equals
        * Returns true if two iterators points the same node and index
    */
	return (this->pList != iterator.pList || this->current != iterator.current);
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator++()
{
	/*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
	if (this->current == NULL && this->index == this->pList->size())
		throw std::out_of_range("Segmentation fault!");
	else if (this->current == NULL && this->index == -1)
	{
		this->current = this->pList->head;
		this->index = 0;
	}
	else
	{
		this->current = this->current->next;
		++this->index;
	}
	return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
	/*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    Iterator newIterator(this->pList, true);
	if (this->current == NULL && this->index == this->pList->size())
		throw std::out_of_range("Segmentation fault!");
	else
	{
		newIterator.current = this->current;
		newIterator.index = this->index;
		++this->index;
		if (this->current == NULL && this->index == -1)
			this->current = this->pList->head;
		else
			this->current = this->current->next;
	}
	return newIterator;
}