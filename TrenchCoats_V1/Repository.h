#pragma once
#include "TrenchCoat.h"
#include <vector>

using namespace std;



class Repository
{
private:
	vector<TrenchCoat> objects; // the trench coats are saved as std vector

public:
	//constructor
	Repository() : objects{} {}

	//getters
	vector<TrenchCoat> getTrenchCoatsFromRepo() { return objects; }
	TrenchCoat& getObjectOnPositionCopy(int position) const;
	TrenchCoat getObjectOnPosition(int position) { return this->objects.at(position); }
	int getRepositorySize() const { return this->objects.size(); }

	/*
	returns -1 if the object wasn't found
	returns the position otherwise
	*/
	int findByLink(std::string link);
	
	//CRUD operations
	int addObject(const TrenchCoat& object);
	int removeObject(const TrenchCoat& object);
	int removeObjectByLink(std::string link);
	int updateObject(std::string link, int size_new, std::string color_new, int price_new, int quantity_new);

	void populate();
};