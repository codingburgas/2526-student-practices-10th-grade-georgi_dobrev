#pragma once


class Hall
{
private:
	int hallNumber;
	int seatNumber;

public:
	Hall(int hallNumber, int seatNumber);

	int getHallNumber();
	int getSeatNumber();

};