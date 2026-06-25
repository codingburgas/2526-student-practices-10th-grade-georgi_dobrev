#pragma once
enum class seatType
{
	silver,
	gold,
	platinum

};

class Seat
{
private:
	int seatNumber;
	int row;
	seatType type;
	bool isBooked;

public:
	Seat(int s, int r, seatType t);

	seatType getType();
	double getPrice();

};