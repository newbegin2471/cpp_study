#include <iostream>
#include "student.h"
using namespace std;

int main()
{
    StuInfo s;
    s.init();
    s.setNum(5);
    s.input();
    cout<<"显示成绩:"<<endl;
    s.show();
    s.sort();
    cout<<"显示排序后成绩:"<<endl;
    s.show();
    s.freeScore();
    return 0;
}