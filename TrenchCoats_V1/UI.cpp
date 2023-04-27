#include "UI.h"
#include <iostream>
#include <Windows.h>


using namespace std;


// print functions 
void printSelectModeMenu()
{
	cout << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MODE SELECTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	cout << ("1. To continue as an administrator, press 1.\n");
	cout << ("2. To continue as an administrator, press 2.\n");
	cout << ("*. To exit, press 0.\n\n\n");
}


void printAdminMenu()
{
	cout << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	cout << ("1. To see all coats, press 1.\n");
	cout << ("2. To add a new coat, press 2.\n");
	cout << ("3. To remove a coat, press 3.\n");
	cout << ("4. To update the information about a coat, press 4.\n");
	cout << ("*. To exit, press 0.\n\n\n");
}


void printUserMenu()
{
	cout << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	cout << ("1. To see all coats of a given size, press 1.\n");
	cout << ("2. To see the shopping basket and the total price of the items, press 2.\n");
	cout << ("*. To exit, press 0.\n\n\n");
}


void printCartMenu()
{
	cout << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SHOPPING CART ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	cout << ("1. If you want to add this item to your shopping cart, press 1.\n");
	cout << ("2. To move to the next one, press 2.\n");
	cout << ("*. To return, press 0.\n\n\n");
}


void play(string link)
{
	// we use Microsoft Edge to open the photos which are saved as links
	// from the cart, we get the element on the postion of the current index and get the photo
	// the photo ( saved as a string ) to to an array that contains a null-terminated sequence of characters 
	//																(i.e., a C-string, or const char*) 
	// after the shell is executed, a window is opened in a maximized form
	ShellExecuteA(NULL, NULL, "msedge.exe", link.c_str(), NULL, SW_SHOWMAXIMIZED);
}


void UI::printAllCoats()
{
	Repository* coats = this->service->getRepo();
	int length = coats->getRepositorySize();
	for (int i = 0; i < length; i++)
	{
		TrenchCoat coat = coats->getTrenchCoatsFromRepo().at(i);
		cout << coat.getPhotograph() << "\ncolor: " << coat.getColor() << "\nsize: " << coat.getSize();
		cout << "\nprice: " << coat.getPrice() << "\nquantity: " << coat.getQuantity() <<"\n\n";
	}
	cout << "\n\n";
}




//Validators
bool validSize(int size)
{
	if (size % 2 == 0 && size >= 32 && size <= 52)
	{
		return true;
	}
	return false;
}



bool validString(string input)
{
	int length = input.length();
	for (int i = 0; i < length; i++)
	{
		if (isdigit(input[i]))
		{
			return false;
		}
	}
	return true;
}


bool validColor(string color)
{
	int length = color.length();
	if (length < 3 || length > 15)
	{
		return false;
	}
	if (validString(color))
	{
		return true;
	}
	return false;
}


bool validQuantity(int q)
{
	if (q < 0)
	{
		return false;
	}
	return true;
}


bool validLink(string link)
{
	return false;
}


bool validPrice(int price)
{
	if (price < 30 || price > 99999)
	{
		return false;
	}
	return true;
}




//menu-running functions
void UI::runAdminMenu()
{
	int option = 1;
	while (option)
	{
		printAdminMenu();
		cout << "option : ";
		cin >> option;
		if (option == 1)
		{
			this->printAllCoats();
		}
		else if (option == 2)
		{
			this->addUI();
		}
		else if (option == 3)
		{
			this->deleteUI();
		}
		else if (option == 4)
		{
			this->updateUI();
		}
		else if (option == 0)
		{
			cout << "You no longer have admin rights.\n\n\n";
		}
		else
		{
			cout << "Incorrect option!!!\n";
		}
	}
}


void UI::runUserMenu()
{
	ShoppingCart* final_list = new ShoppingCart();

	//the total sum of the purchases
	int sum = 0;

	int option = 1;
	while (option)
	{
		printUserMenu();
		cout << "option : ";
		cin >> option;
		if (option == 1)
		{
			int size;
			cout << "Introduce the size (0 if you want to see all coats): ";
			cin >> size;
			while (((size % 2 == 0 && size >= 32 && size <= 52) || (size == 0)) == false)
			{
				cout << "The size is not correct!\n ";
				cout << "Introduce the size (0 if you want to see all coats): ";
				cin >> size;
			}

			// creating a new cart and initializing it with the specified coats
			// the function getBySize creates that cart
			ShoppingCart* list = this->service->getBySize(size);

			//this keeps the list going
			bool done = false;

			while (!done)
			{
				//get current coat using the current index
				int index = list->getCurrentIndex();
				TrenchCoat coat = list->getCoatFromList(index);
				string link = coat.getPhotograph();

				//open the link
				play(link);

				//print current coat
				cout << coat.getPhotograph() << "\ncolor: " << coat.getColor() << "\nsize: " << coat.getSize();
				cout << "\nprice: " << coat.getPrice() << "\nquantity: " << coat.getQuantity() << "\n\n\n";

				printCartMenu();
				int option2 = 1;
				cout << "Introduce your option:";
				cin >> option2;

				if (option2 == 1)
				{
					// go to the next item
					list->next();

					//add a copy of the element to the shopping cart
					//elements cand be added more than once
					final_list->addTrenchCoatToCart(TrenchCoat(coat));
					//to change this, we should modify the addTrenchCoatToCart function to check for shared links
					//there is a modified version in Service.cpp, in case we want to add each item just once, uniquely
					

					//display the sum after updating it
					sum += coat.getPrice();
					cout << "Yay! You added a new item to your cart!\n";
					cout << "          -total sum : " << sum << "\n\n\n";
				}
				else if (option2 == 2)
				{
					//go to the next item
					list->next();
					cout << "          -total sum : " << sum << "\n\n\n";
				}
				else if (option2 == 0)
				{
					done = true;
				}
				else
				{
					cout << "Invalid option!!!";
				}

			}
			
			//deleting the temporary filtered list used from browsing from memory
			delete[] list->getVector()->elements;
			delete list->getVector();
			delete list;
		}
		else if (option == 2)
		{
			cout << "All the items in your cart cost " << sum << ".\n\n";
			int length = final_list->getCartLength();
			for (int i = 0; i < length; i++)
			{
				TrenchCoat coat = final_list->getCoatFromList(i);
				cout << coat.getPhotograph() << "\ncolor: " << coat.getColor() << "\nsize: " << coat.getSize();
				cout << "\nprice: " << coat.getPrice() << "\nquantity: " << coat.getQuantity() << "\n\n";
			}
			cout << "\n\n";

		}
		else if (option == 0)
		{
			cout << "You will be redirected to role selection.\n\n\n";
		}
		else
		{
			cout << "Incorrect option!!!\n";
		}
	}
	//deleting the shopping cart from memory
	delete[] final_list->getVector()->elements;
	delete final_list->getVector();
	delete final_list;
}


void UI::displayCoats(ShoppingCart* final_list, int& sum)
{
	int size;
	cout << "Introduce the size (0 if you want to see all coats): ";
	cin >> size;
	while (((size % 2 == 0 && size >= 32 && size <= 52) || (size == 0)) == false)
	{
		cout << "The size is not correct!\n ";
		cout << "Introduce the size (0 if you want to see all coats): ";
		cin >> size;
	}

	// creating a new cart and initializing it with the specified coats
	ShoppingCart* list = new ShoppingCart(); 
	list = this->service->getBySize(size);
	//this keeps the list going
	bool done = false;

	while (!done)
	{
		//get current coat using the current index
		int index = list->getCurrentIndex();
		TrenchCoat coat = list->getCoatFromList(index);
		string link = coat.getPhotograph();

		//open the link
		list->play();
		
		//print current coat
		cout << coat.getPhotograph() << "\ncolor: " << coat.getColor() << "\nsize: " << coat.getSize();
		cout << "\nprice: " << coat.getPrice() << "\nquantity: " << coat.getQuantity() << "\n\n\n";

		printCartMenu();

		int option;
		cout << "Introduce your option:";
		cin >> option;

		if (option == 1)
		{
			// go to the next item
			list->next();
			final_list->addTrenchCoatToCart(coat);

			//display the sum after updating it
			sum += coat.getPrice();
			cout << "Yay! You added a new item to your cart!\n";
			cout << "          -total sum : " << sum << "\n\n\n";
		}
		else if (option == 2)
		{
			//go to the next item
			list->next();
			cout << "          -total sum : " << sum << "\n\n\n";
		}
		else if (option == 0)
		{
			done = true;
		}
		else
		{
			cout << "Invalid option!!!";
		}

	}
}


void UI::runMenu()
{
	int option = 1;
	while (option != 0)
	{
		printSelectModeMenu();
		cout << "option : ";
		cin >> option;
		if (option == 1)
		{
			runAdminMenu();
		}
		else if (option == 2)
		{
			runUserMenu();
		}
		else if (option == 0)
		{
			cout << "The app is closing.\n";
		}
		else
		{
			cout << "Incorrect option!!!\n";
		}
	}
}


//admin functions
void UI::addUI()
{
	string link;
	int size_new;
	string color_new;
	int price_new;
	int quantity_new;

	cout << "Introduce a link to the trench coat's photograph: ";
	cin >> link;

	if (this->service->findInRepoService(link) != -1)
	{
		cout << "The coat couldn't be added because it already exists.\n";
	}
	else
	{
		cout << "Introduce the size: ";
		cin >> size_new;
		while (validSize(size_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the size: ";
			cin >> size_new;
		}

		cout << "Introduce the color: ";
		cin >> color_new;
		while (validColor(color_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the color: ";
			cin >> color_new;
		}

		cout << "Introduce the price: ";
		cin >> price_new;
		while (validPrice(price_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the price: ";
			cin >> price_new;
		}

		cout << "Introduce the quantity: ";
		cin >> quantity_new;
		while (validQuantity(quantity_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the quantity: ";
			cin >> quantity_new;
		}

		int result = this->service->addService(TrenchCoat(size_new, color_new, price_new, quantity_new, link));

		if (result != -1)
		{
			cout << "The coat was added to the database.\n";
		}
		else
		{
			cout << "The coat couldn't be added.\n";
		}
	}
}


void UI::deleteUI()
{
	string link;

	cout << "Introduce a link to the trench coat's photograph: ";
	cin >> link;

	if (this->service->findInRepoService(link) == -1)
	{
		cout << "The coat doesn't exist.\n";
	}
	else
	{
		int result = this->service->removeService(link);

		if (result == 1)
		{
			cout << "The coat was deleted from the database.\n";
		}
		else
		{
			cout << "The coat couldn't be deleted.\n";
		}
	}
}


void UI::updateUI()
{
	string link, new_link;
	int size_new;
	string color_new;
	int price_new;
	int quantity_new;

	cout << "Introduce a link to the trench coat's photograph: ";
	cin >> link;

	if (this->service->findInRepoService(link) == -1)
	{
		cout << "The coat doesn't exist.\n";
	}
	else
	{
		cout << "Introduce the size: ";
		cin >> size_new;
		while (validSize(size_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the size: ";
			cin >> size_new;
		}

		cout << "Introduce the color: ";
		cin >> color_new;
		while (validColor(color_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the color: ";
			cin >> color_new;
		}

		cout << "Introduce the price: ";
		cin >> price_new;
		while (validPrice(price_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the price: ";
			cin >> price_new;
		}

		cout << "Introduce the quantity: ";
		cin >> quantity_new;
		while (validQuantity(quantity_new) == false)
		{
			cout << "Invalid input!\n";
			cout << "Introduce the quantity: ";
			cin >> quantity_new;
		}

		int result = this->service->updateService(link, size_new, color_new, price_new, quantity_new);

		if (result != -1)
		{
			cout << "The coat was updated.\n";
		}
		else
		{
			cout << "The coat couldn't be updated.\n";
		}
	}
}



//User functions




