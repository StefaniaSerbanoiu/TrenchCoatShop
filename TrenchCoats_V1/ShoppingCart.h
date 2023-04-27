#pragma once
#include "DynamicVector.h"


class ShoppingCart
{
private:
	DynamicVector<TrenchCoat>* cart;
	int current_index;

public:
	//constructors
	ShoppingCart() : cart{ new DynamicVector<TrenchCoat>() }, current_index{ 0 } {}
	ShoppingCart(DynamicVector<TrenchCoat>* coats) : cart{coats}, current_index{0} {}



	//getters
	/*
	the total number of elements in the shopping cart
	*/
	int getCartLength() { return cart->getSize(); }

	DynamicVector<TrenchCoat>* getVector() { return cart; }

	int getCurrentIndex();

	/*
	* return a pointer to the coats available
	*/
	TrenchCoat* getAllCoats() const { return this->cart->getElements(); }

	/*
	gets the coat from a specific position(given as parameter)
	*/
	TrenchCoat getCoatFromList(int postion) const { return this->getAllCoats()[postion]; }

	/*
	return a pointer to the current event
	*/
	TrenchCoat getCurrentCoat();

	/*
	return the postion of a coat with a given link, if the coat exists
	-1 if it doesn't exist
	*/
	int getPosition(std::string link);



	bool isEmpty() { return this->getCartLength() == 0; }



	//CRUD 
	/*
	adds a new trench coat to the cart
	returns 1 if the operation was successful
	returns 0 if the coat already exists, so it can't be added
	*/
	int addTrenchCoatToCart(const TrenchCoat& coat);
	/*
	deletes a coat, given its photograph's link
	returns 1 if it was deleted
	returns 0 if it didn't already exist
	*/
	int deleteByLink(std::string link);


	void play() const;
	void next();

	//destructor
	virtual ~ShoppingCart() {}
};