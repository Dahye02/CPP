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
    char name;
    int Size=3;
    cin>>name;
    cin.getline(name, Size);


    /*
    c++ 강제형변환 (추가)
    static_cast<typeName>

    산술연산자 : + - * / >>(=//) %
    auto : 데이터형 자동 결정
    
    strlen, sizeof, strcpy 함수
    */


   //구조체
    struct Mystruct{
        string name1;
        string position;
        float height;
        float weight;
    };
    //Mystruct A;
    //A.name="Son";
    Mystruct A[2]={
        {"personA","striker",183,77},
        {"personB","keeper",165,60}
    };
    //동적구조체할당
    Mystruct* temp = new Mystruct;
    cin>>temp->name;
    cin>>(*temp).age;

    /* 
        <공용체(union)>
        서로 다른 데이터형을 한 번에 한 가지만 보관할 수 있음.

        <열거체(enum)>
        기호 상수를 만드는 것에 대한 또다른 방법
        enum spectrum {red, orange, yellow, green=6, vlue=8, violet=10, indigo, ultraviolet};
        1. spectrum을 새로운 데이터형 이름으로 만든다.
        2. red, orange, yellow.. 0에서부터 7까지 정수 값을 각각 나타내는 기호상수 만듦
        3. 열거자들끼리의 산술연산 불가능(+, - ..)
        spectrum a=orange //값 : 1
    */

   /*
        <new연산자>
        어떤 데이터형을 원하는지 new연산자에게 알려주면,
        new연산자는 그에 알맞은 크기의 메모리 블록을 찾아내 그 주소를 리턴한다.

        <delete연산자>
        사용한 메모리를 해제
        
        double* p3 = new double[3];
        p3[0]=0.2;
        p3[1]=0.5;
        p3[2]=0.8;

        cout << "p3[1] is " << p3[1] << ".\n";

        p3 = p3+1;

        cout << "Now p3[0] is " << p3[0] << " and ";
        cout << "p3[1] is " << p3[1] << ".\n";

        p3 = p3-1;
        delete[] p3;
    */

   /*
        <함수를 지시하는 포인터>
        1. 함수의 주소를 얻는다
        2. 함수를 지시하는 포인터를 선언
        3. 함수를 지시하는 포인터를 사용하여 그 함수 호출
        int (*변수이름)(int); //주소 얻기
        변수이름=함수이름;     //포인터 선언
        cout << (*pf)(3) <<endl;  //사용
   */

    /*
        <인라인함수>
        컴파일의 인라인 함수 호출 = 점프가 아닌 그에 대응하는 함수 코드로 대체
        코드 실행속도 향상에 기여
        inline float square(float x) { return x*x; }

        <디폴트 매개변수>
        int square(int x, int y=3);
        int num=square(x);-->y는 default값인 3으로 지정됨
    */

   /*
        <참조(reference)란?>
        미리 정의된 변수의 실제 이름 대신 사용할 수 있는 대용 이름
        함수의 매개변수에 사용하며, 주소사용과 같이 변수들의 값을 바꿀 수 있따(전역변수처럼...)
        int a;
        int& b=a; --> 참조(주소x)
   */

    //함수오버로딩 : 여러개의 함수를 같은 이름으로 연결
    /*
        int sum(int, int);
        int sum(float, float);
    */

   /*
        <함수 템플릿>
        구체적인 데이터형을 포괄할 수 있는 일반형으로 함수를 정의(auto와 비슷)
        오버로딩 사용가능
        template <class 함수이름(Any)>
        Any sum(int a, Any b){
            return a+b;
        }

   */

    return 0;
}