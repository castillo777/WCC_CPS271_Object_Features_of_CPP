#ifndef STOCKLISTTYPE_H_
#define STOCKLISTTYPE_H_
#include <cassert>
#include <iostream>

using namespace std;

const int MAX = 50;

template <class elemType>
class StockListType
{
public:
	bool isEmpty() const;
	bool isFull() const;
	int getLength() const;
	int getMaxSize() const;
	void sort();
	void print() const;
	void insertAt(const elemType& item, int position);
	StockListType(int listSize = MAX);
	~StockListType();

protected:
	int maxSize;
	int length;
	elemType *list;
};

template <class elemType>
bool StockListType<elemType>::isEmpty() const
{ //function to check if array is empty
	return (length == 0);
}

template <class elemType>
bool StockListType<elemType>::isFull() const
{ //function to check if array is full
	return (length == maxSize);
}

template <class elemType>
int StockListType<elemType>::getLength() const
{ //function to get length
	return length;
}

template <class elemType>
int StockListType<elemType>::getMaxSize() const
{ //function to get maxSize
	return maxSize;
}

template <class elemType>
StockListType<elemType>::StockListType(int listSize)
{ //default constructor
	maxSize = listSize;
	length = 0;
	list = new elemType[maxSize];
}

template <class elemType>
StockListType<elemType>::~StockListType()
{ //destructor
	delete[] list;
}

template <class elemType>
void StockListType<elemType>::sort()
{ //sort function
	int i, j;
	int min;
	elemType temp;

	for (i = 0; i < length; i++)
	{
		min = i;
		for (j = i; j < length; ++j)
			if (list[j] < list[min])
				min = j;
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}

template <class elemType>
void StockListType<elemType>::print() const
{ //print function
	int i;
	for (i = 0; i < length; ++i)
		cout << list[i];
	cout << endl;
}

template <class elemType>
void StockListType<elemType>::insertAt(const elemType& item, int position)
{ //insert function
	assert(position >= 0 && position < maxSize);
	list[position] = item;
	length++;
}

#endif