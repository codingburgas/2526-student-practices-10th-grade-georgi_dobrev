#include "cinemaSystem.h"
#include <iostream>
#include <vector>
#include<string>
#include"movie.h"
#include"cinema.h"
#include"showtime.h"

CinemaSystem::CinemaSystem() {
    
    loadTestData();
}

void CinemaSystem::loadTestData() {
   
  
    movies.push_back(Movie("The Matrix","English", "Sci-Fi", 136));
    movies.push_back(Movie("Inception", "English", "Sci-Fi", 148));
    movies.push_back(Movie("Avatar", "Bulgarian", "Action", 162));

    
    Cinema c1("Cinema City", "Burgas");
    Hall h1(1, 100);
    Hall h2(2, 120);
    c1.addHall(h1);
    c1.addHall(h2);

    cinemas.push_back(c1);
}

std::vector<Movie> CinemaSystem::searchMovies(std::string title, std::string language, std::string genre, std::string releaseDate)
{
    std::vector<Movie> results;

    for (auto& movie : movies) {
        
       
        bool matchTitle = (title == "" || movie.getName() == title);
        bool matchGenre = (genre == "" || movie.getGenre() == genre);

        
        bool matchLanguage = true;
        bool matchDate = true;  

        if (matchTitle && matchGenre && matchLanguage && matchDate) {
            results.push_back(movie);
        }
    }

    return results;
}

std::vector<Cinema> CinemaSystem::getCinemas()
{
    return cinemas;
}
std::vector<Movie> CinemaSystem::getMovies()
{
    return movies;
}

void CinemaSystem::addMovie(Movie& newMovie) 
{
    movies.push_back(newMovie);
}

void CinemaSystem::deleteMovie(std::string title) 
{
    for (size_t i = 0; i < movies.size(); ++i) {
        if (movies[i].getName() == title) {
            movies.erase(movies.begin() + i);
            break;
        }
    }
}






bool CinemaSystem::bookTicket(int showIndex, int seatNumber, std::string& customerName) {
    
    if (showIndex < 0 || showIndex >= showtimes.size()) {
        std::cout << "Error: Invalid showtime selection!\n";
        return false;
    }

   
    Show& selectedShow = showtimes[showIndex];

    
    if (selectedShow.isSeatBooked(seatNumber)) {
        std::cout << "\n[RESERVATION FAILED] Seat " << seatNumber << " is already taken by another customer!\n";
        return false;
    }

    
    double ticketPrice = 0.0;
    std::string seatType = "";

    if (seatNumber <= 10) {
        ticketPrice = 10.00; 
        seatType = "Silver";
    }
    else if (seatNumber <= 20) {
        ticketPrice = 15.00; 
        seatType = "Gold";
    }
    else {
        ticketPrice = 20.00;
        seatType = "Platinum";
    }

    
    selectedShow.reserveSeat(seatNumber);

    
    std::cout << "\n========================================\n";
    std::cout << "       BOOKING CONFIRMED SUCCESSFULLY    \n";
    std::cout << "========================================\n";
    std::cout << "Passenger/Customer: " << customerName << "\n";
    std::cout << "Seat Number: " << seatNumber << " (" << seatType << " Class)\n";
    std::cout << "Total Ticket Price: $" << ticketPrice << "\n";
    std::cout << "----------------------------------------\n";
    std::cout << "[NOTIFICATION Service]: Booking email confirmation dispatched to " << customerName << "@cinema.com\n";
    std::cout << "========================================\n";

    return true;
}


