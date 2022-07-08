#include "overloadex_struct.h"
using namespace std;

const int MAX = 3;

Time::Time()
{
	hours = mins = 0;
}

Time::Time(int h, int m) {
	hours = h;
	mins = m;
}

// Time:: - 사용범위 결정 연산자
void Time::addHours(int h) {
	hours += h;
};

void Time::addMins(int m) {
	mins += m;
	hours += mins / 60;
	mins %= 60;
};

//  <연산자 오버로딩 전>
/*
    Time Time::sum(Time& t) {
        Time sum;
        sum.mins = mins + t.mins;
        sum.hours = hours + t.hours;
        sum.hours += sum.mins / 60;
        sum.mins %= 60;
        return sum;
    };
*/
//  <연산자 오버로딩 후>
Time Time::operator+(Time& t){
    Time sum;
        sum.mins = mins + t.mins;
        sum.hours = hours + t.hours;
        sum.hours += sum.mins / 60;
        sum.mins %= 60;
        return sum;
};

Time Time::operator*(int n) {
	Time result;
	long resultMin = hours * n * 60 + mins * n;
	result.hours = resultMin / 60;
	result.mins = resultMin % 60;
	return result;
}

void Time::show() {
	std::cout << "시간 : " << hours << std::endl;
	std::cout << "분 : " << mins << std::endl;
}

Time::~Time()
{
}

std::ostream& operator<<(std::ostream& os, Time& t){
    os << t.hours << "시간" << t.mins << "분";
    return os;
}

// 상속
NewTime::NewTime() : Time(){ 
    //private에 직접 접근 불가능 --> :Time = 멤버초기화위치
    day=0;
}

NewTime::NewTime(int h, int m, int d) : Time(h,m){
    day=d;
}

/*
    void NewTime::print(){
        std::cout << "일 : " << day << std::endl;
        show();
    }
*/
void NewTime::show(){ // : Time을 사용하지 않는 이유 - 값을 수정하는것이 아니기 때문에 굳이 값을 받아오지 않아도 된다.
    std::cout << "일 : " << day << std::endl;
    std::cout << "시간 : " << getHour() << std::endl;
    std::cout << "분 : " << getMins() << std::endl;
}

int main(){
    /*
        Time class를 배열에 넣어 사용한다 했을 때, 요소들의 타입이 서로 다르기 때문에 오류가 발생한다.
        이때는 주소값을 이용하면 배열로도 사용이 가능하다.
    */
    Time* times[MAX];   //--->주소값을 이용한 배열
	int day;
	int hours;
	int mins;

	for (int i = 0; i < MAX; i++) {
		cout << i + 1 << "번째 원소를 정의합니다." << endl;
		cout << "시간을 입력하십시오." << endl;
		cin >> hours;
		cout << "분을 입력하십시오." << endl;
		cin >> mins;
		char check;
		cout << "일 정보가 있다면 1, 없다면 0을 입력하십시오." << endl;
		cin >> check;
		if (check == '0')
			times[i] = new Time(hours, mins);
		else {
			cout << "일을 입력하십시오." << endl;
			cin >> day;
			times[i] = new NewTime(hours, mins, day);
		}
	}

	for (int i = 0; i < MAX; i++) {
		cout << i + 1 << "번째 정보입니다." << endl;
		times[i]->show();
	}

	for (int i = 0; i < MAX; i++) {
		delete times[i];
	}

    NewTime temp1();
    NewTime temp2(3,30,2);
    temp2.show();
    printf("\n");

    Time day1(1, 40);
	Time day2(2, 30);
	day1.show();
	day2.show();

	Time total;
	//total1 = day1.sum(day2); ---> 연산자 오버로딩 전 sum함수 사용
    total = day1 + day2;    // ---> 연산자 오버로딩 후

    //아래는 day3 = operator*(3,t1);와 같은 뜻
    Time t3;
    t3 = day1 * 3;

	total.show();
    printf("\n");
    t3.show();
    printf("\n");

	return 0;
}