#include<iostream>
#include"LoginService.h"


void displayMenu()
{
	std::cout << "Menu:" << std::endl;
	std::cout << "1: Enter as user" << std::endl;
	std::cout << "2: Enter as admin" << std::endl;
	std::cout << "0: Exit" << std::endl;
	std::cout << "Enter your choice: " << std::endl;
}

void first_menu(int choice)
{
	switch (choice)
	{
	case 1: {
		std::string username1, password1;
		std::cout << "Enter username: ";
		std::cin >> username1;

		std::cout << "Enter password: ";
		std::cin >> password1;
		LoginPage(username1, password1);

		break;
	}

	case 2:

		break;

	case 0:

		break;

	default: 
		std::cout << "Incorrect input. Try again." << std::endl;
	}
}