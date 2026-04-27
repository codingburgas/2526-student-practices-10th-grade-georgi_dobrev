#include<iostream>
#include <string>
#include"LoginService.h"

void LoginPage(std::string username, std::string password)
{
	LoginService loginService;

	User* user = loginService.login(username, password);

	if (user != nullptr && user->getRole() == "user")
	{
		std::cout << "Welcome, user!\n";
	}
	else
	{
		std::cout << "Invalid login or not a user\n";
	}

}