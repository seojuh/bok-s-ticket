#include "Asiancup.h"
#include "mainmonitor.h"
#include "reservation.h"
#include "gameschedule.h"
#include "user.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>


int main() 
{
    User user;   //유저
    AsianCup asianCup;  //아시안컵
    MainMonitor monitor;    //화면 출력
    GameSchedule schedul;   //경기 일정
    Reservation reservation;    //예약
    bool loginSuccess = false; //로그인 성공 기준 
    int num;    //인원수
    user.loadFromFile(); 

    while (true) 
    {
        if (!loginSuccess)
        {
            string line;
            ifstream gamefile("user_choice_game.txt");
            ifstream seatfile("user_reservation_seat.txt");            
            monitor.DisplayMoniter();
            int choice;
            cout << "선택: ";
            cin >> choice;
            cin.ignore(); 
            switch (choice) 
            {
                case 1:
                    loginSuccess = user.login(); //로그인 
                    break;
                case 2:
                    user.join();    //회원가입
                    break;
                case 3:
                    user.find_id();     //아이디 찾기
                    break;
                case 4:
                    user.find_pw();     //비밀번호 찾기
                    break;
                case 5:
                    cout << "프로그램을 종료합니다." << endl;      //종료
                    return 0;
                case 6:         //한국 아시안 컵 정보 출력
                    asianCup.Relay();
                    asianCup.Venue();
                    asianCup.Player_List();
                    asianCup.Player_Info();
                    break;
                case 7:     //예매 확인
                    user.login();
                    if(gamefile.is_open())          //저정된 경기 정보 파일 읽기
                    {
                        while(getline(gamefile, line))
                        cout<<line<<endl;
                    }
                    else
                    {
                        cout<<"예매하신 내역이 없습니다."<<endl<<"Enter를 누르시면 처음화면으로 돌아갑니다."<<endl;
                        cin.get();
                        break;
                    }
                    if(seatfile.is_open())             //저장된 좌석 정보 파일 읽기
                    {
                        while(getline(seatfile,line))
                        cout<<line<<endl;
                    }
                    cout<<"인원 수: "<<num<<"명"<<endl;
                    cout<<endl<<"Enter를 누르시면 처음화면으로 돌아갑니다";
                    cin.get();
                    break;
                default:
                    cout << "잘못된 선택입니다. 다시 시도해주세요." << endl;
                    sleep(1.5);
                    break;
            }
            gamefile.close();
            seatfile.close();
        }
        else if(loginSuccess)   //로그인 성공시
        {
            while(schedul.ShowMenu())
            {
                if(!reservation.GameReservation())
                {
                    break;
                }
                monitor.DisplayGameMoniter();
                int cash = reservation.SeatReservation();
                if(reservation.CashReservation())   //결제 진행
                {
                   cout<<"인원 수를 입력해주시겠습니까?";
                   cin>>num;
                   cout<<"인원 수: "<<num<<"명"<<endl;
                   cout<<"결제가 완료되었습니다. 총 금액은: "<<cash*num<<"원 입니다."<<endl;
                   sleep(1.5);
                }
                else
                {
                    break;                    
                }
                system("clear");
                break;
            }
            loginSuccess=false; //초기화
        }
    }
    return 0;
} 

