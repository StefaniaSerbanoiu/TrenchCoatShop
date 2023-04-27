#include "Service.h"
#include <iostream>

//constructor
Service::Service(Repository* repository, ShoppingCart* cart) 
	: repo{ repository }, cart{ cart } {}



//REPO functions
// 
// 
//getters
TrenchCoat& Service::getCoatFromRepository(int position)
{
	return (TrenchCoat&)this->repo->getObjectOnPosition(position);
}


//CRUD for Repository
int Service::addService(const TrenchCoat& coat)
{
	return this->repo->addObject(coat);

}


int Service::removeService(std::string link)
{
	return this->repo->removeObjectByLink(link);
}


int Service::updateService(std::string link, int size_new, std::string color_new, int price_new, int quantity_new)
{
	return this->repo->updateObject(link, size_new, color_new, price_new, quantity_new);
}


// find function
/*
	returns -1 if the object wasn't found or the index is not valid
	returns the position of the element otherwise
*/
int Service::findInRepoService(std::string link)
{
	return this->repo->findByLink(link);
}



//SHOPPING CART functions

ShoppingCart* Service::getBySize(int size)
{ 	
	// we add a copy of each item from the repo into a new DynamicVector<TrenchCoat> pointer
	DynamicVector<TrenchCoat>* list = new DynamicVector<TrenchCoat>();
	int length = this->getRepoSize();
	Repository* repo = this->getRepo();
	for (int i = 0; i < length; i++)
	{
		TrenchCoat t = TrenchCoat(repo->getObjectOnPosition(i));
		list->add(t);
	}
	
	// we create a new cart in which we add the wanted items
	ShoppingCart* cart = new ShoppingCart();
	
	if (size == 0) // for this number, the size doens't matter and all coats are added
	{
		for (int i = 0; i < length; i++)
		{
			cart->addTrenchCoatToCart(list->getElement(i));
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			int elemSIze = list->getElement(i).getSize();
			if (elemSIze == size)
			{
				cart->addTrenchCoatToCart(list->getElement(i));
			}
		}
	}

	//deleting the list from memory
	delete[] list->elements;
	delete list;

	return cart;
}

