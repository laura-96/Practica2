#include <stdio.h>

#ifndef __cDList__
#define __cDList__


template <class TYPE>
struct p2List_item
{
	TYPE data;
	p2List_item<TYPE>* next;
	p2List_item<TYPE>* prev;
};



template <class TYPE>
class p2List
{
private:
	p2List_item <TYPE>* start;
	p2List_item <TYPE>* end; //Despite this pointer isn't really necessary for the class cDList to work, it can agilize some other methods
	unsigned int  size;

public:
	p2List(){ start = NULL; end = NULL; size = 0; }

	~p2List() { Clear(); }

	p2List_item <TYPE>* getLast() const
	{
		return end;
	}

	p2List_item <TYPE>* getFirst() const
	{
		return start;
	}

	p2List_item <TYPE>* Index(const int N) const
	{
		p2List_item <TYPE>* tmp = start;
		for (int p = 0; p < N; p++)
		{
			if (tmp == NULL)
			{

				return 0;
				break;
			}
			tmp = tmp->next;
		}
		return tmp;
	}

	void  add(const TYPE valor)
	{
		p2List_item <TYPE>* createdDNode = new p2List_item <TYPE>;
		createdDNode->data = valor;
		createdDNode->next = NULL;

		if (end != NULL)
		{
			end->next = createdDNode;
		}

		createdDNode->prev = end;
		end = createdDNode;

		if (start == NULL)
		{
			start = createdDNode;
		}
		size++;
	}

	int find(const TYPE& data)
	{
		p2List_item <TYPE>* tmp = start;
		int index = 0;

		while (tmp != NULL)
		{
			if (tmp->data == data)
				return(index);

			++index;
			tmp = tmp->next;
		}
		return (-1);
	}

	bool  del(p2List_item <TYPE>* nDel)
	{
		if (nDel != NULL && start != NULL && end != NULL)
		{
			if (nDel)
			{
				if (nDel->next != NULL)
				{
					nDel->next->prev = nDel->prev;   //The value "previous" from the node which follows nDel, which was before nDel itself, is now the node before nDel.
				}
				else
				{
					end = nDel->prev;
				}
				if (nDel->prev != NULL)
				{
					nDel->prev->next = nDel->next;       //Here we do the same, but with the "next" value, so both nodes now "ignore" nDel.
				}
				else
				{
					start = nDel->next;
				}
			}
			else
			{
				return false;
			}
			delete nDel;
			size--;
			return true;
		}

		return false;
	}


	void  Clear()
	{
		while (start != NULL)
		{
			end = start->next;
			delete start;
			start = end;
		}
		size = 0;
	}

	unsigned int count() const
	{
		return size;
	}
};

#endif