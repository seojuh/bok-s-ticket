#include "Asiancup.h"
#include "gameschedule.h"
#include <iostream>
#include <unistd.h>

using namespace std;

//경기일정 보여주는 화면
bool GameSchedule::ShowMenu()
{
    AsianCup asiangroup;
    asiangroup.Group();
    char alp;
    int num;
    cout<<"=========================================="<<endl;
    cout<<"1. 경기 일정 보기"<<endl;
    cout<<"2. 로그아웃"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"경기 일정을 보실거면 1번, 로그아웃을 하실거면 2번을 입력해주세요: ";
    cin>>num;
    if(num==1)
    {
        cout<<"(A, B, C, D, E ,F)조에서 원하시는 그룹의 경기일정을 선택해주세요:";
        cin >> alp;
        cin.ignore();
        switch(alp)
        {
            case 'A':
            case 'a':
                asiangroup.Game_Schedul_A(); 
                return true;
            case 'B':
            case 'b':
                asiangroup.Game_Schedul_B();
                return true;
            case 'C':
            case 'c':
                asiangroup.Game_Schedul_C();
                return true;
            case 'D':
            case 'd':
                asiangroup.Game_Schedul_D();
                return true;
            case 'E':
            case 'e':
                asiangroup.Game_Schedul_E();
                return true;
            case 'F':
            case 'f':
                asiangroup.Game_Schedul_F();
                return true;
            default:
                cout << "잘못된 선택입니다. 다시 시도해주세요." << endl;
                sleep(1.5);
                return true;
        }
    }
    else if(num == 2)
    {

        cout<<"=========================================="<<endl;
        cout<<"     로그아웃 합니다."<<endl; 
        cout<<"     초기화면으로 돌아가겠습니다."<<endl; 
        cout<<"     로그인 해주세요."<<endl;
        cout<<"=========================================="<<endl;
        sleep(1.5);        
        return false;
    }
    return true;
}
