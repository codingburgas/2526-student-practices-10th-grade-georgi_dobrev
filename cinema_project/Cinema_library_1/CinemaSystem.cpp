#include "CinemaSystem.h"
#include <iostream>

void seedInitialData(std::vector<Cinema>& cinemas) {
    Movie m1 = { "Матрицата", "Английски", "Научна фантастика", "1999" };
    Movie m2 = { "Гладиатор", "Английски", "Драма", "2000" };
    Movie m3 = { "Замръзналото кралство", "Български", "Анимация", "2013" };

    Cinema c1;
    c1.name = "Кино Арена Мол";
    c1.city = "София";
    c1.halls = { {"Зала 1"}, {"Зала 2 IMAX"} };
    c1.shows = { {m1, "18:00", "Зала 1"}, {m2, "21:00", "Зала 2 IMAX"} };

    Cinema c2;
    c2.name = "Синема Сити";
    c2.city = "Пловдив";
    c2.halls = { {"Зала А"}, {"Зала Б"} };
    c2.shows = { {m1, "14:00", "Зала А"}, {m3, "16:30", "Зала Б"} };

    cinemas.push_back(c1);
    cinemas.push_back(c2);
}


void printAllCinemas(const std::vector<Cinema>& cinemas) {
    for (const auto& cinema : cinemas) {
        std::cout << "\n=== КИНО: " << cinema.name << " (" << cinema.city << ") ===\n";
        std::cout << "Прожекции днес:\n";
        if (cinema.shows.empty()) {
            std::cout << "  Няма налични прожекции.\n";
        }
        for (const auto& show : cinema.shows) {
            std::cout << "  - [" << show.time << "] " << show.movie.title
                << " | Жанр: " << show.movie.genre
                << " | Език: " << show.movie.language
                << " (" << show.hallName << ")\n";
        }
    }
}


void searchMoviesInCinemas(const std::vector<Cinema>& cinemas, int criteria, const std::string& query) {
    bool found = false;
    std::cout << "\n--- Резултати от търсенето ---\n";

    for (const auto& cinema : cinemas) {
        for (const auto& show : cinema.shows) {
            bool match = false;
            if (criteria == 1 && show.movie.title == query) match = true;
            else if (criteria == 2 && show.movie.language == query) match = true;
            else if (criteria == 3 && show.movie.genre == query) match = true;
            else if (criteria == 4 && show.movie.releaseDate == query) match = true;

            if (match) {
                std::cout << "Филм: \"" << show.movie.title << "\" се прожектира в "
                    << cinema.name << " (" << cinema.city << ") в " << show.time << " часа.\n";
                found = true;
            }
        }
    }
    if (!found) {
        std::cout << "Не бяха намерени прожекции по този критерий.\n";
    }
}


bool addBooking(Cinema& cinema, int showIndex, CustomerType custType, PaymentMethod payMethod) {
    if (custType == CustomerType::Online && payMethod == PaymentMethod::Cash) {
        std::cout << "\n[ГРЕШКА] Онлайн клиентите не могат да плащат в брой (Правило R7)!\n";
        return false;
    }

    if (showIndex < 0 || showIndex >= static_cast<int>(cinema.shows.size())) {
        std::cout << "\n[ГРЕШКА] Невалиден номер на прожекция!\n";
        return false;
    }

    Show selectedShow = cinema.shows[showIndex];

    Booking newBooking;
    newBooking.movieTitle = selectedShow.movie.title;
    newBooking.showTime = selectedShow.time;
    newBooking.customerType = custType;
    newBooking.paymentMethod = payMethod;

    cinema.bookings.push_back(newBooking);

    std::cout << "\n[УСПЕХ] Резервацията за \"" << selectedShow.movie.title << "\" беше направена успешно!\n";
    return true;
}


void printAllBookings(const std::vector<Cinema>& cinemas) {
    std::cout << "\n--- АРХИВ РЕЗЕРВАЦИИ ---\n";
    bool anyBookings = false;

    for (const auto& cinema : cinemas) {
        for (const auto& b : cinema.bookings) {
            anyBookings = true;
            std::cout << "Кино: " << cinema.name << " | Филм: " << b.movieTitle << " | Час: " << b.showTime << " | Тип: ";
            std::cout << (b.customerType == CustomerType::Online ? "Онлайн" : "На каса");
            std::cout << " | Плащане: " << (b.paymentMethod == PaymentMethod::Cash ? "В брой" : "Карта") << "\n";
        }
    }
    if (!anyBookings) {
        std::cout << "Няма направени резервации все още.\n";
    }
}