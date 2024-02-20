#ifndef RESERVAITION_h
#define RESERVAITION_h
#include <vector>
#include <iostream>

using namespace std;

//경기 예매 클래스
class Reservation
{
public:
    bool GameReservation();
    int SeatReservation();
    bool CashReservation();
};


#endif