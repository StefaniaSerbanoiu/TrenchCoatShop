#include "Tests.h"
#include <assert.h>



void test_addService()
{
	Repository* repository = new Repository();
	repository->populate();
	ShoppingCart* cart = new ShoppingCart();
	Service* service = new Service(repository, cart);

	assert(service->addService(TrenchCoat(36, "Beige", 21275, 100, "dgsdg")) == 1);
	assert(service->addService(TrenchCoat(36, "Beige", 21275, 100, "https://media.dior.com/couture/ecommerce/media/catalog/product/G/B/1676656893_327M34A3332_X1700_E01_ZHC.jpg?imwidth=1080")) == -1);
	assert(service->removeService("https://media.dior.com/couture/ecommerce/media/catalog/product/G/B/1676656893_327M34A3332_X1700_E01_ZHC.jpg?imwidth=1080") == 1);
	assert(service->removeService("https://media.dior.com/couture/ecommerce/media/catalog/product/G/B/1676656893_327M34A3332_X1700_E01_ZHC.jpg?imwidth=1080") == -1);
	assert(service->updateService("dgsdg", 34, "lila", 123, 123) == 1);
	assert(service->updateService("notexist", 34, "lila", 356, 355) == -1);

	delete service;
	delete[] cart->getVector()->elements;
	delete cart->getVector();
	delete cart;
	delete repository;
}


void test_removeService()
{
	Repository* repository = new Repository();
	repository->populate();
	ShoppingCart* cart = new ShoppingCart();
	Service* service = new Service(repository, cart);

	assert(service->removeService("https://media.dior.com/couture/ecommerce/media/catalog/product/G/B/1676656893_327M34A3332_X1700_E01_ZHC.jpg?imwidth=1080") == 1);
	assert(service->removeService("https://media.dior.com/couture/ecommerce/media/catalog/product/G/B/1676656893_327M34A3332_X1700_E01_ZHC.jpg?imwidth=1080") == -1);

	delete service;
	delete[] cart->getVector()->elements;
	delete cart->getVector();
	delete cart;
	delete repository;
}


void test_updateService()
{
	Repository* repository = new Repository();
	repository->populate();
	ShoppingCart* cart = new ShoppingCart();
	Service* service = new Service(repository, cart);

	assert(service->addService(TrenchCoat(36, "Beige", 21275, 100, "dgsdg")) == 1);
	assert(service->updateService("dgsdg", 34, "lila", 123, 123) == 1);
	assert(service->updateService("notexist", 34, "lila", 356, 355) == -1);

	delete service;
	delete[] cart->getVector()->elements;
	delete cart->getVector();
	delete cart;
	delete repository;
}


void allTests()
{
	test_addService();
	test_removeService();
	test_updateService();
}

