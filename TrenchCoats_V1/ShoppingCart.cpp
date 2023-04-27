#include "ShoppingCart.h"
#include <Windows.h>
#include <iostream>


TrenchCoat ShoppingCart::getCurrentCoat() 
{
	if (this->current_index == this->cart->getSize())
	{
		this->current_index = 0;
	}
	TrenchCoat currentCoat = this->cart->getElement(this->current_index);
	return currentCoat;
}


int ShoppingCart::getCurrentIndex()
{
	return this->current_index;
}


int ShoppingCart::getPosition(std::string link)
{
	int length = this->getCartLength();
	for (int i = 0; i < length; i++)
	{
		if (this->getCoatFromList(i).getPhotograph() == link)
		{
			return i;
		}
	}
	return -1;	
}



//CRUD
int ShoppingCart::addTrenchCoatToCart(const TrenchCoat& coat)
{
	//this allows shopping more coats of the same type
	//this is so because there is no check for unicity
	this->cart->add(coat);
	return 1;
	
	// modified version to add each item just once
	/*
	if (this->getPosition(coat.getPhotograph()) == -1)
	{
		this->cart->add(coat);
		return 1;
	}
	return 0;
	*/
}


int ShoppingCart::deleteByLink(std::string link)
{
	int position = this->getPosition(link);
	if (position != -1)
	{
		this->cart->removeByIndex(position);
		return 1;
	}
	return 0;
}


void ShoppingCart::play() const 
{
	// we use Microsoft Edge to open the photos which are saved as links
	// from the cart, we get the element on the postion of the current index and get the photo
	// the photo ( saved as a string ) to to an array that contains a null-terminated sequence of characters 
	//																(i.e., a C-string, or const char*) 
	// after the shell is executed, a window is opened in a maximized form
	ShellExecuteA(NULL, NULL, "msedge.exe", cart->getElements()[current_index].getPhotograph().c_str(), NULL, SW_SHOWMAXIMIZED);
}


void ShoppingCart::next()
{
	if (this->isEmpty() == false)
	{
		this->current_index++;
		std::cout << this->current_index;
		TrenchCoat currentTrenchCoat = this->getCurrentCoat();
		std::cout << currentTrenchCoat.getPrice();
	}
}


