#pragma once

#include <string>
#include "movie.h" 
#include "hall.h"  

class Show 
{
private:
    Movie movie;       
    Hall hall;         
    std::string time;

public:
    
    Show(const Movie& m, const Hall& h, std::string t);

    
    Movie getMovie();

    Hall getHall();

    std::string getTime();
};
