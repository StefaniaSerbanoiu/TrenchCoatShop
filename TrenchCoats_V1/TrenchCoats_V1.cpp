#include <iostream>
#include "UI.h"
#include "Tests.h"
#define _CRTDBG_MAP_ALLOC


int main()
{
    //allTests();

    Repository* repository = new Repository();
    repository->populate();
    ShoppingCart* cart = new ShoppingCart();
    Service* service = new Service(repository, cart);
    UI* ui = new UI(service);
    ui->runMenu();
    
    delete ui;
    delete service;
    delete[] cart->getVector()->elements;
    delete cart->getVector();
    delete cart;
    delete repository;

    _CrtDumpMemoryLeaks();
}

