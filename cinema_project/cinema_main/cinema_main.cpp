
#include <iostream>
#include "../Cinema_library_1/menu.h"
#include "../Cinema_library_1/LoginService.h"

int main()
{
	displayMenu();
	int choice;
	std::cin >> choice;
	first_menu(choice);


}

