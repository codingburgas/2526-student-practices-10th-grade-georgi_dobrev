#pragma once
#include <string>
#include<iostream>

class Movie
{
private:
	std::string name;
	std::string language;
	std::string genre;
	int duration;

public:
	Movie(std::string n, std::string l, std::string genre, int duration);

	std::string getName();
	std::string getLanguage();
	std::string getGenre();
	int getDuration();


};