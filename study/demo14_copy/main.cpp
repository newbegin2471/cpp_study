#include <iostream>
using namespace std;
class Stu
{
    private:
        string name;
        int age;
        double score;
        int *ptr;
    public:
    void show()
    {
        cout<<"name="<<name<<endl;
        cout<<"age="<<age<<endl;
        cout<<"score="<<score<<endl;
        cout<<"*ptr="<<*ptr<<endl;
    }
    //无参构造
    Stu():ptr(nullptr)
    {
        cout<<"Stu:无参构造"<<endl;
    }
    Stu(string n,int a,double s):name(n),age(a),score(s),ptr(new int(1314))
    {
        cout<<"Stu:有参构造"<<endl;
    }
    ~Stu()
    {
        delete ptr;
        cout<<"Stu:析构函数"<<this<<endl;
    }
    //拷贝构造函数
    Stu(const Stu &other):name(other.name),age(other.age),score(other.score),ptr(new int(*(other.ptr)))
    {
        cout<<"拷贝构造函数"<<endl;
    }
};
int main()
{
    Stu s1("evie",18,100);
    Stu s2=s1;
    s1.show();
    s2.show();
    return 0;
}