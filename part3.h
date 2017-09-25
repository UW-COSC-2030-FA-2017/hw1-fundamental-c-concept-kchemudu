// Krishna Sai C
// COSC 2030
// homework1_part3
// part3.h

#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>;
using namespace std;

template <class T>
class Collection
{
public:
	Collection(int size);
	bool isEmpty();
	void makeEmpty();
	void insert(T const& x);
	void remove(T x);
	void removeRandom();
	bool notContained(T x);
	void setSize(int x);
	void printArray();
private:
	T  * arrayOfObjects;
	int currentSize = 0;


};

#endif;
