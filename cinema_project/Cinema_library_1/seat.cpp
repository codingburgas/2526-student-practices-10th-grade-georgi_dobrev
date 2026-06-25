#include "seat.h"

Seat::Seat(int s, int r, seatType t) :seatNumber(s), row(r), type(t)
{

}

seatType Seat::getType()
{
	return type;
}

double Seat::getPrice()
{
	switch(type)
	{ 
	case seatType::silver:
		return 5.00;

	case seatType::gold:
		return 8.00;

	case seatType::platinum:
		return 10.00;
	default:
		return 0.00;
	}
}