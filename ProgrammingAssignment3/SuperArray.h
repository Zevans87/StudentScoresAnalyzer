#pragma once
#ifndef SUPERARRAY_H
#define SUPERARRAY_H

class SuperArray
{
private:
    int size;
    int* iArray;
    int numElements;

public:
    SuperArray(int s = 25);
    int getNumElement();
    void setNumElement(int);
    void fillRandom(int, int, int);
    void makeCopy(int const*, int);
    bool isFull() const;
    bool isValidIndex(int) const;
    void insertAtEnd(int);
    int const* getArray() const;
    void insertAtIndex(int, int);      
    int getAnElement(int) const;
    void displayAllArray() const;           // Displays the whole array, even the unpopulated slots
    void displayPopulatedSection() const;   // Displays only the populated array slots
    int getAverage();
    int getMax();
};
#endif 