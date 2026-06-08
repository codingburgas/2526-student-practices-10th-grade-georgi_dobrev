#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

#include "../Cinema_library_1/CinemaSystem.h" 

int main() {
    
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::vector<Cinema> database;
    seedInitialData(database);

    int choice = 0;
    while (choice != 4) {
        std::cout << "\n===============================\n";
        std::cout << "   СИСТЕМА ЗА КИНО БИЛЕТИ\n";
        std::cout << "===============================\n";
        std::cout << "1. Покажи всички кина и прожекции\n";
        std::cout << "2. Търси филм\n";
        std::cout << "3. Направи резервация\n";
        std::cout << "4. Изход\n";
        std::cout << "Изберете опция (1-4): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            printAllCinemas(database);
            break;

        case 2: {
            int crit = 0;
            std::cout << "\nИзберете критерий:\n1. Заглавие\n2. Език\n3. Жанр\n4. Година\nИзбор: ";
            std::cin >> crit;
            std::cout << "Въведете търсената дума: ";
            std::string query;
            std::cin.ignore();
            std::getline(std::cin, query);
            searchMoviesInCinemas(database, crit, query);
            break;
        }

        case 3: {
            std::cout << "\n--- ИЗБОР НА КИНО ---\n";
            for (size_t i = 0; i < database.size(); ++i) {
                std::cout << i << ". " << database[i].name << " (" << database[i].city << ")\n";
            }
            int cinemaIdx;
            std::cout << "Изберете номер на кино: ";
            std::cin >> cinemaIdx;

            if (cinemaIdx < 0 || cinemaIdx >= static_cast<int>(database.size())) {
                std::cout << "Невалидно кино.\n";
                break;
            }

            Cinema& selectedCinema = database[cinemaIdx];
            std::cout << "\n--- ИЗБОР НА ПРОЖЕКЦИЯ ---\n";
            for (size_t i = 0; i < selectedCinema.shows.size(); ++i) {
                std::cout << i << ". [" << selectedCinema.shows[i].time << "] " << selectedCinema.shows[i].movie.title << "\n";
            }
            int showIdx;
            std::cout << "Изберете номер на прожекция: ";
            std::cin >> showIdx;

            int custTypeInput;
            std::cout << "\nТип клиент (1. Онлайн / 2. На каса): ";
            std::cin >> custTypeInput;
            CustomerType cType = (custTypeInput == 1) ? CustomerType::Online : CustomerType::WalkIn;

            int payMethodInput;
            std::cout << "Метод на плащане (1. В брой / 2. С карта): ";
            std::cin >> payMethodInput;
            PaymentMethod pMethod = (payMethodInput == 1) ? PaymentMethod::Cash : PaymentMethod::CreditCard;

            
            addBooking(selectedCinema, showIdx, cType, pMethod);

            
            printAllBookings(database);
            break;
        }

        case 4:
            std::cout << "Излизане от програмата. Довиждане!\n";
            break;

        default:
            std::cout << "Невалиден избор. Опитайте пак.\n";
            break;
        }
    }
    return 0;
}