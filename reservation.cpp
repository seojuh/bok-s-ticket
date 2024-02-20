#include "reservation.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

//경기 선택
bool Reservation::GameReservation()
{
    char answer;
    cout<<"이 경기를 선택하시겠습니까?"<<endl;
    cout<<"원하신다면 Y를 입력해주세요, N을 누르시면 처음 화면으로 돌아가겠습니다: ";
    cin >> answer;
    
    if(answer=='y' || answer=='Y')
    {
        cout<<"경기가 선택되셨습니다."<<endl;
        return true;
    }
    else if(answer=='n' || answer=='N')
    {
        cout<<"취소되셨습니다. 처음으로 돌아가겠습니다."<<endl;
        sleep(1.5);
        remove("user_choice_game.txt");//파일 데이터 지우기 
        return false;
    }
    sleep(1.5);
    system("clear");
    return true;
}

//좌석 예약 금액
int Reservation::SeatReservation()
{
    char rating;
    int num;
    int cash;
    ofstream seatfile("user_reservation_seat.txt");
    cout<<"좌석을 예매하시겠습니까?"<<endl;
    cout<<"좌석은 MVIP, VIP, GOLD, SILVER 등급이 있습니다."<<endl<<endl;
    cout<<"등급별 금액표입니다."<<endl;
    cout<<"====================================================="<<endl;
    cout<<"MVIP: "<<"200,000원"<<endl<<"좌석: A-1, A-2, A-3, A-4"<<endl;
    cout<<"VIP: "<<"150,000원"<<endl<<"좌석: B-1, B-2, B-3, B-4"<<endl;
    cout<<"GOLD: "<<"100,000원"<<endl<<"좌석: D-1, D-2, D-3, D-4"<<endl;
    cout<<"SILVER: "<<"50,000원"<<endl<<"좌석: C-1, C-2, C-3, C-4"<<endl;
    cout<<"====================================================="<<endl<<endl;
    cout<<"원하시는 좌석의 등급을 입력해주세요. "<<endl;
    cout<<"(MVIP 좌석이면 'A', VIP 좌석이면 'B', ....): "; 
    cin>>rating;
    switch (rating)
    {
        case 'A':
        case 'a':
            cout<<"원하시는 좌석의 번호를 입력해주세요(1~4까지 있습니다.): ";
            cin>>num;
            cout<<"선택하신 등급: MVIP "<<endl<<"좌석: "<<"A"<<"-"<<num<<" 입니다."<<endl;
            cash=200000;
            seatfile<<"등급: MVIP "<<"좌석: "<<"A"<<"-"<<num<<" 인원 수 1명 기준 20만원 입니다."<<endl;
        break;
        case 'B':
        case 'b':
            cout<<"원하시는 좌석의 번호를 입력해주세요(1~4까지 있습니다.): ";
            cin>>num;
            cout<<"선택하신 등급: VIP "<<endl<<"좌석: "<<"B"<<"-"<<num<<" 입니다."<<endl;
            cash=150000;
            seatfile<<"등급: VIP "<<"좌석: "<<"B"<<"-"<<num<< " 인원 수 1명 기준 15만원 입니다."<<endl;
        break;
        case 'C':
        case 'c':
            cout<<"원하시는 좌석의 번호를 입력해주세요(1~4까지 있습니다.): ";
            cin>>num;
            cout<<"선택하신 등급: SILVER "<<endl<<"좌석: "<<"C"<<"-"<<num<<" 입니다."<<endl;
            cash=50000;
            seatfile<<"등급: SILVER "<<"좌석: "<<"C"<<"-"<<num<<" 인원 수 1명 기준 5만원 입니다."<<endl;
            break;
        case 'D':
        case 'd':
            cout<<"원하시는 좌석의 번호를 입력해주세요(1~4까지 있습니다.): ";
            cin>>num;
            cout<<"선택하신 등급: GOLD "<<endl<<"좌석: "<<"D"<<"-"<<num<<" 입니다."<<endl;
            cash=100000;
            seatfile<<"등급: GOLD "<<"좌석: "<<"D"<<"-"<<num<<" 인원 수 1명 기준 10만원 입니다."<<endl;
            break;
    default:
            cout<<"잘못된 선택입니다."<<endl;
            sleep(1.5);
            break;
    }
    return cash; 
}
// 결제 진행
bool Reservation::CashReservation()
{
    sleep(1.5);
    system("clear"); 
    char answer;
    cout<<"결제를 진행하시겠습니까? (Y/N)을 입력해주세요 "<<endl;
    cout<<"Y를 입력하시면 결제, N을 입력하시면 처음으로 돌아갑니다: ";
    cin>>answer;
    if(answer=='y' || answer=='Y')
    {
        return true;
    }
    else if(answer=='n' || answer=='N')
    {
        cout<<"취소되셨습니다. 처음으로 돌아가겠습니다."<<endl;
        sleep(1.5);
        remove("user_reservation_seat.txt");//파일 지우기
        remove("user_choice_game.txt");//파일 데이터 지우기         
        system("clear");
        return false;
    }
    return false;
}