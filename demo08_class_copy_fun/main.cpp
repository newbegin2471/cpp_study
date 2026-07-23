#include <iostream>
#include <cstring>
//拷贝构造函数，实现深拷贝，同类的不管是私有还是公有属性都可以拷贝，尽量拷贝函数传参用引用；
class Person{
        char *name;
        int age;
    public:
        Person(const char *n,   int a){
            age=a;
            name=new char[strlen(n)+1];
            strcpy(name,n);
            std::cout<<"有参类构造函数被调用"<<std::endl;
        }
        Person(const Person &other){
            age=other.age;
            name=new char[strlen(other.name)+1];
            strcpy(name,other.name);
            std::cout<<"调用拷贝构造函数"<<std::endl;
        }
        ~Person(){
            delete[] name;
            std::cout<<"析构调用"<<std::endl;
        }
        void showInfo(){
            std::cout<<"name:"<<name<<" "<<"age:"<<age<<std::endl;
        }
};
int main()
{
    Person p1("csg",20);
    p1.showInfo();
    Person p2=p1;
    p2.showInfo();
    return 0;
}
