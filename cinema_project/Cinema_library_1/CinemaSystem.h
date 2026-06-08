#pragma once
#include <string>
#include <vector>

// Перечисления за бизнес логиката (Етап 2)
enum class CustomerType { Online, WalkIn };
enum class PaymentMethod { Cash, CreditCard };

// Структура за Резервация
struct Booking {
    std::string movieTitle;
    std::string showTime;
    CustomerType customerType;
    PaymentMethod paymentMethod;
};

// Структура за Филм
struct Movie {
    std::string title;
    std::string language;
    std::string genre;
    std::string releaseDate;
};

// Структура за Прожекция
struct Show {
    Movie movie;
    std::string time;
    std::string hallName;
};


struct Hall {
    std::string name;
};


struct Cinema {
    std::string name;
    std::string city;
    std::vector<Hall> halls;
    std::vector<Show> shows;
    std::vector<Booking> bookings;
};


void seedInitialData(std::vector<Cinema>& cinemas);
void printAllCinemas(const std::vector<Cinema>& cinemas);
void searchMoviesInCinemas(const std::vector<Cinema>& cinemas, int criteria, const std::string& query);
bool addBooking(Cinema& cinema, int showIndex, CustomerType custType, PaymentMethod payMethod);
void printAllBookings(const std::vector<Cinema>& cinemas);