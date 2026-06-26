#pragma once

#include "../Cinema_library_1/cinemaSystem.h"

class ConsoleMenu {
public:
    
    void run();

private:
   
    void adminMenu(CinemaSystem& system);
    void customerMenu(CinemaSystem& system);
};
