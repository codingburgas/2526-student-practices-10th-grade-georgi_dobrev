#include "booking.h"


Booking::Booking( Show& s, std::string name, std::vector<int> seats, double price, std::string payment)
    : show(s), customerName(name), selectedSeats(seats), totalPrice(price), paymentMethod(payment), isConfirmed(false)
{
}

void Booking::confirmBooking() {
    isConfirmed = true; 
}


Show Booking::getShow()
{ 
    return show; 
}

std::string Booking::getCustomerName()
{ 
    return customerName; 
}

std::vector<int> Booking::getSelectedSeats()
{
    return selectedSeats;
}

double Booking::getTotalPrice()
{ 
    return totalPrice;
}

std::string Booking::getPaymentMethod()
{ 
    return paymentMethod;
}

bool Booking::getIsConfirmed()
{ 
    return isConfirmed;
}
