#include <iostream>

#include "part3.h"

using namespace std;

template<class T>
Collection<T>::Collection(int size)
{
	setSize(size);
}

template <class T>
bool Collection<T> ::isEmpty()
{
	if (currentSize == 0)
	{
		return true;
	}
	return false;
}

template<class T>
void Collection<T> ::makeEmpty()
{
	if (isEmpty())
	{
		cout << "The array is already empty." << endl;
	}
	else
	{
		for (int i = 0; i < currentSize; i++)
		{
			arrayOfObjects[i] = NULL;
		}
		currentSize = 0;
	}

}
// assuming the insert function inserts the object to the end of the list.
template<class T>
void Collection<T>::insert(T const & x)
{
	arrayOfObjects[currentSize] = x;
	currentSize++;
}
template<class T>
void Collection<T>::remove(T x)
{
	int i = 0;
	int count = 0;
	while (i < currentSize)
	{
		if (arrayOfObjects[i] == x || &arrayOfObjects[i] == &x)
		{
			count++;
		}
		i++;
	}
	if (count == 0)
	{
		cout << "The element provided does not exist in the collection" << endl;
	}
	else if (count == 1)
	{
		int i = 0;
		int position = 0;
		while (i < currentSize)
		{
			if (arrayOfObjects[i] == x || &arrayOfObjects[i] == &x)
			{
				position = i;
			}
			i++;
		}
		while (position < currentSize)
		{
			arrayOfObjects[position] = arrayOfObjects[position + 1];
			position++;
		}
		arrayOfObjects[currentSize - 1] = NULL;
		currentSize--;
	}
	else
	{
		int i = 0;
		int y = 0;
		int position [count] = {};
		while (i < currentSize)
		{
			if (arrayOfObjects[i] == x || &arrayOfObjects[i] == &x)
			{
				position[y] = i;
				y++;
			}
			i++;
		}
		for (int z = 0; z < count; z++)
		{
			int post = position[z];
			while (post < currentSize)
			{
				arrayOfObjects[post] = arrayOfObjects[post + 1];
				post++;
			}
			arrayOfObjects[currentSize - 1] = NULL;
			currentSize--;
			for(int a = 0; a< count; a++)
            {
                position[a]--;
            }
		}
	}
}

/*
template<class T>
void Collection<T>::remove(T x)
{
	if (notContained(x))
	{
		cout << "The element provided does not exist in the collection" << endl;
	}
	else
	{
		int i = 0;
		int position = 0;
		int counter = 0;
		while (i < currentSize)
		{
			if (arrayOfObjects[i] == x)
			{
				position = i;
				while (position < currentSize)
				{
					arrayOfObjects[position] = arrayOfObjects[position + 1];
					position++;
				}
				counter++;
				//delete arrayOfObjects[currentSize - 1];
				arrayOfObjects[currentSize - 1]= NULL;
			}
			i++;
		}
		currentSize = currentSize - counter;
	}
}
*/


template<class T>
void Collection<T>::removeRandom()
{
	if (isEmpty())
	{
		cout << "The list already empty" << endl;
	}
	else
	{
		int position = rand() % currentSize;
		cout << "Element from position " << position << " has been removed." << endl;
		while (position < currentSize)
		{
			arrayOfObjects[position] = arrayOfObjects[position + 1];
			position++;
		}
		//delete arrayOfObjects[currentSize - 1];
		arrayOfObjects[currentSize - 1] = NULL;
		currentSize--;
	}

}

template<class T>
bool Collection<T>::notContained(T x)
{
	bool notContained = true;
	int i = 0;
	while (i < currentSize)
	{
		if (arrayOfObjects[i] == x || &arrayOfObjects[i] == &x)
		{
			notContained = false;
		}
		i++;
	}
	return notContained;
}

template<class T>
void Collection<T>::setSize(int x)
{
	arrayOfObjects = new T[x];
	cout << "The size of the collection/array has been set to " << x << endl;
}

template<class T>
void Collection<T>::printArray()
{
	cout << "[";
	for (int i = 0; i < currentSize; i++)
	{
		cout << arrayOfObjects[i] << " ";
	}
	cout << "]" << endl;
}

int main()
{

	int max_size;
	cout << "please enter the maximum size of the array:  ";
	cin >> max_size;
	Collection<int> intCollection(max_size);


	intCollection.insert(2);
	intCollection.insert(3);
	intCollection.insert(4);

	intCollection.printArray();

	intCollection.remove(2);
	intCollection.printArray();

	intCollection.insert(13);
	intCollection.insert(21);
	intCollection.insert(4);
	intCollection.printArray();
	intCollection.remove(4);
	intCollection.printArray();
	intCollection.removeRandom();
	intCollection.printArray();

	intCollection.insert(0);
	intCollection.insert(13);
	intCollection.insert(0);
	intCollection.insert(13);
	intCollection.insert(4);
	intCollection.insert(1);
	intCollection.printArray();
	intCollection.remove(13);
	intCollection.printArray();
	intCollection.removeRandom();
	intCollection.printArray();
	intCollection.remove(0);
	intCollection.printArray();



}
