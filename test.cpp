#include <iostream> //전처리 F12누르면 확인ㄱㄴ
#include <climits>
using namespace std;
/*
iostream을 사용할 때 using std를 하지 않으면
std::count, std::endl같이 사용해야함
*/
int main() {
    cout<<"Hello,World!"<<endl;
    //endl - 줄바꿈
    // << - 데이터의 흐름,방향

    int a=10;
    int b=20;
    char c[]={'a','b','c','\0'};
    cout << "a=" << a << ", b="<< b << endl;
    cout << c <<endl;
    /*
    char과 string의 차이
        string은 결합, 수정 등이 가능!
    */


    //입력(cin>> == scanf & cin.getline-->공백포함)
    cin>>name;
    cin.getline(name, Size);


    /*
    c++ 강제형변환 (추가)
    static_cast<typeName>

    산술연산자 : + - * / >>(=//) %
    auto : 데이터형 자동 결정
    
    strlen, sizeof함수
    */

    return 0;
}