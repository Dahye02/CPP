#include <iostream>
#include <sstream>

#ifndef TIME

class Time{
    private:
        int hours;
        int mins;

    public:
        Time();
        Time(int, int);
        void addHours(int);
        void addMins(int);

        //  Time sum(Time&); ---> 연산자 오버로딩 전
        Time operator+(Time&);// ---> 연산자 오버로딩 후
        Time operator*(int);

        // <friend> : 멤버함수가 아니어도 private에 접근할 수 있도록 함
        friend Time operator*(int n, Time& t) {
		    return t * n;
	    }
        friend std::ostream& operator<<(std::ostream&, Time&); //iostream의 '<<'연산자 오버로딩

        virtual void show(); // ---> 가상메소드 
        virtual ~time();
        /*
            1. 기초 클래스에서 가상메서드를 선언하면 그 함수는 기초 클래스 및 파생 클래스에서 모두 가상이 된다.
            2. 상속을 위해 기초 클래스로 사용할 클래스를 정의할 때, 파생 클래스에서 다시 정의해야되는 클래스 메서드들은 가상 함수로 선언해야 한다.

        */
        int getHour(){return hours;}
        int getMins(){return mins;}

        ~Time();
};

#endif


//상속(기초클래스<Time>-파생클래스<NewTime>)
/*
    1. 기존의 클래스에 새로운 기능을 추가할 수 있다.
    2. 클래스가 나타내고 있는 데이터에 다른 거승ㄹ 더 추가할 수 있다.
    3. 클래스 메서드가 동작하는 방식을 변경할 수 있다.
*/
class NewTime : public Time{
    private:
        int day;
    public:
        NewTime();
        NewTime(int, int, int);
        //void print();
        //print는 Time class의 show와 비슷하게 동작을 한다 ---> <다형상속>
        /*
            1. 가상메서드 사용(virtual키워드)
        */
        void show();
};