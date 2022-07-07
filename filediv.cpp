#include "filediv_struct.h"
//헤더 파일을 여러 파일에 포함시킬 때에, 반드시 단 한 번만 포함시켜야 한다.
//------------->#ifndef 이름 ~ #endif 사이에 있는부분은 무조건 1번만 실행된다

int main(){
    MyStruct PandaCoding = {
        "Panda",
        26,
    };
    display(PandaCoding);
    return 0;
}

