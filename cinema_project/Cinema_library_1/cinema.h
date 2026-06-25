#pragma once
#include<string>
#include <vector>
#include "hall.h"

class Cinema
{
private:
	std::string cinemaName;
	std::string cityName;

	std::vector<Hall>halls;

public:
    std::string getCinemaName();
    std::string getCityName();

    Cinema(std::string cinemaName, std::string cityName);
    
    void addHall(Hall& newHall);

    std::vector<Hall> getHalls();


};