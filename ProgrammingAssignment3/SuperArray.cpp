#include "SuperArray.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

SuperArray::SuperArray(int s)
{
	this -> size = s;
	this -> iArray = new int[size];
	this -> numElements = 0;
	for (int i = 0; i < size; i++)
	{
		this -> iArray[i] = 0;
	}
}

int SuperArray::getNumElement()
{
	return this -> numElements;
}

void SuperArray::setNumElement(int x)
{
	this -> numElements = x;
}

void SuperArray::fillRandom(int lowBound, int upBound, int size)
{
	unsigned seed = time(0);
	srand(seed);
	
	this->setNumElement(size);
	for (int i = 0; i < this -> getNumElement(); i++)
	{
		this -> iArray[i] = (rand() % (upBound - lowBound + 1)) + lowBound;
	}
}

void SuperArray::makeCopy(int const* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		this -> iArray[i] = array[i];
	}
}

bool SuperArray::isFull() const
{
	bool flag = false;
	if (numElements == size)
		flag = true;
	return flag;
}

bool SuperArray::isValidIndex(int x) const
{
	bool flag = false;

	if (x >= 0 && x < size)
		flag = true;
	return flag;
}

void SuperArray::insertAtEnd(int x)
{
	if (isFull() == false)
	{
		this -> iArray[getNumElement()] = x;
	}
	for (int i = 0; i < size; i++)
	{
		if (this->iArray[i] == 0)
		{
			this->iArray[i] = x;
			numElements++;
		}
	}
}

void SuperArray::insertAtIndex(int i, int x)
{
	if (isValidIndex(i) == true)
	{
		this -> iArray[i] = x;
		if (i >= this -> getNumElement())
			this -> numElements++;
	}
}

int const* SuperArray::getArray() const
{
	const int* arrayPtr = iArray;
	return arrayPtr;
}

int SuperArray::getAnElement(int i) const
{
	if (isValidIndex(i) == true)
	{
		return this->iArray[i];
	}
	else return -1;
}

void SuperArray::displayAllArray() const	// Displays the whole array, even the unpopulated slots
{
	for (int i = 0; i < this -> size; i++)
	{
		cout << this -> iArray[i] << " ";
	}
	cout << endl;
}

void SuperArray::displayPopulatedSection() const   // Displays only the populated array slots
{
	for (int i = 0; i < numElements; i++)
	{
		if (iArray[i] != 0)
		{
			cout << iArray[i] << " ";
		}
	}
	cout << endl;
}

int SuperArray::getAverage()
{
	int sum = 0, average = 0;
	
	if (this->getNumElement() > 0)
	{
		for (int i = 0; i < this->numElements; i++)
		{
			sum += iArray[i];
		}
		average = sum / this->numElements;
	}
	return average;
}

int SuperArray::getMax()
{
	int maxScore = this -> iArray[0];

	for (int i = 1; i < this->numElements; i++)
	{
		if (this->iArray[i] > maxScore)
		{
			maxScore = iArray[i];
		}
	}

	return maxScore;
}