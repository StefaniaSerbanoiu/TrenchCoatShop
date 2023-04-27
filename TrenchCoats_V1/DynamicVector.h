#pragma once
#include "TrenchCoat.h"
#include <iterator>


template <typename T>
class DynamicVector
{
private:

	// TODO  fileds private
	
	// TODO validation class

	//try 
	//take out const from getRepoObjects


	// careful about
	// dynamic vector from repo changed from not* to *
	//

	//errors
	// from repo
	//object.add() -> objects->add() because pointer
	/* these methods:
	//DynamicVector<TrenchCoat>& getTrenchCoatsFromRepo() const { return (DynamicVector<TrenchCoat>&)objects; }
	DynamicVector<TrenchCoat>* getTrenchCoatsFromRepo() { return objects; }
	TrenchCoat* getObjectOnPosition(int position);
	TrenchCoat& getObjectOnPositionCopy(int position) const;
	int Repository::findByLink(std::string link)
	*/
public:
	T* elements;
	int size;
	int capacity;

	//constructors
	DynamicVector(int capacity = 30);
	DynamicVector(const DynamicVector& vector);

	//operator =
	DynamicVector& operator=(const DynamicVector& vector);

	//operator []
 	T& operator[](int index) { return this->elements[index]; }

	//some CRUD operations
	bool itExists(const T& element);
	int add(const T& element);
	int remove(const T& element);
	int removeByIndex(int index);


	void resize(); //resizes the vector when the capacity is exceeded

	//getters
	int getSize() const { return this->size; }
	int getCapacity() const { return this->capacity; }
	T* getElements() const { return this->elements; }
	T getElement(int index) { return this->elements[index]; }

	//destructor
	~DynamicVector();
};



//constructors
template<typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new T[capacity];
}


template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector& vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->elements = vector.elements;
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = vector.elements[i];
	}
}


//operator =
template<typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& vector)
{
	if (this == &vector)
	{
		return *this;
	}

	this->capacity = vector.capacity;
	this->size = vector.size;

	delete[] this->elements;
	this->elements = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = vector.elements[i];
	}

	return *this;
}


//verify if an element is found inside the vector
template<typename T>
bool DynamicVector<T>::itExists(const T& element)
{
	for (int i = 0; i < this->size; i++)
	{
		if (&(this->elements[i]) == &(element))
		{
			return true;
		}
	}
	return false;
}


//adds a new element to the vector
// returns 1 if the element was added
//0 otherwise, if that element already exists inside the vector
template<typename T>
int DynamicVector<T>::add(const T& element)
{
	int found = 0;

	if (this->itExists(element))
	{
		return 0;
	}

	if (this->size == this->capacity)
	{
		this->resize();
	}

	this->elements[this->size] = element;
	this->size++;
	
	return 1;
	
}
/*
//other version of the add function:

template <typename T>
int DynamicVector<T>::add(const T& element)
{
	int found = 0;

	if (this->itExists(element) == true)
	{
		found = 1; //std::cout << 2;
	}
	else
	{
		//std::cout << 1;
		if (this->size == this->capacity)
		{
			this->resize();
		}
	}

	this->elements[this->size] = element;
	this->size++;

	return found;
}
*/


//removes a given element from the vector
//returns 1 if the deletion was successful
//0 otherwise, if the element wasn't defined in the vector
template<typename T>
int DynamicVector<T>::remove(const T& element)
{
	if (itExists(element) == false)
	{
		return 0; // the element should already exist in order to be deleted
	}

	if (&(this->elements[this->size - 1]) == &element) // the case when the element to delete is the last one
	{
		this->size--;
		return 1;
	}

	for (int i = 0; i < this->size; i++)
	{
		if (&(this->elements[i]) == &element)
		{
			for (int j = i + 1; i < this->size; i++)
			{
				this->elements[j - 1] = this->elements[j];
			}

			i = this->size;
			this->size--;
		}
	}
	return 1;
}


//removes an element on a specific, given position
//returns 1 if the deletion was successfully completed
//returns 0 if the index is not valid
template <typename T>
int DynamicVector<T>::removeByIndex(int index)
{
	if (index < 0 || index >= this->size) // invalid index conditions
	{
		return -1; 
	}

	if (index != (this->size - 1))
	{
		int length = this->size;
		for (int i = index + 1; i < length; i++)
		{
			this->elements[i - 1] = this->elements[i];
		}
	}

	this->size--; // this works for both the case when the index specifies the last element and for a regular index

	return 1;
}



//resizes the vector when the capacity is exceeded
template<typename T>
void DynamicVector<T>::resize()
{
	this->capacity += 10;
	T* new_elements = new T[this->capacity];
	for(int i = 0; i < this->size; i++)
	{
		new_elements[i] = this->elements[i];
	}
	delete[] this->elements;
	this->elements = new_elements;
}


//destructor
template <typename T>
DynamicVector<T>::~DynamicVector()
{
	//delete[] this->elements;
}

