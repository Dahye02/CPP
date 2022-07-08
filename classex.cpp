#include "classex_struct.h"

// 사용 범위 결정 연산자 ::
void Stock::acquire(string co, int n, float pr){
    name=co;
    shares=n;
    share_val=pr;
    set_total();
}

void Stock::buy(int n, float pr){
    shares += n;
	share_val = pr;
	set_total();
}
void Stock::shell(int n, float pr){
    shares -= n;
	share_val = pr;
	set_total();
}
void Stock::update(float pr){
    share_val = pr;
	set_total();
}
void Stock::show(){
    cout << "회사 명 : " << name << endl;
	cout << "주식 수 : " << shares << endl;
	cout << "주가 : " << share_val << endl;
	cout << "주식 총 가치 : " << total_val << endl;
}

Stock& Stock::topval(Stock& s){
    if(s.share_val > share_val)
        return s;
    else  return *this;// --> 포인터!
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
    Stock temp2("Papago",10,100);        // ---> 생성자 o
    temp.acquire("Papago",10,100);
    temp.show();

    Stock s[3]={    //--->생성자 무조건 필요
        Stock("A",10,100),
        Stock("B",12,120),
        Stock("C",14,140)
    };

    /*  <주소 사용>
        Stock *first = &s[0];
        for(int i=1;i<3;i++)
            first=&first->topval(s[i]);
        first->show();
    */

   //   <주소 미사용>
    Stock first = s[0];
    for(int i=1;i<3;i++)
        first=first.topval(s[i]);
    first.show();
    
    return 0;
}