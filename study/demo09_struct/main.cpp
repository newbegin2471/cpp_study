#include <iostream>
using namespace std;
struct Stu{
    public:
        string name="tom";
    private:
        int age=18;
    protected:
        double score=99;
    public:
        void show(){
            cout<<"Stu::name="<<name<<endl;
            cout<<"Stu::age="<<age<<endl;
            cout<<"Stu::score="<<score<<endl;
        }
    struct Car{
        string color;
        int wheel;
    };
};
struct ClassLeader:Stu{
    string position="班长";
    void display(){
        cout<<"name="<<name<<endl;
        // cout<<"age="<<age<<endl;
        cout<<"score="<<score<<endl;
    }
};
int main()
{
    struct Stu s1;//c语言风格形式结构体
    Stu s2;//c++语言形式结构体
    cout<<sizeof(Stu)<<endl;
    cout<<sizeof(Stu::Car)<<endl;
    cout<<"父结构体:"<<endl;
    s2.show();
    cout<<"子结构体:"<<endl;
    ClassLeader s3;
    s3.display();
    return 0;
}