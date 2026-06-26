#pragma once

#include <string>
#include "movie.h" 
#include "hall.h"  
#include<vector>

class Show 
{
private:
    Movie movie;       
    Hall hall;         
    std::string time;

    std::vector<int> bookedSeats;

public:
    
    Show(const Movie& m, const Hall& h, std::string t);

    
    Movie getMovie();

    Hall getHall();

    std::string getTime();



    bool isSeatBooked(int seatNumber) 
    {
        for (int seat : bookedSeats) {
            if (seat == seatNumber) return true;
        }
        return false;
    }

    
    void reserveSeat(int seatNumber) 
    {
        bookedSeats.push_back(seatNumber);
    }
};
