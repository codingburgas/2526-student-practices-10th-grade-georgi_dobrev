#pragma once
#pragma once
#include <vector>
#include <string>
#include "Movie.h"
#include "Cinema.h"
#include "showtime.h"

class CinemaSystem {
private:
    std::vector<Movie> movies;   
    std::vector<Cinema> cinemas; 

public:

    
    void addMovie(Movie& newMovie);
    void deleteMovie(std::string title);
    

   
    CinemaSystem();

   
    void loadTestData();

    
   
    std::vector<Movie> searchMovies(std::string title, std::string language, std::string genre, std::string releaseDate);

   
    std::vector<Cinema> getCinemas();
    std::vector<Movie> getMovies();
};
