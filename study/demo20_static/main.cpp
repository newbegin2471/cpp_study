#include <iostream>
using namespace std;
class Stu{
    public:
        int age=18;
    Stu(){};
    static int flag;  //声明，需要在类外进行定义
    void show(){
        this->age=100;
        this->flag=100;
        cout<<"age="<<age<<"    flag="<<flag<<endl;
    }
    static void fun(){
        flag=666;
        cout<<"静态成员函数：flag="<<flag<<endl;
    }
};
int Stu::flag=520;
int main()
{
    /**************************访问静态成员变量**********/
    //通过类名访问
    cout<<"flag="<<Stu::flag<<endl;
    //通过类对象访问
    Stu s1;
    cout<<sizeof(s1)<<endl;
    cout<<"s1.flag="<<s1.flag<<endl;
    //通过静态成员函数访问
    Stu::fun();
    //通过非静态成员访问
    s1.show();
    /*********************静态成员函数 */
    // 通过类对象调用
    s1.fun();
    //通过类名调用
    Stu::fun();
    //静态成员函数不能访问非静态成员，只能访问静态成员
    return 0;
}