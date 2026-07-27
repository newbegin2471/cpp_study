#include <iostream>
#include <cstring>
using namespace std;
/*
    1.初始化列表使用:
        1.成员是 const 变量,const 变量只能初始化，不能赋值
        2.成员是引用,引用创建时必须绑定对象，不能后续赋值
        3.没有无参构造的父类（串联你继承！重中之重）,父类只有带参构造，编译器无法自动调用，只能在子类初始化列表调用父类构造
    2.继承：允许一个类（子类 / 派生类）复用另一个类（父类 / 基类）的成员，并且可以扩展新功能。
    3.
    =========================================
    基类成员	    public 继承后子类中访问权限
    public	       public
    protected	   protected
    private	       子类不可直接访问
    ========================================
    4.继承构造函数顺序:
    创建子类对象：**先父类构造 → 后子类构造**
    销毁子类对象：**先子类析构 → 后父类析构**
    父类构造**只能写在冒号后的初始化列表，不能写在 {} 内部**
    5.当子类和父类有同名函数 / 变量：**子类隐藏父类成员**，优先调用子类。
        s.Person::show();   // 强制调用父类同名函数









*/
//基类
class Person{
    protected:
        char *name;
        int age;
    public:
        Person(const char *src,int a){
            cout<<"父类构造执行"<<endl;
            age=a;
            name=new char[strlen(src)+1];
            strcpy(name,src);
        }
        void showInfo(){
            cout<<"父类:"<<"姓名:"<<name<<"age:"<<age<<endl;
        }
        virtual ~Person(){
            cout<<"父类析构"<<endl;
        }

};
//子类：继承父类
class Student:public Person
{
    private:
        int id;
    public:
        Student(const char *src,int a,int id):Person(src,a)
        {
            cout<<"子类构造执行"<<endl;
            this->id=id;
        }
        void stuShow(){
            cout<<"子类:"<<"name="<<name<<"age="<<age<<"id="<<id<<endl;
        }
        ~Student(){
            cout<<"子类析构执行"<<endl;
        }
};


int main()
{
    Student stu("csg",20,2026);
    stu.showInfo();
    stu.stuShow();
    return 0;
}