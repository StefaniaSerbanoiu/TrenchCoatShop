#include "TrenchCoat.h"


TrenchCoat::TrenchCoat(const int size, const std::string color, const int price, const int quantity, const std::string link)
	: size{size}, color{color}, price{price}, quantity{quantity}, photograph{link} {}