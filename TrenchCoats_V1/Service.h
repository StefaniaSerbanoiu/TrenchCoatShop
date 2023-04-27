#pragma once
#include "Repository.h"
#include "ShoppingCart.h"


class Service 
{
private:
	Repository* repo;
	ShoppingCart* cart;

public:
	//constructor
	Service(Repository* repository, ShoppingCart* cart);

	//getters
	Repository* getRepo() const { return this->repo; }
	ShoppingCart* getCart() const { return this->cart; }
	TrenchCoat& getCoatFromRepository(int position);
	int getRepoSize() const { return this->repo->getRepositorySize(); }

	//CRUD for Repository
	int addService(const TrenchCoat& coat);
	int removeService(std::string link);
	int updateService(std::string link, int size_new, std::string color_new, int price_new, int quantity_new);

	
	/*returns - 1 if the object wasn't found or the index is not valid
	 returns the position of the element otherwise
	*/
	int findInRepoService(std::string link);



	//Shopping Cart Functions
	ShoppingCart* getBySize(int size);
};