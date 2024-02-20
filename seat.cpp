#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Seat {
public:
    string grade;
    float price;
    bool isBooked;

    Seat(string g, float p) : grade(g), price(p), isBooked(false) {}

    void bookSeat() {
        if (!isBooked) {
            isBooked = true;
            cout << "Seat booked successfully! Price: " << price << endl;
        } else {
            cout << "Seat is already booked." << endl;
        }
    }
};

class Auditorium {
private:
    vector<vector<Seat>> seats;
    map<string, float> priceMap;

public:
    Auditorium() {
        priceMap["MVIP"] = 200.0;
        priceMap["VIP"] = 150.0;
        priceMap["GOLD"] = 100.0;
        priceMap["SILVER"] = 50.0;

        // 예를 들어 5x5 좌석 배열 생성
        for (int i = 0; i < 5; i++) {
            vector<Seat> row;
            for (int j = 0; j < 5; j++) {
                string grade = (i == 0) ? "MVIP" : (i == 1) ? "VIP" : (i < 4) ? "GOLD" : "SILVER";
                row.push_back(Seat(grade, priceMap[grade]));
            }
            seats.push_back(row);
        }
    }

    void bookSeat(int row, int col) {
        if (row < seats.size() && col < seats[0].size()) {
            seats[row][col].bookSeat();
        } else {
            cout << "Invalid seat selection." << endl;
        }
    }

    // 좌석 배열 표시 함수 (콘솔용)
    void displaySeats() {
        for (int i = 0; i < seats.size(); i++) {
            for (int j = 0; j < seats[i].size(); j++) {
                if (seats[i][j].isBooked) {
                    cout << "[X] ";
                } else {
                    cout << "[ ] ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Auditorium auditorium;
    auditorium.displaySeats();
    auditorium.bookSeat(0, 0); // MVIP 좌석 예약
    auditorium.displaySeats();
    return 0;
}