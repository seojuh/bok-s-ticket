#include <iostream>
#include <string>
#include <vector>

using namespace std;

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


int main()
{
    char eng;

    AsianCup Info;
    Info.Group();
    cout<<"원하시는 조의 경기일정을 확인하실려면 그룹 조를 입력해주세요: ";
    cin>>eng;
    while(1)
    {
        if(eng == 'a' || eng == 'A')
        {
            Info.Game_Schedul_A();
            break;        
        }
        else if(eng == 'b' || eng == 'B')
        {
            Info.Game_Schedul_B();
            break;
        }
        else if(eng == 'c' || eng == 'C')
        {
            Info.Game_Schedul_C();
            break;
        }
        else if(eng=='d' || eng == 'D')
        {
            Info.Game_Schedul_D();
            break;
        }
        else if(eng=='e' || eng == 'E')
        {
            Info.Game_Schedul_E();
            break;
        }
        else if(eng=='f' || eng=='F')
        {
            Info.Game_Schedul_F();
            break;
        }
        else
        {
            cout<<"잘못된 선택입니다. 다시 선택해주세요"<<endl;
            break;
        }
    }
   

    return 0;
}