#include "user.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

User::User()
{
    id.push_back(" ");
    pw.push_back(" ");
    pn.push_back(" ");
}

// 회원가입
void User::join()
{
    int num;
    string join_id;
    string join_pw;
    string join_pn;
    system("clear");
    
    cout << " " << "┌────────────────────────────────────────────────────┐" << endl;
    cout << " " << "│              회원가입을 진행하겠습니까?            │"<<endl;
    cout << " " << "├────────────────────────────────────────────────────┤" << endl;
    cout << " " << "│                   1.예 / 2.아니오                  │"<<endl;
    cout << " " << "└────────────────────────────────────────────────────┘" << endl;
    cin >> num;
    
    // 회원가입 선택
    cin.ignore();
    sleep(1.5);
    system("clear");
    
    switch (num)
    {
        case 1:
            while (1)
            {
                int dupid = 0;
                cout << "" << "┌────────────────────────────────────────────────────┐" << endl;
                cout << "" << "│                  ID를 설정해주세요                 │" << endl;
                cout << "" << "└────────────────────────────────────────────────────┘" << endl;
                getline(cin, join_id);
                sleep(1.5);
                system("clear");

                // 아이디 중복 확인
                for (int i = 0; i < numbers_user; i++)
                {
                    if (join_id == id[i])
                    {
                        dupid = 1;
                        break;
                    }
                }

                if (dupid)
                {
                    cout << "===========================================================" << endl;
                    cout << "*         중복된 ID 입니다. 다른 ID를 입력해주세요.       *" << endl;
                    cout << "===========================================================" << endl;
                }
                else
                {
                    break;
                }
            }

            while (1)
            {
            cout << " " << "┌────────────────────────────────────────────────────┐" << endl;
            cout << " " << "│               패스워드를 설정해주세요              │" << endl;
            cout << " " << "└────────────────────────────────────────────────────┘" << endl;
                getline(cin, join_pw);
                sleep(1.5);
                system("clear");

                if (join_pw.length() != 6)
                {
                    cout << "========================================================================" << endl;
                    cout << "*          패스워드 6자리 제대로 입력해주세요                          *" << endl;
                    cout << "========================================================================" << endl;
                }
                else
                {
                    break;
                }
            }

            while (1)
            {
                cout << "========================================================================" << endl;
                cout << "*    본인확인을 위한 휴대폰 번호를 입력해주세요                        *" << endl;
                cout << "*    휴대폰 번호는 ex)01000000000이렇게 숫자만 입력해주세요            *" << endl;
                cout << "========================================================================" << endl;
                getline(cin, join_pn);
                sleep(1.5);
                system("clear");
                int duppn = 0;

                // 휴대폰번호 중복 확인
                for (int i = 0; i < numbers_user; i++)
                {
                    if (join_pn == pn[i])
                    {
                        duppn = 1;
                        break;
                    }
                }

                if (duppn)
                {
                    cout << "========================================================================" << endl;
                    cout << "*    중복된 휴대폰 번호 입니다. ID/PW를 잊으셨다면 찾기를 눌러주세요    *" << endl;
                    cout << "========================================================================" << endl;
                }
                else
                {
                    break;
                }
            }

            id.push_back(join_id);
            pw.push_back(join_pw);
            pn.push_back(join_pn);
            //회원가입 고유번호 부여
            this->user_unique_num += numbers_user;
            numbers_user++;

            cout << "========================================================================" << endl;
            cout << "*    회원가입이 완료되셨습니다.                                          *" << endl;
            cout <<"    "<<join_id << "회원님의 회원번호는: " << user_unique_num << " 입니다."<< endl;
            cout << "========================================================================" << endl;
            
            saveToFile();
            sleep(1.5);
            system("clear");
            break;

        case 2:
            cout << "┌────────────────────────────────────────────────────┐" << endl;
            cout << "│              처음 화면으로 가겠습니다.             │" << endl;
            cout << "└────────────────────────────────────────────────────┘" << endl;
            sleep(1.5);
            break;

        default:
            cout << "┌────────────────────────────────────────────────────┐" << endl;
            cout << "│                 잘못된 선택입니다.                 │" << endl;
            cout << "└────────────────────────────────────────────────────┘" << endl;
            sleep(1.5);
            break;
    }
}

//로그인
bool User::login()
{
    string input_id;
    string input_pw;
    bool Login = false; // 로그인 상태를 나타내는 변수로 변경
    while(!Login)
    {
        sleep(1.5);
        system("clear");
        cout<<"========================================================================="<<endl;
        cout<<"                          로그인 진행중입니다.                      "<<endl;
        cout<<"========================================================================="<<endl;
        cout<<"아이디를 입력해주세요: ";
        getline(cin,input_id);
        cout<<"패스워드를 입력해주세요: ";
        getline(cin, input_pw);
        for(int i=0; i<numbers_user; i++)
        {
            system("clear");
            if(input_id == id[i] && input_pw == pw[i])
            {
                cout<<"========================================================================="<<endl;
                cout<<"                          로그인 성공입니다.                      "<<endl;
                cout<<"========================================================================="<<endl;
                sleep(1.5);
                system("clear");
                Login = true;
                break;
            }

        }
        if(!Login)
        {
            system("clear");
            cout<<"========================================================================="<<endl;
            cout<<"                           로그인 실패입니다.                             "<<endl;
            cout<<"========================================================================="<<endl;
            cout<<"다시 입력해주세요"<<endl;
        } 
    }
    return Login;   
};

//아이디 찾기
void User::find_id()
{
    system("clear");
    string find_pn;

    cout<<"========================================================================"<<endl;
    cout<<"*    아이디를 찾기위해서 휴대폰 번호를 입력해주세요                    *"<<endl;
    cout<<"========================================================================"<<endl;
    cin>>find_pn;

    bool found = false;
    for(int i=0; i<numbers_user; i++)
    {
        if(find_pn==pn[i])
        {
            cout<<"아이디는 "<<id[i]<<"입니다."<<endl;
            sleep(1.5);
            system("clear");
            found = true;
            break;
        }
    }
    if(!found)
    {
        system("clear");
        cout<<"일치하는 휴대폰 번호가 없습니다."<<endl; 
        cout<<"다시 아이디 찾기를 선택해주시거나 회원가입을 해주세요."<<endl;
        sleep(1.5);
    }
    
}

//비밀번호 찾기
void User::find_pw()
{
    system("clear");
    string find_pn;
    cout<<"========================================================================"<<endl;
    cout<<"*     패스워드를 찾기 위해서 휴대폰 번호를 입력해주세요                *"<<endl;
    cout<<"========================================================================"<<endl;
    cin>>find_pn;

    bool found = false;
    for(int i=0; i<numbers_user; i++)
    {
        if(find_pn == pn[i])
        {
            cout<<"패스워드는 "<<pw[i]<<"입니다."<<endl;
            sleep(1.5);
            system("clear");
            found = true;
            break;        
        }
    }
    if(!found)
    {   
        system("clear");
        cout<<"========================================================================"<<endl;
        cout<<"일치하는 휴대폰 번호가 없습니다."<<endl;
        cout<<"다시 비밀번호 찾기를 선택해주거나 회원가입을 해주세요."<<endl;
        cout<<"========================================================================"<<endl;
        sleep(1.5);        
    }
    
}

// 파일 저장
void User::saveToFile()
{
    ofstream file("user.txt", ios::app);

    if (file.is_open())
    {

        int latestIndex = id.size() - 1;
        file << id[latestIndex] << ' ' << pw[latestIndex] << ' ' << pn[latestIndex] << endl;

        file.close();
    }
    else
    {
        cout<<"========================================================================"<<endl;        
        cout << "파일을 열 수 없습니다." << endl;
        cout<<"========================================================================"<<endl;
    }
}

//파일 불러오기
void User::loadFromFile()
{
    ifstream file("user.txt");

    if (file.is_open())
    {
        // 파일에서 정보를 읽어와 벡터에 저장
        string temp_id, temp_pw, temp_pn;
        while (file >> temp_id >> temp_pw >> temp_pn)
        {
            id.push_back(temp_id);
            pw.push_back(temp_pw);
            pn.push_back(temp_pn);
        }
        numbers_user=id.size();
        file.close();
    }
    else
    {
        cout<<"========================================================================"<<endl;
        cout << "파일을 열 수 없습니다." << endl;
        cout<<"========================================================================"<<endl;
    }
}