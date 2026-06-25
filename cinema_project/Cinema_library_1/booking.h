#pragma once
#include<string>
#include<vector>
#include"showtime.h"

class Booking
{
private:
	Show show;
	std::string customerName;
	std::vector<int> selectedSeats;
	double totalPrice;
	std::string paymentMethod;
	bool isConfirmed;

public:
	Booking(Show& s, std::string name, std::vector<int>seats, double price, std::string payment);

	void confirmBooking();


	Show getShow();
	std::string getCustomerName();
	std::vector<int> getSelectedSeats();
	double getTotalPrice();
	std::string getPaymentMethod();
	bool getIsConfirmed();
};