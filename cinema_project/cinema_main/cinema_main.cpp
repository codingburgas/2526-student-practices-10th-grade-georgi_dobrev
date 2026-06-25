#include <iostream>
#include <string>
#include <vector>
#include "../Cinema_library_1/cinemaSystem.h"


void handleAdminMenu(CinemaSystem& system);
void handleCustomerMenu(CinemaSystem& system);

int main() {
    
    CinemaSystem system;
    int mainChoice = 0;

   
    while (mainChoice != 3) {
        std::cout << "\n====================================\n";
        std::cout << "    MOVIE TICKET BOOKING SYSTEM     \n";
        std::cout << "====================================\n";
        std::cout << "1. Login as Customer\n";
        std::cout << "2. Login as Administrator (Stage 4)\n";
        std::cout << "3. Exit Program\n";
        std::cout << "====================================\n";
        std::cout << "Enter your choice (1-3): ";
        std::cin >> mainChoice;
        std::cin.ignore(); 

        switch (mainChoice) {
        case 1:
            handleCustomerMenu(system);
            break;
        case 2:
            handleAdminMenu(system);
            break;
        case 3:
            std::cout << "\nThank you for using our system. Goodbye!\n";
            break;
        default:
            std::cout << "\nInvalid choice! Please select 1, 2, or 3.\n";
            break;
        }
    }
    return 0;
}

void handleCustomerMenu(CinemaSystem& system) {
    int choice = 0;
    while (choice != 3) {
        std::cout << "\n--- CUSTOMER INTERFACE ---\n";
        std::cout << "1. View All Available Movies\n";
        std::cout << "2. Search Movies (Requirement R4)\n";
        std::cout << "3. Back to Main Menu\n";
        std::cout << "Enter choice (1-3): ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::vector<Movie> allMovies = system.getMovies();
            std::cout << "\nAvailable Movies in Database:\n";
            if (allMovies.empty()) {
                std::cout << "[No movies available]\n";
            }
            else {
                for (auto& movie : allMovies) {
                    std::cout << "- " << movie.getName() << " [Genre: " << movie.getGenre() << "]\n";
                }
            }
        }
        else if (choice == 2) {
            std::string title, genre;
            std::string language = "";    
            std::string releaseDate = ""; 

            std::cout << "\nEnter movie title to search (or press Enter to skip): ";
            std::getline(std::cin, title);

            std::cout << "Enter genre to search (or press Enter to skip): ";
            std::getline(std::cin, genre);

            std::vector<Movie> foundMovies = system.searchMovies(title, language, genre, releaseDate);

            std::cout << "\nSearch Results:\n";
            if (foundMovies.empty()) {
                std::cout << "No movies match your criteria.\n";
            }
            else {
                for (auto& movie : foundMovies) {
                    std::cout << "-> " << movie.getName() << " (Genre: " << movie.getGenre() << ")\n";
                }
            }
        }
    }
}


void handleAdminMenu(CinemaSystem& system) {
    int choice = 0;
    while (choice != 3) {
        std::cout << "\n--- ADMINISTRATOR PANEL (Stage 4) ---\n";
        std::cout << "1. Add a New Movie (Requirement R12)\n";
        std::cout << "2. Delete a Movie (Requirement R12)\n";
        std::cout << "3. Back to Main Menu\n";
        std::cout << "Enter choice (1-3): ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string title, genre, language;
            int duration;

            std::cout << "\nEnter movie title: ";
            std::getline(std::cin, title);

            std::cout << "\nEnter movie language: ";
            std::getline(std::cin, language);

            std::cout << "Enter movie genre: ";
            std::getline(std::cin, genre);

            std::cout << "Enter duration (in minutes): ";
            std::cin >> duration;
            std::cin.ignore();

           
           
            Movie newMovie(title,language, genre, duration);
            system.addMovie(newMovie);

            std::cout << "\n[Success] Movie \"" << title << "\" has been added to the system database.\n";
        }
        else if (choice == 2) {
            std::string title;
            std::cout << "\nEnter the exact title of the movie to delete: ";
            std::getline(std::cin, title);

            system.deleteMovie(title);
            std::cout << "\n[Processed] Delete action completed for: " << title << "\n";
        }
    }
}
