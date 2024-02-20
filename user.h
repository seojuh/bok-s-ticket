#ifndef User_h
#define User_h

#include <vector>
#include <string>
using namespace std;

//사용자 클래스
class User
{
private:
    vector <string> id;
    vector <string> pw;
    vector <string> pn;
    int numbers_user=1;
public:
    User();
    int user_unique_num = 1000; //임의 회원 고유번호
    void join();
    bool login();
    void find_id();
    void find_pw();
    void saveToFile();
    void loadFromFile();
};

#endif