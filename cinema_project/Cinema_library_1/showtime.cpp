#include "showtime.h"


Show::Show(const Movie& m, const Hall& h, std::string t) : movie(m), hall(h), time(t)
{
    
}


Movie Show::getMovie()
{
    return movie;
}

Hall Show::getHall()
{
    return hall;
}

std::string Show::getTime()
{
    return time;
}
