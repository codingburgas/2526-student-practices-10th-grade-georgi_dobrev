#pragma once
#include <string>
#include<vector>

class User
{
private:
	std::string username;
	std::string password;
	std::string role;
public:
	User(std::string username, std::string password, std::string role);

	std::string getUsername();
	std::string getPassword();
	std::string getRole();
};

class LoginService
{
private:
	std::vector<User> users;

public:
	LoginService();

	bool registerUser(const std::string& username, const std::string& password, const std::string& role);
	User* login(const std::string& username, const std::string& password);
};


void LoginPage(std::string username, std::string password)
{

};