#include <iostream>
#include <cstring>
/*
    用法：1.成员变量与形参重名，区分变量
    2.返回 *this，实现链式调用
    3.判断自赋值（operator = 重载）
    4.获取当前对象地址    
*/
class Person{
    public:
        char *name;
        int age;
    //普通构造
    Person(const char *n,int a){
        name=new char[strlen(n)+1];
        strcpy(name,n);
        age=a;
    }
    //==========1.区分变量与形参==========
    void setAge(int age){
        this->age=age;
    }
    void setName(const char *name){
        //为防止内存泄漏
        delete[] this->name;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    //============2.获取对象地址=============
    void printAddr(){
        std::cout<<"this对象地址:"<<this<<'\n';
    }
    //===========3.返回*this,实现链式调用====
    Person &setAgeChain(int age){
        this->age=age;
        return *this;
    }
    Person &setNameChain(const char *name){
        delete[] this->name;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        return *this;
    }
    //==============判断自赋值==============
    Person &operator=(const Person & other){
        if(this==&other){
            std::cout<<"触发自赋值\n"<<std::endl;
            return *this;
        }
        delete[] this->name;
        this->name=new char[strlen(other.name)+1];
        strcpy(this->name,other.name);
        this->age=other.age;
        return *this;
    }
    // 拷贝构造中不需要判断 this == &other
    Person(const Person& other)
    {
        this->name = new char[strlen(other.name)+1];
        strcpy(this->name, other.name);
        this->age = other.age;
    }
    // ========== 陷阱：静态成员函数不能使用this ==========
    static void staticFunc()
    {
        // cout << this; // ?编译报错！静态函数没有对象
    }

    void showInfo()
    {
        std::cout << "name:" << this->name << " age:" << this->age << '\n';
    }

    ~Person()
    {
        delete[] name;
    }

};
int main()
{
    Person p1("tom",20);
    p1.setName("Jack");
    p1.printAddr();
    p1.showInfo();
    return 0;
}
