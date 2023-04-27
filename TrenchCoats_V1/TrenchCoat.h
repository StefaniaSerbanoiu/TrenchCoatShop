#pragma once
#include <string>


class TrenchCoat
{
private:
	int size;
	std::string color;
	int price;
	int quantity;           // how many coats are available in the deposit
	std::string photograph; // the photograph is memorized as a link towards an online resource

public:
	//constructors
	TrenchCoat(): size{0}, color{""}, price{0}, quantity{0}, photograph{""} {}
	TrenchCoat(const int size, const std::string color, const int price, const int quantity, const std::string link);
	//copy constructor
	TrenchCoat(const TrenchCoat& other)
		: size{ other.getSize() }, color{ other.getColor() }, price{ other.getPrice() },
		quantity{ other.getQuantity() }, photograph{ other.getPhotograph() }
	{}
	//destructor
	~TrenchCoat() {}

	//getters
	int getSize() const { return this->size; }
	std::string getColor() const { return this->color; }
	int getPrice() const { return this->price; }
	int getQuantity() const { return this->quantity; }
	std::string getPhotograph() const { return this->photograph; }

	//setters
	void setSize(int new_size) { this->size = new_size; }
	void setColor(std::string new_color) { this->color = new_color; }
	void setPrice(int new_price) { this->price = new_price; }
	void setQuantity(int new_quantity) { this->quantity = new_quantity; }
	void setPhotograph(std::string link) { this->photograph = link; }
};