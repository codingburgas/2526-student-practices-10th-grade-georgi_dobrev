#include <iostream>
#include <string>
#include"movie.h"


Movie::Movie(std::string n, std::string l, std::string g, int d):name(n), language(l), genre(g), duration(d)
{

}

std::string Movie::getName()
{
	return name;
}

std::string Movie::getLanguage()
{
	return language;
}

std::string Movie::getGenre()
{
	return genre;
}

int Movie::getDuration()
{
	return duration;
}