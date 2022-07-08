#ifndef Stock

#include <iostream>
#include <sstream>
using namespace std;

/*
    <클래스란?>
    추상화를 사용자 정의 데이터형으로 변환해주는 수단
    1. 클래스 선언
    2. 클래스 매서드 정의
*/
class Stock{
    private:
        string name;
        int shares;
        float share_val;
        double total_val;
        void set_total() {total_val=shares*share_val;}
    
    //private의 값들은 직접접근 불가능 ---> public의 멤버함수로만 변경가능 == 데이터 은닉
    public:
        void acquire(string, int, float);
        void buy(int, float);
        void shell(int, float);
        void update(float);
        void show();

        //2개 이상의 Stock을 받아 연산하려면..?
        Stock& topval(Stock&);

        Stock(string, int, float);
        ~Stock();
};
#endif // !STOCK