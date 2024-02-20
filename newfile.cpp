int main() 
{
    User user;
    AsianCup asianCup;
    MainMonitor monitor;
    GameSchedule schedul;
    Reservation reservation;
    bool loginSuccess = false;

    user.loadFromFile(); // 파일에서 사용자 정보 로드

    while (true) 
    {
        if (!loginSuccess) // 로그인 상태가 아닌 경우
        {
            monitor.DisplayMoniter();
            int choice;
            cout << "선택: ";
            cin >> choice;
            cin.ignore(); 

            switch (choice) 
            {
                case 1:
                    loginSuccess = user.login();
                    break;
                case 2:
                    user.join();
                    break;
                case 3:
                    user.find_id();
                    break;
                case 4:
                    user.find_pw();
                    break;
                case 5:
                    cout << "프로그램을 종료합니다." << endl;
                    return 0;
                default:
                    cout << "잘못된 선택입니다. 다시 시도해주세요." << endl;
                    break;
            }
        }
        else // 로그인 성공한 경우
        {
            while(schedul.ShowMenu()) // 경기 일정 보기 메뉴 반복
            {
                if(!reservation.GameReservation()) // 경기 선택 취소 시 메뉴로 돌아감
                {
                    break;
                }
                monitor.DisplayGameMoniter();
                reservation.SeatReservation();
            }
            loginSuccess = false; // 로그아웃 상태로 전환
        }
    }

    return 0;
}   


class Reservation
{
    // ... 기존 코드 ...
public:
    void SaveReservationInfo(const string& userId, const string& game, const string& seat);
    void LoadReservationInfo();
    void DisplayUserReservations(const string& userId);
private:
    map<string, pair<string, string>> userReservations; // 사용자 ID를 key로, 경기 및 좌석 정보를 value로 저장
};

void Reservation::SaveReservationInfo(const string& userId, const string& game, const string& seat)
{
    userReservations[userId] = make_pair(game, seat);

    ofstream file("reservations.txt", ios::app);
    if (file.is_open())
    {
        file << userId << " " << game << " " << seat << endl;
        file.close();
    }
}

void Reservation::LoadReservationInfo()
{
    ifstream file("reservations.txt");
    string userId, game, seat;

    if (file.is_open())
    {
        while (file >> userId >> game >> seat)
        {
            userReservations[userId] = make_pair(game, seat);
        }
        file.close();
    }
}

void Reservation::DisplayUserReservations(const string& userId)
{
    if (userReservations.find(userId) != userReservations.end())
    {
        cout << "경기: " << userReservations[userId].first << ", 좌석: " << userReservations[userId].second << endl;
    }
    else
    {
        cout << "예매 내역이 없습니다." << endl;
    }
}

// 메인 함수 내부
if (loginSuccess)
{
    // ... 기존 코드 ...
    cout << "6. 예매 확인하기" << endl;
    // ... 기존 코드 ...

    int choice;
    cin >> choice;

    switch (choice)
    {
        // ... 기존 코드 ...
        case 6:
            reservation.DisplayUserReservations(user.getCurrentUserId());
            break;
    }
}


// 예: Reservation 클래스 내 결제 및 예매 정보 저장 기능

class Reservation {
private:
    struct ReservationInfo {
        string userID;
        string gameInfo;
        string seatInfo;
        string paymentInfo;
    };

    vector<ReservationInfo> reservations;

public:
    void processPayment() {
        // 결제 정보 입력 및 처리
        // ...
        // 결제 성공 후 예매 정보 저장
        ReservationInfo info;
        info.userID = /* 현재 로그인한 사용자 ID */;
        info.gameInfo = /* 선택한 경기 정보 */;
        info.seatInfo = /* 선택한 좌석 정보 */;
        info.paymentInfo = /* 결제 정보 */;
        reservations.push_back(info);

        // 파일에 예매 정보 저장
        saveToFile(info);
    }

    void displayUserReservations(const string& userID) {
        // 사용자의 예매 정보 표시
        for (const auto& res : reservations) {
            if (res.userID == userID) {
                // res 정보 표시
            }
        }
    }

    // 파일 입출력 관련 함수
    // ...
};


#include <iostream>
// ... 다른 include 문들 ...

using namespace std;

// ... 클래스 정의들 (User, AsianCup 등) ...

int main() {
    User user;
    AsianCup asianCup;
    MainMonitor monitor;
    GameSchedule schedule;
    Reservation reservation;
    bool loginSuccess = false;

    user.loadFromFile(); 

    while (true) {
        if (!loginSuccess) {
            monitor.DisplayMoniter();
            int choice;
            cout << "선택: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    loginSuccess = user.login();
                    break;
                case 2:
                    user.join();
                    break;
                case 3:
                    user.find_id();
                    break;
                case 4:
                    user.find_pw();
                    break;
                case 5:
                    cout << "프로그램을 종료합니다." << endl;
                    return 0;
                default:
                    cout << "잘못된 선택입니다. 다시 시도해주세요." << endl;
                    break;
            }
        } else {
            if (!schedule.ShowMenu()) {
                loginSuccess = false;
                continue;
            }

            if (reservation.GameReservation()) {
                reservation.SeatReservation();
                reservation.processPayment(); // 결제 처리 함수 호출

                char checkReservations;
                cout << "예매한 티켓을 확인하시겠습니까? (Y/N): ";
                cin >> checkReservations;
                if (checkReservations == 'Y' || checkReservations == 'y') {
                    reservation.displayUserReservations(user.getCurrentUserID()); // 현재 로그인한 사용자 ID를 사용
                }
            }
        }
    }

    return 0;
}


// 현재 로그인한 사용자의 고유 ID를 반환하는 함수
int User::getCurrentUserID() {
    return user_unique_num; // 현재 로그인한 사용자의 고유 번호 반환
}
Reservation 클래스에 추가할 메서드들
cpp
Copy code
// 결제 처리 함수
void Reservation::processPayment() {
    cout << "결제를 진행합니다." << endl;
    // 결제 관련 로직 구현
    // 예시: 결제 금액 확인, 카드 정보 입력, 결제 승인 등
    cout << "결제가 완료되었습니다." << endl;
}

// 예매 확인 함수
void Reservation::displayUserReservations(int userID) {
    cout << "사용자 " << userID << "의 예매 내역:" << endl;
    // 사용자 ID에 따른 예매 내역 조회 로직 구현
    // 예시: 파일 또는 데이터베이스에서 사용자 ID에 해당하는 예매 내역 조회
    // 예매 내역 출력
}