#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

int user;
int numbers_user = 1;
//사용자 클래스
class User
{
private:
    vector <string> id;
    vector <string> pw;
    vector <string> pn;
public:
    User()
    {
        id.push_back(" ");
        pw.push_back(" ");
        pn.push_back(" ");
    }
    int user_unique_num = 1000;
    void join();
    void login();
    void find_id();
    void find_pw();
    void saveToFile();
    void loadFromFile();
};

//로그인
void User::login()
{
    string input_id;
    string input_pw;
    int Login=0;
    while(Login != 1)
    {
        cout<<"========================================================================="<<endl;
        cout<<"                                로그인 진행중입니다.                      "<<endl;
        cout<<"========================================================================"<<endl;
        cout<<"아이디를 입력해주세요: ";
        getline(cin,input_id);
        cout<<"패스워드를 입력해주세요: ";
        getline(cin, input_pw);
        for(int i=0; i<numbers_user; i++)
        {
            if(input_id == id[i] && input_pw == pw[i])
            {
                cout<<"========================================================================="<<endl;
                cout<<"                                로그인 성공입니다.                      "<<endl;
                cout<<"========================================================================"<<endl;
                sleep(2);
                system("clear");
                break;
            }
        }
        if(Login !=1)
        {
            cout<<"========================================================================="<<endl;
            cout<<"                                로그인 실패입니다.                      "<<endl;
            cout<<"========================================================================"<<endl;
        } 
    }
    return;    
};

// 회원가입
void User::join()
{
    int num;
    string join_id;
    string join_pw;
    string join_pn;
    system("clear");
    
    cout << "========================================================================" << endl;
    cout << "*                                                                      *" << endl;
    cout << "*                                                                      *" << endl;
    cout << "*   회원가입을 하시겠습니까?                                            *" << endl;
    cout << "*                                                                     *" << endl;
    cout << "========================================================================" << endl;
    cout << "*   1. 예                                                               *" << endl;
    cout << "*   2. 아니오                                                           *" << endl;
    cout << "========================================================================" << endl;
    cin >> num;
    
    // 회원가입 선택
    cin.ignore();
    sleep(1);
    system("clear");
    
    switch (num)
    {
        case 1:
            while (1)
            {
                int dupid = 0;
                cout << "========================================================================" << endl;
                cout << "*    아이디를 입력해주세요:                                              *" << endl;
                cout << "========================================================================" << endl;
                getline(cin, join_id);
                sleep(1);
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
                    cout << "========================================================================" << endl;
                    cout << "*    중복된 ID 입니다. 다른 ID를 입력해주세요.                           *" << endl;
                    cout << "========================================================================" << endl;
                }
                else
                {
                    break;
                }
            }

            while (1)
            {
                int duppw = 0;
                cout << "========================================================================" << endl;
                cout << "*    패스워드를 입력해주세요(6자리 입력해주세요):                         *" << endl;
                cout << "========================================================================" << endl;
                getline(cin, join_pw);
                sleep(1);
                system("clear");

                if (join_pw.length() != 6)
                {
                    cout << "========================================================================" << endl;
                    cout << "*    패스워드 6자리 제대로 입력해주세요                                  *" << endl;
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
                cout << "*    본인확인을 위한 휴대폰 번호를 입력해주세요                           *" << endl;
                cout << "*    휴대폰 번호는 ex)01000000000이렇게 숫자만 입력해주세요               *" << endl;
                cout << "========================================================================" << endl;
                getline(cin, join_pn);
                sleep(1);
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
                    cout << "*    중복된 휴대폰 번호 입니다. ID/PW를 잊으셨다면 찾기를 눌러주세요       *" << endl;
                    cout << "========================================================================" << endl;
                }
                else
                {
                    break;
                }
            }

            // 회원가입이 완료되면 벡터에 추가
            id.push_back(join_id);
            pw.push_back(join_pw);
            pn.push_back(join_pn);

            this->user_unique_num += numbers_user;
            numbers_user++;

            cout << "========================================================================" << endl;
            cout << "*    회원가입이 완료되셨습니다.                                          *" << endl;
            cout << "*" << join_id << "회원님의 회원번호는: " << user_unique_num << " 입니다." << "     *" << endl;
            cout << "========================================================================" << endl;
            
            saveToFile();
            sleep(1);
            system("clear");
            break;

        case 2:
            cout << "처음 화면으로 가겠습니다." << endl;
            break;

        default:
            cout << "잘못된 선택입니다." << endl;
            break;
    }
}
//아이디 찾기
void User::find_id()
{

    string find_pn;

    cout<<"========================================================================"<<endl;
    cout<<"*    아이디를 찾기위해서 휴대폰 번호를 입력해주세요                           *"<<endl;
    cout<<"========================================================================"<<endl;
    cin>>find_pn;

    for(int i=0; i<numbers_user; i++)
    {
        if(find_pn==pn[i])
        {
            cout<<"아이디는 "<<id[i]<<"입니다."<<endl;
            sleep(1);
            system("clear");
            break;
        }
        else
        {
            cout<<"일치하는 휴대폰 번호가 없습니다."<<endl;
            break;
        }
    }
}

//비밀번호 찾기
void User::find_pw()
{
    string find_pn;
    cout<<"========================================================================"<<endl;
    cout<<"*     패스워드를 찾기 위해서 휴대폰 번호를 입력해주세요                    *"<<endl;
    cout<<"========================================================================"<<endl;
    cin>>find_pn;

    for(int i=0; i<numbers_user; i++)
    {
        if(find_pn == pn[i])
        {
            cout<<"패스워드는 "<<pw[i]<<"입니다."<<endl;
            sleep(1);
            system("clear");
            break;
        }
        else
        {   
            cout<<"일치하는 휴대폰 번호가 없습니다."<<endl;
            break;
        }
    }
}

//파일 저장
void User::saveToFile()
{
    ofstream file("user.txt", ios::app);

    if (file.is_open())
    {
        // 벡터의 크기만큼 반복하면서 파일에 저장
        for (size_t i = 0; i < id.size(); i++)
        {
            file << id[i] << ' ' << pw[i] << ' ' << pn[i] << '\n';
        }

        file.close();
    }
    else
    {
        cerr << "파일을 열 수 없습니다." << endl;
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

        file.close();
    }
    else
    {
        cerr << "파일을 열 수 없습니다." << endl;
    }
}

class AsianCup
{
private:
    vector <string> A;
    vector <string> B;
    vector <string> C;
    vector <string> D;
    vector <string> E;
    vector <string> F;
public:
    void Group();
    void Game_Schedul_A();
    void Game_Schedul_B();
    void Game_Schedul_C();
    void Game_Schedul_D();
    void Game_Schedul_E();
    void Game_Schedul_F();
    void Relay();
    void Venue();
    void Player_List();
    void Player_Info();          
};

void AsianCup::Group()
{
    cout<<"Group A: 카타르, 중국, 타지키스탄, 레바논"<<endl;
    cout<<"Group B: 호주, 우즈베키스탄, 시리아, 인도"<<endl;
    cout<<"Group C: 이란, 아랍에미리트, 홍콩, 팔레스타인"<<endl;
    cout<<"Group D: 일본, 인도네시아, 이라크, 베트남"<<endl;
    cout<<"Group E: 대한민국, 말레이시아, 요르단, 바레인"<<endl;
    cout<<"Group F: 사우디아라비아, 태국, 키르기스스탄, 오만"<<endl;                
}

void AsianCup::Game_Schedul_A()
{
    cout<<"Group A조의 경기 일정입니다."<<endl;
    cout<<"1. 2024년 1월 13일 토요일 01:00, 카타르 VS 레바논, 루사일 스타디움"<<endl;
    cout<<"2. 2024년 1월 13일 토요일 23:30, 중국 VS 타지키스탄, 압둘라 빈 칼리파 경기장"<<endl;
    cout<<"3. 2024년 1월 17일 수요일 20:30, 레바논 VS 중국. 알 투마마 경기장"<<endl;
    cout<<"4. 2024년 1월 17일 수요일 23:30, 타지키스탄 VS 카타르, 알 베이트 경기장"<<endl;
    cout<<"5. 2024년 1월 23일 화요일 00:00, 타지키스탄 VS 레바논. 자심 빈 하마드 스타디움"<<endl;
    cout<<"6. 2024년 1월 23일 화요일 00:00, 카타르 VS 중국, 칼리파 국제 경기장"<<endl;
}

void AsianCup::Game_Schedul_B()
{
    cout<<"Group B조의 경기 일정입니다."<<endl;
    cout<<"1. 2024년 1월 13일 토요일 20:30, 호주 VS 인도, 아마드 빈 알리 스타디움"<<endl;
    cout<<"2. 2024년 1월 14일 일요일 02:30, 우즈베키스탄 VS 시리아, 자심 빈 하마드 스타디움"<<endl;
    cout<<"3. 2024년 1월 18일 목요일 20:30, 시리아 VS 호주, 자심 반 하마드 스타디움"<<endl;
    cout<<"4. 2024년 1월 18일 목요일 20:30, 시리아 VS 호주, 자심 반 하마드 스타디움"<<endl;
    cout<<"5. 2024년 1월 18일 목요일 23:30, 인도 VS 우즈베키스탄, 아마드 빈 알리 스타디움"<<endl;
    cout<<"6. 2024년 1월 23일 화요일 20:30, 호주 VS 우즈베키스탄, 알 자누브 경기장"<<endl;   
}

void AsianCup::Game_Schedul_C()
{
    cout<<"Group C조의 경기 일정입니다."<<endl;
    cout<<"1. 2024년 1월 14일 일요일 23:30, 아랍 에미리트 VS 홍콩, 칼리파 국제 경기장"<<endl;
    cout<<"2. 2024년 1월 15일 월요일 02:30, 이란 VS 팔레스타인, 교육도시 경기장(알라이안)"<<endl;
    cout<<"3. 2024년 1월 19일 금요일 02:30, 팔레스타인 VS 아랍 에미리트, 알 자누브 경기장"<<endl;
    cout<<"4. 2024년 1월 20일 토요일 02:30, 홍콩 VS 이란, 칼리파 국제 경기장"<<endl;
    cout<<"5. 2024년 1월 24일 수요일 00:00, 홍콩 VS 팔레스타인, 압둘리 빈 칼리파 경기장"<<endl;
    cout<<"6. 2024년 1월 24일 수요일 00:00, 이란 VS 아랍 에미리트, 교육도시 경기장(알라이안)"<<endl;      
}

void AsianCup::Game_Schedul_D()
{
    cout<<"Group D조의 경기 일정입니다."<<endl;
    cout<<"1. 2024년 1월 14일 일요일 20:30, 일본 VS 베트남, 알 투마마 경기장"<<endl;
    cout<<"2. 2024년 1월 15일 월요일 23:30, 인도네시아 VS 이라크, 아마드 빈 알리 스타디움"<<endl;
    cout<<"3. 2024년 1월 19일 금요일 20:30, 이라크 VS 일본, 교육도시 경기장(알 라이안)"<<endl;
    cout<<"4. 2024년 1월 19일 금요일 23:30, 베트남 VS 인도네시아, 압둘라 빈 칼리파 경기장"<<endl;
    cout<<"5. 2024년 1월 24일 수요일 20:30, 일본 VS 인도네시아, 알 투마마 경기장"<<endl;
    cout<<"6. 2024년 1월 24일 수요일 20:30, 이라크 VS 베트남, 자심 빈 하마드 스타디움"<<endl;     
}

void AsianCup::Game_Schedul_E()
{
    cout<<"Group E조의 경기 일정입니다."<<endl;
    cout<<"1. 2024년 1월 15일 월요일 20:30, 한국 VS 바레인, 자심 빈 하마드 스타디움"<<endl;
    cout<<"2. 2024년 1월 16일 화요일 02:30, 말레이시아 VS 요르단, 알 자누브 경기장"<<endl;
    cout<<"3. 2024년 1월 20일 토요일 20:30, 요르단 VS 대한민국, 알 투마마 경기장"<<endl;
    cout<<"4. 2024년 1월 20일 토요일 23:30, 바레인 VS 말레이시아, 자심 빈 하마드 스타디움"<<endl;
    cout<<"5. 2024년 1월 25일 목요일 20:30, 한국 VS 말레이시아, 알 자누브 경기장"<<endl;
    cout<<"6. 2024년 1월 25일 목요일 20:30, 요르단 VS 바레인, 칼리파 국제 경기장"<<endl;     
}

void AsianCup::Game_Schedul_F()
{
    cout<<"Group F조의 경기 일정입니다."<<endl;
    cout<<"1. 2024년 1월 16일 화요일 23:30, 태국 VS 키르기스 공화국, 압둘라 빈 칼리파 경기장"<<endl;
    cout<<"2. 2024년 1월 17일 수요일 02:30, 사우디 아라비아 VS 오만, 칼리파 국제 경기장"<<endl;
    cout<<"3. 2024년 1월 21일 일요일 23:30, 오만 VS 태국, 압둘라 빈 칼리파 경기장"<<endl;
    cout<<"4. 2024년 1월 22일 월요일 02:30, 키르기스 공화국 VS 사우디 아라비아, 아마드 빈 알리 스타디움"<<endl;
    cout<<"5. 2024년 1월 26일 금요일 00:00, 키르기스 공화국 VS 오만, 압둘라 빈 칼리파 경기장"<<endl;
    cout<<"6. 2024년 1월 26일 금요일 00:00, 사우디 아라비아 VS 태국, 교육도시 경기장(알 라이안)"<<endl;    
}

void AsianCup::Relay()
{
    cout<<"경기 중계는 tvN, tvN SPORTS, 쿠팡 플레이에서 중계합니다."<<endl;
}

void AsianCup::Venue()
{
    cout<<"개최지는 카타르 도하, 알 와크라, 알 라이안, 알 코르에서 개최합니다."<<endl;
}

void AsianCup::Player_List()
{
    cout<<"한국 감독: 위르겐 클리스만"<<endl;
    cout<<"한국 선수 명단"<<endl<<"오현규, 정우영, 조규성, 문선민, 박용우, 손흥민, 양현준, 이강인, 이순민, 이재성, 홍현석, 황인범, 황희찬"<<endl<<
           "김민재, 김영권, 김주성, 김지수, 김진수, 김태환, 박진섭, 설영우, 이기제, 정승현, 김승규, 송범근, 조현우"<<endl;
}

void AsianCup::Player_Info()
{
    cout<<"한국 선수들 포지션 정보"<<endl;
    cout<<"FW: 오현규, 정우영, 조규성"<<endl;
    cout<<"MF: 문선민, 박용우, 손흥민, 양형준, 이강인, 이순민, 이재성, 홍현석, 황인범, 황희찬"<<endl;
    cout<<"DF: 김민재, 김영권, 김주성, 김지수, 김진수, 김태환, 박진섭, 설영우, 이기제, 정승현"<<endl;
    cout<<"GK: 김승규, 송범근, 조현우"<<endl;
    cout<<"Coach: 안드레아스 헤어초크, 차두리, 파올로 스트링가라, 안드레아스 쾨프케, 베르너 로이타드, 이재홍"<<endl;
}

class MainMonitor
{
public:
    void Display();
};

void MainMonitor::Display()
{
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣶⣦⣤⣄⡀⠀⠢⣀⣠⣤⣤⣶⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠄⠉⢻⠀⠀⠀⠀⡿⠉⠀⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⡷⢗⢤⣦⡆⠀⠀⢀⣯⡦⠼⢶⡇⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⢷⠈⣀⠘⣧⠀⠀⢸⡅⢀⠁⢸⠛⢮⡳⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⡖⠈⠀⢉⡉⢻⡀⠀⡟⡟⡉⠀⠈⠀⠈⠋⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣏⣿⠀⠀⠀⡀⢍⣹⡇⢰⣿⡭⠀⡄⠀⠀⣼⢠⡞⢰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⢿⣿⣿⣇⠀⠀⠑⢄⣂⣣⣽⣿⣡⠎⠀⠀⢰⣿⣿⣃⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣶⣄⠀⣌⣪⣻⣿⣆⠀⢀⣴⣿⣿⣿⡟⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⠟⠳⠇⢠⣿⣿⣽⣿⢟⣠⣾⣿⣿⣿⣟⠍⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⠆⢰⣿⣻⡟⢉⣰⣿⣿⣿⣿⣿⠿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣫⣭⣴⢾⣻⣽⣽⡿⠛⠕⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁⠀⠀⠻⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⢿⡀⣿⣟⣻⣾⠛⠳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠟⠛⠷⠿⠏⠉⠻⢦⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣶⡀⣴⡶⠶⢰⣶⠀⢰⣶⡆⠀⣶⣦⠀⣶⠀⢀⣴⠶⠶⡆⣶⠀⢰⣶⣶⡶⢶⣆⠒⠂⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣯⣽⣧⣙⣻⣶⣼⣿⢀⣿⣯⣿⡄⣿⡟⣿⣿⠀⢸⣿⣀⣀⡀⣿⣀⣸⡿⣿⡷⠾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠀⠀⠛⠛⠛⠋⠘⠛⠚⠃⠀⠘⠓⠛⠃⠘⠛⠀⠀⠉⠛⠛⠁⠉⠛⠋⠁⠙⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"========================================================================="<<endl;
    cout<<"*                            Bok's Ticket                               *"<<endl;
    cout<<"*                                                                       *"<<endl;
    cout<<"*   1. 로그인                                                           *"<<endl;
    cout<<"*   2. 회원가입                                                         *"<<endl;
    cout<<"*   3. 아이디 찾기                                                      *"<<endl;
    cout<<"*   4. 비밀번호 찾기                                                    *"<<endl;
    cout<<"*   5. 종료                                                             *"<<endl;
    cout<<"========================================================================"<<endl;          
}

int main()
{
    char eng;

    User user;
    AsianCup asianCup;
    MainMonitor mainMonitor;

    mainMonitor.Display();

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        user.login();
        asianCup.Group();
        cout << "원하시는 조의 경기 일정을 확인하실려면 그룹 조를 입력해주세요: ";
        cin >> eng;
        switch (eng)
        {
        case 'A':
            asianCup.Game_Schedul_A();
            break;
        case 'B':
            asianCup.Game_Schedul_B();
            break;
        case 'C':
            asianCup.Game_Schedul_C();
            break;
        case 'D':
            asianCup.Game_Schedul_D();
            break;
        case 'E':
            asianCup.Game_Schedul_E();
            break;
        case 'F':
            asianCup.Game_Schedul_F();
            break;
        default:
            cout << "잘못된 선택입니다." << endl;
            break;
        }
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
        break;

    default:
        cout << "잘못된 선택입니다." << endl;
        break;
    }

    return 0;
}