#ifndef Asiancup_h
#define Asiancup_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

//경기일정,정보 클래스
class AsianCup
{
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

#endif