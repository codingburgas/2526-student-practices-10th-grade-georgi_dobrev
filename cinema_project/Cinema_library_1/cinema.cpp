#include"cinema.h"
#include<string>
#include<vector>

Cinema::Cinema(std::string n, std::string c) :cinemaName(n), cityName(c)
{

}

std::string Cinema::getCinemaName()
{
	return cinemaName;
}

std::string Cinema::getCityName()
{
	return cityName;
}

void Cinema::addHall(Hall& newHall)
{
	halls.push_back(newHall); 
}

std::vector<Hall> Cinema::getHalls() 
{
	return halls;
}
