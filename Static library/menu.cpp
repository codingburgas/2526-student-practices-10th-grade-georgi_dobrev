#include<iostream>
#include"menu.h"

using namespace std;

void RunMenu(int choice)
{
    

    while (choice != 0)
    {
        std::cout << "\n=== CINEMA SYSTEM ===\n";
        std::cout << "1. Customer\n";
        std::cout << "2. Admin\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";

        

        if (choice == 1)
        {
            std::cout << "Customer menu (stub)...\n";
        }
        else if (choice == 2)
        {
            std::cout << "Admin menu (stub)...\n";
        }
        else if (choice == 0)
        {
            std::cout << "Exiting...\n";
        }
        else
        {
            std::cout << "Invalid choice.\n";
        }
    }
}