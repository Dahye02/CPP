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
        Stock(string, int, float);
        ~Stock();
};

// 사용 범위 결정 연산자 ::
void Stock::acquire(string co, int n, float pr){
    name=co;
    shares=n;
    share_val=pr;
    set_total();
}

void Stock::buy(int n, float pr){}
void Stock::shell(int n, float pr){}
void Stock::update(float pr){}
void Stock::show(){
    cout << "name : " << name << endl;
    cout << "shares : " << shares << endl;
    cout << "share_val : " << share_val << endl;
    cout << "total val : " << total_val << endl;
}

//생성자 - int a=4처럼 바로 이용할 수 있게 한다(안써도됨)
//생성자 또한 오버로딩이 가능하다.
Stock::Stock(string co, int n, float pr){
    name=co;
    shares=n;
    share_val=pr;
    set_total();
}
//파괴자 - 매개변수를 가질 수 없다
Stock::~Stock(){
}

int main(){
    //Stock temp; ---> 생성자 x
    Stock temp = Stock("Panda",100,1000); // ---> 생성자 o
    Stock temp2("Panda",100,1000);        // ---> 생성자 o
    temp.acquire("Panda",100,1000);
    temp.show();
}